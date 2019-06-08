//Jacobi������
#include<stdio.h>
#include<math.h>

float sum(int n,float list[100],float x[100]);
float add(int n,float list[100]);
int main()
{
	float a[20][20];
	int n;						//�������Ϊn 
	int i,j,k;
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
	
	
	//����  G  �Ĵ�С�ж��Ƿ�����
	float G[100][100]; //��ʼ��
	
	//��G 
	for(i=0;i<n;i++)
	{
		//�Խ���Ԫ��Ϊ0 
		G[i][i]=0;
		//������ 
		for(j=i+1;j<n;j++)
		{
			G[i][j]=-a[i][j]/a[i][i];
		}
		//������ 
		for(j=0;j<i;j++)
		{
			G[i][j]=-a[i][j]/a[i][i];
		}
	}
	
	//���  G
	printf("G ���£� \n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%f    ",G[i][j]);
		}
		printf("\n");
	} 
	
	//��G�������
	float max;//  �����
	for(i=0;i<n;i++)
	{
		float a_s;//��ʼ���� 
		a_s=add(n,G[i]);//��ÿ�е�Ԫ�ؾ���ֵ֮�� 
			//printf("a_s=%f\n",a_s);
		
		//������� 
		if(a_s>max)
		{
			max=a_s;
			//printf("max=%f",max);
		}
		
	}
	
	//���� G �ж��Ƿ�����
	if(max>=1)
	{
		printf("||G||=%f,jacobi����������\n",max);
	}
	else
	{
		printf("||G||=%f,,jacobi��������\n",max);
	}
	 
	//����������� 
	int m;
	printf("�������������m:");
	scanf("%d",&m);
	for(i=1;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			float s;//���  
			s= sum(n,a[j],x[i-1]);						//��� 
			x[i][j]=-1*(s-a[j][j]*x[i-1][j]-b[j])/a[j][j];//���� 
		}
	}
	
	//����������
	
	//��һ��   x0  x1  x2  ... xn 
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
 
 //����Ԫ�ؾ���ֵ֮��
float add(int n,float list[100])
{
	int i;
	float a_sum = 0;//�͵ĳ�ʼ��
	
	//��� 
	for(i=0;i<n;i++)
	{
		a_sum+=fabs(list[i]);
	}
 	
 	return a_sum;
} 
