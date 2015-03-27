/* console.c:

    Console functions to initialize, print and write the characters to console.
*/

#include "console.h"

/* initialize the console driver */
void init_console(void) {

  xpos = 0;
  ypos = 5;

  video = (unsigned char *) VIDEO;
}

/* main kernel console-printing function */
void printk (const char *msg) {
  int c;

  while ((c = *msg++) != 0) {
    putchar (c);
  }
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

  *(video + (xpos + ypos * COLUMNS) * 2) = c & 0xFF;
  *(video + (xpos + ypos * COLUMNS) * 2 + 1) = ATTRIBUTE;

  xpos++;
  if (xpos >= COLUMNS)
    goto newline;
}
