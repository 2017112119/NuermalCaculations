/*�ҽط�  ���ò��� ����*/
#include<stdio.h>
#include<math.h>

/*��������*/
double f(double x);

/*����f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}



/*����������*/
int main()
{
	double x0;/*��ֵ*/
	double x[100];/*�洢���е�x*/
	double m;/*�м�ֵ*/
	int i=0;/*��¼��������*/
	printf("�����벻�������x�ĳ�ʼֵx0=");
	scanf("%lf",&x0);/*�����ֵ*/
	x[0]=x0;
	x[1]=x0+0.1;
	
	/*����*/
	while(1)
	{
		x[i+2]=x[i+1]-f(x[i+1])*(x[i+1]-x[i])/(f(x[i+1])-f(x[i]));
		i++;
		printf("������%d�εĽ��Ϊ��x(%d)=%lf\n",i,i,x[i+1]);
		if(fabs(x[i+1]-x[i])<0.0000001)
		{
			break;
		}
	}
}
