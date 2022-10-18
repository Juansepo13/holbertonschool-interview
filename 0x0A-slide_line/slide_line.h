#ifndef SLIDE_LINE
#define SLIDE_LINE

#include <stdlib.h>
#include <stdio.h>

#define SLIDE_LEFT 'L'
#define SLIDE_RIGHT 'R'

int slide_line(int *line, size_t size, int direction);
void slide_line_left(int *line, int size_);
void slide_line_right(int *line, int size_);


#endif /* SLIDE_LINE */
