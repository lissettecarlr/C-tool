/*!
 * @file MedianFilter.h
 * @brief ��λֵ�˲�
 * @author fzj
 * @version 0.1
 * @data 2021-1-21
 */
 
#ifndef MEDIANFILTER_H_
#define MEDIANFILTER_H_


#define MEDIAN_FILTER_BUFFER_SIZE 500
#define MEDIAN_FILTER_TRASH_PROP 0.1
/*!
 * \brief ��λֵ�˲����룬�����ǰ�ɶ�δ���
 * \param [IN] data ��Ҫ�˲�������
 * \param [IN] size ��Ҫ�˲������ݳ���
 */
void medianFilterDataInput(unsigned char *data,unsigned short size);
 
 
/*!
 * \brief ��λֵ�˲����������Ļ��������˲���ɵ�����
 * \param [IN] data �˲��������
 * \retval �˲�������ݸ���
 */
unsigned short medianFilterDataOut(unsigned char *data,unsigned short size);
 
 
#endif
