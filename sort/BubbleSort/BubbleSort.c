#include "stdio.h"

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

void BubbleSort(int arr[], int len)
{
    int temp;
    int j,i;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}



int main(void)
{
    int a[9] = {7,4,9,3,2,6,1,5,8};
    BubbleSort(a,9);
    qprint(a,9);
    return 0;
}