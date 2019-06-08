//Jacobi迭代法
#include<stdio.h>
#include<math.h>

float sum(int n,float list[100],float x[100]);
float add(int n,float list[100]);
int main()
{
	float a[20][20];
	int n;						//矩阵阶数为n 
	int i,j,k;
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
	
	
	//根据  G  的大小判断是否收敛
	float G[100][100]; //初始化
	
	//求G 
	for(i=0;i<n;i++)
	{
		//对角线元素为0 
		G[i][i]=0;
		//上三角 
		for(j=i+1;j<n;j++)
		{
			G[i][j]=-a[i][j]/a[i][i];
		}
		//下三角 
		for(j=0;j<i;j++)
		{
			G[i][j]=-a[i][j]/a[i][i];
		}
	}
	
	//输出  G
	printf("G 如下： \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f    ",G[i][j]);
		}
		printf("\n");
	} 
	
	//求G的无穷范数
	float max;//  无穷范数
	for(i=0;i<n;i++)
	{
		float a_s;//初始化和 
		a_s=add(n,G[i]);//求每行的元素绝对值之和 
			//printf("a_s=%f\n",a_s);
		
		//求最大范数 
		if(a_s>max)
		{
			max=a_s;
			//printf("max=%f",max);
		}
		
	}
	
	//根据 G 判断是否收敛
	if(max>=1)
	{
		printf("||G||=%f,jacobi迭代不收敛\n",max);
	}
	else
	{
		printf("||G||=%f,,jacobi迭代收敛\n",max);
	}
	 
	//输入迭代次数 
	int m;
	printf("请输入迭代次数m:");
	scanf("%d",&m);
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			float s;//求积  
			s= sum(n,a[j],x[i-1]);						//求积 
			x[i][j]=-1*(s-a[j][j]*x[i-1][j]-b[j])/a[j][j];//迭代 
		}
	}
	
	//输出迭代结果
	
	//第一行   x0  x1  x2  ... xn 
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
 
 //向量元素绝对值之和
float add(int n,float list[100])
{
	int i;
	float a_sum = 0;//和的初始化
	
	//求和 
	for(i=0;i<n;i++)
	{
		a_sum+=fabs(list[i]);
	}
 	
 	return a_sum;
} 
