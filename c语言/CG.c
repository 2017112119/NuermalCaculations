/*
CG���������ݶȷ��� 
�����Ϲ����ݶȷ����޲���ֹ 
(1)��ȡx(0), r(0)=b-Ax(0),   p(0)=r(0)
(2) ���� a(k)=(r(k),p(k))/(A*p(k),p(k)),    x(k+1)=x(k)+a(k)*p(k)
(3) r(k+1) = r(k)-a(k)*A*p(k),       beta(k)=(r(k+1),r(k+1))/(r(k),r(k))   p(k+1)=r(k+1)+beta(k)*p(k)

*/ 

#include<stdio.h>

//�������� 
float sum(int n,float list[100],float x[100]);

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
	
	//����������� 
	int m;
	printf("�������������m:");
	scanf("%d",&m);
	
	//x�Ľ�� 
	float x[30][n];
	for(i=0;i<n;i++)
	{
		x[0][i]=0.00;//�����ĳ�ֵ 
	}
	
	float r[100][100];// r��ʾ�ݶȷ��� 
	float p[100][100];// p��ʾ
	float alpha[100];// 
	float beta[100];
	float Ap[100][100];//����A*p(k)��ֵ 
	//����r(0)  p(0)
	 
	for(i=0;i<n;i++)
	{
		
		r[0][i]=b[i]-sum(n,a[i],x[0]);
		
	}//r(0)�ļ���
	
	//p(0)�ļ���
	for(i=0;i<n;i++)
	{
		p[0][i]=r[0][i];
	}
	
	
	//��������
	for(i=0;i<m;i++)
	{
		//����Ap(i) 
		for(j=0;j<n;j++)
			Ap[i][j]=sum(n,a[j],p[i]);
			
		//����alpha(k) 
		alpha[i]=sum(n,r[i],p[i])/sum(n,Ap[i],p[i]);
		
		//����x(k+1)
		for(k=0;k<n;k++)
		{
			x[i+1][k]=x[i][k]+alpha[i]*p[i][k];
		}
		
		//����r(k+1)
		for(k=0;k<n;k++)
		{
			r[i+1][k]=r[i][k]-alpha[i]*Ap[i][k];
		}
		
		//����beta(k)
		beta[i]=sum(n,r[i+1],r[i])/sum(n,r[i],r[i]);
		
		//����p(k+1)
		for(j=0;j<n;j++)
		{
			p[i+1][j]=r[i+1][j]+beta[i]*p[i][k];
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
