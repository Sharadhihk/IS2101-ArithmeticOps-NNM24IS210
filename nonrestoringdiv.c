#include<stdio.h>
#include<stdlib.h>

void bin(int num,int bit){
    for(int i=bit-1;i>=0;i--)
    printf("%d",(num>>i)&1);
}

int main() {
    int dividend, divisor;
    int q=0, rem=0;
    int n, i;
    printf("Enter dividend: ");
    scanf("%d", &dividend);
    printf("\nEnter divisor: ");
    scanf("%d", &divisor);

    if(divisor==0) {
        printf("\nCannot divide by zero\n");
    }
    int temp=dividend;
    n=0;
    while (temp>0) {
        temp>>=1;
        n++;
    }
    
    for(i=n-1;i>=0;i--)
    {
        rem=(rem<<1)|((dividend>>i)&1);
        if(rem>=divisor) 
        {
            rem=rem-divisor;
            q=(q<<1)|1;
        } 
        else 
        {
            q=(q<<1)|0;
        }
    }
    printf("\nQuotient: ");
    bin(q,32);
    printf("\nRemainder: ");
    bin(rem,32);
    return 0;
}
