#include <stdio.h>
#include <stdlib.h>

typedef struct {

    int ch;
    int zn;

} Rational;

void print_rational(const Rational*);
int find_gcd(int, int);
void simplify_rational(Rational*);

int main() {

    Rational* num1 = (Rational*)malloc(sizeof(Rational));
    
    if(num1 == NULL)
        return 1;

    num1->ch = 105;
    num1->zn = 150;

    print_rational(num1);
    printf("After invoking simplify_rational():\n");
    simplify_rational(num1);
    print_rational(num1);

    return 0;
}

void print_rational(const Rational * num) {

    printf("%d/%d\n", num->ch, num->zn);
}

int find_gcd(int n1, int n2) {

    int temp;

    while(n1 > 0) {

        temp = n1;
        n1 = n2 % n1;
        n2 = temp;
    }

    return n2;
}

void simplify_rational(Rational * num) {

    int gcd = find_gcd(num -> ch, num -> zn);
    num -> ch /= gcd;
    num -> zn /= gcd;
}