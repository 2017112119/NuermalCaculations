/*二分法*/
#include<stdio.h>
#include<math.h>

/*函数声明*/
double two_fen(double a,double b);
double f(double x); 


/*函数f(x)*/
double f(double x)
{
	return pow(x,3)-3*x+1;
}
/*二分法，求解*/
double two_fen(double a,double b)
{
	double xk,r,L;
	if(f(a)*f(b)>0)
	{
		printf("在该区间上没有解");
	}
	else if(f(a)*f(b)<0)
	{
		
		while(1)
		{
			xk=(a+b)/2;
			if(f(xk)*f(b)<0)
			{
				a=xk;
			}
			else
			{
				b=xk;
			}
			if(fabs(f(xk))<=0.000001)
			{
				printf("最后一次迭代 : (%lf,%lf)  f=%lf\n",a,b,f(xk));
				printf("求得的方程的解为x=%lf\n",xk);
				break;
			}
			
			printf("迭代进行中 : (%lf,%lf)  f(x)=%lf\n",a,b,f(xk));
		}
		return;
	}
	else if(fabs(f(a))<=1e-6)
	{
		printf("求得的方程的解为x=%lf\n",a);
	}
	else if(fabs(f(b))<=1e-6)
	{
		printf("求得的方程的解为x=%lf\n",b);
	}
}

int main()
{
	printf("请输入零点所在区间:");
	double a1,b1;
	scanf("%lf%lf",&a1,&b1);
	two_fen(a1,b1);
	return 0;
}
