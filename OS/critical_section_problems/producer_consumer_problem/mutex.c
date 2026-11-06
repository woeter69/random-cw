#include <stdio.h>

int mutex = 1;     // Mutex initialized to unlocked
int full = 0;      // Number of filled slots
int empty = 10;    // Number of empty slots (capacity = 10)
int x = 0;         // Item count / buffer representation

void producer() {
    --mutex;
    ++full;
    --empty;

    x++;
    printf("\nProducer produces %d", x);

    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;

    printf("\nConsumer consumes %d", x);
    x--;

    ++mutex;
}

int main() {
    int n;

    printf("1 for Producer\n");
    printf("2 for Consumer\n");
    printf("3 for Exit\n");

    do {
        printf("\nEnter your choice: ");
        if (scanf("%d", &n) != 1) {
            break;
        }

        switch (n) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("\nBuffer is Full");
                }
                break;

            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("\nBuffer is Empty");
                }
                break;

            case 3:
                printf("\nExit");
                break;

            default:
                printf("\nInvalid choice! Please choose 1, 2, or 3.");
                break;
        }
    } while (n != 3);

    return 0;
}
