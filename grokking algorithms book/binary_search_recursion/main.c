/*
 * main.c
 *
 *  Created on: Oct 17, 2024
 *      Author: thomas ashraf zaki
 */
#include <stdio.h>
int binary_search(int arr[],int item, int min, int max){
		int mid=(max+min)/2;
		//base case
		if(arr[mid]==item)
			return mid;
		//recursive case
	    if (min>=max){
			return -1;
		}
		 if(arr[mid]>item){
			max=mid-1;
			return 0 + binary_search(arr,item,min,max);
		}
		 if(arr[mid]<item){
			min=mid+1;
			return 0 + binary_search(arr,item,min,max);
		}

}
void main (void){
	int arr[]={2,4,13,33,45,66,76,402,555,652};
	int item;
	printf("Enter the item to search : \n");
	fflush(stdin);    	fflush(stdout);
	scanf("%d",&item);
	int min =0,max=sizeof(arr)/sizeof(int)-1;
	int result=binary_search(arr,item,min,max);
	if(result==-1)
		printf("the index is : none");
	else
		printf("the index is : %d",result);

}
