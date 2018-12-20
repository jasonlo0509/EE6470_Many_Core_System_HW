#include <iostream>
#include <cstdlib>
#include <cmath>
#include "sync.h"

void BaremetalDNN_model_wraper();

float g_input[4*12*12], g_output[4*6*6];
int in_c, in_h, in_w;
int out_c, out_h, out_w;
int g_nc;

extern "C" void thread_entry(int cid, int nc) {
	std::cout << "cid = " << cid << "\n" ;
	
	g_nc = nc;
	
	if(cid == 0){
		BaremetalDNN_model_wraper();
	}
	else {
		for(int i = 0; i < 2; i++){
			std::cout << cid << std::endl;
			barrier(nc);
			int start_c, end_c;
			start_c = gethartid()*(out_c / 4);
			if(gethartid() != g_nc - 1){
				end_c = (gethartid()+1)*(out_c / 4);
			}
			else{
				end_c = out_c;
			}
			
			for(unsigned int c = start_c; c < end_c; ++c) {
			for(unsigned int h = 0; h < out_h; ++h) {
			for(unsigned int w = 0; w < out_w; ++w) {
			const auto Oidx = out_w * out_h * c +
			              out_w * h +
			              w;
			// initialize with minimum value
			auto max = -100000.0;
			for(unsigned int fh = 0; fh < 2; ++fh) {
			for(unsigned int fw = 0; fw < 2; ++fw) {
			  const auto Ih = (h * 2) + fh;
			  const auto Iw = (w * 2) + fw;
			  const auto Iidx = in_w * in_h * c +
			                in_w * Ih +
			                Iw;
			  max = fmax(max, g_input[Iidx]);
			}}
			g_output[Oidx] = max;
			}}}
			
  
			barrier(nc);
		}
	}

}