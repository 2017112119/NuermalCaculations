//��SOR����γ��ɳڵ�����
/*wΪ�ɳ����ӣ���wΪ1ʱ����ΪGauss-Seidel��������һ��Ϊ�˱�֤��������������Ҫ��
0<w<2. ��0<w<1ʱ��Ϊ���ɳڷ��� ��1<w<2ʱ��Ϊ���ɳڷ���ͨ��ͳ��Ϊ���ɳڷ���SOR��*/ 
#include<stdio.h>

float sum(int n,float list[100],float x[100]);//�������� 


int main()
{
	float a[20][20];
	int n;						//�������Ϊn 
	int i,j;
	printf("��������������");
	scanf("%d",&n);
	
	//�������� 
	printf("���������A\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
			scanf("%f",&a[i][j]); 
	}
	
	//����b
	float b[n];					//b
	printf("������b:\n");
	for(i=0;i<n;i++)
	{
		scanf("%f",&b[i]);
	 }
	
	
	//x�Ľ�� 
	float x[30][n];
	for(i=0;i<n;i++)
	{
		x[0][i]=0.00;//�����ĳ�ֵ 
	}
	
	//����������� 
	int m;
	printf("�������������m:");
	scanf("%d",&m);
	
	//�����ɳ����� 
	printf("�������ɳ�����w:");
	float w;
	scanf("%f",&w);
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			float s;//���
			s= sum(n,a[j],x[i-1]);
			x[i][j]=(1-w)*x[i-1][j]-1*w*(s-a[j][j]*x[i-1][j]-b[j])/a[j][j];//���� 
			x[i-1][j]=x[i][j];
		}
	}
	
	//����������
	
	//��һ��   x0  x1  x2  ... xn 
	int k;
	printf("      ");
	for(k=0;k<n;k++)
	{
		printf("x%d            ",k);
	}
	printf("\n");
	
	//������  m=i, x0     x1     x2      ..xn 
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
 
 //�����������   (���ȣ�a1i�б�,x1i�б�)
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
