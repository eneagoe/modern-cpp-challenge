#include <fstream>
#include <ios>
#include <iostream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::filesystem;

void remove_emtpy_lines(fs::path filepath)
{
    std::ifstream filein(filepath.native(), std::ios::in);
    if (!filein.is_open())
        throw std::runtime_error("cannot open input file");

    auto temppath = fs::temp_directory_path() / "temp.txt";
    std::ofstream fileout(temppath.native());

    if (!fileout.is_open())
        throw std::runtime_error("cannot create temporary file");

    std::string line;
    while (std::getline(filein, line))
        if (line.length() > 0 && line.find_first_not_of(' ') != line.npos)
            fileout << line << '\n';

    filein.close();
    fileout.close();

    fs::remove(filepath);
    fs::rename(temppath, filepath);
}

using namespace std;

int main(void)
{
    string path;

    cin >> path;

    remove_emtpy_lines(path);

    return 0;
}
