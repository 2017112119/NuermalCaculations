/*
�ݷ�����  ������ ������ֵ �Լ���Ӧ���������� 
*/
#include<stdio.h>
#include<math.h>

/*����ȫ�ֱ���*/
double A[100][100];/*����A*/
double x[100];/*����*/
void mul();/*��������*/
double max(int n);

int main()
{
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
		x[i]=0;
		for(j=0;j<n;j++)
		{
			A[i][j]=0;
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
	
	/*x�ĳ�ʼ��*/
	for(i=0;i<n;i++)
	{
		x[i]=1;
	}
	
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
			ans[i]+=A[i][j]*x[j];
		}
	}
	
	/*���¸�ֵ�� x*/
	for(i=0;i<n;i++)
	{
		x[i]=ans[i];
	}
}
