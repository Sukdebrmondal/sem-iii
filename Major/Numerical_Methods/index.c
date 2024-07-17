#include <stdio.h>
int main()
{
   

    int i,j,n;
    printf("Enter the terms : ");
    scanf("%d",&n);

    float a[50][50];
    printf("Enter the value of x:\n ");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i][0]);
    }
    printf("Enter the value of y:\n ");
    for(int i=0;i<n;i++){
        scanf("%f",&a[i][1]);
    }
    
    for(int j=2;j<(2+n-1);j++){
        for(int i=0;i<n-1;i++){
            a[i][j]=a[i+1][j-1]-a[i][j-1];
        }
    }
    int k=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<(2+n-1)-k;j++){
            printf("%f ",a[i][j]);
        }
        k++;
        printf("\n");
    }
    
    return 0;
}