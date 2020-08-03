#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ORDERS 10000
#define SENTINEL_START_TIME 2000000

struct order {
    int start_time;
    int duration;
    int price;
};

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

void process_cases(int nb_cases);
void scan_orders(int nb_orders, struct order orders[]);
int compute_value(int nb_orders, struct order orders[]);
struct order *next_compatible_order(int position, struct order *current, struct order orders[]);
bool does_end_before_start(struct order *first, struct order *second);

int main() {
    int nb_cases;
    scanf("%d", &nb_cases);

    process_cases(nb_cases);

    return EXIT_SUCCESS;
}

void process_cases(int nb_cases) {
    struct order orders[MAX_ORDERS+1];

    for (int test_case = 0; test_case < nb_cases; ++test_case) {
        int nb_orders;
        scanf("%d", &nb_orders);
        scan_orders(nb_orders, orders);

        int value = compute_value(nb_orders, orders);

        printf("%d\n", value);
    }
}

void scan_orders(int nb_orders, struct order orders[]) {
    for (int i = 0; i < nb_orders; ++i) {
        scanf("%d %d %d",
                &orders[i].start_time,
                &orders[i].duration,
                &orders[i].price);
    }

    orders[nb_orders].start_time = SENTINEL_START_TIME;
    orders[nb_orders].duration = 0;
    orders[nb_orders].price = 0;
}

int compute_value(int nb_orders, struct order orders[]) {
    for(int i = nb_orders -1 ; i >= 0; --i) {
        struct order *current = &orders[i];
        struct order *next = &orders[i+1];
        struct order *next_compatible = next_compatible_order(i+1, current, orders);

        current->price = max(current->price + next_compatible->price, next->price);
    }

    return orders[0].price;
}

struct order *next_compatible_order(int position, struct order *current, struct order orders[]) {
    int i = position;
    struct order *order_i = &orders[i];
    while (!does_end_before_start(current, order_i)) {
        ++i;
        order_i = &orders[i];
    }
    return order_i;
}

bool does_end_before_start(struct order *first, struct order *second) {
    return first->start_time + first->duration <= second->start_time;
}
