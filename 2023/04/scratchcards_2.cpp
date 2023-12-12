#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

#define CARD_NUM 203

int main() {
    std::ifstream file;
    std::string line;
    file.open("input");
    
    std::vector<int> multipliers(CARD_NUM, 1);
    size_t i = 0;
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

        size_t matches = 0;
        for (int w : winning) {
            if (std::binary_search(have.begin(), have.end(), w)) {
                matches++;
            }
        }

        for (size_t j = 1; j <= matches; j++) {
            multipliers[i + j] += multipliers[i];
        }

        i++;
    }

    size_t card_sum = 0;
    for (int m : multipliers) {
        card_sum += m;
    }

    std::cout << card_sum << "\n";

    return 0;
}
