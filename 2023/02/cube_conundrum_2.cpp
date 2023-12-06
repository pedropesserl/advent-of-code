#include <iostream>
#include <stdlib.h>
#include <string.h>

int main() {
    size_t sum = 0;

    FILE *file = fopen("input", "r");
    char *line = (char*)calloc(1024, sizeof(char));
    while (fgets(line, 1024, file)) {
        char *saveptr1, *saveptr2, *saveptr3;

        char *token = strtok_r(line, ":", &saveptr1);

        int rgb[3] = {0, 0, 0};

        char *round_str;
        while ((round_str = strtok_r(NULL, ";", &saveptr1)) != NULL) {
            char *number_color = strtok_r(round_str, ",", &saveptr2);
            do {
                char *number = strtok_r(number_color, " ", &saveptr3);
                char *color = strtok_r(NULL, " ", &saveptr3);
                if (strncmp(color, "red", 3) == 0) {
                    if (std::stoi(number) > rgb[0]) {
                        rgb[0] = std::stoi(number);
                    }
                } else if (strncmp(color, "green", 5) == 0) {
                    if (std::stoi(number) > rgb[1]) {
                        rgb[1] = std::stoi(number);
                    }
                } else if (strncmp(color, "blue", 4) == 0) {
                    if (std::stoi(number) > rgb[2]) {
                        rgb[2] = std::stoi(number);
                    }
                } else {
                    fprintf(stderr, "AAAAAAAAAAAAAAAAA\n");
                    exit(1);
                }
            } while ((number_color = strtok_r(NULL, ",", &saveptr2)) != NULL);
        }
        
        sum += rgb[0] * rgb[1] * rgb[2];
    }

    std::cout << sum << "\n";

    free(line);
    return 0;
}
