/*��Ȩ�� ��������    ��f(x) ��  xk�����Ľ�*/
#include<stdio.h>
#include<math.h>

/*��������*/
double fai(double x);
double dfai(double x);

/*����������*/
int main()
{
	double x0;/*��ֵ*/
	double x1;/*�������ֵ*/
	double L;
	
	printf("�������ʼֵx0=");
	scanf("%lf",&x0); 
	L=dfai(x0);/*Ȩ*/
	printf("L=%lf\n",L);
	/*����*/
	while(1)
	{
		x1=1/(1-L)*(fai(x0)-L*x0);
		printf("xk=%lf\n",x1);
		/*�жϾ���*/
		if(fabs(x1-x0)<0.0001)
		{
			printf("\n####################\n");
			printf("���յĽ��Ϊx=%lf\n",x1);
			break;
		}
		x0=x1;
	}
	return 0;
}

double fai(double x)/*x = fai(x)*/
{
	return exp(-x);
}

double dfai(double x)/*fai(x) �ĵ���*/
{
	return -exp(-x);
}

