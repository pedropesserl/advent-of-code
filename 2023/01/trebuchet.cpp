#include <bits/stdc++.h>

int main() {
    std::string line;
    char value[2];
    size_t sum = 0;

    std::ifstream file;
    file.open("input");
    while (getline(file, line)) {
        char *b = &(line[0]);
        char *e = &(line[line.size() - 1]);
        while (!isdigit(*b))
            b++;
        while (!isdigit(*e))
            e--;
        value[0] = *b;
        value[1] = *e;
        sum += std::stoi(value);
    }

    std::cout << sum << "\n";

    return 0;
}
