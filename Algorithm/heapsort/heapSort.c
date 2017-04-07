#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//�Ѵ�С 
int heapSize=0;
//���ڵ������ 
int PARENT(int i){
	return (i-1)/2;
}
//������������ 
int LEFT(int i){
	return 2*i+1;
}
//������������ 
int RIGHT(int i){
	return 2*i+2;
}

//����A[PARENT(i)]>A[i]
//һ���������� 


//��С��A[PARENT(i)]<A[i] 
//һ���������ȶ���


//������������ 
//�ڵ�iΪ���Ķѱ����������� 
void maxHeapify(int* arr,int i){
	int temp;
	int largest=i;
	int left=LEFT(i);
	int right=RIGHT(i);
	//s-max ��ȡ��ǰ����Լ������ӽڵ������ֵ������ 
	if(left<heapSize&&arr[left]>arr[i]){
		largest=left;
	}
	if(right<heapSize&&arr[right]>arr[largest]){
		largest=right;
	}
	//e-max 
	if(largest!=i){
		temp=arr[largest];
		arr[largest]=arr[i];
		arr[i]=temp;
		maxHeapify(arr,largest);
	}
	 
}
//��ʼ������ 
void initMaxHeap(int* arr,int len){
	int i;
	heapSize=len;
	for(i=len/2;i>=0;i--){
		maxHeapify(arr,i);	
	}
}

void heapSort(int* arr,int len){
	int i,temp;
	initMaxHeap(arr,len);
	for(i=len-1;i>0;i--){
		//s-swap a[0] a[i]
		temp=arr[0];
		arr[0]=arr[i];
		arr[i]=temp;
		//e-swap
		//ÿ�ν�����С1 
		heapSize-=1;
		//ִ�����ѱ������ʣ�������Ԫ�طŵ�arr[0] 
		maxHeapify(arr,0);
	}
}


int main(int argc, char *argv[]) {
	int i;
	int a[]={20,335,64,34,97,124,678,215,-10,0};
	int len=sizeof(a)/sizeof(int);
	heapSort(a,len);
	for(i=0;i<len;i++){
		printf("%d\t",a[i]);
	}	
	return 0;
}
