/*ŷ����  Euler method*/
#include<stdio.h>

/*����f(x,y)*/
double f(double x,double y)
{
	return y-2*x/y;
}
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
	printf("Euler Method ������Ϊ 1 \n");
	for(i=0;i<n;i++)
	{
		y[i+1]=y[i]+h*f(x0+i*h,y[i]);
	}
	/*������*/
	for(i=0;i<n+1;i++)
	{
		printf("x=%lf,y=%lf\n",x0+i*h,y[i]);
	}
	
	return 0;
	
}
