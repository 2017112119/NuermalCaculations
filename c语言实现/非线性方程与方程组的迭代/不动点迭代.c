/*不动点迭代*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double fa(double x);

/*将f(x)=0  化为   fa(x)=x*/
/*定义不动点函数*/
double fa(double x)
{
	return pow(x+1,1.0/3);
}

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
