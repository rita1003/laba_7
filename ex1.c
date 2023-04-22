/* Ответы на вопросы:
    1. Возьмем такой словарь: summer, sun, hello, glasses, apples, world, carrot, juice, 
    princess, age. Он хорош тем, что тут есть 2 слова, которые имеют две первых одинаковых
    буквы (sun и summer). Это нам поможет проверить, как ведут себя сортировки в случае, если
    буквы в начале слов одинаковы. Также возьмем еще один словарь, чтобы делать утверждения на 
    основе нескольких проверок, а не на основе одной. Пусть это будет словарь: bonjour, livre,
    pays, terminer, offrir, fermer, aimer, vrai, difficile, musique.

    В результате сортировки первого словаря мы видим такие результаты:
        1. Сортировка выбором: 9 итераций, 3.081 секунда
        2. Сортировка пузырьком: 29 итераций, 3.190 секунд
        3. Сортировка расчёской: 9 итераций, 3.081 секунда

    В результате сортировки второго словаря мы видим такие результаты:
        1. Сортировка выбором: 9 итераций, 3.086 секунд
        2. Сортировка пузырьком: 22 итерации, 3.161 секунда
        3. Сортировка расчёской: 12 итераций, 3.355 секунд

    Это позволяет нам сделать вывод, что сортировка выбором - лучшее решение для программиста.
    За меньшее количество итераций и меньшее количество секунд (по сравнению с другими способами
    сортировки) она способна отсортировать любой словарь. 

    Но это, конечно, в среднем. На самом деле, можно подобрать такой словарь, с которым, например,
    сортировка пузырьком справится быстрее. Возьмем уже отсортированный словарь и посмотрим, 
    как будут вести себя различные способы сортировки. Словарь: apple, book, climb, door, eggs,
    flavour, glasses, hair, id, jump. Получим такие результаты:
        1. Сортировка выбором: 9 итераций, 3.09 секунд
        2. Сортировка пузырьком: 0 итераций, 3.009 секунд
        3. Сортировка расчёской: 0 итераций, 3.011 секунд
    И действительно, видим, что сортировка пузырьком за 0 итераций и за самое маленькое время
    справилась со своей задачей. Именно поэтому нельзя предугадать, какая сортировка в конкретной
    ситуации будет лучшим вариантом. Но целесообразнее всего, пожалуй, использовать сортировку 
    выбором. 

    2. Нет, каждая из сортировок выполнялась за разное время, и в подтверждение этому можно 
    посмотреть на данные из ответа на первый вопрос. Это и очевидно: в сортировке пузырьком, например,
    сраниваются соседние элементы - что в общем случае более времязатратно. В сортировке выборкой,
    например, при каждой итерации ищется наименьший элемент, и количество итераций в данном
    случае ВСЕГДА будет равно количество элементов минус единица, что, в общем случае, менее 
    времязатратно.
*/

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

int CombSort (char words[10][100]) { //сортировка расчёской
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
    sleep(3);
    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf ("Ваш отсортированный массив (метод Сomb Sort): \n");
    PrintArray(words);
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