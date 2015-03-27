/* console.h */

#ifndef __CONSOLE_H__
#define __CONSOLE_H__

/* Some screen stuff. */
/* The number of columns. */
#define COLUMNS                 80
/* The number of lines. */
#define LINES                   24
/* The attribute of an character. */
#define ATTRIBUTE               0x1F
/* The video memory address. */
#define VIDEO                   0xB8000

/* Variables. */
/* Save the X position. */
int xpos;
/* Save the Y position. */
int ypos;
/* Point to the video memory. */
volatile unsigned char *video;


void init_console(void); /* initialize the console driver */
void printk (const char *msg); /* main kernel console-printing function */


#endif
