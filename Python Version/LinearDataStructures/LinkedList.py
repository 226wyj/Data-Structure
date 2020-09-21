class Node:
    """链表节点

    Attributes:
        data: 节点中存储的值
        next: 下一个节点的引用，类似于指针
    """


    def __init__(self, data):
        super().__init__()
        self.data = data
        self.next = None

class LinkedList:
    """动态链表

    Attributes:
        head: 头节点，不存储数据
    """


    def __init__(self):
        super().__init__()
        self.head = None
        
    def getLength(self):
        """获取链表长度，不包括头节点"""
        length = 0
        pre = self.head
        while pre:
            pre = pre.next
            length += 1
        return length
    
    def showList(self):
        """输出链表中的所有的值"""
        print('[', end=' ')
        pre = self.head
        while pre:
            print(pre.data, end=' ')
            pre = pre.next
        print(']')

    def appendData(self, data):
        """向链表末尾追加数据"""
        newNode = Node(data)
        if self.head is None: 
            self.head = newNode
        else:
            pre = self.head
            while pre:
                pre = pre.next
            pre = newNode
    
    def deleteData(self, data):
        """删除链表中的某个值，成功返回True，失败返回False"""
        if self.head is None:
            print("There's no data in the linkedlist.")
            return False
        pre = self.head
        nex = pre.next
        findFlag = False
        while nex:
            if nex.data == data:
                findFlag = True
                break
            pre = nex
            nex = pre.next
        if not findFlag:
            print("Sorry, the data doesn't exist in the linkedlist.")
            return False
        else:
            pre.next = nex.next
            return True

    def getData(self, index):
        """获取节点的值，index代表节点编号从1开始，我们规定第一个数据节点为1号节点
        
        Args:
            index: 节点编号
        
        Returns:    
            如果下表越界，返回None
            否则返回获取的data值
        """


        length = self.getLength()
        if index > length or index < 0:
            print("Index Out of range error")
            return None
        else:
            pre = self.head
            for i in range(index - 1):
                pre = pre.next
            return pre.data

    def setData(self, index, data):
        """将第index个节点的值设置为data，我们规定第一个数据节点为1号节点
        
        Args:   
            index: 下标
            data: 待设置的值
        
        Returns: 
            如果下标越界，返回False
            否则返回True
        """


        length = self.getLength()
        if index > length or index < 0:
            print("Index Out of range error")
            return False
        else:
            pre = self.head
            for i in range(index - 1):
                pre = pre.next
            pre.data = data
            return True

    def clearList(self):
        """清空整个链表"""
        self.head = None

if __name__ == "__main__":
    myList = LinkedList()
    # 向链表中插入1 ~ 5
    for i in range(1, 6):
        myList.appendData(i)
    myList.appendData(1)
    print("链表长度为: ", myList.getLength())
    myList.showList()

    myList.appendData(2)
    myList.showList()

