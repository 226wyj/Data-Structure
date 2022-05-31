from typing import List
from random import randint

from pyparsing import nums


def count_sort(arr: List[int]) -> List[int]:
    # 根据数组中的最大值和最小值确定另开辟数组的空间大小
    max_num = max(arr)
    min_num = min(arr) 
    length = max_num - min_num + 1

    # 将原数组中的元素的值作为下标偏移量映射到辅助计数数组中
    count = [0] * length
    for index in arr:
        count[index - min_num] += 1
    
    # 根据计数数组中各个坐标还原数组元素
    index = 0
    for idx, cnt in enumerate(count):
        while cnt:
            arr[index] = idx + min_num
            cnt -= 1
            index += 1
    return nums


if __name__ == '__main__':
    arr = []
    for i in range(10):
        arr.append(randint(1, 10))
    print(arr)
    print(count_sort(arr))
