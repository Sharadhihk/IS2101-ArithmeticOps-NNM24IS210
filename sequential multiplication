#include <stdio.h>

void printBinary(int num) {
    if (num == 0) {
        printf("0");
        return;
    }

    int binary[32]; 
    int index = 0;

    while (num > 0) {
        binary[index++] = num % 2;
        num = num / 2;
    }
    for (int i = index - 1; i >= 0; i--) {
        printf("%d", binary[i]);
    }
}

int main() {
   
    int numbers[] = {2, 3, 4}; 
    int count = sizeof(numbers) / sizeof(numbers[0]);

   
    int result = 1;
    for (int i = 0; i < count; i++) {
        result *= numbers[i];
    }

    printf("Multiplication result: %d\n", result);

    printf("Binary of result: ");
    printBinary(result);
    printf("\n");

    return 0;
}
