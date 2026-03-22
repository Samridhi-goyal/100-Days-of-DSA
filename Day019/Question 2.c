/*Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums
A circular array means the end of the array connects to the beginning of the array.
Formally, the next element of nums[i] is nums[(i + 1) % n] and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j], 
there does not exist i <= k1, k2 <= j with k1 % n == k2 % n*/

int maxSubarraySumCircular(int* nums, int numsSize) {
    int total = 0;
    int maxSum = nums[0], currMax = 0;
    int minSum = nums[0], currMin = 0;

    for(int i = 0; i < numsSize; i++) {
        currMax = (currMax > 0) ? currMax + nums[i] : nums[i];
        if(currMax > maxSum) maxSum = currMax;

        currMin = (currMin < 0) ? currMin + nums[i] : nums[i];
        if(currMin < minSum) minSum = currMin;

        total += nums[i];
    }

    if(maxSum < 0) return maxSum;

    return (total - minSum > maxSum) ? (total - minSum) : maxSum;
}
