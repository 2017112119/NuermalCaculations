/*Aitken加速与Steffensen迭代 */
#include<stdio.h>
#include<math.h>

/*函数声明*/
double fai(double x);

/*定义主函数*/
int main()
{
	double x0;/*初值*/
	double x1;/*迭代后的值*/
	double x2;/**/
	int num=0;/*迭代次数*/
	
	printf("请输入初始值x0=");
	scanf("%lf",&x0); 
	/*迭代*/
	while(1)
	{
		/*迭代 公式*/
		x1=fai(x0);
		x2=fai(x1);
		x1=x0-(x1-x0)*(x1-x0)/(x2-2*x1+x0);
		num++;
		
		/*精度判断*/
		if(fabs(x1-x0)<0.00001)
		{
			printf("最终结果为：x=%lf\n",x1);
			printf("迭代次数为：n=%d\n",num);
			break;
		}
		/*更新*/
		x0=x1;
	}
	return 0;
}

double fai(double x)/*x = fai(x)*/
{
	return exp(-x);
}

