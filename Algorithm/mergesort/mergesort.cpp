#include <stdio.h>
#include<stdlib.h>
#include <malloc.h>
void merge(int* array,int p,int q,int r);
void mergeSort(int* arr,int p,int r);
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	int arr[]={1,3,4,12,45,23,56,78,9,27};
	int i=0;
	mergeSort(arr,0,8);
	
	for(;i<9;i++){
		printf("------%d----",*(arr+i));
	}
	return 0;
}

//合并两个已经排好的序列，其中p<=q<r 
//此函数为合并array[p-q]和array[q+1-r] 
void merge(int* array,int p,int q,int r){
//	int m_len_1=q-p+1;
//	int m_len_2=r-q;
	int m_len=r-p+1;
	
	int* mp_temp=(int*)malloc(sizeof(int)*m_len);
	
	int m_i=p;
	int m_j=q+1;
	int m_temp=0;
	//把两个数组中较小的 插入mp_temp数组中,直到某一个数组的数据全部插入 
	while(m_i<q+1&&m_j<r+1){
		if(*(array+m_i)<=*(array+m_j)){
			*(mp_temp+m_temp)=*(array+m_i);
			m_i++;
		}else{
			*(mp_temp+m_temp)=*(array+m_j);
			m_j++;
		}
		m_temp++;
	}
	
//	printf("%d-----%d----%d---%d\n",m_i,m_j,m_len_1,m_len_2);
//插入另一个数组余下的数据 
	if(m_i==q+1){
		for(;m_j<r+1;m_j++){
//			printf("if");
			*(mp_temp+m_temp)=*(array+m_j);
			m_temp++; 
		}
	}else{
		for(;m_i<q+1;m_i++){
//			printf("else");
			*(mp_temp+m_temp)=*(array+m_i);
			m_temp++; 
		}	
	}
	
	//把排好序的数组mp_temp赋值给数组array 
	for(m_i=0;m_i<m_len;m_i++){
		*(array+p++)=*(mp_temp+m_i);
	}
	free(mp_temp);
}

//归并排序，采用分治法 
void mergeSort(int* arr,int p,int r){
	int q;
	if(p<r){
		q=(p+r)/2;
		mergeSort(arr,p,q);
		mergeSort(arr,q+1,r);
		merge(arr,p,q,r);
	}
}
