#include <stdio.h>
#include <string.h>

void paixu(int a[][4],int *b,int num,int x);
void nuo(int *b,int x,int num);

int main ()
{
	
	int n=0;//考生总数
	int l=0;//最低录取分数线
	int h=0;//优先录取线 
	
	scanf("%d %d %d",&n,&l,&h);
	int m=n;//达到最低分数线的人数 
	int b[4][n];  //圣人，君子，类三，其他 
	b[0][0]=0,b[1][0]=0,b[2][0]=0,b[3][0]=0;//初始化b 
	int num[4]={0};//圣人君子类三其他的数量 
	
	int a[n][4];
	//读入数据
	for (int i=0;i<n;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		a[i][3]=a[i][1]+a[i][2];//计算每个人的总分 
		if (a[i][1]<l||a[i][2]<l) m--;//不及格的排除 
		else{
			if (a[i][1]>=h&&a[i][2]>=h){//找出圣人
				if (num[0]==0) b[0][0]=i;//初始化b 
				num[0]++;
				paixu(a,b[0],num[0],i);	
				//调试一下下
//				printf("i=%d时，num[0]=%d,b[0]=",i,num[0]);
//				for (int j=0;j<num[0];j++){
//					printf("%d\t",b[0][j]);
//				}
//				printf("\n");
			}else if (a[i][1]>=h&&a[i][2]<h){//找出君子
				if (num[1]==0) b[1][0]=i;//初始化b
				num[1]++;
				paixu(a,b[1],num[1],i);
				//调试一下下
//				printf("i=%d时，num[1]=%d,b[1]=",i,num[1]);
//				for (int j=0;j<num[1];j++){
//					printf("%d\t",b[1][j]);
//				}
//				printf("\n");
				 
			}else if (a[i][1]>a[i][2]){//找出类三 
				if (num[2]==0) b[2][0]=i;//初始化b
				num[2]++;
				paixu(a,b[2],num[2],i);
				//调试一下下
//				printf("i=%d时，num[2]=%d,b[2]=",i,num[2]);
//				for (int j=0;j<num[2];j++){
//					printf("%d\t",b[2][j]);
//				}
//				printf("\n");
			}else {//找出其他 
				if (num[3]==0) b[3][0]=i;//初始化b
				num[3]++;
				paixu(a,b[3],num[3],i);
				//调试一下下
//				printf("i=%d时，num[3]=%d,b[3]=",i,num[3]);
//				for (int j=0;j<num[3];j++){
//					printf("%d\t",b[3][j]);
//				}
//				printf("\n");
			}
		} 
	}
	
	 
	//调试一下下
	//输出整个数组
//	for (int i=0;i<n;i++){
//		for (int j=0;j<4;j++){
//			printf("%d\t",a[i][j]);
//		}
//		printf("\n");
//	} 
//	//分类的结果
//	for (int i=0;i<4;i++){
//		printf("b[%d]=\t",i);
//		for (int j=0;j<num[i];j++){
//			printf("%d\t",b[i][j]);
//		}
//		printf("\n");
//	} 

	//输出
	printf("%d\n",m);
	for (int i=0;i<4;i++){
		for (int j=0;j<num[i];j++){
			printf("%d %d %d\n",a[b[i][j]][0],a[b[i][j]][1],a[b[i][j]][2]);
		}
		
	} 
	
	
	return 0;
	}

void paixu(int a[][4],int *b,int num,int x)//x就是那个i 
{
	
	for (int i=0;i<num;i++){
		
		if (a[x][3]>a[b[i]][3]){//如果总分更高的话 

			nuo(b,i,num);
			b[i]=x;
			
			break;
		}

		if (a[x][3]==a[b[i]][3]){//如果总分相等的话 
			if (a[x][1]>a[b[i]][1]){//如果德分更高的话 
				
				nuo(b,i,num);
				b[i]=x;
				
				break; 
			} 
			if (a[x][1]==a[b[i]][1]){//如果德分相等的话 
				if (a[x][0]<a[b[i]][0]){//如果学号更低的话 
					
					nuo(b,i,num);
					b[i]=x;
					
					break;
				} 
			}
		}
		
		if (i==num-2){//如果是最小的话 
			b[i+1]=x;
			
			break;
		}
		
		
	}
	
	
	 
	
}


//挪位置 
void nuo(int *b,int x,int num)//x就是paixu里面的那个i
{
	
	for (int i=num-1;i>x;i--){
		b[i]=b[i-1];
	} 
	
} 



