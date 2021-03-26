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

/*!
 * \brief 冒泡排序
 * \param [IN] arr 数据首地址
 * \param [IN] len 数据个数
 */
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

#include <stdlib.h>
#include <string.h>

void swap(void *data1,void *data2,unsigned int size)
{
    if(size >8)return;
    unsigned char temp[8]; //不动态申请，假设最大为longlong
    memcpy(temp,data1,size);
    memcpy(data1,data2,size);
    memcpy(data2,temp,size);
}

/*!
 * \brief 冒泡排序
 * \param [IN] arr 数据首地址
 * \param [IN] len 数据个数
 * \param [IN] size 数据类型大小
 * \param [IN] compare 比较大小
 */
void BubbleSort2(void *arr,unsigned int len,unsigned int size,int (*compare)(const void*a,const void*b))
{
    int i,j;
    for(i=0;i<len-1;i++)
    {
        for(j=0;j<len-1-i;j++)
        {
            if( compare(arr+j*size,arr+(j+1)*size) >0)
            {
                //printf("%d,%d  ",*(int *)(arr+j*size),*(int *)(arr+(j+1)*size));
                swap(arr+j*size,arr+(j+1)*size,size);
                //printf("%d,%d\n",*(int *)(arr+j*size),*(int *)(arr+(j+1)*size));
            }
        }
    }
}

/*
 * \brief 比较函数 
 */
int cmp(const void *a,const void *b)
{
    if( (*(int *)a) > (*(int *)b) )
    {
        return  1;
    }
    else
    {
        return -1;
    }
}

int main(void)
{
    int a[9] = {7,4,9,3,2,6,1,5,8};
    BubbleSort2(a,9,sizeof(int),cmp);
    qprint(a,9);
    return 0;
}