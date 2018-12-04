# HW7
### Yun-Chen Lo (107061548)

## How to run
```bash
// build platform first
$ cd application
$ mkdir build; cd build
$ cmake ../
$ make lenet_sw // part I
$ make lenet_hw // part II
```

## General description
In this homework, we have to port lenet to RISC-V, and use software to control hardware through register interface


## Implementation Details
I first directly cross compile all code from LenetCPP to RISC-V
Then I change the code in Op.cpp to control the hardware
## Experimental results

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
I think this hw give us a sense of how to port the hardware application to cpu