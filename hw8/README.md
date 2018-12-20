# HW8
### Yun-Chen Lo (107061548)

## How to run
```bash
// build platform first
$ cd application
$ mkdir build; cd build
$ cmake ../
$ make lenet_sw // run parallelized version of lenet_sw with 4 cores
```

## General description
In this homework, we have to port lenet to RISC-V multi-core platform

## Implementation Details
1. I only execute lenet on core 0, as for other cores, I execute maxpooling.
2. The handshaking is implemented by barrier function
3. We use global variable to combine all results

## Experimental results
The parallelized version output is the same as the sequential version.
The number of instructions being executed for cores is similar between sequential version(49,032,313) & parallelized version(48,000,126). I think it is because max-pooling is not the runtime bottleneck.

```bash
{
	[
	8.4 4.2 2.5 4.6
	6.4 0.0 2.5 7.6
	4.2 0.0 4.4 6.1
	3.4 3.1 5.7 2.7
	]
}
Output:
{
	[
	8.4 7.6
	4.2 6.1
	]
}
The network finishes correctly!
```

## Discussions and conclusions
I think if just observe the 