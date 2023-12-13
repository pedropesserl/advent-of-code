#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <array>
#include <algorithm>

typedef unsigned long long u64;

std::vector<u64> parse_seeds(std::string line) {
    std::vector<u64> seeds;
    std::stringstream stream_line(line);
    std::string token;
    getline(stream_line, token, ':'); // token contains "seeds"
    getline(stream_line, token, ':'); // token contains all of the seed values
    std::stringstream stream_seeds(token);
    while (getline(stream_seeds, token, ' ')) {
        if (!token.empty()) {
            seeds.push_back(std::stoull(token));
        }
    }
    return seeds;
}

std::vector<std::array<u64, 3>> parse_ranges(std::ifstream& file) {
    std::vector<std::array<u64, 3>> ranges;
    std::string line;
    while (getline(file, line) && !line.empty()) {
        std::stringstream stream_line(line);
        std::string token;
        std::array<u64, 3> range;
        while (getline(stream_line, token, ' ') && token.empty());
        range[0] = std::stoull(token);
        while (getline(stream_line, token, ' ') && token.empty());
        range[1] = std::stoull(token);
        while (getline(stream_line, token, ' ') && token.empty());
        range[2] = std::stoull(token);
        ranges.push_back(range);
    }
    return ranges;
}

std::vector<u64> apply_ranges(std::vector<u64> values,
                              std::vector<std::array<u64, 3>> ranges) {
    std::vector<u64> new_values = values;
    for (size_t i = 0; i < values.size(); i++) {
        for (std::array<u64, 3> range : ranges) {
            if (range[1] <= values[i] && values[i] < range[1] + range[2]) {
                new_values[i] = range[0] + (values[i] - range[1]);
                break;
            }
        }
    }
    return new_values;
}

int main() {
    std::ifstream file;
    std::string line;
    file.open("input");
    getline(file, line); // seeds
    std::vector<u64> values = parse_seeds(line);

    getline(file, line); // blank line
    while (getline(file, line)) { // read map header
        std::vector<std::array<u64, 3>> ranges = parse_ranges(file);
        values = apply_ranges(values, ranges);
    }

    std::cout << *std::min_element(values.begin(), values.end()) << "\n";

    return 0;
}
