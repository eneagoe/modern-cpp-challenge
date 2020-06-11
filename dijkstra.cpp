#include <iostream>
#include <map>
#include <set>
#include <vector>

template <typename Vertex = int, typename Weight = double>
class graph
{
public:
    typedef Vertex vertex_type;
    typedef Weight weight_type;
    typedef std::pair<Vertex, Weight> neighbour_type;
    typedef std::vector<neighbour_type> neighbour_list_type;
public:
    void add_edge(Vertex const source, Vertex const target, Weight const weight, bool const bidirectional = true)
    {
        adjacency_list[source].push_back(std::make_pair(target, weight));
        adjacency_list[target].push_back(std::make_pair(source, weight));
    }

    size_t vertex_count() const { return adjacency_list.size(); }
    std::vector<Vertex> verteces() const
    {
        std::vector<Vertex> keys;
        for (auto const & kvp : adjacency_list)
            keys.push_back(kvp.first);

        return keys;
    }

    neighbour_list_type const & neighbours(Vertex const & v) const
    {
        auto pos = adjacency_list.find(v);
        if (pos == adjacency_list.end())
            throw std::runtime_error("vertex not found");

        return pos->second;
    }

    constexpr static Weight Infinity = std::numeric_limits<Weight>::infinity();

private:
    std::map<vertex_type, neighbour_list_type> adjacency_list;
};

template <typename Vertex, typename Weight>
void shortest_path(
        graph<Vertex, Weight> const & g,
        Vertex const source,
        std::map<Vertex, Weight>& min_distance,
        std::map<Vertex, Vertex>& previous)
{
    auto const n = g.vertex_count();
    auto const verteces = g.verteces();

    min_distance.clear();

    for (auto const & v : verteces)
        min_distance[v] = graph<Vertex, Weight>::Infinity;
    min_distance[source] = 0;

    previous.clear();

    std::set<std::pair<Weight, Vertex>> vertex_queue;
    vertex_queue.insert(std::make_pair(min_distance[source], source));

    while (!vertex_queue.empty()) {
        auto dist = vertex_queue.begin()->first;
        auto u = vertex_queue.begin()->second;

        vertex_queue.erase(std::begin(vertex_queue));

        auto const & neighbours = g.neighbours(u);
        for (auto const & neighbour : neighbours) {
            auto v = neighbour.first;
            auto w = neighbour.second;
            auto dist_via_u = dist + w;

            if (dist_via_u < min_distance[v]) {
                vertex_queue.erase(std::make_pair(min_distance[v], v));

                min_distance[v] = dist_via_u;
                previous[v] = u;
                vertex_queue.insert(std::make_pair(min_distance[v], v));
            }
        }
    }
}

template <typename Vertex>
void build_path(
        std::map<Vertex, Vertex> const & prev, Vertex const v,
        std::vector<Vertex> & result)
{
    result.push_back(v);
    auto pos = prev.find(v);
    if (pos == std::end(prev))
        return;

    build_path(prev, pos->second, result);
}

template <typename Vertex>
std::vector<Vertex> build_path(std::map<Vertex, Vertex> const & prev, Vertex const v)
{
    std::vector<Vertex> result;
    build_path(prev, v, result);
    std::reverse(std::begin(result), std::end(result));

    return result;
}

template <typename Vertex>
void print_path(std::vector<Vertex> const & path)
{
    for (size_t i = 0; i < path.size(); ++i) {
        std::cout << path[i];
        if (i < path.size() - 1)
            std::cout << " -> ";
    }
}

using namespace std;

int main(void)
{
    graph<char, double> g;
    g.add_edge('A', 'B', 7);
    g.add_edge('A', 'C', 9);
    g.add_edge('A', 'F', 14);
    g.add_edge('B', 'C', 10);
    g.add_edge('B', 'D', 15);
    g.add_edge('C', 'D', 11);
    g.add_edge('C', 'F', 2);
    g.add_edge('D', 'E', 6);
    g.add_edge('E', 'F', 9);

    char source = 'A';
    std::map<char, double> min_distance;
    std::map<char, char> previous;
    shortest_path(g, source, min_distance, previous);

    for (auto const & kvp : min_distance) {
        std::cout << source << " -> " << kvp.first << " : " << kvp.second << '\t';

        print_path(build_path(previous, kvp.first));

        std::cout << std::endl;
    }

    return 0;
}
