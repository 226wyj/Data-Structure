a = [1,2, 3, 5, 3, 2, 9, 28, 4, 6]

def simple_selection_sort(a):
    for i in range(len(a)): 
        min = i                         # min记录的是最小值的下标
        for j in range(i + 1, len(a)):
            if a[min] >= a[j]:
                min = j
        temp = a[min]
        a[min] = a[i]
        a[i] = temp
    return a   

print(simple_selection_sort(a))   