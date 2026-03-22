/*Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
The product of any prefix or suffix of nums is guaranteed to fit in a 32-bit integer.
You must write an algorithm that runs in O(n) time and without using the division operation.*/

int* productExceptSelf(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * numsSize);
    
    result[0] = 1;
    for(int i = 1; i < numsSize; i++) {
        result[i] = result[i - 1] * nums[i - 1];
    }
    
    int right = 1;
    for(int i = numsSize - 1; i >= 0; i--) {
        result[i] = result[i] * right;
        right *= nums[i];
    }
    
    *returnSize = numsSize;
    return result;
}
