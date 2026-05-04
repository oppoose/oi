#include <stdio.h>
#include <math.h>

double f(double a3, double a2, double a1, double a0, double x) {
    return ((a3*x + a2)*x + a1)*x + a0;
}

double df(double a3, double a2, double a1, double x) {
    return (3*a3*x + 2*a2)*x + a1;
}

int main() {
    double a3, a2, a1, a0;
    double L, R;
    scanf("%lf %lf %lf %lf", &a3, &a2, &a1, &a0);
    scanf("%lf %lf", &L, &R);

    double x = (L + R) / 2;

    for (int i = 0; i < 100; i++) {
        double fx = f(a3,a2,a1,a0,x);
        double dfx = df(a3,a2,a1,x);

        if (fabs(dfx) < 1e-12) {
            x = (L + R) / 2;
        } else {
            double x_new = x - fx / dfx;

            if (x_new < L || x_new > R) {
                x_new = (L + R) / 2;
            }

            if (f(a3,a2,a1,a0,L) * f(a3,a2,a1,a0,x_new) < 0) {
                R = x_new;
            } else {
                L = x_new;
            }

            x = x_new;
        }

        if (fabs(f(a3,a2,a1,a0,x)) < 1e-10) break;
    }
    printf("%.2f\n", x);
    return 0;
}
