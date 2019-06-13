//折半查找
int Binary_Search(int *a, int n, int key)
{
    int low, high, mid;
    low = 1;
    high = n;
    while(low < high)
    {
        mid = (high + low) / 2;
        if(key < a[mid])
        {
            high = mid - 1;
        }
        else if(key > a[mid])
        {
            low = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return 0;   //查找失败
}

//插值查找, 对折半查找的改进
in Insert_Search(int *a, int n, int key)
{
    int low, high, mid;
    low = 1;
    high = n;
    while(low < high)
    {
        mid = low + (high - low) * (key - a[low]) / (a[high] - a[low]);
        if(key < a[mid])
            high = mid - 1;
        else if(key > a[mid])
            low = mid + 1;
        else
            return mid;
    }
    return 0;
}

//斐波那契查找
int Fibonacci_Search(int *a, int n, int key)
{
    int low, high, mid, i, k;
    low = 1;
    high = n;
    k = 0;
    while(n > F[k] - 1)
        k++;
    for(i = n; i < F[k] - 1; i++)
        a[i] = a[n];
    while(low <= high)
    {
        mid = low + F[k-1] - 1;
        if(key < a[mid])
        {
            high = mid - 1;
            k = k - 1;
        }
        else if(key > a[mid])
        {
            low = mid + 1;
            k = k - 2;
        }
        else
        {
            if(mid <= n)
                return mid;
            else 
                return n;
        }
    }
    return 0; 
}