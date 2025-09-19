#include <stdlib.h>
#include <string.h>

#include "terminal.h"
#include "init.h"
#include "output.h"

Grid *g = NULL;


void init() {
	// Initial cursor pos
	Con.cx = 1;
	Con.cy = 1;
	
	// Allocate rows and cols of terminal, initialise grid with these values.
	if (getWindowSize(&Con.screenrows, &Con.screencols) == -1) die("getWindowSize");

	g = initGrid(g, Con.screenrows, Con.screencols);
	if (!g) die("Couldn't initialise the grid.");

	// Pointers to start/end cell.
	g->start_cell = NULL;
    g->end_cell = NULL;
	
}

Grid* initGrid(Grid *g, int rows, int cols) {
	g = malloc(sizeof(Grid));
	if (!g) die("Couldn't allocate memory for grid of terminals size.");

	// Allocate the rows and cols.
	g->rows = rows;
	g->cols = cols;

	// Allocate memory for an array of row pointers, sized for rows
	g->cells = malloc(sizeof (Cell*) * rows * cols);
	if (!g->cells) die("g->cells not allocated.");

	// Lord forgive me.
	for (int y = 0; y < rows; y++) {
		for (int x = 0; x < cols; x++) {

			// Make terminal edges borders by default.
			if (y == 0 || x == 0 || y == Con.screenrows - 1 || x == Con.screencols - 1) {
				// Don't need to init .x .y here as we won't change them ever.
				g->cells[getGridIndex(g, x, y)].type = PERM_BARRIER;
				g->cells[getGridIndex(g, x, y)].ch = '#';
			} else {
				g->cells[[getGridIndex(g, x, y)]].type = EMPTY;
				g->cells[[getGridIndex(g, x, y)]].x = x;
				g->cells[[getGridIndex(g, x, y)]].y = y;
				g->cells[[getGridIndex(g, x, y)]].ch = ' ';
			}
			
		}
	}
	return g;
}


void freeGrid(Grid *g) {
	free(g->cells);
}