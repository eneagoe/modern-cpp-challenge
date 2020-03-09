#include <cstring>
#include <iostream>

using namespace std;

unsigned int gray_encode(const unsigned int n)
{
    return n ^ (n << 1);
}

unsigned int gray_decode(unsigned int n)
{
    for(auto i = 1U << 31; i > 1; i >>= 1) {
        if(n & i)
            n ^= i >> 1;
    }

    return n;
}

string to_binary(unsigned int value, const int digits)
{
    return bitset<32>(value).to_string().substr(32 - digits, digits);
}

int main(void)
{
    for (auto i = 0; i < 32; i++) {
        auto encoded = gray_encode(i);
        auto decoded = gray_decode(encoded);

        cout << i << " " <<
            to_binary(i, 5) << " " <<
            to_binary(encoded, 5) << " " <<
            decoded << endl;
    }

    return 0;
}
