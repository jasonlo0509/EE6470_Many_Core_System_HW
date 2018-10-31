void BaremetalDNN_toplevel(
float* ret /* float[1][4][2][2] */,
	const float* data /* float[1][1][6][6] */ ,
	const float* net0_conv0_weight /* float[4][1][3][3] */ ,
	const float* net0_conv0_bias /* float[4] */ );
