/*�������ι�ʽ*/
#include<stdio.h>
#include<math.h>
#define PI 3.1415926

double f(double x)
{
	double ans;
	ans=exp(-x*x/2)/sqrt(2*PI);
	return ans;
}

double I(double a,double b,int n)
{
	double h;/*����*/
	double If=0;/*����ֵ*/
	h=(b-a)/n;
	int i;
	for(i=0;i<n;i++)
	{
		If+=(h/2)*(f(a+i*h)+f(a+(i+1)*h));/*�ۼ������*/
	}
	return If;
}
int main()
{
	double a,b;/*��������*/
	printf("�������������(a,b):");
	scanf("%lf%lf",&a,&b);
	printf("���������ĵȷָ���n:");
	int n=10000;
	double res;
	res=I(a,b,n);
	printf("����ֵΪ%lf",res);
	
}
