#include<stdio.h> 
#include<stdlib.h>

#define N 100
#define SIZE 100 //预定义要进行转置的矩阵最大大小为 100*100
//为了函数参数传递的方便，将行和列的具体大小定义为全局变量
int a_column;
int a_row ;
int b_row;
int c[SIZE][SIZE]={0};
//矩阵的输入函数
void inputMatrix(int a[][SIZE] , int n, int m){ 
 int i,j;
 for(i = 0;i < n;i++){
  for(j = 0;j < m;j++){
   scanf("%d",&a[i][j]);
  }
 }
}
//矩阵的输出函数
void outputMatrix(int c[][SIZE] , int n, int m){
 int i,j;
 for(i = 0;i < n;i++){
  for(j = 0;j < m;j++){
   printf("%d ",c[i][j]);  
  }
  printf("\n"); 
 }
}
//矩阵的乘法算
void matrixMultiplication(int a[][SIZE], int b[][SIZE]){
 int i,j,k;
 for(i = 0;i < a_column;i++)
 {
  for(j = 0; j < b_row ; j++)
  {
   for(k = 0; k < a_row;k++)
   {
    c[i][j] = c[i][j]+ a[i][k] * b[k][j];
   }
  }
 }
}

int getA(int arcs[N][N],int n)//按第一行展开计算|A|
{
	if(n==1)
	{
		return arcs[0][0];
	}
	int ans = 0;
	int temp[N][N];
	int i,j,k;
	for(i=0;i<n;i++)
	{
		for(j=0;j<n-1;j++)
		{
			for(k=0;k<n-1;k++)
			{
				temp[j][k] = arcs[j+1][(k>=i)?k+1:k];
				
			}
		}
		int t = getA(temp,n-1);
		if(i%2==0)
		{
			ans += arcs[0][i]*t;
		}
		else
		{
			ans -=  arcs[0][i]*t;
		}
	}
	return ans;
}
void getAStart(int arcs[N][N],int n,int ans[N][N])//计算每一行每一列的每个元素所对应的余子式，组成A*
{
	if(n==1)
	{
		ans[0][0] = 1;
		return;
	}
	int i,j,k,t;
	int temp[N][N];
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			for(k=0;k<n-1;k++)
			{
				for(t=0;t<n-1;t++)
				{
					temp[k][t] = arcs[k>=i?k+1:k][t>=j?t+1:t];
				}
			}
 
		
			ans[j][i]  =  getA(temp,n-1);
			if((i+j)%2 == 1)
			{
				ans[j][i] = - ans[j][i];
			}
		}
	}
}

//主函数
 
int main()
{ 
 //定义数组并初始化
 int a[SIZE][SIZE]={0};
 int b[SIZE][SIZE]={0};
 printf("请输入第一个矩阵的行数 : ");
 scanf("%d",&a_column);
 printf("\n请输入第一个矩阵的列数 :");
 scanf("%d",&a_row);
 //函数调用及主功能实现
 printf("\n请输入矩阵A( %d X %d 形式)\n" , a_column , a_row);
 inputMatrix(a, a_column , a_row); 
 printf("注意：根据数学原理，您将输入的第二个矩阵的行数为 %d\n",a_row);
 printf("请输入矩阵B的列数 : ");
 scanf("%d",&b_row);
 printf("\n请输入矩阵B( %d X %d 形式) : \n" , a_row , b_row);
 inputMatrix(b, a_row , b_row);
 //调用相乘函数
 matrixMultiplication(a,b);
 printf("A与B相乘后的矩阵C是:\n");
 outputMatrix(c, a_column , b_row);
 getchar();
 system("pause"); 
 return 0;
}
