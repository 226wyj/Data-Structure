def quickSort(nums):
    if len(nums) <= 1:
        return nums
    
    mid = len(nums) // 2
    pivot = nums[mid]
    
    left, right = [], []
    for i, num in enumerate(nums):
        if i == mid:
            continue
        if num <= pivot:
            left.append(num)
        elif num > pivot:
            right.append(num)
    
    return quickSort(left) + [pivot] + quickSort(right)

if __name__ == '__main__':
    arr = [10, 7, 8, 9, 1, 5] 
    print ("Sorted array:", quickSort(arr)) 
