/*!
 * @file MedianFilter.c
 * @brief ��λֵ�˲�
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
 * \brief ��С��������
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
 * \brief �˲�����
 */
void medianFilterSort(void)
{
		AscendingSort(MedianBuffer.data,MedianBuffer.dataNumber);
}


/*!
 * \brief ��λֵ�˲����룬�����ǰ�ɶ�δ���
 * \param [IN] data ��Ҫ�˲�������
 * \param [IN] size ��Ҫ�˲������ݳ���
 */
void medianFilterDataInput(unsigned char *data,unsigned short size)
{
		
		if(MedianBuffer.dataNumber >= MEDIAN_FILTER_BUFFER_SIZE)
		{
				return;
		}
		if((MedianBuffer.dataNumber +size) > MEDIAN_FILTER_BUFFER_SIZE)
		{
				size = MEDIAN_FILTER_BUFFER_SIZE - MedianBuffer.dataNumber;//ʣ��
		}
		for(int i=0;i<size;i++)
		{
				MedianBuffer.data[MedianBuffer.dataNumber++] = data[i];
		}
}




/*!
* \brief ��λֵ�˲����������Ļ��������˲���ɵ�����
* \param [IN] data �˲��������
* \param [IN] size ����buffer�ĳߴ�
* \retval �˲�������ݸ���
*/
unsigned short medianFilterDataOut(unsigned char *data,unsigned short size)
{
		//��buffer��������
	  medianFilterSort();
		//ȥ��ͷβ
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
		//���buffer�����˲�������
		MedianBuffer.dataNumber = 0;
		return retNumber;
		
}



