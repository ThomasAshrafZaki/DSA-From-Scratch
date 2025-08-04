/*
 * main.c
 *
 *  Created on: Oct 17, 2024
 *      Author: thomas ashraf zaki
 */
#include <stdio.h>
#define size   10
int binary_search(int arr[size],int item){
	int min=0,max=size-1,mid;
	while(min<=max){
		mid=(max+min)/2;
		if(arr[mid]==item)
			return mid;
		if(arr[mid]>item){
			max=mid-1;
		}
		if(arr[mid]<item){
			min=mid+1;
		}
	}
	return -1;
}
void main (void){
	int arr[size]={2,4,13,33,45,66,76,402,555,652};
	int item;
	printf("Enter the item to search : \n");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&item);
	int result=binary_search(arr,item);
	if(result==-1)
		printf("the index is : none");
	else
		printf("the index is : %d",result);

}
