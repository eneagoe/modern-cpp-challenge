#include <iostream>

using namespace std;

bool prime(long long int n)
{
    if(n <= 3)
        return n != 1;

    if((n % 2 == 0) || (n % 3 == 0))
        return false;

    for(auto i = 5; i * i <= n; i += 6)
        if ((n % i == 0) || (n % (i + 2) == 0))
            return false;

    return true;
}

int main(void)
{
    long long int n;

    cin >> n;

    if(n % 2 == 0 && n > 2)
        n--;

    while(!prime(n) && n > 0)
        n -= 2;

    cout << n << endl;

    return 0;
}