#include <iostream>
#include <cmath>

using namespace std;

double a0, a1, a2, a3;

double f(double x)
{
    return a3 * x * x * x * x + a2 * x * x + a1 * x + a0;
}

int main()
{
    double x0, x1, x2, Fx0, Fx1, E, ER;
    const int maxIter = 1000;

    cout << "Enter coefficients a3 a2 a1 a0 and tolerance E: ";
    if (!(cin >> a3 >> a2 >> a1 >> a0 >> E)) {
        cerr << "Invalid input. Exiting.\n";
        return 1;
    }

    cout << "Please enter initial guesses x0 and x1: ";
    if (!(cin >> x0 >> x1)) {
        cerr << "Invalid input. Exiting.\n";
        return 1;
    }

    for (int iter = 1; iter <= maxIter; ++iter) {
        Fx0 = f(x0);
        Fx1 = f(x1);

        double denom = (Fx1 - Fx0);
        if (denom == 0.0) {
            cerr << "Zero denominator encountered in secant formula.\n";
            return 1;
        }

        x2 = x1 - Fx1 * (x1 - x0) / denom;

        if (x2 != 0.0)
            ER = fabs((x2 - x1) / x2);
        else
            ER = fabs(x2 - x1);

        if (ER < E) {
            cout.setf(ios::fixed);
            cout.precision(10);
            cout << "Root (x) = " << x2 << " after " << iter << " iterations\n";
            return 0;
        }

        x0 = x1;
        x1 = x2;
    }

    cerr << "Method did not converge within " << maxIter << " iterations\n";
    return 1;
}
