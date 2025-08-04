/*
 * main.c
 *
 *  Created on: Oct 21, 2024
 *      Author: thomas ashraf zaki
 */

#include <stdio.h>
#include <math.h>
int Max_In_List(int arr[],int size){
	//base case when the length =2
	if (size==2){
		if(arr[0]>arr[1])
			return arr[0];
		else
			return arr[1];
	}
	//recusive case when compare arr[i]>arr[++1]
	int max =Max_In_List(&arr[1],--size);
	return ((arr[0]>max?arr[0]:max));
}

void main (void){
	int list[]={1,5,7,9,6,4,99};
	int max = Max_In_List(list,(sizeof(list)/sizeof(int)));
	printf("the max is : %d",max);
}

