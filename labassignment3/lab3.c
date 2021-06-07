//Xiaoying Liu
//liu.xiaoying@northeastern.edu
/*
Insertion Sort:
	1. set a marker for the sorted section after the first element
	2. put the first unsorted element into a temp place and allocate it to the right place in sorted section
			a|b,c,d,e...
	   sorted|unsorted
	3. repeat step 2 util unsorted section is empty

Prathibha's instruction:
j=i-1 j>=0
in j loop

there should be three loops: 
1. for loop (unsorted);
2. while loop(sorted);
3. while(check the condition)
*/

#include <stdio.h>
#define MAX 8
int main()
{
    int arr[MAX] = {80,35,56,45,10,90,12,67};
    int i,j,temp;
    for (i=1; i<MAX; i++) {
    	j = i - 1;
    	temp = arr[i];
    	while (j>=0 && arr[j]>temp) {
    		arr[j+1]=arr[j];
    		j--;
    	}
    	arr[j+1]=temp;
    }
    
    for(i=0; i<MAX; i++) {
    	printf("%d\n", arr[i]);
    }
    
    return 0;
}
