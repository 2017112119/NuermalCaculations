/*EulerMethod  改进欧拉法*/
#include<stdio.h>

double f(double x,double y)
{
	return y-2*x/y;
}

/*定义主函数*/
int main()
{
	double y[100];/*存储结果*/
	double x0;/*初值对应的x0*/ 
	double h;/*步长*/
	int n;/*步数*/
	int i;/*计数*/
	printf("请输入初值x0以及对应y(x0):");
	scanf("%lf%lf",&x0,&y[0]);/*获取输入*/
	printf("请输入步长h:");
	scanf("%lf",&h);
	printf("请输入你要进行多少步:n=");
	scanf("%d",&n);
	/*迭代*/
	printf("改进 Euler Method 收敛阶为 2 \n");
	for(i=0;i<n;i++)
	{
		y[i+1]=y[i]+h/2*(f(x0+i*h,y[i])+f(x0+(i+1)*h,y[i]+h*f(x0+i*h,y[i])));
	}
	/*输出结果*/
	for(i=0;i<n+1;i++)
	{
		printf("x=%lf,y=%lf\n",x0+i*h,y[i]);
	}
	
	return 0;
}
