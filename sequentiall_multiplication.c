#include <stdio.h>
#include <stdint.h>

void arithmetic_right_shift(int16_t *A, int8_t *Q, int *Q_1) {
    int new_Q_1 = *Q & 1; 
    int msb_A = (*A & 0x8000) ? 1 : 0;

    *Q = ((*A & 1) << 7) | ((*Q & 0xFF) >> 1);
    *A = (*A >> 1) | (msb_A << 15); 

    *Q_1 = new_Q_1;
}

int main() {
    int8_t M, Q;            
    int16_t A = 0;           
    int Q_1 = 0;            
    int count = 8;            

    printf("Enter multiplicand (M): ");
    scanf("%hhd", &M);

    printf("Enter multiplier (Q): ");
    scanf("%hhd", &Q);

    printf("\nInitial Values:\n");
    printf("A: %d, Q: %d, M: %d, Q-1: %d\n", A, Q, M, Q_1);

    while (count > 0) {
        if (Q & 1) {
            A = A + M;
            printf("Added M to A → A: %d\n", A);
        }

        arithmetic_right_shift(&A, &Q, &Q_1);
        printf("After shift → A: %d, Q: %d, Q-1: %d\n", A, Q, Q_1);

        count--;
    }

    // final result
    int16_t result = (A << 8) | (Q & 0xFF);

    printf("\nFinal Product: %d\n", result);
    return 0;
}
