#ifndef BINARY_SEARCH_H
#define BINARY_SEARCH_H

#include <vector>

using namespace std;

// 二分法模板
int binary_search(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while(left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else if(nums[mid] == target)
            return mid;// 直接返回
    }
    // 直接返回
    return -1;
}

int left_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] == target)
            right = mid - 1;   // 别返回，锁定左侧边界
    }
    // 最后要检查 left 越界的情况
    if (left >= nums.size() || nums[left] != target)
        return -1;
    return left;
}


int right_bound(vector<int> nums, int target) {
    int left = 0, right = nums.size() - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)
            left = mid + 1;
        else if (nums[mid] > target)
            right = mid - 1;
        else if (nums[mid] == target)
            left = mid + 1;// 别返回，锁定右侧边界
    }
    // 最后要检查 right 越界的情况
    if (right < 0 || nums[right] != target)
        return -1;
    return right;
}

#endif // BINARY_SEARCH_H
