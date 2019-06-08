/*
两点三次Hermite插值 
*/
#include<stdio.h>

int main()
{
	double a[4][2];//存储数据    依次为两个节点   以及两个节点 的导数
	int i,j;
	
	//输入数据并存储到a中 
	printf("请输入数据（前两组为节点 ，后两组为导数）：\n");
	for(i=0;i<4;i++)
	{
		for(j=0;j<2;j++)
		{
			scanf("%lf",&a[i][j]);
		}
	}
	
	double x;//要求的x
	printf("请输入你要求的x：");
	scanf("%lf",&x);
	
	double L[2];//存储 Ln[x]的值 
	L[0]=(x-a[1][0])/(a[0][0]-a[1][0]);
	L[1]=(x-a[0][0])/(a[1][0]-a[0][0]);
	
	double alp[2];
	alp[0]=(1+2*L[1])*(L[0]*L[0]);
	alp[1]=(1+2*L[0])*(L[1]*L[1]);
	
	double beta[2];
	beta[0]=(x-a[0][0])*(L[0]*L[0]);
	beta[1]=(x-a[1][0])*(L[1]*L[1]);
	
	double res;
	res=a[0][1]*alp[0]+a[1][1]*alp[1]+a[2][1]*beta[0]+a[3][1]*beta[1];
	
	printf("所求结果为：%lf",res);
}
