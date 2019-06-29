/*���ݷ�*/
#include<stdio.h>
#include<math.h>
#define N 100

/*����ȫ�ֱ���*/
double A[N][N];/*����A*/
double A_n[N][N];/*�������*/
double x[N];/*����*/
void mul();/*��������*/
double max(int n);
double getA(double arcs[N][N],int n);
void getAStart(double arcs[N][N],int n,double ans[N][N]);

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

int main()
{
	double a;/*�洢����� ����ʽֵ*/
	int i,j;/*����*/
	double uk[100];/*uk=max(x)*/
	int n;
	/*���� n*/
	printf("���������Ľ���n=");
	scanf("%d",&n);
	
	/*��ʼ��*/
	for(i=0;i<n;i++)
	{
		uk[i]=0;
		x[i]=1;
		for(j=0;j<n;j++)
		{
			A_n[i][j]=0;
		}
		
	}

	/*���� A*/
	printf("������ %d X %d �ľ���A:\n",n,n);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%lf",&A[i][j]);
		}
	}
	
	/*����ȫ����*/
	double astar[N][N];/*����������*/
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
	
	printf("����A�������£�\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf    ",A_n[i][j]);
		}
		printf("\n");
	}
	printf("###############\n");
	
	/*����*/
	int c=0;/*��¼��������*/
	uk[0]=1;/*uk[0]*/
	printf("����A������ֵ�����������������£�\n");
	while(1)
	{
		
		mul(n);/*����*/
		uk[c+1]=max(n);
		
		/*���*/
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
		
		if(fabs(uk[c+1]-uk[c])<0.000001)/*�ж��Ƿ�����*/
		{
			printf("��������Ϊn = %d",c+1);
			break;
		}
		c++;
		
	}


}


double max(int n)/*n ��ʾ�б�Ԫ�ظ���*/
{
	double max=0;/*�洢���ֵ*/
	int i;/*����*/
	
	/*Ѱ�����ֵ*/
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
	int i,j;/*����*/
	double ans[100];/*Ax�Ľ��*/
	
	/*��ʼ��  ans[100]*/
	for(i=0;i<n;i++)
	{
		ans[i]=0;
	}
	
	/*����*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			ans[i]+=A_n[i][j]*x[j];
		}
	}
	
	/*���¸�ֵ�� x*/
	for(i=0;i<n;i++)
	{
		x[i]=ans[i];
	}
}
