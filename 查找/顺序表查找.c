//顺序查找, a为数组, n为要查找的数组长度, key为要查找的关键字
int Sequential_Search(int *a, int n, int key)
{
    int i;
    for(i = 1; i <= n; i++)
    {
        if(a[i] == key)
            return i;
    }
    return 0;
}

//优化: 有哨兵的顺序查找
int Sequential_Search2(int *a, int n, int key)
{
    int i = n;
    a[0] = key;
    while(a[i] != key)
    {
        i--;
    }
    return i;   //返回0则说明查找失败
}