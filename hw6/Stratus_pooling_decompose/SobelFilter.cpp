#include <cmath>
#ifndef NATIVE_SYSTEMC
#include "stratus_hls.h"
#endif

#include "SobelFilter.h"

SobelFilter::SobelFilter( sc_module_name n ): sc_module( n )
{
#ifndef NATIVE_SYSTEMC
	HLS_FLATTEN_ARRAY(ram);
#endif
	SC_THREAD( do_filter );
	sensitive << i_clk.pos();
	dont_initialize();
	reset_signal_is(i_rst, false);
        
#ifndef NATIVE_SYSTEMC
	i_rgb.clk_rst(i_clk, i_rst);
  o_result.clk_rst(i_clk, i_rst);
#endif
}

SobelFilter::~SobelFilter() {}

int out_ch = 4;
int out_w = 12;
int out_h = 12;

void SobelFilter::do_filter() {
	{
#ifndef NATIVE_SYSTEMC
		HLS_DEFINE_PROTOCOL("main_reset");
		i_rgb.reset();
		o_result.reset();
#endif
		wait();
	}
	int offset;
	while (true) {
		// save data into ram
		for (unsigned int ch = 0; ch<out_ch/4; ++ch) {
			for (unsigned int w = 0; w<out_w; ++w) {
				for (unsigned int h = 0; h<out_h; ++h) {
					offset = ch * out_ch/4 + h * out_h + w * out_w;
#ifndef NATIVE_SYSTEMC
					{
						HLS_DEFINE_PROTOCOL("input");
						ram[offset] = i_rgb.get();
						wait();
					}
#else
					ram[offset] = i_rgb.read();
#endif
					
				}
			}
		}
		for(unsigned int c = 0; c < out_ch/4; ++c) {
		for(unsigned int h = 0; h < out_h; ++h) {
		for(unsigned int w = 0; w < out_w; ++w) {
			
			// initialize with minimum value
			sc_dt::sc_uint<32> max = 0;
			for(unsigned int fh = 0; fh < 2; ++fh) {
			for(unsigned int fw = 0; fw < 2; ++fw) {
				int Ih = (h * 2) + fh;
				int Iw = (w * 2) + fw;
				//int Iidx = data_shape.Idx(c, Ih, Iw);
				offset = c * out_ch/4 + Ih * out_h + Iw * out_w;
				if(max <= ram[offset])
					max = ram[offset];
			}}
#ifndef NATIVE_SYSTEMC
			{
				HLS_DEFINE_PROTOCOL("output");
				o_result.put(max);
				wait();
			}
#else
		o_result.write(max);
#endif
		}}}

	}
}

