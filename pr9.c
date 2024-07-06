#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

int min_steps(int x, int y) {
    if (x == y) return 0;
    int distance = y - x;
    int step = 1;
    int total_steps = 0;
    int current_position = x;

    while (distance > 0) {
        total_steps++;
        distance -= step;
        current_position += step;

        if (distance > 0) {
            step = (step == 1) ? 2 : 1;
        }
    }

    return total_steps;
}

int main() {
    SetConsoleCP ( 1251 );
    SetConsoleOutputCP ( 1251 );
    int x, y;
    printf("Введіть значення x і y: ");
    scanf("%d %d", &x, &y);

    if (x < 0 || y < 0 || x > y || y >= (1 << 31)) {
        printf("Недійсні введені значення.\n");
        return 1;
    }

    int result = min_steps(x, y);
    printf("Мінімальна кількість кроків від %d до %d: %d\n", x, y, result);

    return 0;
}
