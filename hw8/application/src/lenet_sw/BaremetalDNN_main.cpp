#include <iostream>
#include <cassert>
#include "runtime.h"
#include "BaremetalDNN_model.h"
#include "BaremetalDNN_Toplevel.h"

float data[1][1][14][14] = {{{{0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    0.00000000e+00,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    4.87574607e-06,1.09633664e-02,5.13961948e-02,5.19433320e-02,
    1.55828185e-02,7.60553157e-05,1.36642047e-05,3.07168158e-09,
    0.00000000e+00,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,0.00000000e+00,9.82938175e-09,
    1.09450864e-02,4.27332014e-01,9.24751878e-01,9.29469168e-01,
    6.11982048e-01,2.97649890e-01,8.04951265e-02,1.17324363e-03,
    0.00000000e+00,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,6.00684391e-09,1.12740195e-03,
    1.92625076e-01,9.08443272e-01,9.18700814e-01,6.09106421e-01,
    8.60435545e-01,9.56212640e-01,7.47310936e-01,4.84028347e-02,
    5.28949749e-06,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,4.76956571e-04,1.28372684e-01,
    7.69098699e-01,9.52158034e-01,3.01712483e-01,1.59164295e-02,
    1.04456477e-01,6.35280252e-01,9.66921449e-01,4.28207010e-01,
    5.33157866e-03,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,1.62080023e-02,6.08624279e-01,
    9.81912613e-01,6.09168053e-01,2.94915661e-02,3.97940812e-06,
    3.23502638e-04,9.59455818e-02,8.35377395e-01,6.93132877e-01,
    2.37744395e-02,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,2.93551758e-02,7.40611553e-01,
    8.70044291e-01,1.19025014e-01,3.28322349e-04,4.77817119e-10,
    2.86690272e-09,3.27845216e-02,7.69210458e-01,7.91252613e-01,
    3.54097337e-02,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,4.17055152e-02,8.43907237e-01,
    6.66423619e-01,2.12402027e-02,2.24808232e-07,0.00000000e+00,
    3.68026662e-07,3.35698202e-02,7.70999014e-01,8.92412484e-01,
    4.74981219e-02,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,3.75579819e-02,8.09226692e-01,
    7.64170945e-01,3.21796425e-02,2.73038370e-09,2.53726762e-06,
    2.04633991e-03,1.89620256e-01,8.84068727e-01,7.09034204e-01,
    2.55953111e-02,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,1.71501040e-02,6.31854415e-01,
    8.28978240e-01,9.06360820e-02,2.82457061e-02,4.29399759e-02,
    2.13504210e-01,7.75341809e-01,9.72531676e-01,4.79595006e-01,
    1.09387571e-02,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,5.92410157e-04,3.49653512e-01,
    9.54569042e-01,7.37353563e-01,7.30921149e-01,7.84547627e-01,
    9.35286641e-01,9.58384216e-01,5.88577032e-01,3.69077288e-02,
    6.91873765e-06,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,2.91509559e-06,3.40839066e-02,
    5.89941502e-01,8.10186625e-01,6.88133776e-01,6.48928165e-01,
    3.85960191e-01,3.05329233e-01,6.33979216e-02,2.05719534e-05,
    0.00000000e+00,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,0.00000000e+00,1.07836649e-05,
    1.67189166e-02,3.77077423e-02,2.33690199e-02,2.18655746e-02,
    1.15977426e-03,7.48682287e-05,1.36381686e-05,3.07168158e-09,
    0.00000000e+00,0.00000000e+00},
   {0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    0.00000000e+00,0.00000000e+00,0.00000000e+00,0.00000000e+00,
    0.00000000e+00,0.00000000e+00}}}};
float golden_out[1][10] = {{19.926655  ,-8.12159   , 5.568624  ,-4.098072  ,-7.000052  , 2.1064756 ,
   3.7502055 , 3.0716705 , 0.8413372 ,-0.03656473}};

void BaremetalDNN_model_wraper() {

  float* ret = (float*) new float[1][10];

	BaremetalDNN_toplevel(
	ret,
	(float*)data,
	(float*)net0_conv0_weight,
	(float*)net0_conv0_bias,
	(float*)net0_conv1_weight,
	(float*)net0_conv1_bias,
	(float*)net0_dense0_weight,
	(float*)net0_dense0_bias
  );
	compare<float>((float*)golden_out, ret, 10);
	delete[] ret;

}
