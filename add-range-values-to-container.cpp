#include <iostream>
#include <list>
#include <vector>

using namespace std;

template <typename C, typename... Args>
void push_back(C& c, Args&&... args)
{
    (c.push_back(args), ...);
}

int main()
{
    vector<int> v;

    push_back(v, 1, 2, 3, 4);
    copy(begin(v), end(v),
            ostream_iterator<int>(cout, " "));

    list<int> lst;
    push_back(lst, 1, 2, 3, 4);
    copy(begin(lst), end(lst),
            ostream_iterator<int>(cout, " "));
}
