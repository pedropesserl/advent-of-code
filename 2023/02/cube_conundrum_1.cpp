#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAXRED 12
#define MAXGREEN 13
#define MAXBLUE 14

int main() {
    size_t sum = 0;

    FILE *file = fopen("input", "r");
    char *line = (char*)calloc(1024, sizeof(char));
    while (fgets(line, 1024, file)) {
        char *saveptr1, *saveptr2, *saveptr3;

        char *game_id_str = strtok_r(line, " ", &saveptr1);
        game_id_str = strtok_r(NULL, ":", &saveptr1);
        size_t game_id = std::stoi(game_id_str);

        char *round_str;
        int impossible = 0;
        while (!impossible && (round_str = strtok_r(NULL, ";", &saveptr1)) != NULL) {
            char *number_color = strtok_r(round_str, ",", &saveptr2);
            do {
                char *number = strtok_r(number_color, " ", &saveptr3);
                char *color = strtok_r(NULL, " ", &saveptr3);
                if (strncmp(color, "red", 3) == 0) {
                    if (std::stoi(number) > MAXRED) {
                        impossible = 1;
                        break;
                    }
                } else if (strncmp(color, "green", 5) == 0) {
                    if (std::stoi(number) > MAXGREEN) {
                        impossible = 1;
                        break;
                    }
                } else if (strncmp(color, "blue", 4) == 0) {
                    if (std::stoi(number) > MAXBLUE) {
                        impossible = 1;
                        break;
                    }
                } else {
                    fprintf(stderr, "AAAAAAAAAAAAAAAAA\n");
                    exit(1);
                }
            } while ((number_color = strtok_r(NULL, ",", &saveptr2)) != NULL);
        }

        if (!impossible) {
            sum += game_id;
        }
    }

    std::cout << sum << "\n";

    free(line);
    return 0;
}
