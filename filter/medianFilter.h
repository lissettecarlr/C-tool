/*!
 * @file MedianFilter.h
 * @brief ��λֵ�˲�
 * ����һ�����ݣ��˳��ߵ�λ���ݣ���ֵ�ó������������
 * ����һ�����ݣ��õ���λ�ߣ��޷���ʽ�˲�ȥ�������ݣ�����µ�һ������
 * @author fzj
 * @version 0.1
 * @data 2021-1-21
 */
 
#ifndef MEDIANFILTER_H_
#define MEDIANFILTER_H_

#define MF_ERROR_FLAG 0

#define MEDIAN_FILTER_TRASH_PROP_LOW  0.2
#define MEDIAN_FILTER_TRASH_PROP_HIGH 0.2


/*!
 * \brief ����һ�����ݣ�����˲���ֵ�ںϺ�ĵ�������
 * \param [IN] inputData �������ݵ�ַ
 * \param [IN] inputSize �������ݳ���
 * \param [IN] ouputData �������
 * \retval ����MF_ERROR_FLAG��ʶ�˲�����
 */
char medianFilterSingle(unsigned short *inputData,unsigned short inputSize,unsigned short *outputData);
 
 
/*!
 * \brief ����һ�����ݣ�����˲����һ������
 * \param [IN] inputData �������ݵ�ַ
 * \param [IN] inputSize �������ݳ���
 * \param [IN] ouputData ������ݵ�ַ
 * \param [IN] ouputSize ������ݳ���
 * \retval ����MF_ERROR_FLAG��ʶ�˲����󣬷��򷵻�������ݸ���
 */
char medianFilterMultiple(unsigned short *inputData,unsigned short inputSize,unsigned short *outputData,unsigned short *ouputSize);
 

 
#endif
