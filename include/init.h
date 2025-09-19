#ifndef INIT_H
#define INIT_H
#include "output.h"

void init();
Grid* initGrid(Grid *g, int rows, int cols);
void freeGrid(Grid *g);

#endif