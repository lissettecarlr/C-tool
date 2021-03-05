/*!
 * @file MedianFilter.c
 * @brief ��λֵ�˲�
 * @author fzj
 * @version 0.2
 * @data 2021-03-21
 * @data 2021-03-21 ��д
 */

#include "medianFilter.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

#define HASH_SIZE 20
static unsigned char hash[HASH_SIZE] = {0};
/*!
 * \brief ���� ����
 * ð�������ʱ�ϳ�����������ռ���ڴ�϶���ʹ�õ���ջ������ѡ���˹�ϣ�������򣬸������֧����֪���ֵ�Ҳ�Ϊ����
 * \param [IN] data �������ݵ�ַ
 * \param [IN] size �������ݳ���
 */
void medianFilterSort(unsigned short *data,unsigned short size)
{
	int i=0;
	int j=0;
    memset(hash, 0, (HASH_SIZE) * sizeof(hash[0]));
    //���hash��
    for (i = 0; i < size; i++) hash[data[i]]++;
    //����˳�����
    for (i = 0,j=0; i < (HASH_SIZE); i++) 
    {
        if (hash[i] > 0)
        {
            while (hash[i] != 0) 
            {
                data[j++] = i;
                hash[i]--;
            }
        }
    }	
}


char medianFilterSingle(unsigned short *inputData,unsigned short inputSize,unsigned short *outputData)
{
	unsigned short outputDataPos=0;
	unsigned short dataNumber=inputSize;
	unsigned short firstFilterSum=0;
	medianFilterSort(inputData,inputSize);
	
	printf("dataNumber1 %d \n",dataNumber);
	outputDataPos = MEDIAN_FILTER_TRASH_PROP_LOW *dataNumber;
 	printf("outputDataPos %d \n",outputDataPos);

	unsigned short a = (outputDataPos+dataNumber*MEDIAN_FILTER_TRASH_PROP_HIGH);
	printf("dataNumber=%d,a=%d \n",dataNumber,a);

	dataNumber=dataNumber-(outputDataPos+dataNumber*MEDIAN_FILTER_TRASH_PROP_HIGH);
	printf("dataNumber3 %d \n",dataNumber);

	for(int y=0;y<dataNumber;y++)
	{
	    firstFilterSum+=inputData[y+outputDataPos];
		printf("[%d] ",inputData[y+outputDataPos]);
	}
	*outputData = firstFilterSum/dataNumber;
	return 1;
	
}

char medianFilterMultiple(unsigned short *inputData,unsigned short inputSize,unsigned short *outputData,unsigned short *ouputSize)
{}