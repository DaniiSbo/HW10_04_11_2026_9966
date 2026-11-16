#define _CRT_SECURE_NO_DEPRECATE

#include <stdio.h>
#include <stdlib.h>
#include "figures.h"

int main(void) {
    int r_out, r_in;
    int r2_out, r2_in;
    int choice;
    char symbol;

    system("chcp 65001 > nul");

    puts("Введите внешний радиус полукольца");
    scanf("%d", &r_out);
    puts("Введите внутренний радиус полукольца");
    scanf("%d", &r_in);

    if (r_out <= 0 || r_in <= 0 || r_in >= r_out) {
        puts("Ошибка: должно выполняться условие 0 < внутренний радиус < внешний радиус");
        system("pause");
        return 1;
    }

    do {
        puts("");
        puts("Меню:");
        puts("1 - рассчитать площадь");
        puts("2 - вывести определение фигуры");
        puts("3 - нарисовать фигуру");
        puts("4 - вывести параметры фигуры");
        puts("5 - сравнить с другой фигурой по площади");
        puts("0 - выход");
        puts("Введите номер операции");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Площадь полукольца: %.2f\n", area_half_ring(r_out, r_in));
                break;
            case 2:
                print_definition();
                break;
            case 3:
                puts("Введите символ для рисования");
                scanf(" %c", &symbol);
                draw_half_ring(r_out, r_in, symbol);
                break;
            case 4:
                print_params(r_out, r_in);
                break;
            case 5:
                puts("Введите внешний и внутренний радиусы второй фигуры");
                scanf("%d %d", &r2_out, &r2_in);
                if (r2_out <= 0 || r2_in <= 0 || r2_in >= r2_out) {
                    puts("Ошибка: для второй фигуры должно выполняться условие 0 < внутренний радиус < внешний радиус");
                } else {
                    printf("Площадь первой фигуры: %.2f\n", area_half_ring(r_out, r_in));
                    printf("Площадь второй фигуры: %.2f\n", area_half_ring(r2_out, r2_in));
                    printf("Разность площадей: %.2f\n", compare_half_rings(r_out, r_in, r2_out, r2_in));
                }
                break;
            case 0:
                puts("Работа завершена");
                break;
            default:
                puts("Нет операции с таким номером");
        }
    } while (choice != 0);

    system("pause");
    return 0;
}
