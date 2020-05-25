#include <fstream>
#include <iostream>
#include <string>
#include <experimental/filesystem>

namespace fs = std::filesystem;

class logger
{
    fs::path logpath;
    std::ofstream logfile;
public:
    logger() {
        auto name = "AAAA.tmp"; // this should be a unique, random salt
        logpath = fs::temp_directory_path() / (name);
        logfile.open(logpath.c_str(), std::ios::out|std::ios::trunc);
    }

    ~logger() noexcept {
        try {
            if (logfile.is_open())
                logfile.close();
            if (!logpath.empty())
                fs::remove(logpath);
        } catch (...) {}
    }

    void persist(fs::path const & path) {
        logfile.close();
        fs::rename(logpath, path);
        logpath.clear();
    }

    logger& operator<<(std::string_view message) {
        logfile << message.data() << '\n';

        return *this;
    }
};

using namespace std;

int main(void)
{
    logger log;

    try {
        log << "this is a line" << "and this is another one";
        throw std::runtime_error("error");
    } catch (...) {
        log.persist(R"(lastlog.txt)");
    }

    return 0;
}
