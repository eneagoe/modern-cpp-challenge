#include <iostream>
#include <unordered_map>

using namespace std;

int main(void)
{
    long long int limit = 1000000;
    long long int i, k, m = 0, current = 0;
    unordered_map<long long int, int> cache;

    cache.insert(make_pair(1, 0));

    for(i = 1; i <= limit; i++) {
        current = 0;
        k = i;

        while(k > 1) {
            if(cache.find(k) != cache.end())
                break;
            current++;
            if(k % 2)
                k = 3 * k + 1;
            else
                k /= 2;
        }

        if(cache.find(k) != cache.end())
            cache.insert(make_pair(i, current + cache[k]));
        else
            cache.insert(make_pair(i, current));
        if(cache[m] < cache[i])
            m = i;
    }

    cout << "MAX = " << m << " " << cache[m] << endl;

    return 0;
}
