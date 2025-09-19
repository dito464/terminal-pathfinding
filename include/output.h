#ifndef OUTPUT_H
#define OUTPUT_H

#include "abuf.h"
#include "terminal.h"

enum CellTypes {
    START,
    END,
    BARRIER,
    PERM_BARRIER,
    EMPTY
};  

typedef Cell {
    enum CellTypes type;
    int x, y;
    char ch;
} Cell;

typedef struct Grid {
    int rows, cols;
    Cell **cells;

    Cell *start_cell;
    Cell *end_cell;

    
    return
} Grid;

extern Grid *g;

void drawPathfindingVisualizer();
void drawWelcomeScreen();
void drawGrid(abuf *ab);
void drawWelcomeRows(abuf *ab);
int getGridIndex(Grid* grid, int row, int column){
    return Grid->cols * row + column;
}

#endif