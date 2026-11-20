#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>

int sum(int m, int n);
double get_power_of_two(int power, int dummy);
int main2();

int main() {
    setlocale(LC_ALL, "ru_RU.UTF-8");

    int count;
    char symbol1;
    char symbol2;

    printf("Введите количество символов: ");
    scanf("%d", &count);
    printf("Введите основной символ: ");
    scanf(" %c", &symbol1);
    printf("Введите второй символ (для второй половины): ");
    scanf(" %c", &symbol2);
    printf("\nРезультат:\n");
    putchar('+');

    for (int start = 1; start <= count; start++) {

        if (start <= count / 2) {
            putchar(symbol1);
        }
        else {
            putchar(symbol2);
        }

        putchar('!');
    }

    putchar('+');
    printf("\n");

    puts("\nЗадание 1");
    int m, n;
    printf("Введите m: ");
    scanf("%d", &m);
    printf("Введите n: ");
    scanf("%d", &n);

    int cnt = 0;
    int s = 0;
    if (m <= n) {
        for (int i = m; i <= n; i++) {
            s += i;
            cnt++;
            printf("итерация %d: сумма = %d\n", cnt, s);
        }
    }
    else {
        for (int i = m; i >= n; i--) {
            s += i;
            cnt++;
            printf("итерация %d: сумма = %d\n", cnt, s);
        }
    }

    s = sum(m, n);
    int k = (m >= n) ? (m - n + 1) : (n - m + 1);
    printf("выполнено %d раз\nсумма = %d\n", k, s);

    puts("\nЗадание 1A (Пункты 1-4)");
    int n_pow;
    printf("Введите степень n: ");
    scanf("%d", &n_pow);

    double last_val = 0;
    for (int i = 0; i <= n_pow; i++) {
        double val = get_power_of_two(i, 0);
        printf("2^%d = %10.0f\n", i, val);
        if (i == n_pow) {
            last_val = val;
        }
    }
    printf("Результат: %.1fK\n", last_val / 1024.0);

    puts("\nЗадание 1A (Пункт 5)");
    int m_val;
    printf("Введите заданное целое число m: ");
    scanf("%d", &m_val);

    double last_val_k = 1.0;
    for (int i = 0; get_power_of_two(i, 0) <= (double)m_val; i++) {
        last_val_k = get_power_of_two(i, 0);
        printf("2^%d = %10.0f\n", i, last_val_k);
    }
    printf("Результат: %.1fK\n", last_val_k / 1024.0);

    main2();

    return 0;
}

int sum(int m, int n) {
    int total = 0;
    if (m <= n) {
        for (int i = m; i <= n; i++) total += i;
    }
    else {
        for (int i = m; i >= n; i--) total += i;
    }
    return total;
}

double get_power_of_two(int power, int dummy) {
    return pow(2.0, (double)power);
}

double f(double x) {
    return 1.8 * x * x - sin(10 * x);
}

int main2() {
    double step;
    printf("\nЗадание 2. Табулирование функции.\n");
    printf("Функция: y = 1.8 * x^2 - sin(10 * x)\n");
    printf("Интервал: [0.2; 2.2]\n\n");
    printf("Введите шаг табуляции: ");
    scanf("%lf", &step);
    if (step <= 0.0) {
        printf("Ошибка: шаг табуляции должен быть больше 0\n");
    }
    else {
        puts("|----------------------|");
        puts("|      x     |  f(x)    |");
        puts("|----------------------|");
        for (double x = 0.2; x <= 2.2 + 1e-9; x += step) {
            printf("| %10.4lf | %8.6lf |\n", x, f(x));
        }

        puts("|----------------------|");
    }

    return 0;
}