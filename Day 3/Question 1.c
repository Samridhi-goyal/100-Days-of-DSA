/*Problem: Implement linear search to find key k in an array. Count and display the number of comparisons performed.

Input:
- First line: integer n (array size)
- Second line: n space-separated integers
- Third line: integer k (key to search)

Output:
- Line 1: "Found at index i" OR "Not Found"
Line 2: "Comparisons = c"

Example:
Input:
5
10 20 30 40 50
30

Output:
Found at index 2
Comparisons = 3

Explanation: Compared with 10, 20, 30 (found at index 2 with 3 comparisons)*/

#include <stdio.h>
int main(){
    int n;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    
    int arr[n];
    printf("Enter %d  numbers: \n",n);
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    
    int k,store_index=-1,count=0;
    printf("Enter the target or key to be searched: \n");
    scanf("%d",&k);
    
    for (int j=0; j<n; j++){
        count++;
        if(arr[j] == k){
            store_index=j;
            break;
        }
    }
    
    if(store_index>=0){
        printf("Found at index: %d \n",store_index);
        printf("Number of comparisons made:%d \n",count);
    }
    else{
        printf("Not found \n");
        printf("Number of comparisons made:%d \n",count);
    }
}
