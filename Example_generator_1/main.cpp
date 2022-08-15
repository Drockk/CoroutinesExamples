#include <iostream>

#include "generator.h"
#include "utils.h"

template<typename T>
unique_generator<T> range(const T from, const T to) {
    for(auto start = from; start < to; start++) {
        co_yield start;
    }
}

int main(int argc, char** argv) {
    if(argc == 1) {
        std::cerr << "No Command line arguments passed\n";
        return 1;
    }
    if(argc > 3) {
        std::cerr << "Too many command line arguments passed\n";
        return 1;
    }

    const auto from = Utils::parseCommandLineArgument(argv[1]);
    const auto to = Utils::parseCommandLineArgument(argv[2]);

    for(const auto it: range(from, to)) {
        std::cout << it << "\n";
    }

    return 0;
}