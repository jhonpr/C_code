#include <stdio.h>
#include <stdlib.h>


/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//堆大小 
int heapSize=0;
//父节点的索引 
int PARENT(int i){
	return (i-1)/2;
}
//左子树的索引 
int LEFT(int i){
	return 2*i+1;
}
//右子树的索引 
int RIGHT(int i){
	return 2*i+2;
}

//最大堆A[PARENT(i)]>A[i]
//一般用于排序 


//最小堆A[PARENT(i)]<A[i] 
//一般用于优先队列


//保持最大堆性质 
//节点i为根的堆保持最大堆性质 
void maxHeapify(int* arr,int i){
	int temp;
	int largest=i;
	int left=LEFT(i);
	int right=RIGHT(i);
	//s-max 获取当前点的以及左右子节点中最大值的索引 
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
//初始化最大堆 
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
		//每次将堆缩小1 
		heapSize-=1;
		//执行最大堆保持性质，会把最大元素放到arr[0] 
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
