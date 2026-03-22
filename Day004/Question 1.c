/*Problem: Given an array of n integers, reverse the array in-place using two-pointer approach.

Input:
- First line: integer n
- Second line: n space-separated integers

Output:
- Print the reversed array, space-separated

Example:
Input:
5
1 2 3 4 5

Output:
5 4 3 2 1

Explanation: Swap pairs from both ends: (1,5), (2,4), middle 3 stays*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array: \n");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter %d numbers: \n",n);
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int j,k;
    for(j=0,k=(n-1);j<(n/2);j++,k--){
        arr[j]=arr[j]+arr[k];
        arr[k]=arr[j]-arr[k];
        arr[j]=arr[j]-arr[k];
    }
    
    printf("The updated array is: \n");
    for(int a=0;a<n;a++){
        printf("%d \t",arr[a]);
    }
}
