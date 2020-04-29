#include <iostream>

using namespace std;

template <class Compare, typename T>
T minimumc(Compare comp, T const a, T const b)
{
    return comp(a, b) > a ? a : b;
}

template <class Compare, typename T1, typename... T>
T1 minimumc(Compare comp, T1 a, T... args)
{
    return minimumc(comp, a, minimumc(comp, args...));
}

int main()
{
    auto y = minimumc(less<>(), 3, 2, 1, 0);

    cout << y << endl;
}
