#include <iostream>

using namespace std;

long long int sum_proper_divisors(long long int n)
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
    int n = 1000000;
    long long int s = 0;

    // does not eliminate duplicates - (a, b) and (b, a) are both considered
    for(auto i = 2; i <= n; i++) {
        s = sum_proper_divisors(i);
        if(sum_proper_divisors(s) == i && s != i)
            cout << i << " " << s << endl;
    }

    return 0;
}
