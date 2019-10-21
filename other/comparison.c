#include "stdint.h"
#include "stdio.h"

//比对两个数组的n个数据是否相等,是范围0，否返回0
int comparison_bytes(const uint8_t *scr,const uint8_t *dest,uint16_t n)
{
    for(uint16_t i=0;i<n;i++)
    {
        if( *(scr+i)  != *(dest+i))
        {
            return 0;
        }
    }
   return 1;
}

//void main()
//{
//   uint8_t data1[3] = {1,1,3};
//   uint8_t data2[3] = {1,2,3};
//   printf("%d\n",comparison_bytes(data1,data2,3));
//}