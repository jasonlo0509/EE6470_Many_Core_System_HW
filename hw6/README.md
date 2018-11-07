# HW6
### Yun-Chen Lo (107061548)

## How to run
```bash
In lenet_SCML/ (part I)
$ mkdir build
$ cd build
$ cmake ../
$ make
$ ./pooling
In lenet_SCML_decompose/ (part II)
$ mkdir build
$ cd build
$ cmake ../
$ make
$ ./pooling
// single layer version for debug
In lenet_layer3_SCML/   
In lenet_layer3_SCML_decompose/
```

## General description
In this homework, we have to implement a LENET using SCML platform, and port the software pooling logic to hardware. The second part we need to decompose the data \& do sub-data sequentially. 


## Implementation Details
### part I
1. I replace the Test_Thread with BaremetalDNN\_model\_wraper
2. In Op.cpp, I config the pooling engine \& DMA to do the data transfer.
3. In addition, remember extern the Testbench class in Op.py and make it a global variable in main.cpp

### part II
1. The only different is I decompose the input data into 4 decomposed sub-data along channel-side.

## Experimental results
Cycle count:
1. version I 1652 ns
2. version II 1856 ns

Bandwidth required for Bus:
version I is 4x of version II during transfer.

We can see that by intuition decomposition input data by four will increase the execution time by four times, but because the data trasfer is not the bottleneck for cycle count, we can reduce the bandwidth while not sacrificing so much cycle time.
## Discussions and conclusions
The machine generated code is very hard to trace, if a more readable code will be very good!!!