class InsertionSort:
    """插入排序，这里默认按升序排列"""

    def insertionSort(self, array):
        for i in range(1, len(array)):
            tmp = array[i]
            j = i - 1
            while j >= 0 and array[j] > tmp:
                array[j + 1] = array[j]
                j -= 1
            array[j + 1] = tmp
        return array

    def showResults(self, array):
        print("---------------------------------------")
        print("排序前: ")
        print(array)
        print("排序后: ")
        print(self.insertionSort(array))  
        print("---------------------------------------")   

if __name__ == "__main__":
    data1 = [1, 2, 4, 3, 7, 5, 0, 6]
    data2 = [2, 1, 3, 4, 7, 9, 5, 8, 6]

    demo = InsertionSort()
    demo.showResults(data1)
    demo.showResults(data2)   