#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "maze_LH.h"

int curr_x; // Our current X coordinate while traversing the maze
int curr_y; // Our current Y coordinate while taversing the maze
int WAY = 1;
int maze_out[rows][cols]; // massive where writen the exit way
int step_symbol = 142;    // step symbol
int direction = 0;        // If 1 North. If 2 South. If 3 East. If 4 West
int prew_x = 0;           // Our previous X coordinate while traversing the maze
int prew_y = 0;           // Our Previous Y coordinate while traversing the maze
int orientX = 0;          // If this value is -1 we stepped East (left). If this value is 1, we stepped West (right)
int orientY = 0;          // If this value is -1, we stepped North (up). If this value is 1, we stepped South (down)
int enterance(int labyrynth[][cols], int Cols) // find cols position to enterancce of labyrynth
    
{
    int input_cols = -1;
    int a;
    for (a = 0; a < cols; a++)
    {
        if (labyrynth[0][a] == WAY)
        {
            labyrynth[0][a] = 0; // close exit
            input_cols = a;
            break;
        }
    }
    if (input_cols == (-1)) // if not find enterence stop program
    {
        printf("enterence in labyrynth not find!\n\r");
        exit(0);
    }
    return (input_cols);
}

int left_hand(int maze[][cols], const int enterance, const int Cols, const int Rows, int mark, int space)
{
    WAY = mark;
    step_symbol = space;
    memset(maze_out, 254, sizeof maze_out); // infill output massive ASCII value of character ■ = 254
    maze_out[0][enterance] = step_symbol;   // paste first step;

    curr_x = enterance;
    curr_y = 1;

    while (curr_y < Cols)
    {
        move();
    }
    print_result();
}

void print_result()
{

    int row, column = 0;
    for (row = 0; row < rows; row++)
    {
        for (column = 0; column < cols; column++)
        {
            printf("%c ", maze_out[row][column]);
        }
        printf("\n");
    }

    getchar();
}

int findOrientation()
{
    orientX = curr_x - prew_x; // If orientX is 1, we stepped left. Else, right
    orientY = curr_y - prew_y; // If orientX is 1, we stepped up. Else, down

    return 1;
}

int updateDirection()
{
    // find directions
    if (orientY == -1 && orientX == 0) // North
    {
        direction = 1;
    }

    else if (orientY == 1 && orientX == 0) // South
    {
        direction = 2;
    }

    else if (orientX == 1 && orientY == 0) // East
    {
        direction = 3;
    }

    else // West
    {
        direction = 4;
    }
}

int move()
{
    findOrientation();
    updateDirection();
    // update Previous Coordinates
    prew_x = curr_x;
    prew_y = curr_y;

    if (direction == 1) // 1 we face North
    {
        if (curr_x + 1 >= cols || maze_in[curr_y][curr_x + 1] == WAY) // So we check if we can go right, and return 0 if we can't
        {
            ++curr_x; // If we can go right, we step right
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_y - 1 < 0 || maze_in[curr_y - 1][curr_x] == WAY) // If we can't go right, we go up
        {
            --curr_y; // Decrementing our Y coordinate means we step up
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_x - 1 < 0 || maze_in[curr_y][curr_x - 1] == WAY) // If not up either, we try to go left
        {
            --curr_x; // Decrementing our X coordinate mimics going left
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_y + 1 >= rows || maze_in[curr_y + 1][curr_x] == WAY) // If we can't go any of the other directions, we must step down
        {
            ++curr_y; // incrementing our Y coordinate mimics heading down
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }
    }

    else if (direction == 2) // 2 we face south, and check our proper directions in order
    {
        if (curr_x - 1 < 0 || maze_in[curr_y][curr_x - 1] == WAY)
        {
            --curr_x;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_y + 1 >= rows || maze_in[curr_y + 1][curr_x] == WAY)
        {
            ++curr_y;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_x + 1 >= cols || maze_in[curr_y][curr_x + 1] == WAY)
        {
            ++curr_x;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_y - 1 < 0 || maze_in[curr_y - 1][curr_x] == WAY)
        {
            --curr_y;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }
    }

    else if (direction == 3) // 3 we face East, and check the correct directions in order
    {
        if (curr_y + 1 >= rows || maze_in[curr_y + 1][curr_x] == WAY)
        {
            ++curr_y;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_x + 1 >= cols || maze_in[curr_y][curr_x + 1] == WAY)
        {
            ++curr_x;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_y - 1 < 0 || maze_in[curr_y - 1][curr_x] == WAY)
        {
            --curr_y;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_x - 1 < 0 || maze_in[curr_y][curr_x - 1] == WAY)
        {
            --curr_x;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }
    }

    else if (direction == 4) // 4 we face West and check the correct directions in order
    {
        if (curr_y - 1 < 0 || maze_in[curr_y - 1][curr_x] == WAY)
        {

            --curr_y;
            maze_out[curr_y][curr_x] = 87;

            return 1;
        }

        if (curr_x - 1 < 0 || maze_in[curr_y][curr_x - 1] == WAY)
        {

            --curr_x;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_y + 1 >= rows || maze_in[curr_y + 1][curr_x] == WAY)
        {

            ++curr_y;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }

        if (curr_x + 1 >= cols || maze_in[curr_y][curr_x + 1] == WAY)
        {

            ++curr_x;
            maze_out[curr_y][curr_x] = step_symbol;
            return 1;
        }
    }
}
