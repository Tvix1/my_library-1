#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Funktsiya dlya vychisleniya vozrasta
int calculate_age(int birth_year, int birth_month, int birth_day) {
    // Poluchayem tekushchuyu datu
    time_t t = time(NULL);
    struct tm current_time = *localtime(&t);

    int age = current_time.tm_year + 1900 - birth_year;

    // Esli eshche ne nastupil den' rozhdeniya v etom godu, umenshayem vozrast na 1
    if (current_time.tm_mon + 1 < birth_month ||
        (current_time.tm_mon + 1 == birth_month && current_time.tm_mday < birth_day)) {
        age--;
    }

    return age;
}

int main() {
    char first_name[50], last_name[50];
    int birth_day, birth_month, birth_year;

    // Zapros imeni, familii i daty rozhdeniya
    printf("Enter your first name: ");
    if (scanf("%49s", first_name) != 1) {
        printf("Invalid input for first name.\n");
        return 1;
    }

    printf("Enter your last name: ");
    if (scanf("%49s", last_name) != 1) {
        printf("Invalid input for last name.\n");
        return 1;
    }

    printf("Enter your birth day (DD): ");
    if (scanf("%d", &birth_day) != 1 || birth_day < 1 || birth_day > 31) {
        printf("Invalid input for birth day.\n");
        return 1;
    }

    printf("Enter your birth month (MM): ");
    if (scanf("%d", &birth_month) != 1 || birth_month < 1 || birth_month > 12) {
        printf("Invalid input for birth month.\n");
        return 1;
    }

    printf("Enter your birth year (YYYY): ");
    if (scanf("%d", &birth_year) != 1 || birth_year < 1900 || birth_year > 2100) {
        printf("Invalid input for birth year.\n");
        return 1;
    }

    // Vychislenie vozrasta
    int age = calculate_age(birth_year, birth_month, birth_day);

    // Vyvod previatstviya
    printf("\nHello, %s %s! You are %d years old.\n", first_name, last_name, age);

    return 0;
}