#include <stdio.h>

//交互函数
void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//debug 测试
void test_swap(){
	int a = 5,b =6;
	printf("a = %d,b = %d\n",a,b);
	swap(&a,&b);
	printf("a = %d,b = %d\n",a,b);
}

//冒泡排序实现 O(n2) S(1)
void bubbleSort(int * arr, int size){
	for(int i =0;i<size;i++){
		for(int j = 0;j<size-i-1;j++){
			if(arr[j+1] < arr[j]){
				swap(&arr[j+1],&arr[j]);
			}
		}
	}
}

void test_bubbleSort(){
	printf("test bubbleSort\n");
	int array[] = {76,38,90,89,27,18,63};
	int size = sizeof(array) / sizeof(int);
	bubbleSort(array,size);
	for(int i =0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

//选择排序
void selectSort(int * arr, int size){
	for(int i = 0;i<size;i++){
		int min = i;
		for(int j=i+1;j<size;j++){
			if(arr[min] > arr[j]) min = j;
		}
		swap(&arr[i],&arr[min]);
	}
}

void test_selectSort(){
	printf("test selectSort\n");
	int array[] = {76,38,90,89,27,18,63};
	int size = sizeof(array) / sizeof(int);
	selectSort(array,size);
	for(int i =0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

//插入排序
void insertSort(int * arr, int size){
	for(int i=1;i<size;i++){
		int select = arr[i];
		int j = i-1;
		while(j >= 0 && select < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = select;
	}
}

void test_insertSort(){
	printf("test insertSort\n");
	int array[] = {76,38,90,89,27,18,63};
	int size = sizeof(array) / sizeof(int);
	insertSort(array,size);
	for(int i =0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}

//折半插入排序 （不太好理解，先抄一遍吧）

void binaryInsertSort(int * arr, int size){
	int low,hight,mid,key;
	for(int i = 1;i<size;i++){
		key = arr[i];
		low = 0;
		hight = i -1;
		while (hight>=low) //寻找最终的插入点 即low的位置
		{
			mid = (low + hight)/2;
			if(arr[mid]>key){
				hight = mid - 1; //插入点在左边
			}
			else{
				low = mid + 1; //插入点在右边
			}
		}

		int j = i-1;
		while (j>=low)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[low] = key;
	}
}


void test_binarySort(){
	printf("test binarySort\n");
	int array[] = {76,38,90,89,27,18,63,876};
	int size = sizeof(array) / sizeof(int);
	binaryInsertSort(array,size);
	for(int i =0;i<size;i++){
		printf("%d ",array[i]);
	}
	printf("\n");
}
