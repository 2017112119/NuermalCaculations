/*
牛顿迭代法
对于不同的题目 我们只需要修改  f(x) 即对应 的  df(x) 即可 
*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double fa(double x);
double f(double x);
double df(double x);

/*将f(x)=0  化为   fa(x)=x*/
/*定义不动点函数*/
double fa(double x)
{
	return x-f(x)/df(x);
}

/*定义f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}

/*定义df(x)  表示 f(x)的导数*/
double df(double x)
{
	return 3*x*x-3;
}

/*定义主函数*/
int main()
{
	double x0;/*初值*/
	double m;/*中间值*/
	int i=0;/*记录迭代次数*/
	printf("请输入不动点迭代x的初始值x0=");
	scanf("%lf",&x0);/*输入初值*/
	
	while(1)
	{
		m=x0;
		x0=fa(x0);
		i++;
		printf("迭代第%d次的结果为：x(%d)=%lf\n",i,i,x0);
		if(fabs(m-x0)<0.0000001)
		{
			break;
		}
	}
}
