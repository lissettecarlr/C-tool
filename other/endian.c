#include "stdio.h"

/**
 * @brief 判断大小端
 * @return 返回0表示是大端存储，其他为小端
*/
int IsBigEndian(void)
{
    union Endian
    {
        short int a;
		char b;
    }temp;
    temp.a = 0X1234;
    if(temp.b == 0X12) //低字节存储了高位数据 为大端
        return 0;
    else
        return 1;
}

int main()
{
    if(IsBigEndian() == 0)
    {
        printf("big\n");
    }
    else
        printf("small\n");
    return 0;
}