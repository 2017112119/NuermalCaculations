/*���������*/
#include<stdio.h>
#include<math.h>

/*��������*/
double fa(double x);

/*��f(x)=0  ��Ϊ   fa(x)=x*/
/*���岻���㺯��*/
double fa(double x)
{
	return pow(x+1,1.0/3);
}

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
