/*����������*/

#include<stdio.h>
#include<math.h> 
#define N 100

double getA(double arcs[N][N],int n);
void getAStart(double arcs[N][N],int n,double ans[N][N]);
double Norm(double A[100][100],int n,int choice);

int main()
{
	double A[100][100];/*����A*/
	int i,j;/*����*/
	int n;/*����ά��*/
	int choice;/*ѡ��*/
	
	/*����*/
	printf("���������ά��n=");
	scanf("%d",&n);
	printf("������n�׾���A��\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	/*��A����*/
	double astar[N][N];/*����������*/
	double A_n[N][N];/*A����*/
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
	/*����������*/
	while(1)
	{
	printf("1.�з������������.\n");
	printf("2.�з���.��1-������\n");
	printf("3.2-����.\n");
	printf("���������������˳���\n");
	printf("���������ѡ��");
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

double Norm(double A[100][100],int n,int choice)/*����n�׾���A�ķ���*/
{
	double res=0;/*�洢���*/
	double max=0;
	int i,j;/*����*/
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

double getA(double arcs[N][N],int n)//����һ��չ������|A|
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
void getAStart(double arcs[N][N],int n,double ans[N][N])//����ÿһ��ÿһ�е�ÿ��Ԫ������Ӧ������ʽ�����A*
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
