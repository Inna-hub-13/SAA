#include <stdio.h>

int gcd_recursion(int, int);

int main() {

    int gcd = gcd_recursion(9, -15);
    printf("gcd = %d\n", gcd);
    return 0;
}

int gcd_recursion(int n1, int n2) {

    return n1 == 0 ? n2 : gcd_recursion(n2 % n1, n1);
}

