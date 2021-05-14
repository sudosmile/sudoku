#include "main.h"

static coord find_empty_cell(map local)
{
    coord out;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (local[i][j] == 0) {
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

static int is_move_valid(map local, coord pos, int num) //checks if move valid
{
    int i, j, box_x, box_y;

    for (i = 0; i < 9; i++) {
        if (local[pos.x][i] == num && pos.y != i)
            return false;
    }
    for (i = 0; i < 9; i++) {
        if (local[i][pos.y] == num && pos.y != i)
            return false;
    }
    box_x = pos.x/3;
    box_y = pos.y/3;
    for (i = (box_y*3); i < (box_x * 3 + 3); i++) {
        for (j = (box_x*3); j < (box_y * 3 + 3); j++) {
            if (local[i][j] == num && (i != pos.x || j != pos.y))
                return false;
        }
    }
    return true;
}

static int solve_all(map local)
{
    int i;
    coord found = find_empty_cell(local);

    if (!(found.none != 1))
        return ERROR;
    for (i = 1; i < 10; i++) {
        if (is_move_valid(local, found, i)) {
            local[found.x][found.y] = i;
            if (solve_all(local))
                return ERROR;
            local[found.x][found.y] = 0;
        }
    }
    return SUCCESS;
}

static void printoku(map local)
{
    int i, j;

    for (i = 0; i < 9; i++) {
        if (i % 3 == 0)
            printf("----------------------\n");
        for (j = 0; j < 9; j++) {
            if (j % 3 == 0)
                printf("|");
            printf("%i ", local[i][j]);
            if (j == 8)
                printf("|");
        }
        printf("\n");
    }
    printf("----------------------\n");
    printf("\n");
}

static void test()
{
    map test_map = {
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
    printf("original:\n");
    printoku(test_map);
    solve_all(test_map);
    printf("solved:\n");
    printoku(test_map);
}

int main()
{
    test();
    return SUCCESS;
}
