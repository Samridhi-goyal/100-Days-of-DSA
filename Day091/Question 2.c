/*Given an array nums with n objects colored red, white, or blue, sort them in-place 
so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.*/

void sortColors(int* nums, int numsSize){
    int low=0, mid=0, high=numsSize-1;

    while(mid<=high){
        if(nums[mid]==0){
            int t=nums[low]; nums[low]=nums[mid]; nums[mid]=t;
            low++; mid++;
        }
        else if(nums[mid]==1){
            mid++;
        }
        else{
            int t=nums[mid]; nums[mid]=nums[high]; nums[high]=t;
            high--;
        }
    }
}
