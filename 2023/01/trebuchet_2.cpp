#include <bits/stdc++.h>

int read_number(char *s) {
    if (strlen(s) < 3)
        return 0;
    if (strncmp(s, "one", 3) == 0)   return 1;
    if (strncmp(s, "two", 3) == 0)   return 2;
    if (strncmp(s, "three", 5) == 0) return 3;
    if (strncmp(s, "four", 4) == 0)  return 4;
    if (strncmp(s, "five", 4) == 0)  return 5;
    if (strncmp(s, "six", 3) == 0)   return 6;
    if (strncmp(s, "seven", 5) == 0) return 7;
    if (strncmp(s, "eight", 5) == 0) return 8;
    if (strncmp(s, "nine", 4) == 0)  return 9;
    return 0;
}

int main() {
    std::string line;

    size_t sum = 0;

    std::ifstream file;
    file.open("input");
    while (getline(file, line)) {
        char *b = &(line[0]);
        char *e = &(line[line.size() - 1]);
        while (!isdigit(*b) && !read_number(b)) {
            b++;
        }
        while (!isdigit(*e) && !read_number(e)) {
            e--;
        }
        if (isdigit(*b)) {
            sum += 10 * (*b - '0');
        } else {
            sum += 10 * read_number(b);
        }
        if (isdigit(*e)) {
            sum += *e - '0';
        } else {
            sum += read_number(e);
        }
    }

    std::cout << sum << "\n";

    return 0;
}
