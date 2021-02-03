class BinarySearch:
    """
    二分查找，nums代表待查找的顺序表，target代表目标元素
    返回值为目标元素的下标，若未找到则返回-1
    要求顺序表必须有序
    """
    def binary_search(self, nums, target):
        left = 0
        right = len(nums) - 1
        while left <= right:
            mid = (left + right) // 2
            if nums[mid] == target:
                return mid
            elif nums[mid] < target:
                left = mid + 1
            elif nums[mid] > target:
                right = mid - 1
        return -1

if __name__ == "__main__":
    nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10]
    demo = BinarySearch()
    print(demo.binary_search(nums, 3))