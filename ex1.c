#include <stdio.h>
#include <string.h> //для strcmp и не только 

/*char SelectionSort () {

}*/

char BubbleSort (char *words) {
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 0; j < 10 - 1 - i; j++) {
            if (strcmp (words[j], words[j + 1])) {
                q = words[j];
                words[j] = words[j + 1];
                words[j + 1] = q;
            }
        }
    }
    return words[10][100];
}

/*char CombSort () {

}*/

int main () {
    char words [10][100];
    int search;

    printf ("Какой алгоритм вы хотите использовать?\n");
    printf ("1. Сортировка выбором (Selection Sort)\n");
    printf ("2. Сортировка пузырьком (Bubble Sort)\n");
    printf ("3. Сортировка расчёчской (Comb Sort)\n");
    printf ("4. Все сортировки\n");
    scanf("%d", &search);

    printf("Введите 10 слов: ");
    for (int i = 0; i < 10; i++) {
        scanf("%s", &words[i]);
    }

    if (search) {
       char sort_words[10][100] = BubbleSort (words);
       for (int i = 0; i < 10; i++) {
        printf("%s", sort_words[i]);
       }

    }

    return 0; 

}