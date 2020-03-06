#include <iostream>

using namespace std;

bool armstrong(int n)
{
    int a, b, c;

    a = n / 100;
    b = (n / 10) % 10;
    c = n % 10;

    return n == (a * a * a + b * b * b + c * c * c);
}

int main(void)
{
    for(auto i = 100; i < 1000; i++)
        if(armstrong(i))
            cout << i << endl;

    // this is supposed to be faster, since division and modulo are very
    // expensive operations compared to multiplication and addition
    // however, in this particular case, the search space is so small, there's
    // practically no difference in execution times
    /* for(auto a = 1; a <= 9; a++) */
    /*     for(auto b = 0; b <= 9; b++) */
    /*         for(auto c = 0; c <= 9; c++) { */
    /*             auto n = a * 100 + b * 10 + c; */
    /*             auto sn = a * a * a + b * b * b + c * c * c; */
    /*             if(n == sn) */
    /*                 cout << a << b << c << endl; */
    /*         } */

    return 0;
}
