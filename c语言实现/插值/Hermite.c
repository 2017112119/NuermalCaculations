/*
��������Hermite��ֵ 
*/
#include<stdio.h>

int main()
{
	double a[4][2];//�洢����    ����Ϊ�����ڵ�   �Լ������ڵ� �ĵ���
	int i,j;
	
	//�������ݲ��洢��a�� 
	printf("���������ݣ�ǰ����Ϊ�ڵ� ��������Ϊ��������\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	
	double x;//Ҫ���x
	printf("��������Ҫ���x��");
	scanf("%lf",&x);
	
	double L[2];//�洢 Ln[x]��ֵ 
	L[0]=(x-a[1][0])/(a[0][0]-a[1][0]);
	L[1]=(x-a[0][0])/(a[1][0]-a[0][0]);
	
	double alp[2];
	alp[0]=(1+2*L[1])*(L[0]*L[0]);
	alp[1]=(1+2*L[0])*(L[1]*L[1]);
	
	double beta[2];
	beta[0]=(x-a[0][0])*(L[0]*L[0]);
	beta[1]=(x-a[1][0])*(L[1]*L[1]);
	
	double res;
	res=a[0][1]*alp[0]+a[1][1]*alp[1]+a[2][1]*beta[0]+a[3][1]*beta[1];
	
	printf("������Ϊ��%lf",res);
}
