#include <stdio.h>
#include <string.h>

int roman_to_arabic(char *roman) {
    int values[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    const char *roman_numerals[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};

    int result = 0;
    size_t i = 0;

    for (size_t j = 0; j < sizeof(values) / sizeof(values[0]); ++j) {
        while (strncmp(roman + i, roman_numerals[j], strlen(roman_numerals[j])) == 0) {
            result += values[j];
            i += strlen(roman_numerals[j]);
        }
    }

    return result;
}

int main() {
    char roman_numeral[100];
    
    scanf("%s", roman_numeral);

    int result = roman_to_arabic(roman_numeral);
    printf("%d\n", result);

    return 0;
}
