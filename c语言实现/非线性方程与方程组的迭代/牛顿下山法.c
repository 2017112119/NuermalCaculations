/*牛顿下山法*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double f(double x);
double df(double x);

int main()
{
	double x0;/*初始值*/
	double x1;/*由x0迭代得到的 值*/
	double lam=1;/*下山因子*/
	int num=0;/*记录迭代次数*/
	printf("请输入初始值x0=");
	scanf("%lf",&x0);
	
	/*迭代*/ 
	while(1)
	{
		lam=1;/*每次都从1 开始*/
		x1=x0-lam*f(x0)/df(x0);/*迭代*/ 
		printf("num=%d,lam=%lf , xk=%lf , f(xk) = %lf\n",num,lam,x1,f(x1));
		while(fabs(f(x1))>fabs(f(x0)))
		{
			lam=lam/2;
			x1=x0-lam*f(x0)/df(x0);
			printf("num=%d,lam=%lf , xk=%lf , f(xk) = %lf\n",num,lam,x1,f(x1));
		}
		
		if(fabs(x1-x0)<0.00000001)
		{
		printf("迭代完成！\n");
		break;
		}
		else
		{
			x0=x1;
			num++;/*记录迭代次数*/
		}
	}
	
}

/*定义函数*/
double f(double x)
{
	return pow(x,3)/3-x;
}
/*定义函数*/
double df(double x)
{
	return x*x-1;
}
