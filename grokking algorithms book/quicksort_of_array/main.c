/*
 * main.c
 *
 *  Created on: Oct 17, 2024
 *      Author: thomas ashraf zaki
 */
#include <stdio.h>
void QuickSort(int * ptr, int size){
	int pivot_index= find_pivot(ptr,size);//call find_pivot()
	int size_low=pivot_index;//the num of smaller element
	int size_high=size-pivot_index-1;//the num of bigger element
	//base case
	if(size<=1){//2 becouse it already sorted after call find_pivot()
		return;
	}
	//recursive case
	//ptr donot change in the low num becouse i already point in the first of arr
	QuickSort(ptr,size_low);
	//in bigger elements we want to make point to element that it is after the pivot
	int * ptr_high=(int *)ptr+size_low+1;
	QuickSort(ptr_high,size_high);
}
int find_pivot(int arr[],int size){
	int pivot=arr[0];
	int count=0;
	for(int i=1;i<size;i++){//i=1--> donot want to loop after pivot
		if (arr[i]<=pivot){
			//swap
			int temp =arr[i];
			arr[i] =arr[i-1];
			arr[i-1] =temp;
			//count to know the new position of pivot
			count++;
		}
		else{
			//swap the large num with the end element
			int temp =arr[i];
			arr[i] =arr[size-1];
			arr[size-1] =temp;

			//i-- to check the swap element again that i take it from the end
			i--;
			//size-- to not check to the end element that i make sure that is bigger than pivot
			size--;
		}

	}
	return count;
}
void main (void){
	int arr[]={5,3,1,2,5,6,9,11,23,66,1,0};
	//call QuickSort()
	QuickSort(arr,(sizeof(arr)/sizeof(int)));
	printf("the sorted elements is  { ");
	for(int i =0;i<(sizeof(arr)/sizeof(int));i++){
		printf("%d ",arr[i]);
	}
	printf("}");
}

