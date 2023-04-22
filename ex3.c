#include <stdio.h>

int main () {
    char word[100];
    char *word_ukaz; 
    char vowel_letters[6] = {'a', 'e', 'i', 'o', 'u', 'y'};
    char *vowel_letters_ukaz;
    int vowels = 0, consonants;
    printf ("Введите любое слово: ");
    scanf ("%s", &word);
    word_ukaz = word;
    vowel_letters_ukaz = vowel_letters;
    for (int i = 0; *(word_ukaz+i)!='\0'; i++) {
        for (int j = 0; j < 6; j++) {
            if (*(word_ukaz+i) == *(vowel_letters_ukaz+j)) {
                vowels++;
            }
        }
        consonants = i - vowels + 1;
    }

    printf ("Количество согласных: %d\n", consonants);
    printf ("Количество гласных: %d\n", vowels);

    return 0;
}