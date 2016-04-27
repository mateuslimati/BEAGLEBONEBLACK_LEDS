#ifndef GPIOFUNC_H_
#define GPIOFUNC_H_
#include <stdio.h>
#include <stdlib.h> 
#define OUT 0
#define IN 1

void initGpio(int);
void releaseGpio(int);
void gpio_set_dir(int, int);
void gpio_set_value(int, int);

#endif
