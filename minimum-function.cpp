#include <iostream>

using namespace std;

template <typename T>
T minimum(T const a, T const b) { return a < b ? a : b; }

template <typename T1, typename... T>
T1 minimum(T1 a, T... args)
{
    return minimum(a, minimum(args...));
}

int main()
{
    auto x = minimum(5, 4, 2, 3);

    cout << x << endl;
}
