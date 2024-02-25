#include <stdio.h>
#include <stdlib.h>


int main()
{
    int w[10][10], q[10][10];
    int i, j, k, n;
    printf(" Enter the size of the matrix: \n");
    scanf("%d",&n);
    printf(" Enter the value of the matrix: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            scanf("%d",&w[i][j]);
        }
    }

    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            if(w[i][j]==0){
                q[i][j]=111111;
            }
            else{
                q[i][j]=w[i][j];
            }
        }
    }

    printf("The matrix is: \n");
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            printf("\t%d ",q[i][j]);

        }
        printf("\n");
    }

    for(k=0;k<n;k++){
        printf("\nMatrix %d is : \n",k+1);
        for(i=0;i<n;i++){
            for(j=0;j<n;j++){
                if(q[i][j] < (q[i][k]+q[k][j])){
                        q[i][j]=q[i][j];

                }
                else{
                    q[i][j] = q[i][k]+q[k][j];
                }
                printf("\t%d ",q[i][j]);

            }
             printf("\n");
        }
    }
    return 0;
}
