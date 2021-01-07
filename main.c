#include <stdio.h>

struct coord {
    int x;
    int y;
    int none;
};

struct coord find_empty(int map[9][9])
{
    struct coord out;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (map[i][j] == 0) {
                out.x = i;
                out.y = j;
                out.none = 0;
                return out;
            }
        }
    }
    out.none = 1;
    return out;
}

int valid(int map[9][9], struct coord pos, int num) //checks if move valid
{
    int i, j, box_x, box_y;

    //check row
    for (i = 0; i < 9; i++) {
        if (map[pos.x][i] == num && pos.y != i)
            return 0;
    }

    //check col
    for (i = 0; i < 9; i++) {
        if (map[i][pos.y] == num && pos.y != i)
            return 0;
    }

    //check box
    box_x = pos.x/3;
    box_y = pos.y/3;
    for (i = (box_y*3); i < (box_x * 3 + 3); i++) {
        for (j = (box_x*3); j < (box_y * 3 + 3); j++) {
            if (map[i][j] == num && (i != pos.x || j != pos.y))
                return 0;
        }
    }

    //all conditions met: move valid
    return 1;
}

int solve(int map[9][9])
{
    struct coord found = find_empty(map);
    int row, col, i;
    if (found.none != 1) {
        row = found.x;
        col = found.y;
    } else
        return 1;
    for (i=1; i < 10; i++) {
        if (valid(map, found, i)) {
            map[found.x][found.y] = i;
            if (solve(map))
                return 1;
            map[found.x][found.y] = 0;
        }
    }
    return 0;
}

int main(int arc, char *arv[])//will take user input and make a board
{
    return 0;
}
