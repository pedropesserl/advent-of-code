#include <iostream>
#include <fstream>
#include <cmath>

#define LIN_NUM 140
// accounting for \n
#define COL_NUM 141

size_t process_number(char *buffer, size_t pos) {
    while (isdigit(buffer[pos - 1])) {
        pos--; // get to the first digit of the number
    }
    size_t number = 0;
    while (isdigit(buffer[pos])) {
        number = 10*number + buffer[pos] - '0';
        buffer[pos] = '.'; // make sure we don't count numbers twice
        pos++;
    }
    return number;
}

size_t find_neighbor_numbers(char *buffer, size_t pos) {
    size_t partial_sum = 0;
    for (int k = -1; k <= 1; k++) {
        for (int l = -1; l <= 1; l++) {
            if (isdigit(buffer[pos + k*COL_NUM + l])) {
                partial_sum += process_number(buffer, pos + k*COL_NUM + l);
            }
        }
    }
    return partial_sum;
}

int main() {
    std::ifstream file;
    file.open("input"); // open input file
    std::string s;
    getline(file, s);

    file.seekg(0, std::ios::end);   // go to the end
    size_t file_len = file.tellg(); // report location (this is the length)
    file.seekg(0, std::ios::beg);   // go back to the beginning
    char *buffer = (char*)malloc(file_len); // allocate memory for a buffer of appropriate dimension
    file.read(buffer, file_len);    // read the whole file into the buffer
    file.close();

    size_t sum = 0;

    for (size_t i = 0; i < LIN_NUM; i++) {
        for (size_t j = 0; j < COL_NUM; j++) {
            char c = buffer[i*COL_NUM + j];
            if (c != '.' && c != '\n' && !isdigit(c)) {
                // is a symbol: iterate through neighbors
                sum += find_neighbor_numbers(buffer, i*COL_NUM + j);
            }
        }
    }

    std::cout << sum << "\n"; 

    return 0;
}
