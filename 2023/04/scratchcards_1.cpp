#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#define N_WIN 10
#define N_HAV 25

int main() {
    size_t sum = 0;

    std::ifstream file;
    std::string line;
    file.open("input");
    while (getline(file, line)) {
        std::stringstream stream_line(line);
        std::string token;
        getline(stream_line, token, '|');
        std::stringstream stream_winning(token);
        getline(stream_line, token, '|');
        std::stringstream stream_have(token);

        std::vector<int> winning;
        while (getline(stream_winning, token, ' ')) {
            if (!token.empty()) {
                winning.push_back(std::stoi(token));
            }
        }
        std::vector<int> have;
        while (getline(stream_have, token, ' ')) {
            if (!token.empty()) {
                have.push_back(std::stoi(token));
            }
        }

        std::sort(have.begin(), have.end());

        size_t points = 0;
        for (int w : winning) {
            if (std::binary_search(have.begin(), have.end(), w)) {
                if (points == 0) {
                    points = 1;
                } else {
                    points *= 2;
                }
            }
        }
        
        sum += points;
    }

    std::cout << sum << "\n";

    return 0;
}
