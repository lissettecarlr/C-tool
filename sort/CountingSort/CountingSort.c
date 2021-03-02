#include "stdio.h"
#include "stdlib.h"
#include "string.h"

//工具函数，用于输出数组数据
void qprint(int* pData, int count)
{
    printf("\n");
	for (int i = 0; i< count; i++) 
    {
        printf("[%d] ",pData[i]);
	}
    printf("\n");
}

void CountSort(int a[],int n)
{
    int i=0,j=0,max=0;
    //找到最大值，节约内存
    for(i=0;i<n;i++)
    {
        if(a[i] >max)
        {
            max = a[i];
        }
    }

    int *b = (int *)malloc((max + 1) * sizeof(int));
    memset(b, 0, (max + 1) * sizeof(b[0]));
    //填充hash表
    for (i = 0; i < n; i++) b[a[i]]++;
    //按照顺序读出
    for (i = 0,j=0; i < (max + 1); i++)  // unstable , stabilized by prefix sum array
    {
        if (b[i] > 0)
        {
            while (b[i] != 0)  // for case when number exists more than once
            {
                a[j++] = i;
                b[i]--;
            }
        }
    }
    free(b);
}


int main(void)
{
    int a[9] = {7,4,9,3,2,6,1,5,8};
    CountSort(a,9);
    qprint(a,9);
    return 0;
}