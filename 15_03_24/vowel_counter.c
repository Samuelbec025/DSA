#include <stdio.h>
#include <string.h>

void countVowelsAndConsonants(char str[]) {
    int vowels = 0, consonants = 0;
    for (int i = 0; i < strlen(str); i++) {
        char ch = str[i];
        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                vowels++;
            } else {
                consonants++;
            }
        }
    }
    printf("Vowels: %d\n", vowels);
    printf("Consonants: %d\n", consonants);
}

int main() {
    char str[] = "hello";
    countVowelsAndConsonants(str);
    return 0;
}
