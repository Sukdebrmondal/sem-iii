#include <stdio.h>
int main()
{
    float a[50][50];
    int i, j, n;
    printf("Enter the number of terms: ");
    scanf("%d", &n);

    printf("Enter the value of x and y: ");
    for (i = 0; i < n; i++)
    {
        scanf("%f %f", &a[i][0], &a[i][1]);
    }
    printf("The value x and y: ");
    for (i = 0; i < n; i++)
    {
        printf("%f %f", a[i][0], a[i][1]);
        printf("\n");
    }

    printf("The result:\n");
    for(int j=2;j<(2+n-1);j++){
        for(int i=0;i<(n-1);i++){
            a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
    }

    int k = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<(2+n-1)-k;j++){
            printf("%f ",a[i][j]);
        }
        k++;
        printf("\n");
    }

}