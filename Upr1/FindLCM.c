#include <stdio.h>

int find_gcd(int, int);
int lcm(int, int);

int main() {

    int lcm1 = lcm(8, 12);
    int lcm2 = lcm(25, 15);

    printf("lcm1 = %d\n", lcm1);
    printf("lcm2 = %d\n", lcm2);
    
    return 0;
}

int find_gcd(int n, int m) {

    int temp;

    while(n > 0) {

        temp = n;
        n = m % n;
        m = temp;
    }

    return m;
}


int lcm(int n, int m) {

    return n * m / find_gcd(n, m);
}