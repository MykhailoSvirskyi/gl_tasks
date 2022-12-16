#include <stdio.h>
#include <math.h>
const double pi = 3.14159265359;
int main()
{  
    while(1) {
        
        double a,z1,z2,input;
            printf("Please enter number a: ");
            scanf("%lf", &a);
           
            z1=cos(a)+sin(a)+cos(3*a)+sin(3*a);
            z2=2*(sqrt(2))*cos(a)*sin((pi/4)+2*a);
            printf("result:\n\r z1=%lf \n\r z2=%lf \n\r",z1,z2);
                //return 0;
            }
}
