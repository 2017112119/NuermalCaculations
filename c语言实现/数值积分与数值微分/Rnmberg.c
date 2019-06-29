/*Romberg算法   */
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
	double h;/*步长*/
	double If=0;/*积分值*/
	h=(b-a)/n;
	int i;
	for(i=0;i<n;i++)
	{
		If+=(h/90)*(7*f(a+i*h)+32*f(a+(i+1/4)*h)+12*f(a+(i+1/2)*h)+32*f(a+(i+3/4)*h)+7*f(a+(i+1)*h));/*累加求积分*/
	}
	return If;
}
int main()
{
	double a,b;/*积分区间*/
	printf("请输入积分区间(a,b):");
	scanf("%lf%lf",&a,&b);
	int n=10000;/*分割分数*/
	double R;/*龙贝格积分*/
	R=64/63*I(a,b,2*n)-1/63*I(a,b,n);
	printf("积分值为R=%lf",R);
	
}
