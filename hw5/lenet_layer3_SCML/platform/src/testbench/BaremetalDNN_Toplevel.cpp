#include "BaremetalDNN_Op.h"
#include "runtime.h"
void BaremetalDNN_toplevel(
float* ret /* float[1][4][2][2] */,
	const float* data /* float[1][1][6][6] */ ,
	const float* net0_conv0_weight /* float[4][1][3][3] */ ,
	const float* net0_conv0_bias /* float[4] */ ){
#include "BaremetalDNN_Tensor.h"
float* LocalBuf0 = new float[64];
float* LocalBuf1 = new float[64];
// tvmop: 3 : relu0
relu0_tensor.data = (void*) LocalBuf0;
fuse_conv2d_relu_1((void*) relu0_tvmval,(void*) relu0_typeid,4);
// tvmop: 4 : max_pool2d0
max_pool2d0_tensor.data = (void*) ret;
fuse_max_pool2d_1((void*) max_pool2d0_tvmval,(void*) max_pool2d0_typeid,2);

delete[] LocalBuf0;
delete[] LocalBuf1;
}