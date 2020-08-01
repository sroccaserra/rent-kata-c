#include <stdio.h>
#include <stdlib.h>

#define MAX_ORDERS 10000

struct order {
    int start_time;
    int duration;
    int price;
};

static struct order Orders[MAX_ORDERS];

void process_cases(int nb_cases);
void compute_value(int nb_orders);
void scan_orders(int nb_orders);

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
        compute_value(nb_orders);
    }
}

void compute_value(int nb_orders) {
    scan_orders(nb_orders);

    int value = 0;
    if (nb_orders == 1) {
        value = Orders[0].price;
    }
    else {
        if (Orders[1].start_time >= Orders[0].start_time + Orders[0].duration) {
            value = Orders[0].price +  Orders[1].price;
        }
        else {
            value = Orders[0].price > Orders[1].price
                ? Orders[0].price
                : Orders[1].price;
        }
    }
    printf("%d\n", value);
}

void scan_orders(int nb_orders) {
    for (int i = 0; i < nb_orders; ++i) {
        scanf("%d %d %d",
                &Orders[i].start_time,
                &Orders[i].duration,
                &Orders[i].price);
    }
}
