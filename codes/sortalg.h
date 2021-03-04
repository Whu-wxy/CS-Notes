#ifndef SORTALG_H
#define SORTALG_H

#include <vector>
#include <iostream>
#include <algorithm>

using namespace  std;

//冒泡排序
void bibleSort(vector<int>& arr, int n)
{
    for(int i=0; i<n; i++)
    {
        bool bSorted = false; //优化，当前一轮没有进行交换时，说明数组已经有序，没有必要再进行下一轮的循环了
        for(int j = 1; j<n-i; j++)  //一次把一个元素放到后面
        {
            if(arr[j] < arr[j-1])
            {
                bSorted = true;
                swap(arr[j], arr[j-1]);
            }
        }
        if(!bSorted) break;
    }
}

// 快速排序
void quickSort(vector<int>& arr, int l, int r)
{
    if(l >= r) return;

    int temp = arr[l];
    int left = l;
    int right = r;

    // 以l为基准，比l小的放左边，比l大的放右边
    while(l < r)
    {
        while(l<r && arr[r]>=temp) r--;  //注意r先减
        while(l<r && arr[l]<=temp) l++;
        swap(arr[l], arr[r]); //小的放左边，大的放右边
    }
    swap(arr[left], arr[r]); //把基准移动到中间，出了循环，arr[r]一定是比基准小的，因此可以交换

    quickSort(arr, left, r-1);  //左闭右闭
    quickSort(arr, r+1, right);
}

// 直接插入排序
void insertSort(vector<int>& arr, int n)
{
    for(int i=1; i<n; i++)
    {
        int pos = i;
        int val = arr[i];
        while(pos>0 && arr[pos-1] > val)
        {
            arr[pos] = arr[pos-1];
            pos--;
        }
        arr[pos] = val;
    }
}

// 希尔排序
void shellSort(vector<int>& arr, int n)
{
    int d = n/2; //增量d，每次减半，逐渐减少到1（最后一个一定要为1）
    for(; d>=1; d/=2)
    {
        for(int i=d; i<n; i++)
        {
            int pos = i;
            int val = arr[pos];
            while(pos-d>=0 && arr[pos-d] > val)
            {
                arr[pos] = arr[pos-d];
                pos -= d;
            }
            arr[pos] = val;
        }
    }
}

// 归并排序
void mergeSort(vector<int>& arr, int l, int r)
{
    if(l == r) return; //只有一个， 不用排序

    int mid = l + (r-l)/2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid+1, r);

    vector<int> temp(r-l+1, 0);

    int ptrL = l, ptrR = mid+1;
    int ptrRes = 0;
    while(ptrL <= mid && ptrR <= r)
    {
        if(arr[ptrL] <= arr[ptrR])
            temp[ptrRes++] = arr[ptrL++];
        else
            temp[ptrRes++] = arr[ptrR++];
    }
    while(ptrL <= mid)
        temp[ptrRes++] = arr[ptrL++];
    while(ptrR <= r)
        temp[ptrRes++] = arr[ptrR++];

    for(int i=l,j=0; i<=r; i++,j++) //把排好的段复制回arr
        arr[i] = temp[j];
}

// 选择排序
void selectSort(vector<int>& arr)
{
    for(int i=0; i<arr.size(); i++)
    {
        int minIdx = i;
        for(int j=i+1; j<arr.size(); j++)
        {
            if(arr[j] < arr[minIdx])
                minIdx = j;
        }
        swap(arr[i], arr[minIdx]);
    }
}


// 堆排序
//调整堆，以start位置为根节点，调整到end
void adjustHeap(vector<int>& arr, int start, int end)
{
    int root = start;
    int child = 2*start + 1; //索引从0开始是这个，如果从1开始，则为2*start
    while(child <= end)
    {
        if(child < end && arr[child] < arr[child+1]) //找左右结点最大的那个
            child++;  //切换到右节点

        if(arr[root] >= arr[child]) return; //父节点比最大的子节点大，说明调整到位
        else
        {
            swap(arr[root], arr[child]);
            root = child;
            child = 2*root + 1;
        }
    }
}

// 从小到大，大根堆
void heapSort(vector<int>& arr, int n)
{
    for(int i=n/2; i>=0; i--)
    {
        adjustHeap(arr, i, n);  //筛选算法，从最下面的非叶子结点向根节点调整，大的上浮，小的下沉
    }

    for(int i=0; i<=n; i++) //注意：这里调整n的数值可以只找出topK个最大/最小的
    {
        swap(arr[0], arr[n-i]);   //把大根堆根节点和最后一个交互，即把最大值移到了最后
        adjustHeap(arr, 0, n-i-1);  //调整根节点，注意：已排好元素不在树中了
    }
}



