/*  4��Ronge-Kutta�� */
#include<stdio.h>

/*���庯��f(x,y)*/
double f(double x,double y)
{
	return x*x-y;
}

/*����  ������*/
int main()
{
	double y[100];/*�洢���*/
	double x0;/*��ֵ��Ӧ��x0*/ 
	double h;/*����*/
	int n;/*����*/
	int i;/*����*/
	printf("�������ֵx0�Լ���Ӧy(x0):");
	scanf("%lf%lf",&x0,&y[0]);/*��ȡ����*/
	printf("�����벽��h:");
	scanf("%lf",&h);
	printf("��������Ҫ���ж��ٲ�:n=");
	scanf("%d",&n);
	/*����*/
	printf("4��Ronge-Kutta�� ������Ϊ 4 \n");
	double k1,k2,k3,k4;
	for(i=0;i<n;i++)
	{
		k1=f(x0+i*h,y[i]);
		k2=f(x0+i*h+h/2,y[i]+h/2*k1);
		k3=f(x0+i*h+h/2,y[i]+h/2*k2);
		k4=f(x0+i*h+h,y[i]+h*k3);
		y[i+1]=y[i]+h/6*(k1+2*k2+2*k3+k4);
	}
	/*������*/
	for(i=0;i<n+1;i++)
	{
		printf("x=%lf,y=%lf\n",x0+i*h,y[i]);
	}
	
	return 0;
}
