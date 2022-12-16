#include <stdio.h>
#include <math.h>
#include <ctype.h>
const double pi = 3.14159265359;
int main()
{  
    while(1) {
        
        double a,z1,z2,input;
        printf("Please enter number a: ");
        //scanf("%lf", &a);

            if(scanf("%lf", &a) == 1) //check if entered in terminal symbols is not word 
            {

            z1=cos(a)+sin(a)+cos(3*a)+sin(3*a); //determine and print z1 and z2
            z2=2*(sqrt(2))*cos(a)*sin((pi/4)+2*a);
            printf("result:\n\r z1=%lf \n\r z2=%lf \n\r",z1,z2);
                
            }
            else 
            {
            printf("please write numeric character!\n\r"); // if written not digit print warning
            return 0;
            }
        }
}
