#include <iostream>

using namespace std;

int main(void)
{
    long long int n;
    long long int sum = 0;

    long long k;

    cin >> n;

    k = n / 3;

    sum += 3 * k * (k + 1) / 2;

    k = n / 5;

    sum += 5 * k * (k + 1) / 2;

    k = n / 15;

    sum -= 15 * k * (k + 1 ) / 2;

    cout << sum << endl;

    return 0;
}
