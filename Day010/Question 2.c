/*Given two integer arrays nums1 and nums2, return an array of their intersection. 
Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.*/

int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    
    // Sort both arrays
    qsort(nums1, nums1Size, sizeof(int), compare);
    qsort(nums2, nums2Size, sizeof(int), compare);
    
    int i = 0, j = 0, k = 0;
    
    // Allocate result array
    int* result = (int*)malloc(sizeof(int) * (nums1Size < nums2Size ? nums1Size : nums2Size));
    
    // Two pointer approach
    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] == nums2[j]) {
            result[k++] = nums1[i];
            i++;
            j++;
        } 
        else if (nums1[i] < nums2[j]) {
            i++;
        } 
        else {
            j++;
        }
    }
    
    *returnSize = k;
}
