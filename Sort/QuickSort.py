class QuickSort():
    """ 快速排序思想: 分治法
    1. 先从数列中取出一个数作为基准数
    2. 分区过程，将比这个数大的数全放到它的右边，小于等于它的数全放到它的左边
    3. 分别对左右区间重复第二步，直到各个区间只有一个数
    """

    # 分区，并返回枢轴位置
    def partition(self, nums, l, r):
        i = l
        j = r
        # 默认选取的枢轴为nums[l]
        pivot = nums[l]
        while i < j:
            # 从后向前搜索，找到小于等于pivot的数，放在pivot的左边
            while i < j and nums[j] >= pivot:
                j -= 1
            nums[i], nums[j] = nums[j], nums[i]
            
            # 从前向后搜索，找到大于等于pivot的数，放在pivot的右边
            while i < j and nums[i] < pivot:
                i += 1
            nums[i], nums[j] = nums[j], nums[i]
        # 返回pivot的位置
        return i

    # 递归，对枢轴的左右两部分分别进行快速排序
    def quickSort(self, nums, l, r):
        if l >= r:
            return nums
        i = self.partition(nums, l, r)
        self.quickSort(nums, l, i - 1)
        self.quickSort(nums, i + 1, r)
        return nums


if __name__ == '__main__':
    test = QuickSort()
    arr = [10, 7, 8, 9, 1, 5] 
    n = len(arr) 
    res = test.quickSort(arr, 0, n - 1) 
    print ("Sorted array:", res) 
