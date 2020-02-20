#include <iostream>
#include <numeric>

using namespace std;

long long int gcd1(long long int a, long long int b)
{
    if(b == 0)
        return a;

    return gcd1(b, a % b);
}

long long int gcd2(long long int a, long long int b)
{
    long long tmp;

    if(a < b) {
        tmp = a;
        a = b;
        b = tmp;
    }

    if(b == 0)
        return a;

    return gcd2(b, a - b);
}


int main(void)
{
    long long int a, b;

    cin >> a >> b;

    cout << gcd1(a, b) << endl;
    cout << gcd2(a, b) << endl;
    cout << gcd(a, b) << endl;

    return 0;
}
