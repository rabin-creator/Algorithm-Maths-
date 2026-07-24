/* start 
Define f(x)
Define derivative fd(x)
I/p coefficient a3,a2,a1,a0,f(x)
I/p initial guess (x0) and error (E)
initialize i=0
calculate x1=x0-(f(x0))/fd(X0)
ER = (x1-x0)/x1
if (ER < E)
print  x1
else 
               X0 = x1
               i=i+1
*/
#include<stdio.h>
#include<Math.h>
#include<conio.h>
#define F(x)(a3 * x * x * x+a2 * x * x+a1 * x+a0 );
#define Fd(x)(3*a3*x*x+2*a2*x+a1);
    float a3,a2,a1,a0;
    int main()
    {
        float x0,x1,x2,E,ER,fx0,fdx0;
        printf(" Enter the coefficients of the polynomial (a3 a2 a1 a0): ");
        scanf("%f %f %f %f",&a3,&a2,&a1,&a0);
        printf(" Enter the initial guess (x0):/n and Enter the error (E): ");
        scanf("%f %f",&x0,&E);
        int i=1;// counts at least one iteration
        While(i==1)
        {
            fx0=F(x0);
            fdx0=Fd(x0);
            x1=x0-(fx0/fdx0);
            ER=(x1-x0)/x1;
            if(ER<E)
            {
                printf("The root is: %f",x1);
                break;
            }
            else
            {
                x0=x1;
                i=i+1;
                if(i==50)
                {
                    printf("The method did not converge within 50 iterations.");
                    break;
                }
            }
            getch();
            }
        }
    }









    