/*
�����߷�
*/
#include<stdio.h>
#include<math.h>

/*��������*/
double f(double x);
double sgn(double x);/*x>0  ����1   x<0���� -1*/
double t_f(double x1,double x2);/*һ�ײ���*/
double s_f(double x1,double x2,double x3);/*���ײ���*/ 

/*����f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}
/*����sgn(x)*/
double sgn(double x)
{
	if(x>0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

/*����������*/
int main()
{
	int i,j;/*����*/
	int num=0;/*��ʾ��������*/
	double w;
	double x0,x1,x2;/*��ʼֵ*/ 
	double zx1,zx2;/*�м�ֵ*/ 
	
	/*�����ֵ x0  x1 x2*/
	printf("�������ʼֵx0=");
	scanf("%lf",&x0);
	printf("�������ʼֵx1=");
	scanf("%lf",&x1);
	printf("�������ʼֵx2=");/*����x2�� ��ȷ���Ϊ�ӽ�*/
	scanf("%lf",&x2);
	
	/*����*/
	while(1)
	{
		w=t_f(x2,x1)+s_f(x2,x1,x0)*(x2-x1);zx1=x1;zx2=x2;
		x2=x2-2*f(x2)/(w+sgn(w)*sqrt(w*w-4*f(x2)*s_f(x2,x1,x0)));
		num++;
		if(fabs(x2-zx2)<0.00000001)
		{
			printf("���ս��Ϊ��x=%lf\n",x2);
			printf("���յ�������Ϊn=%d",num);
			break;
		}
		x0=zx1;
		x1=zx2;
		
	}
	
}

double t_f(double x1,double x2)/*һ�ײ���*/
{
	return (f(x2)-f(x1))/(x2-x1); 
}

double s_f(double x1,double x2,double x3)/*���ײ���*/
{
	return (t_f(x2,x3)-t_f(x1,x2))/(x3-x1);
}
