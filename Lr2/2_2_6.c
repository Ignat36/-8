#include <stdlib.h>
#include <stdio.h>
#include <math.h>

int main() {
    float x, E, y;
    double pi = 3.14159265358979323846264338327950288;
    printf("Enter x in degrees: ");
    while ((!(scanf("%f", &y))) == 1) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    x = y * pi / 180;
    printf("Enter E: ");
    while ((!(scanf("%f", &E))) == 1) {
        printf("Try again: ");
        while (getchar() != '\n') {}
    }
    printf("sin is %f\n", sin(x));
    printf("N is %d\n", foundN(x, E));
    system("pause");
    return 0;
}

int fact(int N) {
    if (N == 1) return 1;
    return fact(N - 1) * N;
}

int foundN(double x, double E) {
    double comparison, right = 0;
    int N = 1;
    do {
        right += pow(-1, N - 1) * pow(x, 2 * N - 1) / fact(2 * N - 1);
        comparison = fabs(sin(x) - right);
        N++;
    } while (comparison > E);
    printf("Taylor is %f\n", right);
    return N - 1;
}