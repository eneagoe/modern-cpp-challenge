#include <iostream>

using namespace std;

int main(void)
{
    long long int n;
    int d = 2;

    cin >> n;

    while(d * d <= n) {
        if(n % d == 0) {
            cout << d << " ";
            while(n % d == 0)
                n /= d;
        }
        d += 1;
    }

    if(n != 1)
        cout << n;

    cout << endl;

    return 0;
}
