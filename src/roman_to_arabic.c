#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SMAX 16

void achtung();
int calc_letters(const char *num_str);
void calc_nums(char *dst, int num_num);

int main(void) {
    char num_str[SMAX] = {0};
    char num_str_assert[SMAX] = {0};
    int result = 0;

    if (fgets(num_str, SMAX, stdin) == NULL) {
        achtung();
    } else {
        if (strcmp(num_str, "N") != 0 && strcmp(num_str, "nulla") != 0 && strcmp(num_str, "nihil") != 0) {
            result = calc_letters(num_str);
            calc_nums(num_str_assert, result);
            if (strcmp(num_str, num_str_assert) != 0) {
                achtung();
            }
        }
        printf("%d", result);
    }

    return 0;
}

void calc_nums(char *dst, int num_num) {
    char buffer[SMAX] = {0};
    int iteration = 1;
    while (num_num != 0) {
        int test_num = num_num % 10 * iteration;
        switch (test_num) {
            case 1:
                strcat(buffer, "I");
                break;
            case 2:
                strcat(buffer, "II");
                break;
            case 3:
                strcat(buffer, "III");
                break;
            case 4:
                strcat(buffer, "VI");
                break;
            case 5:
                strcat(buffer, "V");
                break;
            case 6:
                strcat(buffer, "IV");
                break;
            case 7:
                strcat(buffer, "IIV");
                break;
            case 8:
                strcat(buffer, "IIIV");
                break;
            case 9:
                strcat(buffer, "XI");
                break;
            case 10:
                strcat(buffer, "X");
                break;
            case 20:
                strcat(buffer, "XX");
                break;
            case 30:
                strcat(buffer, "XXX");
                break;
            case 40:
                strcat(buffer, "LX");
                break;
            case 50:
                strcat(buffer, "L");
                break;
            case 60:
                strcat(buffer, "XL");
                break;
            case 70:
                strcat(buffer, "XXL");
                break;
            case 80:
                strcat(buffer, "XXXL");
                break;
            case 90:
                strcat(buffer, "CX");
                break;
            case 100:
                strcat(buffer, "C");
                break;
            case 200:
                strcat(buffer, "CC");
                break;
            case 300:
                strcat(buffer, "CCC");
                break;
            case 400:
                strcat(buffer, "DC");
                break;
            case 500:
                strcat(buffer, "D");
                break;
            case 600:
                strcat(buffer, "CD");
                break;
            case 700:
                strcat(buffer, "CCD");
                break;
            case 800:
                strcat(buffer, "CCCD");
                break;
            case 900:
                strcat(buffer, "MC");
                break;
            case 1000:
                strcat(buffer, "M");
                break;
            case 2000:
                strcat(buffer, "MM");
                break;
            case 3000:
                strcat(buffer, "MMM");
                break;
            default:
                break;
        }
        num_num /= 10;
        iteration *= 10;
    }

    for (int i = (int)strlen(buffer) - 1, j = 0; i >= 0; i--, j++) {
        dst[j] = buffer[i];
    }
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