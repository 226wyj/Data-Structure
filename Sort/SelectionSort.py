class SelectionSort:
    """选择排序，默认按升序排列"""

    def simpleSelectionSort(self, array):
        for i in range(len(array)):
            # min记录最小值的下标，每一次都选择待排序列中最小的一个元素，将其移动到序列最左边
            min = i
            for j in range(i + 1, len(array)):
                if array[min] >= array[j]:
                    min = j
            temp = array[min]
            array[min] = array[i]
            array[i] = temp
        return array
    
    def showResults(self, array):
        print("----------------------------------------")
        print("排序前: ")
        print(array)
        print("排序后: ")
        print(self.simpleSelectionSort(array))
        print("----------------------------------------")

if __name__ == "__main__":
    array = [1,2, 3, 5, 3, 2, 9, 28, 4, 6]
    demo = SelectionSort()
    demo.showResults(array)