/*
��˹��ȥ�� 
*/
#include<stdio.h>
#include<math.h>
double A_[100][100]={{0,0,0,0,sqrt(2)/2,0,1,0,sqrt(2)/2,0,0,0,0,15},{sqrt(2)/2,0,0,0,0,0,0,0,0,0,0,0,0,0},{sqrt(2)/2,1,0,0,0,0,0,0,0,0,0,0,0,0},{0,0,1,0,0,0,0,0,0,0,0,0,0,10},{0,1,0,0,0,-1,0,0,0,0,0,0,0,0},{sqrt(2)/2,0,1,0,sqrt(2)/2,0,0,0,0,0,0,0,0,0},{sqrt(2)/2,0,0,-1,-(sqrt(2)/2),0,0,0,0,0,0,0,0,0},{0,0,0,1,0,0,0,-1,0,0,0,0,0,0},{0,0,0,0,0,0,1,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0,0,0,1,0,0,20},{0,0,0,0,0,0,0,0,0,1,0,0,-1,0},{0,0,0,0,0,0,0,0,0,0,0,sqrt(2)/2,0,0},{0,0,0,0,0,0,0,0,0,0,0,sqrt(2)/2,1,0}};
	
double sum(int n,double list[100],double x[100]);//�������� 
int col=1;
void paixu_h();/**/
int main()
{
	//double A_[100][100];//�����������
	int n;				//�������n
	printf("���������Ľ���n=:");
	scanf("%d",&n);//��ȡ ����
	int i,j;
	
	//�������� 
	/*printf("�������������\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			scanf("%lf",&A_[i][j]);
		}
	}*/

	double m[100][100];
	//��ʼ��
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
	//���� ���������Ϊ������
	//double max;
	
	//����һ������  (�н���)
	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(fabs(A_[i][0])<fabs(A_[j][0]))
			{
				double m_list[100];//�м����
				
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
		//����  ����Li 
		for(i=1+t;i<n;i++)
		{
			m[i][t]=-A_[i][t]/A_[t][t];
		}
	
		
		//�������A�ĵ��� 
		for(i=1+t;i<n;i++)// ��ʼ���� 
		{
			for(j=t;j<n+1;j++)
			{
				//double s=0;//�洢A_[i][j]��ֵ
				int h,k;
				
				//�� A ��Ӧ��תΪ������ 
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
		printf("��i�ε����Ľ����\n");
		for(i=0;i<n;i++)
		{
			for(j=0;j<n+1;j++)
			{
				printf("%lf    ",A_[i][j]);
			}
			printf("\n");
		}
		
		//��ʼ��
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
	printf("���õ���MΪ��\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%lf    ",m[i][j]);
		}
		printf("\n");
	}
	
	//��� ������A(n)
	printf("���õ����������Ϊ��\n");
	for(i=0;i<n;i++)
	{
		for(j=0;j<n+1;j++)
		{
			printf("%lf    ",A_[i][j]);
		}
		printf("\n");
	}
	
	
	//��� 
	double x[20];//����x����ʼ�� 
	for(i=0;i<n;i++)
	{
		x[i]=0;
	}
	int count=0;//����  �������� 
	for(i=n-1;i>=0;i--)
	{
		
		x[i]=A_[i][n]/A_[i][i];
		if(count>=n-1)
		{
			printf("���Է�����Ľ����£�\n");
			//����ش���� 
			for(t=0;t<n;t++)
			{
				printf("x%d = %lf\n",t,x[t]);
			}
			break;//�˳� 
		}
		
		//������Ϊ������ 
		for(j=n-1;j>i-1;j--)
			A_[i-1][n]-=x[j]*A_[i-1][j];
			count+=1;
		
	}
	
	
	
	
}

 //�б���ͺ���   (���ȣ�a1i�б�,x1i�б�)
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
	//��ʼ��
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
	//���� ���������Ϊ������
	//double max;
	
	//����һ������  (�н���)
	for(i=col;i<n;i++)
	{
		for(j=i;j<n;j++)
		{
			if(fabs(A_[i][col])<fabs(A_[j][col]))
			{
				double m_list[100];//�м����
				
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

