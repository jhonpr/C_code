#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
/*
* 插入算法 
输入n个数，输出n个数的排序 
*/


void insertSort(int *array,int len);


//输入需要排序的数组，及数组长度 
void insertSort(int* array,int len){
	int is_j;
	int is_i=1;
	int key;
	 for(;is_i<len;is_i++){
	 	key=*(array+is_i);//把当前位置的值赋值给key
	 	printf("--%d--",key);
		 //将key插入到array[0]-array[i]内
		 is_j=is_i-1;//从后往前插入
		 //此处的key<*(array+is_j)为升序，替换为>则为降序 
		 while(is_j>=0&&key<*(array+is_j)){//如果key>*(array+is_j)的值 ，则找到位置，停止 
		 	*(array+is_j+1)=*(array+is_j);
		 	is_j--;
		 } 
		*(array+is_j+1)=key; 
	 }
} 

//测试程序书写的正确性 
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

