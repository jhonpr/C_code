#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
* �����㷨 
����n���������n���������� 
*/


void insertSort(int *array,int len);


//������Ҫ��������飬�����鳤�� 
void insertSort(int* array,int len){
	int is_j;
	int is_i=1;
	int key;
	 for(;is_i<len;is_i++){
	 	key=*(array+is_i);//�ѵ�ǰλ�õ�ֵ��ֵ��key
	 	printf("--%d--",key);
		 //��key���뵽array[0]-array[i]��
		 is_j=is_i-1;//�Ӻ���ǰ����
		 //�˴���key<*(array+is_j)Ϊ�����滻Ϊ>��Ϊ���� 
		 while(is_j>=0&&key<*(array+is_j)){//���key>*(array+is_j)��ֵ �����ҵ�λ�ã�ֹͣ 
		 	*(array+is_j+1)=*(array+is_j);
		 	is_j--;
		 } 
		*(array+is_j+1)=key; 
	 }
} 

//���Գ�����д����ȷ�� 
int main(int argc, char** argv) {
	int i;
	int a[]={20,335,64,34,97,124,678,215,-10,0};
	int len=sizeof(a)/sizeof(int);
	insertSort(a,len);
	printf("\n");
	for(i=0;i<len;i++){
		printf("%d\n",a[i]);
	}
	
	return 0;
}

