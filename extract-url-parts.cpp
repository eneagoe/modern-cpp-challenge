#include <iostream>
#include <optional>
#include <regex>
#include <string>

using namespace std;

struct uri_parts
{
    std::string protocol;
    std::string domain;
    std::optional<int> port;
    std::optional<std::string> path;
    std::optional<std::string> query;
    std::optional<std::string> fragment;
};

std::optional<uri_parts> parse_uri(std::string uri)
{
    std::regex rx(R"(^(\w+):\/\/([\w.-]+)(:(\d+))?([\w\/\.]+)?(\?([\w=&]*)(#?(\w+))?)?$)");
    auto matches = std::smatch{};
    if (std::regex_match(uri, matches, rx))
    {
        if (matches[1].matched && matches[2].matched)
        {
            uri_parts parts;
            parts.protocol = matches[1].str();
            parts.domain = matches[2].str();
            if (matches[4].matched)
                parts.port = std::stoi(matches[4]);
            if (matches[5].matched)
                parts.path = matches[5];
            if (matches[7].matched)
                parts.query = matches[7];
            if (matches[9].matched)
                parts.fragment = matches[9];

            return parts;
        }
    }

    return {};
}

int main(void)
{
    auto p1 = parse_uri("https://packt.com");
    auto p2 = parse_uri("https://bbc.com:80/en/index.html?lite=true#ui");

    assert(p1.has_value());
    assert(p1->protocol == "https");
    assert(p1->domain == "packt.com");
    assert(!p1->port.has_value());
    assert(!p1->path.has_value());
    assert(!p1->query.has_value());
    assert(!p1->fragment.has_value());

    assert(p2.has_value());
    assert(p2->protocol == "https");
    assert(p2->domain == "bbc.com");
    assert(p2->port == 80);
    assert(p2->path.value() == "/en/index.html");
    assert(p2->query.value() == "lite=true");
    assert(p2->fragment.value() == "ui");

    return 0;
}
