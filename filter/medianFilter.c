/*!
 * @file MedianFilter.c
 * @brief 中位值滤波
 * @author fzj
 * @version 0.1
 * @data 2021-1-21
 */

#include "medianFilter.h"


typedef struct sMedianBuffer{
	unsigned short dataNumber;
	unsigned char data[MEDIAN_FILTER_BUFFER_SIZE];
}MedianBuffer_t;

static MedianBuffer_t MedianBuffer={0,0};


/*!
 * \brief 从小到大排序
 */
void AscendingSort(unsigned char a[], unsigned short size)
{
	unsigned char x = a[0];
	unsigned short i = 0;
	unsigned short j = size - 1;

	if (size>1)
	{
		while (i<j)
		{
			while (i<j)   
			{
				if (a[j]<x)  
				{
					a[i] = a[j]; 
					i++;  
					break;       
				}
				j--;
			}
			while (i<j)
			{
				if (a[i]>x)
				{
					a[j] = a[i];
					j--;
					break;
				}
				i++;
			}
		}
		a[i] = x;

		AscendingSort(a, i);
		AscendingSort(a + i + 1, size - i - 1);
	}
}

/*!
 * \brief 滤波排序
 */
void medianFilterSort(void)
{
		AscendingSort(MedianBuffer.data,MedianBuffer.dataNumber);
}


/*!
 * \brief 中位值滤波输入，在输出前可多次传入
 * \param [IN] data 需要滤波的数据
 * \param [IN] size 需要滤波的数据长度
 */
void medianFilterDataInput(unsigned char *data,unsigned short size)
{
		
		if(MedianBuffer.dataNumber >= MEDIAN_FILTER_BUFFER_SIZE)
		{
				return;
		}
		if((MedianBuffer.dataNumber +size) > MEDIAN_FILTER_BUFFER_SIZE)
		{
				size = MEDIAN_FILTER_BUFFER_SIZE - MedianBuffer.dataNumber;//剩余
		}
		for(int i=0;i<size;i++)
		{
				MedianBuffer.data[MedianBuffer.dataNumber++] = data[i];
		}
}




/*!
* \brief 中位值滤波输出，输出的缓存区是滤波完成的数据
* \param [IN] data 滤波完成数据
* \param [IN] size 传入buffer的尺寸
* \retval 滤波输出数据个数
*/
unsigned short medianFilterDataOut(unsigned char *data,unsigned short size)
{
		//对buffer进行排序
	  medianFilterSort();
		//去掉头尾
	  unsigned short filterNumber = MEDIAN_FILTER_TRASH_PROP * MedianBuffer.dataNumber;
	  unsigned short retNumber = MedianBuffer.dataNumber -(filterNumber *2);
	  if(size < retNumber)
		{
				retNumber = size;
		}
	  for(int i=0;i<retNumber;i++)
	  {
				data[i] = MedianBuffer.data[filterNumber + i];
		}
		//清空buffer返回滤波后数据
		MedianBuffer.dataNumber = 0;
		return retNumber;
		
}



