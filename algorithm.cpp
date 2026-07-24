#include <stdio.h>
#include <math.h>

#define f(x)  (a3*x*x*x*x + a2*x*x + a1*x + a0)
#define fd(x) (4*a3*x*x*x + 2*a2*x + a1)

float a0, a1, a2, a3;

int main()
{
    float x0, x1, fx0, fdx0, E, ER;
    int i;

    printf("Enter the coefficients of a3, a2, a1, a0:\n");
    scanf("%f%f%f%f", &a3, &a2, &a1, &a0);

    printf("Enter initial guess and error tolerance E:\n");
    scanf("%f%f", &x0, &E);

    for (i = 0; i < 50; i++)
    {
        fx0 = f(x0);
        fdx0 = fd(x0);

        /* Check if derivative is zero */
        if (fdx0 == 0.0f)
        {
            printf("Derivative is zero. Stopping.\n");
            break;
        }

        /* Newton-Raphson formula */
        x1 = x0 - (fx0 / fdx0);

        /* Calculate relative error */
        if (x1 != 0.0f)
            ER = fabs((x1 - x0) / x1);
        else
            ER = fabs(x1 - x0);

        /* Check convergence */
        if (ER < E)
        {
            printf("Root = %f\n", x1);
            break;
        }

        x0 = x1;
    }

    if (i == 50)
        printf("Did not converge within 50 iterations.\n");

    return 0;
}