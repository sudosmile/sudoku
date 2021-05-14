#ifndef MAIN_H_
#define MAIN_H_

#include <stdio.h>
#include <stdbool.h>

typedef struct coord {
    int x;
    int y;
    int none;
}coord;

typedef int map[9][9];


static const int ERROR = 84;
static const int SUCCESS = 0;

#endif /* MAIN_H_ */
