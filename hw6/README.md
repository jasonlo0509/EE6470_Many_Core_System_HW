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
// code for getting timing of pooling engine
In Stratus_pooling/   
In Stratus_pooling_decompose/
```

## General description
In this homework, we have to get timing of pooing engine and fill back to the original SCML platform to extract much real results.


## Implementation Details
### Stratus_pooling
1. I write a new testbench and feed different feature map into pooing2D function.
2. Then I use stratus to synthsis the pooing engine and do the cosimulation.

### Stratus_pooling_decompose
1. The only different part is that I change the ram size on pooing engine to 1/4. And do the exeution for four times.

## Experimental results

timing : (for feature map [4,12,12])

1. version I 56740 ns
2. version II 18913 ns

timing : (for feature map [8,4,4])

1. version I 11580 ns
2. version II 5900 ns


The SCML simulation time is:

1. version I 1652ns -> 69972ns
2. version II 1856ns -> 26669ns

We can observe the real simulation time after filling back the real pooling engine timing. But because we didn't do any architecture adjustment, this homework is somehow strange.

## Discussions and conclusions
I think it is strange for this homework to do things like this.
We probably have ot design architecture first, then we could start to do high level synthesis.