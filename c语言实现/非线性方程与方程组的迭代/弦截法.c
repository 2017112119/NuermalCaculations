/*弦截法  利用差商 代替*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double f(double x);

/*定义f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}



/*定义主函数*/
int main()
{
	double x0;/*初值*/
	double x[100];/*存储所有的x*/
	double m;/*中间值*/
	int i=0;/*记录迭代次数*/
	printf("请输入不动点迭代x的初始值x0=");
	scanf("%lf",&x0);/*输入初值*/
	x[0]=x0;
	x[1]=x0+0.1;
	
	/*迭代*/
	while(1)
	{
		x[i+2]=x[i+1]-f(x[i+1])*(x[i+1]-x[i])/(f(x[i+1])-f(x[i]));
		i++;
		printf("迭代第%d次的结果为：x(%d)=%lf\n",i,i,x[i+1]);
		if(fabs(x[i+1]-x[i])<0.0000001)
		{
			break;
		}
	}
}
