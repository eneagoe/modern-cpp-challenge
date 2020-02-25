#include <iostream>
#include <numeric>

using namespace std;

long long int gcd(long long int a, long long int b)
{
    if(b == 0)
        return a;

    return gcd(b, a % b);
}


int main(void)
{
    long long int a, n;
    long long lcm = 1;

    cin >> n;

    while(n--) {
        cin >> a;
        lcm = lcm * a / gcd(lcm, a);
    }

    cout << lcm << endl;

    return 0;
}
