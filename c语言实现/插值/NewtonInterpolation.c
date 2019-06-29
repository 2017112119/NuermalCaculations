/*
Newton Interpolation
*/
//������������ n   Ȼ�����������������   �� ע�� ��㲻 ��  ��  ÿ���ڵ㶼��ͬ   
#include<stdio.h>

int main()
{
	double c_s[100][100];//����洢���̵Ķ�ά����
	int n;//�������������
	int i,j;//����
	
	//��ȡn
	printf("��������������n:");
	scanf("%d",&n);
	 
	//��������  �洢��ǰ���� 
	printf("���������ݣ�\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
			scanf("%lf",&c_s[i][j]);
	}
	
	//���̼��� 
	for(j=2;j<1+n;j++)
	{
		for(i=j-1;i<n;i++)
		{
			c_s[i][j]=(c_s[i][j-1]-c_s[i-1][j-1])/(c_s[i][0]-c_s[i-j+1][0]);
		}
	}
	
	//������Ҫ���  x  ����ֵ 
	double x;
	printf("��������Ҫ���x��");
	scanf("%lf",&x);
	
	//��x����ֵ
	double sum=c_s[0][1];//�洢���   f[x0]
	double mul=1;//�˻� 
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			mul=mul*(x-c_s[j][0]);
		}
		sum=sum+c_s[i][i+1]*mul;
		mul=1;
	}
	
	//������̱�
	printf("�õ��Ĳ��̱����£�\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%lf    ",c_s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//������
	printf("��ֵ������x=%lf���ĺ���ֵΪ��%lf",x,sum);
	
	return 0; 
	
}
