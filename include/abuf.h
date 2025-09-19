#ifndef ABUF_H
#define ABUF_H

#define ABUF_INIT {NULL, 0}

typedef struct abuf {
    char *b;
    int len;
} abuf;

void abAppend(abuf *ab, char *s, int len);
void abFree(abuf *ab);

#endif