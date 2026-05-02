/*Given an integer array nums and an integer k, return the kth largest element in the array.
Note that it is the kth largest element in the sorted order, not the kth distinct element.
Can you solve it without sorting?*/

int findKthLargest(int* nums, int n, int k){
    int l=0, r=n-1, target=k-1;

    while(l<=r){
        int pivot = nums[l + rand()%(r-l+1)];

        int i=l, lt=l, gt=r;

        while(i<=gt){
            if(nums[i] > pivot){
                int t=nums[i]; nums[i]=nums[lt]; nums[lt]=t;
                i++; lt++;
            }
            else if(nums[i] < pivot){
                int t=nums[i]; nums[i]=nums[gt]; nums[gt]=t;
                gt--;
            }
            else{
                i++;
            }
        }

        if(target < lt) r = lt-1;
        else if(target > gt) l = gt+1;
        else return nums[target];
    }
    return -1;
}
