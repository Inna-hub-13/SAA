#include <stdio.h>

int abs(int);
// Subractuing
int gcd_sub(int, int);
// Remainder dividing
int gcd_div_rem(int, int);

int main(){

    int gcd1 = gcd_sub(56, -8);
    int gcd2 = gcd_div_rem(9, -18);
    printf("gcd = %d\n", gcd1);
    printf("gcd = %d\n", gcd2);
    return 0;
}

int abs(int num) {

    return num >= 0 ? num : -1 * num;
}

int gcd_sub(int n, int m) {

    n = abs(n);
    m = abs(m);

    if(m == 0)
        return n;

    while(n != 0){

        if(m > n)
            m = m - n;
         else 
            n = n - m;
    }

    return m;
}

int gcd_div_rem(int n, int m) {
    
    int temp;

    while(n > 0) {

        temp = n;
        n = m % n;
        m = temp;
    }

    return m;
}