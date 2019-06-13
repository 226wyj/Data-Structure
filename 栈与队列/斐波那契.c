#include <stdio.h>

int Fbi(int i)
{
    if(i < 2)
    {
        return i == 0 ? 0 : 1;
    }
    else
    {
        return Fbi(i - 1) + Fbi(i - 2);
    }
}

int main()
{
    int i;
    for(int i = 0; i < 40; i++)
    {
        printf("%d : %d\n", i + 1, Fbi(i));
    }
    return 0;
}
