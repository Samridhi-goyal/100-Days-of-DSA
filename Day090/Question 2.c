/*Given an integer array nums and an integer k, split nums into k non-empty subarrays such that the largest sum of any subarray is minimized.
Return the minimized largest sum of the split.A subarray is a contiguous part of the array.*/

int max(int a,int b){return a>b?a:b;}

int canSplit(int a[],int n,int k,int maxSum){
    int parts=1, curr=0;
    for(int i=0;i<n;i++){
        if(a[i]>maxSum) return 0;
        if(curr+a[i]>maxSum){
            parts++;
            curr=a[i];
            if(parts>k) return 0;
        } else curr+=a[i];
    }
    return 1;
}

int splitArray(int* nums, int numsSize, int k){
    int low=0, high=0, ans=0;

    for(int i=0;i<numsSize;i++){
        low = max(low, nums[i]);
        high += nums[i];
    }

    while(low<=high){
        int mid=(low+high)/2;
        if(canSplit(nums, numsSize, k, mid)){
            ans=mid;
            high=mid-1;
        } else low=mid+1;
    }
    return ans;
}

 
