/*Doolittle�ֽ�  L���Խ���Ԫ��Ϊ1   �൱�� û������Ԫ�ĸ�˹��ȥ��*/
#include<stdio.h>
/*��������*/
double sum(double L[100][100],double U[100][100],int i,int j,int n);
double outMat(double A[100][100],int n);
int main()//���������� 
{
	double A[100][100];/*����A*/
	double L[100][100];/*����L*/
	double U[100][100];/*����U*/
	int i,j,r;/*����*/
	int n;/*����ά��*/
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
	/*��ʼ��*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			L[i][j]=0;
			U[i][j]=0;
		}
	}
	for(i=0;i<n;i++)
	{
		L[i][i]=1;
	}
	/*�ֽ�*/
	for(r=0;r<n;r++)/**/
	{
		
		for(j=r;j<n;j++)/*urj*/
		{
			U[r][j]=(A[r][j]-sum(L,U,r,j,r));
		}
		
		for(i=r+1;i<n;i++)
		{
			L[i][r]=(A[i][r]-sum(L,U,i,r,r))/U[r][r];
		}
	}
	/*���*/
	printf("Crout�ֽ����£�\n");
	printf("����L���£�\n");
	outMat(L,n);
	printf("����U���£�\n");
	outMat(U,n);
	return 0;
	
	
}

double sum(double L[100][100],double U[100][100],int i,int j,int n)/*i����j����� ����Ϊn��*/
{
	double res=0;/*���*/
	int m;/*����*/
	for(m=0;m<n;m++)
	{
		res+=L[i][m]*U[m][j];
	}
	return res;
	
}

double outMat(double A[100][100],int n)/*�������*/
{
	int i,j;/*����*/
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf    ",A[i][j]);
		}
		printf("\n");
	}
}
