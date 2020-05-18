#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

bool validate_license_plate_format(std::string_view str)
{
    std::regex rx(R"([A-Z]{3}-[A-Z]{2} \d{3,4})");

    return std::regex_match(str.data(), rx);
}

int main(void)
{
    assert(validate_license_plate_format("ABC-DE 123"));
    assert(validate_license_plate_format("ABC-DE 1234"));
    assert(!validate_license_plate_format("ABC-DE 12345"));
    assert(!validate_license_plate_format("abc-de 1234"));

    return 0;
}
