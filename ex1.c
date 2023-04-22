#include <stdio.h>
#include <string.h> //для strcmp, strcpy

int PrintArray (char words[10][100]) { //вывод массива
    for (int i = 0; i < 10; i++) {
        printf ("%s\n", words[i]);
    }
    return 0;
}

int SelectionSort (char words[10][100]) {
    char q[100]; //для обмена 
    int min; //для поиска минимального элемента
    for (int i = 0; i < 10 - 1; i++) {
        min = i;
        for (int j = i + 1; j < 10; j++) {
            if (strcmp (words[j], words[min]) < 0) {
                min = j;
            }
        }
        strcpy (q, words[i]);
        strcpy (words[i], words[min]);
        strcpy (words[min], q);
    }

    printf ("Ваш отсортированный массив (метод Selection Sort): \n");
    PrintArray(words);

    return 0; 
}

int BubbleSort (char words[10][100]) {
    char q[100];
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 10 - 1; j > i; j--) {
            if (strcmp (words[j - 1], words[j]) > 0) {
                strcpy (q, words[j - 1]);
                strcpy (words[j - 1], words[j]);
                strcpy (words[j], q);
            }
        }
    }

    printf ("Ваш отсортированный массив (метод Bubble Sort): \n");
    PrintArray(words);

    return 0;
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

    if (search == 1) {
        SelectionSort (words);
    }
    else if (search == 2) {
       BubbleSort (words);
    }

    return 0; 

}