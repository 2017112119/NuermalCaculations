//（SOR）逐次超松弛迭代法
/*w为松弛因子，当w为1时，便为Gauss-Seidel迭代法，一般为了保证迭代过程收敛，要求
0<w<2. 当0<w<1时称为低松弛法， 当1<w<2时称为超松弛法，通常统称为超松弛法（SOR）*/ 
#include<stdio.h>

float sum(int n,float list[100],float x[100]);//函数声明 


int main()
{
	float a[20][20];
	int n;						//矩阵阶数为n 
	int i,j;
	printf("请输入矩阵阶数：");
	scanf("%d",&n);
	
	//矩阵输入 
	printf("请输入矩阵A\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%f",&a[i][j]); 
	}
	
	//输入b
	float b[n];					//b
	printf("请输入b:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&b[i]);
	 }
	
	
	//x的结果 
	float x[30][n];
	for(i=0;i<n;i++)
	{
		x[0][i]=0.00;//迭代的初值 
	}
	
	//输入迭代次数 
	int m;
	printf("请输入迭代次数m:");
	scanf("%d",&m);
	
	//输入松弛因子 
	printf("请输入松弛因子w:");
	float w;
	scanf("%f",&w);
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			float s;//求和
			s= sum(n,a[j],x[i-1]);
			x[i][j]=(1-w)*x[i-1][j]-1*w*(s-a[j][j]*x[i-1][j]-b[j])/a[j][j];//迭代 
			x[i-1][j]=x[i][j];
		}
	}
	
	//输出迭代结果
	
	//第一行   x0  x1  x2  ... xn 
	int k;
	printf("      ");
	for(k=0;k<n;k++)
	{
		printf("x%d            ",k);
	}
	printf("\n");
	
	//后续行  m=i, x0     x1     x2      ..xn 
	for(i=0;i<m;i++)
	{
		printf("m=%d,",i);
		for(j=0;j<n;j++)
		{
			printf("%f    ",x[i][j]);
		}
		printf("\n");
	}
	
 }
 
 //向量求积函数   (长度，a1i列表,x1i列表)
float sum(int n,float list[100],float x[100])
 {
 	float s=0;
 	int i;
 	for(i=0;i<n;i++)
 	{
 		s=s+list[i]*x[i];
	 }
	
	return s;
 }
