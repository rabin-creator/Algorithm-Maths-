#include<iostream>
#include<math.h>
using namespace std;
#define f(x)  (a3*x*x*x*x + a2*x*x + a1*x + a0)

float a0, a1, a2, a3;

int main()
{
    float x0, x1, x2, Fx0, Fx1, E, ER;  cout<<"Enter the coefficients of a3, a2, a1, a0 and E:"<< endl;
  cin>> a3 >> a2 >> a1 >> a0 >> E;
   cout<<" Please enter initial guess "<< endl;
    cin>>x0>>x1;
    while(1)
    {
        Fx0=F(x0);
        Fx1=F(x1);
         x2=x1-((Fx1)*(x1-x0))/(F(x1)-F(x0));
         ER=(x2-x1)/x2  ;
         if(fabs(ER<E))
         {
            cout<<" x is :"<< x2;
            break;
         }
         x0=x1;
         x1=x2;
    }
return 0;
}