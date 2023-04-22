#include <stdio.h>

int main () {
    char word[100];
    char vowel_letters[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    int vowels = 0, consonants;
    printf ("Введите любое слово: ");
    scanf ("%s", &word);
    for (int i = 0; word[i]!='\0'; i++) {
        for (int j = 0; j < 6; j++) {
            if (word[i] == vowel_lertters[j]) {
                vowels++;
            }
        }

    }
    
    consonants = i - vowels;
    printf ("Количество согласных: %d\n", consonants);
    printf ("Количество гласных: %d\n", vowels);

    return 0;
}