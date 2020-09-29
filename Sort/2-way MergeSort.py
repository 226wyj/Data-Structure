def isLastElement(T0, subList, tape, EOF):
    """ 检查是否刚好取到了T0中的最后一个元素
    Parameter:
        T0: 待检查纸带
        subList:    拼接好的最大子序列
        tape:   待插入最大子序列的纸带
        EOF:    结束符

    Return:
        None
    """
    if len(T0) == 0:
        subList.append(EOF)
        tape.append(subList)

def distribute(T0, T1, T2, EOF="END"):
    """将T0中的最大递增子序列依次拆分到T1和T2中
    Parameter:
        T0: 待拆分的纸带
        T1: 辅助纸带1
        T2: 辅助纸带2
        EOF:    结束符
    
    Return: 
        None
    """
    subList = []
    T1.clear()
    T2.clear()
    tapeNum = 1
    while T0:
        tape = T1 if tapeNum % 2 == 1 else T2
        # subList为空，说明还未构造子序列，直接将当前元素插入subList即可
        if subList == []:
            currentNum = T0.pop(0)
            subList.append(currentNum)
            # 每次弹出一个元素之后都要立即检查是否刚好取到了最后一个元素
            isLastElement(T0, subList, tape, EOF)
        else:
            nextNum = T0[0]
            if nextNum >= currentNum:
                subList.append(nextNum)
                T0.pop(0)
                currentNum = nextNum
                # 检查是否刚好取到了最后一个元素
                isLastElement(T0, subList, tape, EOF)
            else:
                subList.append(EOF)                     # 子序列末尾插入终结符
                tape.append(subList)
                subList = []                            # 初始化子序列
                tapeNum += 1                            # 更新纸带编号


def mergeSort(T0, T1, T2, EOF="END"):
    """归并排序
    Parameter:
        T0: 存储原始数据的纸带
        T1: 辅助纸带1
        T2: 辅助纸带2
    
    Return:
        T0[0]，一个已经排好序的序列
    """
    distribute(T0, T1, T2, EOF)
    T0.clear()
    while True:
        # T1和T2中的子序列数量要么相等，要么T2比T1少一个
        # 若T2中的子序列数量较少，则要插入一个空列表
        if len(T2) < len(T1):
            T1.append([])
        assert len(T1) == len(T2)
        mergeCounts = len(T1)
        for i in range(mergeCounts):
            T0.append(merge(T1[i], T2[i]))
        # 当T0中只有一个元素时，则说明排序结束，只剩下了一个完全有序的序列
        if len(T0) == 1:
            break
        else:
            # 将T0中合并好的子序列重新分配到T1和T2中
            # 然后清空T0，重复执行merge操作
            T1.clear()
            T2.clear()
            for i in range(len(T0)):
                tape = T1 if i % 2 == 0 else T2
                tape.append(T0[i])
            T0.clear()
    return T0[0][:-1]   # 返回值要去掉末尾的结束符
    

def merge(subList1, subList2, EOF="END"):
    """将两个内部已经分别有序的子序列按照升序合并成一个序列
    Parameter:
        subList1:   待处理子序列1
        subList2:   待处理子序列2
        EOF:    结束符
    
    Return:
        result: 列表，存储了合并的结果
    """
    result = []
    # 这里取subList的长度>1是为了去掉末尾的EOF结束符
    # 当subList中仅剩EOF时，代表此序列已经被全部处理
    while len(subList1) > 1 and len(subList2) > 1:
        if subList1[0] <= subList2[0]:
            result.append(subList1.pop(0))
        else:
            result.append(subList2.pop(0))
    while len(subList1) > 1:
        result.append(subList1.pop(0))
    while len(subList2) > 1:
        result.append(subList2.pop(0))
    result.append(EOF)  # 最后还要在合并后的序列末尾加入结束符
    return result

if __name__ == "__main__":
    T0 = [1, 8, 2, 5 ,9, 4, 3, 5, 6, 7]
    T1, T2 = [], []
    print(mergeSort(T0, T1, T2))