/* boot.S:
    Multiboot header and stack initialization.

*/
     #define MULTIBOOT_HEADER_MAGIC         0x1BADB002
     #define MULTIBOOT_HEADER_FLAGS         0x00000003
     #define STACK_SIZE                     0x4000

             .section .text
             .global  start

             /* Align 32 bits boundary. */
             .align  4

             /* Multiboot header. */
     multiboot_header:
             /* magic */
             .long   MULTIBOOT_HEADER_MAGIC
             /* flags */
             .long   MULTIBOOT_HEADER_FLAGS
             /* checksum */
             .long   -(MULTIBOOT_HEADER_MAGIC + MULTIBOOT_HEADER_FLAGS)
    start:
             /* Initialize the stack pointer. */
             movl    $(stack + STACK_SIZE), %esp

             /* Reset EFLAGS. */
             pushl   $0
             popf

             /* Now enter the C main function */
             call    main

             /* Our stack area. */
             .comm   stack, STACK_SIZE
