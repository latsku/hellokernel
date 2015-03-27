/* kernel.c:

	Hello World! kernel
*/
#include "console.h"

void main()
{
  init_console();

  printk("Hello World!\n");

  asm("hlt");	// Instead of busy looping at the end, halt the processor.

}


