#include <array>
#include <iostream>
#include <stack>
#include <vector>

template <class RandomIt>
RandomIt partition(RandomIt first, RandomIt last)
{
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;

    while (i <= j) {
        while (i <= j && *i <= pivot)
            i++;
        while (i <= j && *j > pivot)
            j--;
        if (i < j)
            std::iter_swap(i, j);
    }

    std::iter_swap(i - 1, first);

    return i - 1;
}

template <class RandomIt, class Compare>
RandomIt partitionc(RandomIt first, RandomIt last, Compare comp)
{
    auto pivot = *first;
    auto i = first + 1;
    auto j = last - 1;

    while (i <= j) {
        while (i <= j && comp(*i, pivot))
            i++;
        while (i <= j && !comp(*j, pivot))
            j--;
        if (i < j)
            std::iter_swap(i, j);
    }

    std::iter_swap(i - 1, first);

    return i - 1;
}

template <class RandomIt>
void quicksort(RandomIt first, RandomIt last)
{
    if (first < last) {
        auto p = partition(first, last);
        quicksort(first, p);
        quicksort(p + 1, last);
    }
}

template <class RandomIt, class Compare>
void quicksortc(RandomIt first, RandomIt last, Compare comp)
{
    if (first < last) {
        auto p = partitionc(first, last, comp);
        quicksortc(first, p, comp);
        quicksortc(p + 1, last, comp);
    }
}

template <class RandomIt>
void quicksortIterative(RandomIt first, RandomIt last)
{
    std::stack<std::pair<RandomIt, RandomIt>> st;
    st.push(std::make_pair(first, last));
    while (!st.empty()) {
        auto iters = st.top();
        st.pop();

        if (iters.second - iters.first < 2)
            continue;

        auto p = partition(iters.first, iters.second);

        st.push(std::make_pair(iters.first, p));
        st.push(std::make_pair(p + 1, iters.second));
    }
}

using namespace std;

int main(void)
{
    std::vector<int> v{1, 5, 3, 8, 6, 2, 9, 7, 4};
    quicksort(std::begin(v), std::end(v));

    for(auto x: v)
        cout << x << " ";
    cout << endl;

    std::array<int, 9> a{1, 2, 3, 4, 5, 6, 7, 8, 9};
    quicksort(std::begin(a), std::end(a));

    for(auto x: v)
        cout << x << " ";
    cout << endl;

    int b[]{9, 8, 7, 6, 5, 4, 3, 2, 1};
    quicksort(std::begin(b), std::end(b));

    for(auto x: b)
        cout << x << " ";
    cout << endl;

    std::vector<int> v2{1, 5, 3, 8, 6, 2, 9, 7, 4};
    quicksortc(std::begin(v2), std::end(v2), std::greater<>());

    for(auto x: v2)
        cout << x << " ";
    cout << endl;

    std::vector<int> v3{1, 5, 3, 8, 6, 2, 9, 7, 4};
    quicksortIterative(std::begin(v3), std::end(v3));

    for(auto x: v3)
        cout << x << " ";
    cout << endl;

    return 0;
}
