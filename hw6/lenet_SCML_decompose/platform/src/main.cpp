#include "testbench/testbench.h"
#include "acc_platform/acc_platform.h"

// make testbench a global object
Testbench tb("tb");

int sc_main(int argc, char** argv) {
	AccPlatform acc_platform("acc_platform");
	tb.i_socket(acc_platform.bus_t_socket_0);

	sc_start();
	std::cout<< "Simulated time:" << sc_core::sc_time_stamp() << std::endl;

	return 0;
}
