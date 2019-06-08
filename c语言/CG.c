/*
CG法（共轭梯度法） 
理论上共轭梯度法有限步终止 
(1)任取x(0), r(0)=b-Ax(0),   p(0)=r(0)
(2) 计算 a(k)=(r(k),p(k))/(A*p(k),p(k)),    x(k+1)=x(k)+a(k)*p(k)
(3) r(k+1) = r(k)-a(k)*A*p(k),       beta(k)=(r(k+1),r(k+1))/(r(k),r(k))   p(k+1)=r(k+1)+beta(k)*p(k)

*/ 

#include<stdio.h>

//函数声明 
float sum(int n,float list[100],float x[100]);

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
	
	//输入迭代次数 
	int m;
	printf("请输入迭代次数m:");
	scanf("%d",&m);
	
	//x的结果 
	float x[30][n];
	for(i=0;i<n;i++)
	{
		x[0][i]=0.00;//迭代的初值 
	}
	
	float r[100][100];// r表示梯度方向 
	float p[100][100];// p表示
	float alpha[100];// 
	float beta[100];
	float Ap[100][100];//储存A*p(k)的值 
	//计算r(0)  p(0)
	 
	for(i=0;i<n;i++)
	{
		
		r[0][i]=b[i]-sum(n,a[i],x[0]);
		
	}//r(0)的计算
	
	//p(0)的计算
	for(i=0;i<n;i++)
	{
		p[0][i]=r[0][i];
	}
	
	
	//迭代计算
	for(i=0;i<m;i++)
	{
		//计算Ap(i) 
		for(j=0;j<n;j++)
			Ap[i][j]=sum(n,a[j],p[i]);
			
		//计算alpha(k) 
		alpha[i]=sum(n,r[i],p[i])/sum(n,Ap[i],p[i]);
		
		//计算x(k+1)
		for(k=0;k<n;k++)
		{
			x[i+1][k]=x[i][k]+alpha[i]*p[i][k];
		}
		
		//计算r(k+1)
		for(k=0;k<n;k++)
		{
			r[i+1][k]=r[i][k]-alpha[i]*Ap[i][k];
		}
		
		//计算beta(k)
		beta[i]=sum(n,r[i+1],r[i])/sum(n,r[i],r[i]);
		
		//计算p(k+1)
		for(j=0;j<n;j++)
		{
			p[i+1][j]=r[i+1][j]+beta[i]*p[i][k];
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
