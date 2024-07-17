#include <stdio.h>
double fact(int n)
{
    if (n == 1)
        return 1;
    else
    {
        return n * fact(n - 1);
    }
}
double ufact(double u, int n)
{
    if (n == 1)
        return u;
    else
    {
        return (u - (n - 1)) * ufact(u, (n - 1));
    }
}
int main()
{
    double a[50][50];
    int i, j, n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the value of x and y: ");
    for (i = 0; i < n; i++)
    {
        scanf("%lf %lf", &a[i][0], &a[i][1]);
    }
    printf("The value x and y: ");
    for (i = 0; i < n; i++)
    {
        printf("%lf %lf", a[i][0], a[i][1]);
        printf("\n");
    }

    printf("The result:\n");
    for (int j = 2; j < (2 + n - 1); j++)
    {
        for (int i = 0; i < (n - 1); i++)
        {
            a[i][j] = a[i + 1][j - 1] - a[i][j - 1];
        }
    }

    int k = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (2 + n - 1) - k; j++)
        {
            printf("%lf ", a[i][j]);
        }
        k++;
        printf("\n");
    }
    double x, h, u, x_0;
    // find H
    h = a[1][0] - a[0][0];
    // find x0
    x_0 = a[0][0];
    while (1)
    {
        printf("\nEnter the value of X: ");
        scanf("%lf", &x);
        u = (x - x_0) / h;
        // store y0
        double res = a[0][1];
        for (int j = 1; j < n; j++)
        {
            double intp = (ufact(u, j) * a[0][j + 1]) / fact(j);
            res = res + intp;
        }
        printf("The value f(%lf) is: %lf ", x, res);
    }
}