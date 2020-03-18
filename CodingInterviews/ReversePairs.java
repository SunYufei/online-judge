class Solution {
    public int reversePairs(int[] nums) {
        if (nums == null || nums.length == 0)
            return 0;
        return mergeSort(nums, 0, nums.length - 1);
    }

    int mergeSort(int[] nums, int l, int r) {
        if (l >= r)
            return 0;
        int m = (l + r) >> 1;
        int count = mergeSort(nums, l, m) + mergeSort(nums, m + 1, r);
        int[] cache = new int[r - l + 1];
        int i = l, t = l, c = 0;
        for (int j = m + 1; j <= r; j++, c++) {
            while (i <= m && nums[i] <= nums[j])
                ++i;
            while (t <= m && nums[t] < nums[j])
                cache[c++] = nums[t++];
            cache[c] = nums[j];
            count += m - i + 1;
        }
        while (t <= m)
            cache[c++] = nums[t++];
        System.arraycopy(cache, 0, nums, l, r - l + 1);
        return count;
    }
}