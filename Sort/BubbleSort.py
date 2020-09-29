class BubbleSort:
    """冒泡排序，默认按升序排序。这里除了基础版本，还展示了两种变体"""

    def primaryBubbleSort(self, array):
        for i in range(len(array)):
            for j in range(i+1, len(array)):
                if array[i] >= array[j]:
                    temp = array[j]
                    array[j] = array[i]
                    array[i] = temp
        return array

    def normalBubbleSort(self, array):
        for i in range(len(array)):
            for j in range(len(array) - 1, i, -1):
                if array[i] >= array[j]:
                    temp = array[j]
                    array[j] = array[i]
                    array[i] = temp
        return array

    def advancedBubbleSort(self, array):
        # flag用于避免无用的遍历操作，当遍历了整个序列后都没有发生交换操作
        # 则说明序列已经有序，直接退出循环
        flag = True     
        for i in range(len(array)):
            if flag:
                flag = False
                for j in range(len(array) - 1, i - 1, -1):
                    if array[i] >= array[j]:
                        temp = array[j]
                        array[j] = array[i]
                        array[i] = temp
                        flag = True
            else:
                break
        return array

    def showResults(self, array):
        print("---------------------------------------")
        print("排序前: ")
        print(array)
        print("排序后: ")
        print(self.advancedBubbleSort(array))       # 根据需求调用三种冒泡排序方法中的任意一种即可
        print("---------------------------------------")       

if __name__ == "__main__":
    data1 = [1, 2, 4, 3, 7, 5, 0, 6]
    data2 = [2, 1, 3, 4, 7, 9, 5, 8, 6]

    demo = BubbleSort()
    demo.showResults(data1)
    demo.showResults(data2)   