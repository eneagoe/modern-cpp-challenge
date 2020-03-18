#include <cmath>
#include <iomanip>
#include <iostream>

using namespace std;

int main(void)
{
    double p16 = 1, pi = 0, precision = 1000;

    for(int k = 0; k <= precision; k++) {
        pi += 1.0 / p16 * (4.0 / (8 * k + 1) - 2.0 / (8 * k + 4) - 1.0 / (8 * k + 5) - 1.0  /(8 * k + 6));
        p16 *= 16;
    }

    cout << setprecision(20) << pi << endl;

    return 0;
}
