#include <iomanip>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

double truncated_mean(std::vector<int> values, double const percentage)
{
    std::sort(std::begin(values), std::end(values));
    auto remove_count = static_cast<size_t>(values.size() * percentage + 0.5);
    values.erase(std::begin(values), std::begin(values) + remove_count);
    values.erase(std::end(values) - remove_count, std::end(values));
    auto total = std::accumulate(
            std::cbegin(values), std::cend(values),
            0ull,
            [](auto const sum, auto const e) {
                return sum + e;
            });

    return static_cast<double>(total) / values.size();
}

struct movie
{
    int id;
    std::string title;
    std::vector<int> ratings;
};

void print_movie_ratings(std::vector<movie> const & movies)
{
    for (auto const & m : movies)
        std::cout << m.title << " : "
            << std::fixed << std::setprecision(1)
            << truncated_mean(m.ratings, 0.05) << std::endl;
}

using namespace std;

int main(void)
{
    std::vector<movie> movies
    {
        {101, "The Matrix", {10, 9, 10, 9, 9, 8, 7, 10, 5, 9, 9, 8}},
        {102, "Gladiator", {10, 5, 7, 8, 9, 8, 9, 10, 19, 5, 9, 8, 10}},
        {103, "Interstellar", {10, 10, 10, 9, 3, 8, 8, 9, 6, 4, 7, 10}}
    };

    print_movie_ratings(movies);

    return 0;
}
