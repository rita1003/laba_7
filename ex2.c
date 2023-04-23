#include <stdio.h>
#include <string.h> //для strcmp, strcpy
#include <time.h> // для clock_t, clock(), CLOCKS_PER_SEC
#include <unistd.h> // для sleep()

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
    double time_spent = 0.0;
    clock_t begin = clock();
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
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Selection Sort): \n");
    PrintArray(words);
    printf ("Количество итераций: %d\n", count_of_itertion);
    printf ("Время выполнения функции: ");
    printf("%f\n", time_spent);

    return 0; 
}

int BubbleSort (char words[10][100]) { //сортировка пузырьком
    int count_of_itertion = 0; //количество итераций
    char q[100];
    double time_spent = 0.0;
    clock_t begin = clock();
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
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Bubble Sort): \n");
    PrintArray(words);
    printf ("Количество итераций: %d\n", count_of_itertion);
    printf ("Время выполнения функции: ");
    printf("%f\n", time_spent);

    return 0;
}

int CombSort (char (*words_ukaz)[100]) { //сортировка расчёской
    int count_of_itertion = 0; //количество итераций
    float rfactor = 1.24733;
    int j, swaps = 1, gap = 10;
    char q[100];
    double time_spent = 0.0;
    clock_t begin = clock();
    while (gap > 1 || swaps) {
        gap = (int)(gap / rfactor);
        if (gap < 1) {
            gap = 1;
        }
        swaps = 0;

        for (int i = 0; i < 10 - gap; ++i) {
            j = i + gap;
            if (strcmp (*(words_ukaz+i), *(words_ukaz+j)) > 0) {
                strcpy (q, *(words_ukaz+i));
                strcpy (*(words_ukaz+i), *(words_ukaz+j));
                strcpy (*(words_ukaz+j), q);
                count_of_itertion++;
                printf ("Итерация %d\n", count_of_itertion);
                PrintArray(words_ukaz);                
                swaps = 1;
            }
        }
    }
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Сomb Sort): \n");
    PrintArray(words_ukaz);
    printf ("Количество итераций: %d\n", count_of_itertion);
    printf ("Время выполнения функции: ");
    printf("%f\n", time_spent);

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
    
   char (*words_ukaz)[100] = words;
   char (*old_array2_ukaz)[100] = old_array2;

    if (search == 1) {
        SelectionSort (words);
    }
    else if (search == 2) {
        BubbleSort (words);
    }
    else if (search == 3) {
        CombSort (words_ukaz);
    }
    else if (search == 4) {
        SelectionSort (words);
        BubbleSort (old_array);
        CombSort (old_array2_ukaz);
    }

    return 0;
}