#ifndef TESTBENCH_H_
#define TESTBENCH_H_

#include <iostream>
#include <string>
using namespace std;

#include <systemc>
using namespace sc_core;

#ifndef NATIVE_SYSTEMC
#include <cynw_p2p.h>
#endif

#include "filter_def.h"

#define WHITE 255
#define BLACK 0
#define THRESHOLD 90

class Testbench : public sc_module {
public:
	sc_in_clk i_clk;
	sc_out < bool >  o_rst;
#ifndef NATIVE_SYSTEMC
	cynw_p2p< sc_dt::sc_uint<32> >::base_out o_rgb;
	cynw_p2p< sc_dt::sc_uint<32> >::base_in i_result;
#else
	sc_fifo_out< sc_dt::sc_uint<32> > o_rgb;
	sc_fifo_in< sc_dt::sc_uint<32> > i_result;
#endif

  SC_HAS_PROCESS(Testbench);

  Testbench(sc_module_name n);
  ~Testbench();



private:
	
	unsigned int n_txn;
	sc_time max_txn_time;
	sc_time min_txn_time;
	sc_time total_txn_time;
	sc_time total_start_time;
	sc_time total_run_time;
  sc_dt::sc_uint<32> data[4*12*12];

  void feed_rgb();
	void fetch_result();
};
#endif
