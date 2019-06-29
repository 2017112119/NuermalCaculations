/*Cholesky分解 平方根法*/

#include<stdio.h>
#include<math.h>

/*函数声明*/
double sum(double L[100][100],double U[100][100],int i,int j,int n);
double outMat(double A[100][100],int n);
int main()
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

	/*分解*/
	for(r=0;r<n;r++)/**/
	{
		L[r][r]=sqrt(A[r][r]-sum(L,U,r,r,r));
		U[r][r]=L[r][r];
		for(i=r+1;i<n;i++)
		{
			L[i][r]=(A[i][r]-sum(L,U,i,r,r))/L[r][r];
			U[r][i]=L[i][r];
		}
		
	}
	/*输出*/
	printf("Cholesky分解如下：\n");
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
