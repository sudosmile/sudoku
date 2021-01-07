#include <stdio.h>

typedef struct coords {
    int x;
    int y;
    int none;
}coord;

int test_map[9][9] = {
    {0,0,0,0,3,0,0,4,2},
    {8,0,0,0,2,0,0,0,3},
    {0,7,0,9,0,0,5,8,0},
    {0,1,0,0,0,4,0,0,0},
    {6,0,0,0,0,0,0,0,4},
    {0,0,0,8,0,0,0,7,0},
    {0,6,7,0,0,5,0,9,0},
    {1,0,0,0,8,0,0,0,7},
    {3,2,0,0,9,0,0,0,0},
};

coord find_empty(int map[9][9])
{
    coord out;
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

int valid(int map[9][9], coord pos, int num) //checks if move valid
{
    int i, j, box_x, box_y;
    for (i = 0; i < 9; i++) {
        if (map[pos.x][i] == num && pos.y != i)
            return 0;
    }
    for (i = 0; i < 9; i++) {
        if (map[i][pos.y] == num && pos.y != i)
            return 0;
    }
    box_x = pos.x/3;
    box_y = pos.y/3;
    for (i = (box_y*3); i < (box_x * 3 + 3); i++) {
        for (j = (box_x*3); j < (box_y * 3 + 3); j++) {
            if (map[i][j] == num && (i != pos.x || j != pos.y))
                return 0;
        }
    }
    return 1;
}

int solve(int map[9][9])
{
    coord found = find_empty(map);
    int i;
    if (!(found.none != 1))
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

void printoku(int map[9][9])
{
    int i, j;
    for (i = 0; i < 9; i++) {
        if (i % 3 == 0)
            printf("--------------------\n");
        for (j = 0; j < 9; j++) {
            if (j % 3 == 0)
                printf("|");
            printf("%i ", map[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

void test()
{
    printf("original:\n");
    printoku(test_map);
    solve(test_map);
    printf("solved:\n");
    printoku(test_map);
}

int main(int arc, char *arv[])//will take user input and make a board
{
    test();
    return 0;
}
