/* Lagrange Interpolation Method*/
#include<stdio.h>
#include <stdlib.h>
int main()
{
	int n;//������
	int i,j;//���� 
	//double data[100][2];//������� 
	//double *p=data;
	double ** data;
	printf("�����������n: ");
	scanf("%d",&n); 
    data=(double**)malloc(n*sizeof(double*));
 
    for(i=0;i<n;i++){
        data[i]=(double*)malloc(2*sizeof(double));
    }
	printf("������������꣨x,y��ÿ��һ�飺\n");
	
	//��ȡ���� 
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
		scanf("%lf",&data[i][j]);
	}
	
	double x;
	printf("��������Ҫ���Ŀ����xֵ��");
	scanf("%lf",&x);
	
	double sum=0;
	double L[100];
	for(i=0;i<n;i++)
	{
		L[i]=1;
	}
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			L[i]*=(x-data[j][0])/(data[i][0]-data[j][0]);
		}
		for(j=i+1;j<n;j++)
		{
			L[i]*=(x-data[j][0])/(data[i][0]-data[j][0]);
		}
		
		sum+=L[i]*data[i][1];
	}
	
	printf("��ֵ����ʽ��x����ֵΪ��y=");
	printf("%lf",sum);
	
}

//double L(int i,)
