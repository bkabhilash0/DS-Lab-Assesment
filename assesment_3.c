// Sorting Algorithms - Selection, Bubble and Insertion Sort
#include <stdio.h>
#include <stdlib.h>

void read(int *arr,int n){
	int i;
	printf("Enter the Array Elements\n");
	for(i=0;i<n;i++){
		printf("Enter Element %d: ",i+1);
		scanf("%d",(arr+i));
	}
}

void selectionSort(int *arr,int n){
	int i,j,temp;
	for(i=0;i < n-1;i++){
		for(j=i+1;j < n;j++){
			if(arr[j] < arr[i]){
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void bubbleSort(int *arr,int n){
	int i,j,temp;
	for(i=0;i < n-1;i++){
		for(j=0;j < n-1-i;j++){
			if(arr[j] > arr[j+1]){
				temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
}

void insertionSort(int *arr,int n){
	int i,j,key;
	// Considering the First Element to be sorted
	for(i=1;i<n;i++){
		j = i -1;
		key = arr[i];
		
		while(key < arr[j] && j >= 0){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}

void display(int *arr,int n){
	int i;
	printf("The Array Elements are:\n");
	for(i=0;i<n;i++){
		printf("%d",arr[i]);
		if(i < n-1){
			printf(", ");
		}	
	}
	printf("\n");
}

int menu(int *arr,int n){
	int ch;
	printf("Sorting Algorithms\n");
	printf("---------------------------------\n");
	printf("1. Selection Sort\n");
	printf("2. Bubble Sort\n");
	printf("3. Insertion Sort\n");
	printf("4. Exit\n");
	printf("Enter a Choice: ");
	scanf("%d",&ch);
	switch(ch){
		case 1: selectionSort(arr,n);
				printf("After Using Selection Sort:\n");
				break;
		case 2: bubbleSort(arr,n);
				printf("After Using Bubble Sort:\n");
				break;
		case 3: insertionSort(arr,n);
				printf("After Using Insertion Sort:\n");
				break;
		case 4: return -1;
		default: printf("Enter a Valid Choice!\n");
	}
}

void main(){
	int *arr,n,i;
	printf("Enter the size of the Array: ");
	scanf("%d",&n);
	arr = (int*)malloc(n*sizeof(int));
	read(arr,n);
	printf("Before Sorting\n");
	display(arr,n);
	while(1){
		if(menu(arr,n) == -1){
			break;
		}
		display(arr,n);
		break;
	}
	
	printf("Exiting....\n");
}
