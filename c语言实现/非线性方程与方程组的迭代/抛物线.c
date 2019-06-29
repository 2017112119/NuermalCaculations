/*
抛物线法
*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double f(double x);
double sgn(double x);/*x>0  返回1   x<0返回 -1*/
double t_f(double x1,double x2);/*一阶差商*/
double s_f(double x1,double x2,double x3);/*二阶差商*/ 

/*定义f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}
/*定义sgn(x)*/
double sgn(double x)
{
	if(x>0)
	{
		return 1;
	}
	else
	{
		return -1;
	}
}

/*定义主函数*/
int main()
{
	int i,j;/*计数*/
	int num=0;/*表示迭代次数*/
	double w;
	double x0,x1,x2;/*初始值*/ 
	double zx1,zx2;/*中间值*/ 
	
	/*输入初值 x0  x1 x2*/
	printf("请输入初始值x0=");
	scanf("%lf",&x0);
	printf("请输入初始值x1=");
	scanf("%lf",&x1);
	printf("请输入初始值x2=");/*假设x2与 精确解更为接近*/
	scanf("%lf",&x2);
	
	/*迭代*/
	while(1)
	{
		w=t_f(x2,x1)+s_f(x2,x1,x0)*(x2-x1);zx1=x1;zx2=x2;
		x2=x2-2*f(x2)/(w+sgn(w)*sqrt(w*w-4*f(x2)*s_f(x2,x1,x0)));
		num++;
		if(fabs(x2-zx2)<0.00000001)
		{
			printf("最终结果为：x=%lf\n",x2);
			printf("最终迭代次数为n=%d",num);
			break;
		}
		x0=zx1;
		x1=zx2;
		
	}
	
}

double t_f(double x1,double x2)/*一阶差商*/
{
	return (f(x2)-f(x1))/(x2-x1); 
}

double s_f(double x1,double x2,double x3)/*二阶差商*/
{
	return (t_f(x2,x3)-t_f(x1,x2))/(x3-x1);
}
