/*矩阵条件数*/

#include<stdio.h>
#include<math.h> 
#define N 100

double getA(double arcs[N][N],int n);
void getAStart(double arcs[N][N],int n,double ans[N][N]);
double Norm(double A[100][100],int n,int choice);

int main()
{
	double A[100][100];/*矩阵A*/
	int i,j;/*计数*/
	int n;/*矩阵维数*/
	int choice;/*选择*/
	
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
	/*求A的逆*/
	double astar[N][N];/*定义伴随矩阵*/
	double A_n[N][N];/*A的逆*/
	double a = getA(A,n-2);
	if(a==0)
	{
		printf("can not transform!\n");
	}
	else
	{
		getAStart(A,n-2,astar);
		for(i=0;i<n-2;i++)
		{
			for(j=0;j<n-2;j++)
			{
				A_n[i][j]=astar[i][j]/a;
			}
		}
	}
	/*条件数计算*/
	while(1)
	{
	printf("1.行范数（无穷范数）.\n");
	printf("2.列范数.（1-范数）\n");
	printf("3.2-范数.\n");
	printf("输入其他数字则退出。\n");
	printf("请输入你的选择：");
	scanf("%d",&choice);
	if(choice==1)
	{
		printf("cond||A||(infinity)=%lf\n",Norm(A,n,choice)*Norm(A_n,n,choice));
	}
	else if(choice==2)
	{
		printf("cond||A||(1)=%lf\n",Norm(A,n,choice)*Norm(A_n,n,choice));
	}
	else if(choice==3)
	{
		printf("cond||A||(2)=%lf\n",Norm(A,n,choice)*Norm(A_n,n,choice));
	}
	else
	{
		break;
	}
	}
	
	
}

double Norm(double A[100][100],int n,int choice)/*计算n阶矩阵A的范数*/
{
	double res=0;/*存储结果*/
	double max=0;
	int i,j;/*计数*/
	if(choice==1)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				res+=fabs(A[i][j]);
			}
			if(res>max)
			{
				max=res;
			}
		}
		return max;
	}
	else if(choice==2)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				res+=fabs(A[j][i]);
			}
			if(res>max)
			{
				max=res;
			}
		}
		return max;
	}
	else if(choice==3)
	{
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				res+=A[i][j]*A[i][j];
			}
		}
		return sqrt(res);
	}
	else
	{
		return;
	}
}

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
