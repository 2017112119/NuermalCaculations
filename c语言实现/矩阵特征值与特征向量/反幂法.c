/*反幂法*/
#include<stdio.h>
#include<math.h>
#define N 100

/*定义全局变量*/
double A[N][N];/*矩阵A*/
double A_n[N][N];/*矩阵的逆*/
double x[N];/*向量*/
void mul();/*函数声明*/
double max(int n);
double getA(double arcs[N][N],int n);
void getAStart(double arcs[N][N],int n,double ans[N][N]);

double getA(double arcs[N][N],int n)//按第一行展开计算|A|
{
	if(n==1)
	{
		return arcs[0][0];
	}
	double ans = 0;
	double temp[N][N];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			for(k=0;k<n-1;k++)
			{
				temp[j][k] = arcs[j+1][(k>=i)?k+1:k];
				
			}
		}
		double t = getA(temp,n-1);
		if(i%2==0)
		{
			ans += arcs[0][i]*t;
		}
		else
		{
			ans -=  arcs[0][i]*t;
		}
	}
	return ans;
}
void getAStart(double arcs[N][N],int n,double ans[N][N])//计算每一行每一列的每个元素所对应的余子式，组成A*
{
	if(n==1)
	{
		ans[0][0] = 1;
		return;
	}
	int i,j,k,t;
	double temp[N][N];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n-1;k++)
			{
				for(t=0;t<n-1;t++)
				{
					temp[k][t] = arcs[k>=i?k+1:k][t>=j?t+1:t];
				}
			}
 
		
			ans[j][i]  =  getA(temp,n-1);
			if((i+j)%2 == 1)
			{
				ans[j][i] = - ans[j][i];
			}
		}
	}
}

int main()
{
	double a;/*存储矩阵的 行列式值*/
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
		x[i]=1;
		for(j=0;j<n;j++)
		{
			A_n[i][j]=0;
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
	
	/*求逆全过程*/
	double astar[N][N];/*定义伴随矩阵*/
	a = getA(A,n);
	if(a==0)
	{
		printf("can not transform!\n");
	}
	else
	{
		getAStart(A,n,astar);
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				A_n[i][j]=astar[i][j]/a;
			}
		}
	}
	
	printf("矩阵A的逆如下：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf    ",A_n[i][j]);
		}
		printf("\n");
	}
	printf("###############\n");
	
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
			ans[i]+=A_n[i][j]*x[j];
		}
	}
	
	/*重新赋值给 x*/
	for(i=0;i<n;i++)
	{
		x[i]=ans[i];
	}
}
