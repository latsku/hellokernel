/* console.c:

    Console functions to initialize, print and write the characters to console.
*/

#include "console.h"

/* initialize the console driver */
void init_console(void) {

  xpos = 0;
  ypos = 5;

}

/* Put the character C on the screen. */
void putchar (int c) {
  if (c == '\n' || c == '\r') {
    newline:
    xpos = 0;
    ypos++;
    if (ypos >= LINES)
      ypos = 0;
    return;
  }

  *(VIDEO + (xpos + ypos * COLUMNS) * 2) = c & 0xFF;

  xpos++;
  if (xpos >= COLUMNS)
    goto newline;
}

/* main kernel console-printing function */
void printk (const char *msg) {
  int c;

  while ((c = *msg++) != 0) {
    putchar (c);
  }
}
