const int64_t data_shape[4] = {1,1,6,6};
DLTensor data_tensor = {
	(void*)data/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)data_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t net0_conv0_weight_shape[4] = {4,1,3,3};
DLTensor net0_conv0_weight_tensor = {
	(void*)net0_conv0_weight/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)net0_conv0_weight_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
const int64_t net0_conv0_bias_shape[1] = {4};
DLTensor net0_conv0_bias_tensor = {
	(void*)net0_conv0_bias/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	1/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)net0_conv0_bias_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 3 : relu0
// will not be used actually// float[1][4][4][4]
float* relu0 = nullptr;
const int64_t relu0_shape[4] = {1,4,4,4};
DLTensor relu0_tensor = {
	(void*)relu0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)relu0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
// tensor: 4 : max_pool2d0
// will not be used actually// float[1][4][2][2]
float* max_pool2d0 = nullptr;
const int64_t max_pool2d0_shape[4] = {1,4,2,2};
DLTensor max_pool2d0_tensor = {
	(void*)max_pool2d0/*data*/, 
	DLContext({kDLFirmware, 0 /*device_id*/}), 
	4/*ndim*/, 
	DLDataType({2, 32, 1}), /*float code*/
	(int64_t*)max_pool2d0_shape /*shape*/, 
	nullptr /*strides*/, 
	0 /*byte_offset*/, 
};
TVMValue relu0_tvmval[4];
relu0_tvmval[0].v_handle = (void*)&data_tensor;
relu0_tvmval[1].v_handle = (void*)&net0_conv0_weight_tensor;
relu0_tvmval[2].v_handle = (void*)&net0_conv0_bias_tensor;
relu0_tvmval[3].v_handle = (void*)&relu0_tensor;
const int relu0_typeid[4] = {3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/,3 /* handle type id*/};
TVMValue max_pool2d0_tvmval[2];
max_pool2d0_tvmval[0].v_handle = (void*)&relu0_tensor;
max_pool2d0_tvmval[1].v_handle = (void*)&max_pool2d0_tensor;
const int max_pool2d0_typeid[2] = {3 /* handle type id*/,3 /* handle type id*/};
