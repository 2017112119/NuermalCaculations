/*ţ����ɽ��*/
#include<stdio.h>
#include<math.h>

/*��������*/
double f(double x);
double df(double x);

int main()
{
	double x0;/*��ʼֵ*/
	double x1;/*��x0�����õ��� ֵ*/
	double lam=1;/*��ɽ����*/
	int num=0;/*��¼��������*/
	printf("�������ʼֵx0=");
	scanf("%lf",&x0);
	
	/*����*/ 
	while(1)
	{
		lam=1;/*ÿ�ζ���1 ��ʼ*/
		x1=x0-lam*f(x0)/df(x0);/*����*/ 
		printf("num=%d,lam=%lf , xk=%lf , f(xk) = %lf\n",num,lam,x1,f(x1));
		while(fabs(f(x1))>fabs(f(x0)))
		{
			lam=lam/2;
			x1=x0-lam*f(x0)/df(x0);
			printf("num=%d,lam=%lf , xk=%lf , f(xk) = %lf\n",num,lam,x1,f(x1));
		}
		
		if(fabs(x1-x0)<0.00000001)
		{
		printf("������ɣ�\n");
		break;
		}
		else
		{
			x0=x1;
			num++;/*��¼��������*/
		}
	}
	
}

/*���庯��*/
double f(double x)
{
	return pow(x,3)/3-x;
}
/*���庯��*/
double df(double x)
{
	return x*x-1;
}
