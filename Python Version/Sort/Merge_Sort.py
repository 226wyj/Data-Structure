import math

class MergeSort:
    """归并排序，这里默认按照升序排列"""

    def mergeSort(self, array):
        arrayLength = len(array)
        if arrayLength < 2:
            return array
        # 将序列拆分成两部分
        middle = math.floor(arrayLength / 2)
        leftArray = array[:middle]
        rightArray = array[middle:]
        # 分别对两部分进行排序，然后拼在一起
        return self.__merge(self.mergeSort(leftArray), 
                            self.mergeSort(rightArray))

    def __merge(self, leftArray, rightArray):
        # 拼接操作
        mergeResult = []
        while leftArray and rightArray:
            if leftArray[0] <= rightArray[0]:
                mergeResult.append(leftArray.pop(0))
            else:
                mergeResult.append(rightArray.pop(0))
        while leftArray:
            mergeResult.append(leftArray.pop(0))
        while rightArray:
            mergeResult.append(rightArray.pop(0))
        return mergeResult
    
    def showResults(self, array):
        print("--------------------------------------")
        print("未排序前的数组: ")
        print(array)
        print("排序后的数组: ")
        print(self.mergeSort(array))
        print("--------------------------------------")

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