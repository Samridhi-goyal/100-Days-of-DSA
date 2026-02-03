/*You are given an array arr[] of size n - 1 that contains distinct integers in the range from 1 to n (inclusive). 
This array represents a permutation of the integers from 1 to n with one element missing.
Your task is to identify and return the missing element.*/

int missingNum(int *arr, int size) {
    long long expected_sum=(long long) (size+1)*(size+2)/2;
    
    long long actual_sum=0;
    for(int i=0; i<size;i++){
        actual_sum=actual_sum+arr[i];
    }
    
    return (int)(expected_sum-actual_sum);
    
}


