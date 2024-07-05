#define _CRT_SECURE_NO_WARNINGS
#define MODULE 12345
#include <stdio.h>
#include <stdlib.h>


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int n;
    // Запитуємо довжину послідовності у користувача
    printf("Введіть довжину послідовності n: ");
    scanf("%d", &n);

    // Перевіряємо, чи n знаходиться в межах допустимого діапазону
    if (n < 1 || n >= 10000) {
        printf("Неправильне значення: n повинно бути між 1 та 10000\n");
        return 1;
    }

    // Виділяємо пам'ять для масиву dp динамічно
    int* dp = (int*)malloc((n + 1) * sizeof(int));
    if (dp == NULL) {
        printf("Помилка виділення пам'яті\n");
        return 1;
    }

    // Базові випадки
    dp[0] = 1; 
    dp[1] = 2; 
    if (n > 1) dp[2] = 4; 
    if (n > 2) dp[3] = 7; 

    // Заповнюємо масив dp використовуючи рекурентне співвідношення
    for (int i = 4; i <= n; i++) {
        dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MODULE;
    }

    // Виводимо кількість шуканих послідовностей
    printf("Кількість шуканих послідовностей: %d\n", dp[n]);

    // Звільняємо виділену пам'ять
    free(dp);

    return 0;
}
