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

void AscendingSort(int a[], int size)
{
	int x = a[0];//先从数列中取出一个数作为基数   X保存了基数值
	int i = 0;
	int j = size - 1;

	if (size>1)//区数大于1时才排序int
	{
		while (i<j)//i==j时退出
		{
			while (i<j)   //i==j时退出
			{
				if (a[j]<x)  //如果发现有数比基数小
				{
					a[i] = a[j]; //将那个数放入a[i]这个坑，此时a[j]变为新坑
					i++;   //向右移动一个
					break;  //新坑出现后退出循环      
				}
				j--;  //从最右边往左找 
			}
			while (i<j)
			{
				if (a[i]>x)//从左边开始找一个大于基数的数
				{
					a[j] = a[i];//放入上面留下来的坑
					j--;//向左移动一个
					break;
				}
				i++;
			}
		}
		a[i] = x;//填补最后一个坑

		AscendingSort(a, i);//对基数左边的数进行
		AscendingSort(a + i + 1, size - i - 1);//对基数右边的数进行 
											//直到各个区间里只有一个数
	}
}


int main(void)
{
    int a[9] = {7,4,9,3,2,6,1,5,8};
    AscendingSort(a,9);
    qprint(a,9);
    return 0;
}