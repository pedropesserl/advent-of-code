#include <iostream>
#include <fstream>
#include <cmath>

#define LIN_NUM 140
#define COL_NUM 140

int main() {
    std::ifstream file;
    size_t file_len;
    file.open("input");           // open input file
    std::string s;
    getline(file, s);
    size_t col_num = s.length();

    file.seekg(0, std::ios::end); // go to the end
    file_len = file.tellg();      // report location (this is the length)
    file.seekg(0, std::ios::beg); // go back to the beginning
    char *buffer = (char*)malloc(file_len); // allocate memory for a buffer of appropriate dimension
    file.read(buffer, file_len);    // read the whole file into the buffer
    file.close();



    return 0;
}
