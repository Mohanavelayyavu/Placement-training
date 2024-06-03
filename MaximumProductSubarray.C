int maxProduct(int* nums, int numsSize) {
    if (numsSize == 0) return 0;

    int current_max = nums[0];
    int current_min = nums[0];
    int global_max = nums[0];

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] < 0) {
            int temp = current_max;
            current_max = current_min;
            current_min = temp;
        }

        long long max_prod = (long long)nums[i] * current_max;
        long long min_prod = (long long)nums[i] * current_min;
        
        current_max = nums[i] > max_prod ? nums[i] : (int)max_prod;
        current_min = nums[i] < min_prod ? nums[i] : (int)min_prod;

        if (current_max > global_max) {
            global_max = current_max;
        }
    }

    return global_max;
}
