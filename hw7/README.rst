==================
Pooling OVP RISC-V
==================

Toolchain Dependencies
----------------------

1. GNU c++ compiler version 5.4.0 on Ubuntu 16.04

2. `Andes Technology RISC-V LLVM Toolchain <https://github.com/andestech/riscv-llvm-toolchain/tree/8648625a42822048700ba0048edea7c69f00da93>`_

Library Dependencies
--------------------

1. SystemC 2.3.1

2. SCML 2.4.3

3. OVP 20180716.0

Note:

Make sure the **SYSTEMC_HOME**, **SCML_HOME** and **IMPERAS_HOME** is set correctly for CMake to find libraries.

Make sure the **LD_LIBBRARY_PATH** is set correctly to find **libsystemc-2.3.1.so**.

Make sure the **path_to_riscv_toolchain/bin** is included in the **PATH**.

Platform Components
-------------------

OVP RISC-V, Pooling engine, DMA, memory and SCML router

How to Build Platform
---------------------

``$ cd platform``

``$ mkdir build``

``$ cd build``

``$ cmake ..``

``$ make``

How to Build Application
------------------------

``$ cd application``

``$ mkdir build``

``$ cd build``

``$ cmake ..``

``$ make``

How to Run Simulation
---------------------

Under the directory **platform/build** or **application/build**:

Run hello world:

``$ make hello``

Run pure software pooling:

``$ make sw``

Run hardware pooling:

``$ make hw``
