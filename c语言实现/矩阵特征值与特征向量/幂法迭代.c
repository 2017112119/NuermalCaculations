/*
幂法迭代  求矩阵的 主特征值 以及对应的特征向量 
*/
#include<stdio.h>
#include<math.h>

/*定义全局变量*/
double A[100][100];/*矩阵A*/
double x[100];/*向量*/
void mul();/*函数声明*/
double max(int n);

int main()
{
	int i,j;/*计数*/
	double uk[100];/*uk=max(x)*/
	int n;
	/*输入 n*/
	printf("请输入矩阵的阶数n=");
	scanf("%d",&n);
	
	/*初始化*/
	for(i=0;i<n;i++)
	{
		uk[i]=0;
		x[i]=0;
		for(j=0;j<n;j++)
		{
			A[i][j]=0;
		}
	}
	
	/*输入 A*/
	printf("请输入 %d X %d 的矩阵A:\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	
	/*x的初始化*/
	for(i=0;i<n;i++)
	{
		x[i]=1;
	}
	
	/*迭代*/
	int c=0;/*记录迭代次数*/
	uk[0]=1;/*uk[0]*/
	printf("矩阵A主特征值与特征向量迭代如下：\n");
	while(1)
	{
		
		mul(n);/*计算*/
		uk[c+1]=max(n);
		
		/*输出*/
		printf("x=");
		for(i=0;i<n;i++)
		{
			printf("%lf    ",x[i]);
		}
		printf("uk=%lf    ",uk[c+1]);
		printf("yk=");
		for(i=0;i<n;i++)
		{
			x[i]=x[i]/uk[c+1];
			printf("%lf    ",x[i]);
		}
		printf("\n");
		
		if(fabs(uk[c+1]-uk[c])<0.000001)/*判断是否收敛*/
		{
			printf("迭代次数为n = %d",c+1);
			break;
		}
		c++;
		
	}
	
}

double max(int n)/*n 表示列表元素个数*/
{
	double max=0;/*存储最大值*/
	int i;/*计数*/
	
	/*寻找最大值*/
	for(i=0;i<n;i++)
	{
		if(fabs(x[i])>max)
		{
			max=fabs(x[i]);
		}
	}
	return max;
}

void mul(int n)/*A*x*/
{
	int i,j;/*计数*/
	double ans[100];/*Ax的结果*/
	
	/*初始化  ans[100]*/
	for(i=0;i<n;i++)
	{
		ans[i]=0;
	}
	
	/*计算*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ans[i]+=A[i][j]*x[j];
		}
	}
	
	/*重新赋值给 x*/
	for(i=0;i<n;i++)
	{
		x[i]=ans[i];
	}
}
