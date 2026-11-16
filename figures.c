#include <stdio.h>
#include "figures.h"

#define PI 3.14159265358979323846
#define DRAW_HALF 30

double area_half_ring(int r_out, int r_in) {
    return PI * (r_out * r_out - r_in * r_in) / 2.0;
}

void draw_half_ring(int r_out, int r_in, char symbol) {
    int x, y;
    double inner_limit = (double)DRAW_HALF * DRAW_HALF * r_in * r_in;
    double outer_limit = (double)DRAW_HALF * DRAW_HALF * r_out * r_out;

    for (y = DRAW_HALF - 1; y >= 1; y -= 2) {
        for (x = -DRAW_HALF; x <= DRAW_HALF; x++) {
            double cell = (double)(x * x + y * y) * r_out * r_out;

            if (cell >= inner_limit && cell <= outer_limit)
                putchar(symbol);
            else
                putchar(' ');
        }
        putchar('\n');
    }
}

void print_definition(void) {
    puts("Полукольцо — часть кольца, ограниченная двумя концентрическими");
    puts("окружностями с общим центром и расположенная по одну сторону");
    puts("от прямой, проходящей через этот центр.");
}

void print_params(int r_out, int r_in) {
    puts("Фигура: верхняя половина кольца");
    printf("Внешний радиус: %d\n", r_out);
    printf("Внутренний радиус: %d\n", r_in);
    printf("Площадь: %.2f\n", area_half_ring(r_out, r_in));
}

double compare_half_rings(int r1_out, int r1_in, int r2_out, int r2_in) {
    return area_half_ring(r1_out, r1_in) - area_half_ring(r2_out, r2_in);
}
