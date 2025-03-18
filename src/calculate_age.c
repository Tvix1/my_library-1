#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "my_functions.h"

// Реализация функции для ввода строки
int readln(char s[], int maxlen) {
    if (fgets(s, maxlen, stdin) == NULL) {
        return -1;  // Ошибка при считывании
    }
    // Убираем символ новой строки
    s[strcspn(s, "\n")] = 0;
    return 0;
}

// Реализация функции для вывода числа в двоичном формате
void printBinary(unsigned char port) {
    for (int i = 7; i >= 0; i--) {
        printf("%d", (port >> i) & 1);  // Сдвигаем биты и выводим
    }
    printf("\n");
}

// Реализация функции для выполнения арифметических сдвигов
void run_shift_arifmetic() {
    int value = 10;  // Пример числа
    int shift_amount = 2;  // Количество сдвигов

    // Сдвиг влево (умножение на 2^shift_amount)
    int result_left_shift = value << shift_amount;
    printf("Left shift: %d << %d = %d\n", value, shift_amount, result_left_shift);

    // Сдвиг вправо (деление на 2^shift_amount)
    int result_right_shift = value >> shift_amount;
    printf("Right shift: %d >> %d = %d\n", value, shift_amount, result_right_shift);
}

// Реализация функции для вычисления возраста по дате рождения
int calculate_age(int birth_day, int birth_month, int birth_year) {
    time_t t = time(NULL);  // Текущий момент времени
    struct tm current_time = *localtime(&t);

    int age = current_time.tm_year + 1900 - birth_year;

    // Если день рождения еще не наступил в этом году
    if (current_time.tm_mon + 1 < birth_month ||
        (current_time.tm_mon + 1 == birth_month && current_time.tm_mday < birth_day)) {
        age--;
    }

    return age;
}

// Реализация функции для вычисления мощности (P = U * I)
double calculate_power(double voltage, double current) {
    return voltage * current;  // Простое произведение напряжения на ток
}