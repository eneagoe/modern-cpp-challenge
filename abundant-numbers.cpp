#include <iostream>

using namespace std;

long long int sum_proper_divisors(int n)
{
    long long int s = 1, i = 2;

    if(n == 1)
        return 0;
    else if(n <= 3)
        return 1;

    while(i * i <= n) {
        if(n % i == 0) {
            s += i;
            if(n / i != i)
                s += n / i;
        }

        i++;
    }

    return s;
}

int main(void)
{
    int n, i = 1;
    long long int s = 0;

    cin >> n;

    while (i <= n) {
        s = sum_proper_divisors(i);
        if(s > i)
            cout << i << " " << s - i << endl;
        i++;
    }

    return 0;
}

