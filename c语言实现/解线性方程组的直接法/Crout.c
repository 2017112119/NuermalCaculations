/*Crout分解  U主对角线元素为 1*/
#include<stdio.h>
/*函数声明*/
double sum(double L[100][100],double U[100][100],int i,int j,int n);
double outMat(double A[100][100],int n);
int main()//定义主函数 
{
	double A[100][100];/*矩阵A*/
	double L[100][100];/*矩阵L*/
	double U[100][100];/*矩阵U*/
	int i,j,r,k;/*计数*/
	int n;/*矩阵维数*/
	/*输入*/
	printf("请输入矩阵维数n=");
	scanf("%d",&n);
	printf("请输入n阶矩阵A：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	/*初始化*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			L[i][j]=0;
			U[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		U[i][i]=1;
	}
	/*分解*/
	for(r=0;r<n;r++)/**/
	{
		for(i=r;i<n;i++)
		{
			L[i][r]=A[i][r]-sum(L,U,i,r,r);
		}
		for(j=r+1;j<n;j++)/*urj*/
		{
			U[r][j]=(A[r][j]-sum(L,U,r,j,r))/L[r][r];
		}
	}
	/*输出*/
	printf("Crout分解如下：\n");
	printf("矩阵L如下：\n");
	outMat(L,n);
	printf("矩阵U如下：\n");
	outMat(U,n);
	return 0;
	
	
}

double sum(double L[100][100],double U[100][100],int i,int j,int n)/*i行与j列相乘 矩阵为n阶*/
{
	double res=0;/*结果*/
	int m;/*计数*/
	for(m=0;m<n;m++)
	{
		res+=L[i][m]*U[m][j];
	}
	return res;
	
}

double outMat(double A[100][100],int n)/*矩阵输出*/
{
	int i,j;/*计数*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf    ",A[i][j]);
		}
		printf("\n");
	}
}
