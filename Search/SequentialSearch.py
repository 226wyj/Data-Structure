class SequentialSearch:
    """
    顺序查找，若找到则返回目标元素下标，否则返回-1
    """
    def sequential_search(self, nums, val):
        for num in nums:
            if num == val:
                return nums.index(num)
        return -1

if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    demo = SequentialSearch()
    print(demo.sequential_search(nums, 3))