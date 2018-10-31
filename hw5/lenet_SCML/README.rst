================
Pooling SCML DMA
================

Toolchain Dependencies
----------------------

GNU c++ compiler version 5.4.0 on Ubuntu 16.04

Library Dependencies
--------------------

1. SystemC 2.3.1

2. SCML 2.4.3


Note:

Make sure the **SYSTEMC_HOME** and **SCML_HOME** is set correctly for CMake to find libraries.

Make sure the LD_LIBBRARY_PATH is set correctly to find libsystemc-2.3.1.so.

Platform Components
-------------------

Testbench, Pooling engine, DMA, memory and SCML router

How to Build Platform
---------------------

``$ cd platform``

``$ mkdir build``

``$ cd build``

``$ cmake ..``

``$ make``

``$ make run``
