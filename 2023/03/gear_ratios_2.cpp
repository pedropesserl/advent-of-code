#include <iostream>
#include <fstream>
#include <cmath>

#define LIN_NUM 140
// accounting for \n
#define COL_NUM 141

size_t process_number(char *buffer, size_t pos, size_t *new_pos) {
    while (isdigit(buffer[pos - 1])) {
        pos--; // get to the first digit of the number
    }
    size_t number = 0;
    while (isdigit(buffer[pos])) {
        number = 10*number + buffer[pos] - '0';
        pos++;
    }
    *new_pos = pos - 1; // new_pos is the position of the last digit found
    return number;
}

size_t find_neighbor_numbers(char *buffer, size_t pos) {
    size_t gear_ratio = 1;
    int numbers_found = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (isdigit(buffer[pos + i*COL_NUM + j])) {
                numbers_found++;
                if (numbers_found > 2) {
                    return 0;
                }
                size_t new_pos = 0;
                gear_ratio *= process_number(buffer, pos + i*COL_NUM + j, &new_pos);
                if (new_pos == pos + i*COL_NUM + j) { // if finished at the same position
                    j++; // next position is guaranteed to not have a number
                } else {
                    break; // there can't be another number in the same line
                }
            }
        }
    }
    if (numbers_found < 2) {
        return 0;
    }
    return gear_ratio;
}

int main() {
    std::ifstream file;
    file.open("input"); // open input file
    file.seekg(0, std::ios::end);   // go to the end
    size_t file_len = file.tellg(); // report location (this is the length)
    file.seekg(0, std::ios::beg);   // go back to the beginning
    char *buffer = (char*)malloc(file_len); // allocate memory for a buffer
    file.read(buffer, file_len);    // read the whole file into the buffer
    file.close();

    size_t sum = 0;

    for (size_t i = 0; i < LIN_NUM; i++) {
        for (size_t j = 0; j < COL_NUM; j++) {
            char c = buffer[i*COL_NUM + j];
            if (c == '*') {
                // is a star: iterate through neighbors
                sum += find_neighbor_numbers(buffer, i*COL_NUM + j);
            }
        }
    }

    std::cout << sum << "\n"; 

    return 0;
}
