int findOrientation(); // Subtracts our current coordinates from our previous coordinates to find the direction we stepped
int move();            // A function that houses a collection of others to reduce the code in our movement loop
int checkXWest();      // Checks if we are about to head off the grid going West and if a wall exists to the West
int checkXEast();      // Checks if we are about to head off the grid going East and if a wall exists to the East
int checkYNorth();     // Checks if we are about to head off the grid going North and if a wall exists to the North
int checkYSouth();     // Checks if we are about to head off the grid going South and if a wall exists to the South

int enterance(int labyrynth[][cols], int Cols); // find cols position to enterancce of maze
// The "Left Hand Rule" approach is to make your way through the maze
int left_hand(int (*labyrynth)[cols], const int enterance, const int Cols, const int Rows, int mark, int space);
void print_result(); // print result matrix
