#include <stdio.h>
#include <string.h> //для strcmp, strcpy
#include <time.h>

int PrintArray (char words[10][100]) { //вывод массива
    for (int i = 0; i < 10; i++) {
        printf ("%s\n", words[i]);
    }
    return 0;
}

int SelectionSort (char words[10][100]) { //сортировка выбором
    char q[100]; //для обмена 
    int count_of_itertion = 0; //количество итераций
    int min; //для поиска минимального элемента
    clock_t time_start = clock(); 
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
        count_of_itertion++;
        printf ("Итерация %d\n", count_of_itertion);
        PrintArray(words);
    }
    clock_t time_end = clock() - time_start;
    printf ("Ваш отсортированный массив (метод Selection Sort): \n");
    PrintArray(words);
    printf ("Количество итераций: %d\n", count_of_itertion);
    printf ("Время выполнения функции: ");
    printf("%u\n", (double)time_end / CLOCKS_PER_SEC);

    return 0; 
}

int BubbleSort (char words[10][100]) { //сортировка пузырьком
    int count_of_itertion = 0; //количество итераций
    char q[100];
    clock_t time_start = clock(); 
    for (int i = 0; i < 10 - 1; i++) {
        for (int j = 10 - 1; j > i; j--) {
            if (strcmp(words[j - 1], words[j]) > 0) {
                strcpy (q, words[j - 1]);
                strcpy (words[j - 1], words[j]);
                strcpy (words[j], q);
                count_of_itertion++;
                printf ("Итерация %d\n", count_of_itertion);
                PrintArray(words);
            }
        }
    }
    clock_t time_end = clock() - time_start;
    printf ("Ваш отсортированный массив (метод Bubble Sort): \n");
    PrintArray(words);
    printf ("Количество итераций: %d\n", count_of_itertion);
    printf ("Время выполнения функции: ");
    printf("%u\n", (double)time_end / CLOCKS_PER_SEC);

    return 0;
}

int CombSort (char words[10][100]) { //сортировка расчёской
    int count_of_itertion = 0; //количество итераций
    float rfactor = 1.24733;
    int j, swaps = 1, gap = 10;
    char q[100];
    clock_t time_start = clock(); 
    while (gap > 1 || swaps) {
        gap = (int)(gap / rfactor);
        if (gap < 1) {
            gap = 1;
        }
        swaps = 0;

        for (int i = 0; i < 10 - gap; ++i) {
            j = i + gap;
            if (strcmp (words[i], words[j]) > 0) {
                strcpy (q, words[i]);
                strcpy (words[i], words[j]);
                strcpy (words[j], q);
                count_of_itertion++;
                printf ("Итерация %d\n", count_of_itertion);
                PrintArray(words);                
                swaps = 1;
            }
        }
    }
    clock_t time_end = clock() - time_start;
    printf ("Ваш отсортированный массив (метод Сomb Sort): \n");
    PrintArray(words);
    printf ("Количество итераций: %d\n", count_of_itertion);
    printf ("Время выполнения функции: ");
    printf("%u\n", (double)time_end / CLOCKS_PER_SEC);

    return 0;
}

int main () {
    char words [10][100];
    char old_array[10][100]; //т.к. при сортировке мы потеряем старый массив
    char old_array2[10][100];
    int search;

    printf ("Какой алгоритм вы хотите использовать?\n");
    printf ("1. Сортировка выбором (Selection Sort)\n");
    printf ("2. Сортировка пузырьком (Bubble Sort)\n");
    printf ("3. Сортировка расчёской (Comb Sort)\n");
    printf ("4. Все сортировки\n");
    scanf("%d", &search);

    printf("Введите 10 слов: ");
    for (int i = 0; i < 10; i++) {
        scanf("%s", &words[i]);
        strcpy (old_array[i], words[i]); //сохранили значения старого массива 
        strcpy (old_array2[i], words[i]);
    }
    
    if (search == 1) {
        SelectionSort (words);
    }
    else if (search == 2) {
        BubbleSort (words);
    }
    else if (search == 3) {
        CombSort (words);
    }
    else if (search == 4) {
        SelectionSort (words);
        BubbleSort (old_array);
        CombSort (old_array2);
    }
    else {
        printf ("Такого варианта нет. Выберете другой");
    }

    return 0;
}