#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define random(x) (rand()%x)

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
//利用 主元 划分数组，其中 索引为i+1的位置为主元，主元前的所有元素均小于主元，且小于主元后面的元素 ，用数组最后一个元素为主元 
int  partition(int* arr,int p,int r){
	int i,j,temp;
	int flag=arr[r];//主元 
	i=p-1;
	for(j=p;j<r;j++){
		if(arr[j]<flag){
			i++;
			//s-swap arr[i] arr[j]
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
			//e-swap
		}
	}
	//s-swap arr[i+1] arr[rd]
	temp=arr[i+1];
	arr[i+1]=arr[r];
	arr[r]=temp;
	//e-swap
	
	return i+1;
}

//用随机主元分割数组 
int randomPartition(int* arr,int p,int r){
	int temp,randomIndex;
	randomIndex=p+random(r-p+1);
	
	temp=arr[r];
	arr[r]=arr[randomIndex];
	arr[randomIndex]=temp;
	
	return partition(arr,p,r);
}


void quickSort(int* arr,int p,int r){
	int q;
	if(p<r){
		q=randomPartition(arr,p,r);
		quickSort(arr,p,q-1);
		quickSort(arr,q+1,r);
	}
} 


int main(int argc, char *argv[]) {
	int i;
	int a[]={20,335,64,34,97,124,678,215,-10,0};
	int len=sizeof(a)/sizeof(int);
	quickSort(a,0,len-1);
//	printf("\nlen-1=%d",len-1);
	for(i=0;i<len;i++){
		printf("%d\t",a[i]);
	}
	return 0;
}
