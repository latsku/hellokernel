Hello World kernel
==================

How small could a "Hello World!" printing kernel be? 

I wanted to boot x86 machine (emulator) and print hello world with the smallest code base and still keep it understandable. The assembly code is minimal and most of the heavy lifting is done with C. 

How small it is? 
================

5114 bytes

At the moment with GCC 4.6.3.




Compiling & Running with QEMU
=============================

make
make qemu
