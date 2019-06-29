/*  4阶Ronge-Kutta法 */
#include<stdio.h>

/*定义函数f(x,y)*/
double f(double x,double y)
{
	return x*x-y;
}

/*定义  主函数*/
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
	printf("4阶Ronge-Kutta法 收敛阶为 4 \n");
	double k1,k2,k3,k4;
	for(i=0;i<n;i++)
	{
		k1=f(x0+i*h,y[i]);
		k2=f(x0+i*h+h/2,y[i]+h/2*k1);
		k3=f(x0+i*h+h/2,y[i]+h/2*k2);
		k4=f(x0+i*h+h,y[i]+h*k3);
		y[i+1]=y[i]+h/6*(k1+2*k2+2*k3+k4);
	}
	/*输出结果*/
	for(i=0;i<n+1;i++)
	{
		printf("x=%lf,y=%lf\n",x0+i*h,y[i]);
	}
	
	return 0;
}
