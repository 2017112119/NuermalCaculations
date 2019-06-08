/* Lagrange Interpolation Method*/
#include<stdio.h>
#include <stdlib.h>
int main()
{
	int n;//结点个数
	int i,j;//计数 
	//double data[100][2];//存放数据 
	//double *p=data;
	double ** data;
	printf("请输入结点个数n: ");
	scanf("%d",&n); 
    data=(double**)malloc(n*sizeof(double*));
 
    for(i=0;i<n;i++){
        data[i]=(double*)malloc(2*sizeof(double));
    }
	printf("请输入结点的坐标（x,y）每行一组：\n");
	
	//获取输入 
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		scanf("%lf",&data[i][j]);
	}
	
	double x;
	printf("请输入所要求的目标点的x值：");
	scanf("%lf",&x);
	
	double sum=0;
	double L[100];
	for(i=0;i<n;i++)
	{
		L[i]=1;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			L[i]*=(x-data[j][0])/(data[i][0]-data[j][0]);
		}
		for(j=i+1;j<n;j++)
		{
			L[i]*=(x-data[j][0])/(data[i][0]-data[j][0]);
		}
		
		sum+=L[i]*data[i][1];
	}
	
	printf("插值多项式在x处的值为：y=");
	printf("%lf",sum);
	
}

//double L(int i,)
