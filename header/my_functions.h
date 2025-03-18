#ifndef MY_FUNCTIONS_H
#define MY_FUNCTIONS_H

// Функция для ввода строки
int readln(char s[], int maxlen);

// Функция для вывода числа в двоичном формате
void printBinary(unsigned char port);

// Функция для выполнения арифметических сдвигов
void run_shift_arifmetic();

// Функция для вычисления возраста по дате рождения
int calculate_age(int birth_day, int birth_month, int birth_year);

// Функция для вычисления мощности (P = U * I)
double calculate_power(double voltage, double current);

#endif // MY_FUNCTIONS_H