/*
Newton Interpolation
*/
//输入数据组数 n   然后依次输入各组数据   ， 注意 结点不 能  重  每个节点都不同   
#include<stdio.h>

int main()
{
	double c_s[100][100];//定义存储差商的二维数组
	int n;//输入的数据组数
	int i,j;//计数
	
	//获取n
	printf("请输入数据组数n:");
	scanf("%d",&n);
	 
	//数据输入  存储在前两列 
	printf("请输入数据：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<2;j++)
			scanf("%lf",&c_s[i][j]);
	}
	
	//差商计算 
	for(j=2;j<1+n;j++)
	{
		for(i=j-1;i<n;i++)
		{
			c_s[i][j]=(c_s[i][j-1]-c_s[i-1][j-1])/(c_s[i][0]-c_s[i-j+1][0]);
		}
	}
	
	//定义所要求的  x  处的值 
	double x;
	printf("请输入所要求的x：");
	scanf("%lf",&x);
	
	//求x处的值
	double sum=c_s[0][1];//存储结果   f[x0]
	double mul=1;//乘积 
	
	for(i=1;i<n;i++)
	{
		for(j=0;j<i;j++)
		{
			mul=mul*(x-c_s[j][0]);
		}
		sum=sum+c_s[i][i+1]*mul;
		mul=1;
	}
	
	//输出差商表
	printf("得到的差商表如下：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%lf    ",c_s[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	
	//结果输出
	printf("插值函数在x=%lf处的函数值为：%lf",x,sum);
	
	return 0; 
	
}
