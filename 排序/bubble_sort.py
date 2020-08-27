a = [1,2, 3, 5, 3, 2, 9, 28, 4, 6]
b = [2, 1, 3, 4, 5, 6, 7, 8, 9]

def primary_bubble_sort(a):
    for i in range(len(a)):
        for j in range(i+1, len(a)):
            if a[i] >= a[j]:
                temp = a[j]
                a[j] = a[i]
                a[i] = temp
    return a

def normal_bubble_sort(a):
    for i in range(len(a)):
        for j in range(len(a) - 1, i, -1):
            if a[i] >= a[j]:
                temp = a[j]
                a[j] = a[i]
                a[i] = temp
    return a

def advanced_bubble_sort(a):
    flag = True
    for i in range(len(a)):
        if flag:
            flag = False
            for j in range(len(a) - 1, i - 1, -1):
                if a[i] >= a[j]:
                    temp = a[j]
                    a[j] = a[i]
                    a[i] = temp
                    flag = True
        else:
            break
    return a

print(normal_bubble_sort(a))   