// 桶排序
void bucketSort(vector<int>& arr)
{
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i: arr)
    {
        minVal = min(minVal, i);
        maxVal = max(maxVal, i);
    }

    int bucketNum = (maxVal-minVal) / arr.size() + 1;  //每个桶的范围大小为arr.size
    vector<vector<int>> buckets(bucketNum, vector<int>());
    for(int i: arr)
    {
        int idx = (i-minVal) / arr.size();
        buckets[idx].push_back(i);
    }

    for(auto &bucket: buckets)    // 注意这里是引用
        sort(bucket.begin(), bucket.end());

    int idx = 0;
    for(auto bucket: buckets)
    {
        for(int i: bucket)
        {
            arr[idx++] = i;
        }
    }
}

// 计数排序
void countSort(vector<int>& arr)
{
    int minVal = INT_MAX, maxVal = INT_MIN;
    for(int i: arr)
    {
        minVal = min(minVal, i);
        maxVal = max(maxVal, i);
    }
    vector<int> temp(maxVal-minVal+1, 0);
    for(int i: arr)
        temp[i-minVal]++;

    int i = 0, j = 0;
    for(int j=0; j<temp.size(); j++)
    {
        while(temp[j]--)
            arr[i++] = j + minVal;
    }
}

// 基数排序
void radixSort(vector<int>& arr)
{
    int idx = 1, maxVal = INT_MIN;
    for(int i: arr)
    {
        maxVal = max(maxVal, i);
    }

    vector<vector<int>> radix(10, vector<int>());  // 0~9
    while(idx < maxVal)
    {
        for(int i: arr)
        {
            int rest = i / idx;
            radix[rest % 10].push_back(i);   // 根据每一位数放到0~9的桶中，基数是桶的索引
        }

        // 每一位数都将所有数据合并
        int j = 0;
        for(auto vec: radix)
        {
            for(int i: vec)
                arr[j++] = i;
        }
        radix.clear();
        idx *= 10;
    }
}


void sortTest()
{
    vector<int> temp;
//    vector<int> arr{9,8,7,6,5,4,3,2,1,0};
    vector<int> arr{1,3,5,7,2,6,4,8,9,2,8,7,6,0,3,5,9,4,1,0};
//    vector<int> arr{63,157,189,51,101,47,141,121,157,156,194,117,98,139,67,133,181,13,28,109};

//    bibleSort(arr, arr.size());
//    quickSort(arr, 0, arr.size()-1);
//    insertSort(arr, arr.size());
//    shellSort(arr, arr.size());
//    mergeSort(arr, 0, arr.size()-1);
//    selectSort(arr);
//    heapSort(arr, arr.size()-1);
//    bucketSort(arr);
//    countSort(arr);
    radixSort(arr);

    for(auto i: arr)
       cout<<i<<",";
}


// ///////////////////////////////////////
// 快速排序  k-th Element 问题
//int quickSort(vector<int>& nums, int l, int r, int k)
//{
//    if(l >= r)
//    {
//        if(r == nums.size()-k)
//            return nums[r];
//        else
//            return -1;
//    }

//    int left = l;
//    int right = r;
//    int val = nums[l];
//    while(l < r)
//    {
//        while(l<r && nums[r] >= val) r--;
//        while(l<r && nums[l] <= val) l++;
//        swap(nums[l], nums[r]);
//    }
//    swap(nums[left], nums[r]);
//    if(r == nums.size()-k)
//        return val;
//    else if(r > nums.size()-k)
//        return quickSort(nums, left, r-1, k);
//    else if(r < nums.size()-k)
//        return quickSort(nums, r+1, right, k);
//}

//int findKthLargest(vector<int>& nums, int k) {
//    return quickSort(nums, 0, nums.size()-1, k);
//}

int helper(vector<int>& nums, int l, int r)
{
    int left = l;
    int right = r;
    int val = nums[l];
    while(l < r)
    {
        while(l<r && nums[r] >= val) r--;
        while(l<r && nums[l] <= val) l++;
        swap(nums[l], nums[r]);
    }
    swap(nums[left], nums[r]);
    return r;
}

int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size()-1;
    while(l < r)
    {
        int res = helper(nums, l, r);
        if(res == nums.size()-k) return nums[res];
        else if(res > nums.size()-k)
            r = res - 1;
        else
            l = res + 1;
    }
    return nums[l];
}




#endif // SORTALG_H
