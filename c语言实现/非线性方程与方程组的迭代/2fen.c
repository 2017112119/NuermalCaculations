/*���ַ�*/
#include<stdio.h>
#include<math.h>

/*��������*/
double two_fen(double a,double b);
double f(double x); 


/*����f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}
/*���ַ������*/
double two_fen(double a,double b)
{
	double xk,r,L;
	if(f(a)*f(b)>0)
	{
		printf("�ڸ�������û�н�");
	}
	else if(f(a)*f(b)<0)
	{
		
		while(1)
		{
			xk=(a+b)/2;
			if(f(xk)*f(b)<0)
			{
				a=xk;
			}
			else
			{
				b=xk;
			}
			if(fabs(f(xk))<=0.000001)
			{
				printf("���һ�ε��� : (%lf,%lf)  f=%lf\n",a,b,f(xk));
				printf("��õķ��̵Ľ�Ϊx=%lf\n",xk);
				break;
			}
			
			printf("���������� : (%lf,%lf)  f(x)=%lf\n",a,b,f(xk));
		}
		return;
	}
	else if(fabs(f(a))<=1e-6)
	{
		printf("��õķ��̵Ľ�Ϊx=%lf\n",a);
	}
	else if(fabs(f(b))<=1e-6)
	{
		printf("��õķ��̵Ľ�Ϊx=%lf\n",b);
	}
}

int main()
{
	printf("�����������������:");
	double a1,b1;
	scanf("%lf%lf",&a1,&b1);
	two_fen(a1,b1);
	return 0;
}
