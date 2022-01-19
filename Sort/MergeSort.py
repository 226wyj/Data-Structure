class MergeSort:
    """归并排序，这里默认按照升序排列"""

    def mergeSort(self, array):
        if len(array) <= 1:
            return array
        # 将序列拆分成两部分
        mid = len(array) // 2
        left = self.mergeSort(array[:mid])
        right = self.mergeSort(array[mid:])
        # 分别对两部分进行排序，然后拼在一起
        return self.merge(left, right)

    def merge(self, left, right):
        # 拼接操作
        res = []
        while left and right:
            if left[0] < right[0]:
                res.append(left.pop(0))
            else:
                res.append(right.pop(0))
        res += left
        res += right
        return res
    
    def showResults(self, array):
        print("未排序前的数组: ")
        print(array)
        print("排序后的数组: ")
        print(self.mergeSort(array))
        print()

if __name__ == "__main__":
    data1 = [1, 2, 4, 3, 7, 5, 0, 6]
    data2 = [1]
    data3 = [6, 5, 4, 3, 2, 1, 0]
    data4 = [1, 2, 0]   
    demo = MergeSort()
    demo.showResults(data1)
    demo.showResults(data2)
    demo.showResults(data3)
    demo.showResults(data4)