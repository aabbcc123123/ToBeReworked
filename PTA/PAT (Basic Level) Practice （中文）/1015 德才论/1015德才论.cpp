#include <stdio.h>
#include <string.h>

void paixu(int a[][4],int *b,int num,int *result);

int main ()
{
	
	int n=0;//考生总数
	int l=0;//最低录取分数线
	int h=0;//优先录取线 
	
	scanf("%d %d %d",&n,&l,&h);
	int m=n;//达到最低分数线的人数 
	int b[4][n];  //圣人，君子，类三，其他 
	int num[4]={0};//圣人君子类三其他的数量 
	
	int a[n][4];
	//读入数据
	for (int i=0;i<n;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		a[i][3]=a[i][1]+a[i][2];//计算每个人的总分 
		if (a[i][1]<l||a[i][2]<l) m--;//不及格的排除 
		else{
			if (a[i][1]>=h&&a[i][2]>=h) b[0][num[0]]=i,num[0]++;//找出圣人 
			else if (a[i][1]>=h&&a[i][2]<h) b[1][num[1]]=i,num[1]++;//找出君子 
			else if (a[i][1]>a[i][2]) b[2][num[2]]=i,num[2]++;//找出愚人 
			else b[3][num[3]]=i,num[3]++;//找出小人 
		}
	}
	
	
	//调试一下下
//	printf("m=%d\n",m); 
//	//输出整个数组
//	for (int i=0;i<n;i++){
//		for (int j=0;j<4;j++){
//			printf("%d\t",a[i][j]);
//		}
//		printf("\n");
//	} 
//	//分类的结果
//	for (int i=0;i<4;i++){
//		printf("num[%d]=\t",i);
//		for (int j=0;j<num[i];j++){
//			printf("%d\t",b[i][j]);
//		}
//		printf("\n");
//	} 
	
	
	//开始排序
//	printf("************************\n");
	int result[m];//最后输出的结果
	//输出圣人 
	paixu(a,b[0],num[0],result);
	for (int i=0;i<num[0];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
	//输出君子 
	paixu(a,b[1],num[1],result);
	for (int i=0;i<num[1];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
	//输出类三 
	paixu(a,b[2],num[2],result);
	for (int i=0;i<num[2];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
	//输出其他 
	paixu(a,b[3],num[3],result);
	for (int i=0;i<num[3];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
//	printf("************************\n");
	
	//调试，看看result都是些个啥
//	
//	for (int i=0;i<num[0];i++){
//		printf("%d\t",result[i]);
//	} 
//	printf("\n");
	
	
	return 0;
	}

void paixu(int a[][4],int *b,int num,int *result)//num为角色数量 
{
	
	int n=0;//已经排了几个数了 
	int max=0,loc=0;//最高分和位置
	result[0]=b[0];
	do{
		//初始化max和loc
		for (int i=0;i<num;i++){
			if (b[i]!=-1){
				max=a[b[i]][3];
				loc=i;
				break;
			}
		} 
		for (int i=1;i<num;i++){
			if (b[i]!=-1){
				if (a[b[i]][3]>max){
					max=a[b[i]][3];
					loc=i;
				}
				if (a[b[i]][3]=max){//总分相等时 
					if (a[b[i]][1]>a[b[loc]][1]){
						max=a[b[i]][3];
						loc=i;
					} 
					if (a[b[i]][1]==a[b[loc]][1]){//德分相等时 
						if (a[b[i]][0]<a[b[loc]][0]){
							max=a[b[i]][3];
							loc=i;
						} 
					}
				}
			}
			
		}
		
		//检查过一遍后
		result[n]=b[loc];
		b[loc]=-1;
		n++;
		
	} while (n<num); 
	
 } 

