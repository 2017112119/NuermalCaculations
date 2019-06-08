#include <stdio.h>
#include <stdlib.h>
 
int main()
{
    int r,c;
    printf("row column\n");
    scanf("%d %d",&r,&c);
 	int i,j;
    int ** a;
    a=(int**)malloc(r*sizeof(int*));
 
    for(i=0;i<r;i++){
        a[i]=(int*)malloc(c*sizeof(int));
    }
 
    printf("input\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("(%d,%d)",i,j);
            scanf("%d",&a[i][j]);
        }
    }
 
    printf("output\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
	T(a,r,c);
    return 0;
}

int T(int **a,int r,int c)
{
	int i,j;
	printf("output\n");
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            printf("%d\t",a[j][i]);
        }
        printf("\n");
    }
}
