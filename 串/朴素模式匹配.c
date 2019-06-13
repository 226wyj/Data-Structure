//假定串的类型为String，而且串的长度存在0号单元
//返回子串T在主串S中第pos个字符之后的位置，若不存在则返回0
int Index(String S, String T, int pos)
{
    int i = pos;
    int j = 1;  //从T的第一个字符开始
    while(i <= S[0] && j <= T[0])
    {
        if(S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;  //i退回到上次匹配首位的下一位
            j = 1;  //j退回到子串首位
        }
    }
    if(j > T[0])    //匹配成功
        return i - T[0];  
    else
        return 0;
}