/*加权法 迭代加速    求f(x) 在  xk附近的解*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double fai(double x);
double dfai(double x);

/*定义主函数*/
int main()
{
	double x0;/*初值*/
	double x1;/*迭代后的值*/
	double L;
	
	printf("请输入初始值x0=");
	scanf("%lf",&x0); 
	L=dfai(x0);/*权*/
	printf("L=%lf\n",L);
	/*迭代*/
	while(1)
	{
		x1=1/(1-L)*(fai(x0)-L*x0);
		printf("xk=%lf\n",x1);
		/*判断精度*/
		if(fabs(x1-x0)<0.0001)
		{
			printf("\n####################\n");
			printf("最终的结果为x=%lf\n",x1);
			break;
		}
		x0=x1;
	}
	return 0;
}

double fai(double x)/*x = fai(x)*/
{
	return exp(-x);
}

double dfai(double x)/*fai(x) 的导数*/
{
	return -exp(-x);
}

