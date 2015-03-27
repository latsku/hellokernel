# Hello World kernel

How small could a "Hello World!" printing kernel be?

I wanted to boot x86 machine (emulator) and print hello world with the smallest code base and still keep it understandable. The assembly code is minimal and most of the heavy lifting is done with C.


## How small it is?

**5088** bytes at the moment when compiled with GCC 4.6.3. After stripping all symbols 4616 bytes.


## Compiling & Running with QEMU

    make
    make qemu
