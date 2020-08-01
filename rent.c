#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 10000

struct order {
    int start_time;
    int duration;
    int price;
};

void process_cases(int nb_cases);
void compute_value(int nb_orders, struct order orders[]);
void scan_orders(int nb_orders, struct order orders[]);

int main() {
    int nb_cases;
    scanf("%d", &nb_cases);

    process_cases(nb_cases);

    return EXIT_SUCCESS;
}

void process_cases(int nb_cases) {
    struct order orders[MAX_ORDERS];

    for (int test_case = 0; test_case < nb_cases; ++test_case) {
        int nb_orders;
        scanf("%d", &nb_orders);
        compute_value(nb_orders, orders);
    }
}

void compute_value(int nb_orders, struct order orders[]) {

    scan_orders(nb_orders, orders);

    int value = 0;
    if (nb_orders == 1) {
        value = orders[0].price;
    }
    else {
        if (orders[1].start_time >= orders[0].start_time + orders[0].duration) {
            value = orders[0].price +  orders[1].price;
        }
        else {
            value = orders[0].price > orders[1].price
                ? orders[0].price
                : orders[1].price;
        }
    }

    printf("%d\n", value);
}

void scan_orders(int nb_orders, struct order orders[]) {
    for (int i = 0; i < nb_orders; ++i) {
        scanf("%d %d %d",
                &orders[i].start_time,
                &orders[i].duration,
                &orders[i].price);
    }
}
