#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

template <typename Iter>
std::string join_strings(Iter begin, Iter end, char const * const separator)
{
    std::ostringstream os;
    std::copy(begin, end - 1, std::ostream_iterator<std::string>(os, separator));
    os << *(end - 1);

    return os.str();
}

template <typename C>
std::string join_strings(C const & c, char const * const separator)
{
    if (c.size() == 0)
        return std::string{};

    return join_strings(std::begin(c), std::end(c), separator);
}

int main(void)
{
    using namespace string_literals;

    std::vector<std::string> v1{"this", "is", "an", "example"};
    std::vector<std::string> v2{"example"};
    std::vector<std::string> v3{ };

    assert(join_strings(v1, " ") == "this is an example"s);
    assert(join_strings(v2, " ") == "example"s);
    assert(join_strings(v3, " ") == ""s);

    return 0;
}

