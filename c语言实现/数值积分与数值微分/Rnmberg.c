/*Romberg�㷨   */
#include<stdio.h>
#include<math.h>
#define PI 3.1415926
double f(double x)
{
	double ans;
	ans=sin(x)/x;
	if(x==0)
	{
		return 1;
	}
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
		If+=(h/90)*(7*f(a+i*h)+32*f(a+(i+1/4)*h)+12*f(a+(i+1/2)*h)+32*f(a+(i+3/4)*h)+7*f(a+(i+1)*h));/*�ۼ������*/
	}
	return If;
}
int main()
{
	double a,b;/*��������*/
	printf("�������������(a,b):");
	scanf("%lf%lf",&a,&b);
	int n=10000;/*�ָ����*/
	double R;/*���������*/
	R=64/63*I(a,b,2*n)-1/63*I(a,b,n);
	printf("����ֵΪR=%lf",R);
	
}
