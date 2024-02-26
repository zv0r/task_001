#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SMAX 16

void achtung();
int calc_letters(const char *num_str);

int main(void) {
    char num_str[SMAX] = {0};
    int result = 0;

    if (fgets(num_str, SMAX, stdin) == NULL) {
        achtung();
    } else {
        if (strcmp(num_str, "N") != 0 && strcmp(num_str, "nulla") != 0 && strcmp(num_str, "nihil") != 0) {
            result = calc_letters(num_str);
        }
        printf("%d", result);
    }

    return 0;
}

int calc_letters(const char *num_str) {
    int result = 0;
    for (size_t i = 0; i < strlen(num_str); i++) {
        char prev_char = i == 0 ? 0 : num_str[i - 1];
        switch (num_str[i]) {
            case 'M':
                result += prev_char == 'C' ? 800 : 1000;
                break;
            case 'D':
                result += prev_char == 'C' ? 300 : 500;
                break;
            case 'C':
                result += prev_char == 'X' ? 80 : 100;
                break;
            case 'L':
                result += prev_char == 'X' ? 30 : 50;
                break;
            case 'X':
                result += prev_char == 'I' ? 8 : 10;
                break;
            case 'V':
                result += prev_char == 'I' ? 3 : 5;
                break;
            case 'I':
                result++;
                break;
            case 10:
            case 13:
                break;
            default:
                achtung();
        }
    }
    return result;
}

void achtung() {
    fprintf(stderr, "Puck you, Verter!");
    exit(EXIT_FAILURE);
}