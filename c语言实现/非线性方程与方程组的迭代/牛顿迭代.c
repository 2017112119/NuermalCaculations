/*
ţ�ٵ�����
���ڲ�ͬ����Ŀ ����ֻ��Ҫ�޸�  f(x) ����Ӧ ��  df(x) ���� 
*/
#include<stdio.h>
#include<math.h>

/*��������*/
double fa(double x);
double f(double x);
double df(double x);

/*��f(x)=0  ��Ϊ   fa(x)=x*/
/*���岻���㺯��*/
double fa(double x)
{
	return x-f(x)/df(x);
}

/*����f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}

/*����df(x)  ��ʾ f(x)�ĵ���*/
double df(double x)
{
	return 3*x*x-3;
}

/*����������*/
int main()
{
	double x0;/*��ֵ*/
	double m;/*�м�ֵ*/
	int i=0;/*��¼��������*/
	printf("�����벻�������x�ĳ�ʼֵx0=");
	scanf("%lf",&x0);/*�����ֵ*/
	
	while(1)
	{
		m=x0;
		x0=fa(x0);
		i++;
		printf("������%d�εĽ��Ϊ��x(%d)=%lf\n",i,i,x0);
		if(fabs(m-x0)<0.0000001)
		{
			break;
		}
	}
}
