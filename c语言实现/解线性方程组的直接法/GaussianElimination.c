/*
高斯消去法 
*/
#include<stdio.h>
#include<math.h>
double A_[100][100]={{0,0,0,0,sqrt(2)/2,0,1,0,sqrt(2)/2,0,0,0,0,15},{sqrt(2)/2,0,0,0,0,0,0,0,0,0,0,0,0,0},{sqrt(2)/2,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,10},{0,1,0,0,0,-1,0,0,0,0,0,0,0,0},{sqrt(2)/2,0,1,0,sqrt(2)/2,0,0,0,0,0,0,0,0,0},{sqrt(2)/2,0,0,-1,-(sqrt(2)/2),0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,-1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,20},{0,0,0,0,0,0,0,0,0,1,0,0,-1,0},{0,0,0,0,0,0,0,0,0,0,0,sqrt(2)/2,0,0},{0,0,0,0,0,0,0,0,0,0,0,sqrt(2)/2,1,0}};
	
double sum(int n,double list[100],double x[100]);//函数声明 
int col=1;
void paixu_h();/**/
int main()
{
	//double A_[100][100];//定义增广矩阵
	int n;				//矩阵阶数n
	printf("请输入矩阵的阶数n=:");
	scanf("%d",&n);//获取 输入
	int i,j;
	
	//矩阵输入 
	/*printf("请输入增广矩阵：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			scanf("%lf",&A_[i][j]);
		}
	}*/

	double m[100][100];
	//初始化
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
		}
	 } 
	
	for(i=0;i<n;i++)
	{
		m[i][i]=1;
	}
	
	
	int t;
	//迭代 将增广矩阵化为上三角
	//double max;
	
	//按第一列排序  (行交换)
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(fabs(A_[i][0])<fabs(A_[j][0]))
			{
				double m_list[100];//中间矩阵
				
				// i ->  m
				for(t=0;t<n+1;t++)
				{
				 	m_list[t]=A_[i][t];
				}
				// j -> i
				for(t=0;t<n+1;t++)
				{
					A_[i][t]=A_[j][t];
				}
				// m -> j
				for(t=0;t<n+1;t++)
				{
					A_[j][t]=m_list[t];
				}
				
				 
			}
		}
	}
	
	for(t=0;t<n-1;t++)
	{
		//计算  矩阵Li 
		for(i=1+t;i<n;i++)
		{
			m[i][t]=-A_[i][t]/A_[t][t];
		}
	
		
		//增广矩阵A的迭代 
		for(i=1+t;i<n;i++)// 开始的行 
		{
			for(j=t;j<n+1;j++)
			{
				//double s=0;//存储A_[i][j]的值
				int h,k;
				
				//将 A 对应列转为行向量 
				double list[100];
				for(h=0;h<n;h++)
				{
					list[h]=A_[h][j];
				
				}
				A_[i][j]=sum(n,m[i],list);
				
			}
			
		}
		paixu_h(n);
		col++;
		printf("第i次迭代的结果：\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n+1;j++)
			{
				printf("%lf    ",A_[i][j]);
			}
			printf("\n");
		}
		
		//初始化
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
			{
				m[i][j]=0;
			}
		 } 
		
		for(i=0;i<n;i++)
		{
			m[i][i]=1;
		}
		
	}
	printf("所得到的M为：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf    ",m[i][j]);
		}
		printf("\n");
	}
	
	//输出 上三角A(n)
	printf("所得到的增广矩阵为：\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%lf    ",A_[i][j]);
		}
		printf("\n");
	}
	
	
	//求解 
	double x[20];//定义x并初始化 
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	int count=0;//计数  迭代次数 
	for(i=n-1;i>=0;i--)
	{
		
		x[i]=A_[i][n]/A_[i][i];
		if(count>=n-1)
		{
			printf("线性方程组的解如下：\n");
			//输出回代结果 
			for(t=0;t<n;t++)
			{
				printf("x%d = %lf\n",t,x[t]);
			}
			break;//退出 
		}
		
		//将矩阵化为正定的 
		for(j=n-1;j>i-1;j--)
			A_[i-1][n]-=x[j]*A_[i-1][j];
			count+=1;
		
	}
	
	
	
	
}

 //列表求和函数   (长度，a1i列表,x1i列表)
double sum(int n,double list[100],double x[100])
 {
 	double s=0;
 	int i;
 	for(i=0;i<n;i++)
 	{
 		s=s+list[i]*x[i];
	 }
	
	return s;
 }
void paixu_h(int n)
{
	double m[100][100];
	//初始化
	int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m[i][j]=0;
		}
	}
	
	for(i=0;i<n;i++)
	{
		m[i][i]=1;
	}
	
	
	int t;
	//迭代 将增广矩阵化为上三角
	//double max;
	
	//按第一列排序  (行交换)
	for(i=col;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(fabs(A_[i][col])<fabs(A_[j][col]))
			{
				double m_list[100];//中间矩阵
				
				// i ->  m
				for(t=0;t<n+1;t++)
				{
				 	m_list[t]=A_[i][t];
				}
				// j -> i
				for(t=0;t<n+1;t++)
				{
					A_[i][t]=A_[j][t];
				}
				// m -> j
				for(t=0;t<n+1;t++)
				{
					A_[j][t]=m_list[t];
				}
				
				 
			}
		}
	}
}

