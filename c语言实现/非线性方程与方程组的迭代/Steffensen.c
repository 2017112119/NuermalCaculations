/*Aitken������Steffensen���� */
#include<stdio.h>
#include<math.h>

/*��������*/
double fai(double x);

/*����������*/
int main()
{
	double x0;/*��ֵ*/
	double x1;/*�������ֵ*/
	double x2;/**/
	int num=0;/*��������*/
	
	printf("�������ʼֵx0=");
	scanf("%lf",&x0); 
	/*����*/
	while(1)
	{
		/*���� ��ʽ*/
		x1=fai(x0);
		x2=fai(x1);
		x1=x0-(x1-x0)*(x1-x0)/(x2-2*x1+x0);
		num++;
		
		/*�����ж�*/
		if(fabs(x1-x0)<0.00001)
		{
			printf("���ս��Ϊ��x=%lf\n",x1);
			printf("��������Ϊ��n=%d\n",num);
			break;
		}
		/*����*/
		x0=x1;
	}
	return 0;
}

double fai(double x)/*x = fai(x)*/
{
	return exp(-x);
}

