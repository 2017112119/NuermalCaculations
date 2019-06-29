/*复化梯形公式*/
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
	double h;/*步长*/
	double If=0;/*积分值*/
	h=(b-a)/n;
	int i;
	for(i=0;i<n;i++)
	{
		If+=(h/2)*(f(a+i*h)+f(a+(i+1)*h));/*累加求积分*/
	}
	return If;
}
int main()
{
	double a,b;/*积分区间*/
	printf("请输入积分区间(a,b):");
	scanf("%lf%lf",&a,&b);
	printf("请输入您的等分个数n:");
	int n=10000;
	double res;
	res=I(a,b,n);
	printf("积分值为%lf",res);
	
}
