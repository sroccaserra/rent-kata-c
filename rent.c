#include <stdio.h>
#include <stdlib.h>

void process_cases(int nb_cases);
void process_orders(int nb_orders);

int main() {
    int nb_cases;
    scanf("%d", &nb_cases);
    process_cases(nb_cases);

    return EXIT_SUCCESS;
}

void process_cases(int nb_cases) {
    for (int test_case = 0; test_case < nb_cases; ++test_case) {
        int nb_orders;
        scanf("%d", &nb_orders);
        process_orders(nb_orders);
    }
}

void process_orders(int nb_orders) {
    int value = 0;
    for (int i = 0; i < nb_orders; ++i) {
        struct {
            int start_time;
            int duration;
            int price;
        } order;

        scanf("%d %d %d",
                &order.start_time,
                &order.duration,
                &order.price);

        value += order.price;
    }
    printf("%d\n", value);
}
