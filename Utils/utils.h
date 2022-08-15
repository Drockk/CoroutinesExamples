#pragma once
#include <string>
#include <iostream>

namespace Utils {
    inline uint32_t parseCommandLineArgument(const std::string& argument) {
        uint32_t temp;

        try {
            std::size_t position;
            temp = std::stoi(argument, &position);
            if (position < argument.size()) {
                std::cerr << "Trailing characters after number: " << argument << '\n';
                return -1;
            }
        } catch ([[maybe_unused]] std::invalid_argument const &ex) {
            std::cerr << "Invalid number: " << argument << '\n';
            return -1;
        } catch ([[maybe_unused]] std::out_of_range const &ex) {
            std::cerr << "Number out of range: " << argument << '\n';
            return -1;
        }

        return temp;
    }
}