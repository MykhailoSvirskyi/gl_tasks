// created by Mykhailo Svirskyi 26.12.22

//int COLS = 11;
//int ROWS = 11;

#define cols 11
#define rows 11

int maze_in[11][11] = {
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0},
    {0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 0},
    {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
    {0, 1, 1, 1, 0, 1, 1, 1, 0, 1, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0}};
#include "maze_LH.c"
int main()
{
    int ent = enterance(maze_in, cols);
    left_hand(maze_in, ent, cols, rows, 1, 255);

    return 0;
}
