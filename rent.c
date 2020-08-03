#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_ORDERS 10000
#define SENTINEL_START_TIME 2000000

typedef struct {
    int start_time;
    int duration;
    int price;
} Order;

static inline int max(int a, int b) {
    return (a > b) ? a : b;
}

void process_cases(int nb_cases);
void scan_orders(int nb_orders, Order orders[]);
int compute_value(int nb_orders, Order orders[]);
Order *next_compatible_order(int position, Order *current, Order orders[]);
bool does_end_before_start(Order *first, Order *second);

int main() {
    int nb_cases;
    scanf("%d", &nb_cases);

    process_cases(nb_cases);

    return EXIT_SUCCESS;
}

void process_cases(int nb_cases) {
    Order orders[MAX_ORDERS+1];

    for (int test_case = 0; test_case < nb_cases; ++test_case) {
        int nb_orders;
        scanf("%d", &nb_orders);
        scan_orders(nb_orders, orders);

        int value = compute_value(nb_orders, orders);

        printf("%d\n", value);
    }
}

void scan_orders(int nb_orders, Order orders[]) {
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

int compute_value(int nb_orders, Order orders[]) {
    for(int i = nb_orders -1 ; i >= 0; --i) {
        Order *current = &orders[i];
        Order *next = &orders[i+1];
        Order *next_compatible = next_compatible_order(i+1, current, orders);

        current->price = max(current->price + next_compatible->price, next->price);
    }

    return orders[0].price;
}

Order *next_compatible_order(int position, Order *current, Order orders[]) {
    int i = position;
    Order *order_i = &orders[i];
    while (!does_end_before_start(current, order_i)) {
        ++i;
        order_i = &orders[i];
    }
    return order_i;
}

bool does_end_before_start(Order *first, Order *second) {
    return first->start_time + first->duration <= second->start_time;
}
