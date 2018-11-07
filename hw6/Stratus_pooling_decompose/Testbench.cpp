#include <cstdio>
#include <cstdlib>
using namespace std;

#include "Testbench.h"



Testbench::Testbench(sc_module_name n) : sc_module(n) {
  SC_THREAD(feed_rgb);
  sensitive << i_clk.pos();
  dont_initialize();
  SC_THREAD(fetch_result);
  sensitive << i_clk.pos();
  dont_initialize();
}

Testbench::~Testbench() {
	//cout<< "Max txn time = " << max_txn_time << endl;
	//cout<< "Min txn time = " << min_txn_time << endl;
	//cout<< "Avg txn time = " << total_txn_time/n_txn << endl;
	cout << "Total run time = " << total_run_time << endl;
}


void Testbench::feed_rgb() {
  unsigned int x, y, i, v, u; // for loop counter
  unsigned char R, G, B;      // color of R, G, B
  int adjustX, adjustY, xBound, yBound;
	n_txn = 0;
	max_txn_time = SC_ZERO_TIME;
	min_txn_time = SC_ZERO_TIME;
	total_txn_time = SC_ZERO_TIME;
  // set the input feature map
  int in_w = 12;
  int in_h = 12;
  int in_ch = 4;
  int data_num = in_w * in_h * in_ch;

  // input fmap value
  for(int i = 0; i < data_num; i++)
    data[i] = i%100;

#ifndef NATIVE_SYSTEMC
	o_rgb.reset();
#endif
	o_rst.write(false);
	wait(5);
	o_rst.write(true);
	wait(1);
	total_start_time = sc_time_stamp();
  sc_dt::sc_uint<32> rgb;
  int offset;

  for (int ch = 0; ch < in_ch; ++ch) {
    for (x = 0; x != in_w; ++x) {
      for (y = 0; y != in_h; ++y) {
        offset = ch * in_ch + y * in_h + x * in_w;
        rgb = data[offset];
        //cout << "pass data: " << rgb << endl;
  #ifndef NATIVE_SYSTEMC
  					o_rgb.put(rgb);
  #else
  					o_rgb.write(rgb);
  #endif
      }
    }
  }
}

void Testbench::fetch_result() {
  unsigned int x, y, ch; // for loop counter
  int total;
  int out_ch = 4;
  int out_w = 6;
  int out_h = 6;
#ifndef NATIVE_SYSTEMC
	i_result.reset();
#endif
	wait(5);
	wait(1);
  cout << "return data: " << endl;
  for (ch = 0; ch < out_ch; ++ch){
    for (y = 0; y != out_w; ++y) {
      for (x = 0; x != out_h; ++x) {
  #ifndef NATIVE_SYSTEMC
  			total = i_result.get();
  #else
  			total = i_result.read();
  #endif
  			cout << total << " ";
      }
    }
    cout << endl;
  }
	total_run_time = sc_time_stamp() - total_start_time;
  sc_stop();
}
