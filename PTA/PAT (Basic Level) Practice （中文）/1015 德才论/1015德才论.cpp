#include <stdio.h>
#include <string.h>

void paixu(int a[][4],int *b,int num,int *result);

int main ()
{
	
	int n=0;//��������
	int l=0;//���¼ȡ������
	int h=0;//����¼ȡ�� 
	
	scanf("%d %d %d",&n,&l,&h);
	int m=n;//�ﵽ��ͷ����ߵ����� 
	int b[4][n];  //ʥ�ˣ����ӣ����������� 
	int num[4]={0};//ʥ�˾����������������� 
	
	int a[n][4];
	//��������
	for (int i=0;i<n;i++){
		scanf("%d %d %d",&a[i][0],&a[i][1],&a[i][2]);
		a[i][3]=a[i][1]+a[i][2];//����ÿ���˵��ܷ� 
		if (a[i][1]<l||a[i][2]<l) m--;//��������ų� 
		else{
			if (a[i][1]>=h&&a[i][2]>=h) b[0][num[0]]=i,num[0]++;//�ҳ�ʥ�� 
			else if (a[i][1]>=h&&a[i][2]<h) b[1][num[1]]=i,num[1]++;//�ҳ����� 
			else if (a[i][1]>a[i][2]) b[2][num[2]]=i,num[2]++;//�ҳ����� 
			else b[3][num[3]]=i,num[3]++;//�ҳ�С�� 
		}
	}
	
	
	//����һ����
//	printf("m=%d\n",m); 
//	//�����������
//	for (int i=0;i<n;i++){
//		for (int j=0;j<4;j++){
//			printf("%d\t",a[i][j]);
//		}
//		printf("\n");
//	} 
//	//����Ľ��
//	for (int i=0;i<4;i++){
//		printf("num[%d]=\t",i);
//		for (int j=0;j<num[i];j++){
//			printf("%d\t",b[i][j]);
//		}
//		printf("\n");
//	} 
	
	
	//��ʼ����
//	printf("************************\n");
	int result[m];//�������Ľ��
	//���ʥ�� 
	paixu(a,b[0],num[0],result);
	for (int i=0;i<num[0];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
	//������� 
	paixu(a,b[1],num[1],result);
	for (int i=0;i<num[1];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
	//������� 
	paixu(a,b[2],num[2],result);
	for (int i=0;i<num[2];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
	//������� 
	paixu(a,b[3],num[3],result);
	for (int i=0;i<num[3];i++)
		printf("%d %d %d\n",a[result[i]][0],a[result[i]][1],a[result[i]][2]);
//	printf("************************\n");
	
	//���ԣ�����result����Щ��ɶ
//	
//	for (int i=0;i<num[0];i++){
//		printf("%d\t",result[i]);
//	} 
//	printf("\n");
	
	
	return 0;
	}

void paixu(int a[][4],int *b,int num,int *result)//numΪ��ɫ���� 
{
	
	int n=0;//�Ѿ����˼������� 
	int max=0,loc=0;//��߷ֺ�λ��
	result[0]=b[0];
	do{
		//��ʼ��max��loc
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
				if (a[b[i]][3]=max){//�ܷ����ʱ 
					if (a[b[i]][1]>a[b[loc]][1]){
						max=a[b[i]][3];
						loc=i;
					} 
					if (a[b[i]][1]==a[b[loc]][1]){//�·����ʱ 
						if (a[b[i]][0]<a[b[loc]][0]){
							max=a[b[i]][3];
							loc=i;
						} 
					}
				}
			}
			
		}
		
		//����һ���
		result[n]=b[loc];
		b[loc]=-1;
		n++;
		
	} while (n<num); 
	
 } 

