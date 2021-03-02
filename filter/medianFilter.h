/*!
 * @file MedianFilter.h
 * @brief 中位值滤波
 * @author fzj
 * @version 0.1
 * @data 2021-1-21
 */
 
#ifndef MEDIANFILTER_H_
#define MEDIANFILTER_H_


#define MEDIAN_FILTER_BUFFER_SIZE 500
#define MEDIAN_FILTER_TRASH_PROP 0.1
/*!
 * \brief 中位值滤波输入，在输出前可多次传入
 * \param [IN] data 需要滤波的数据
 * \param [IN] size 需要滤波的数据长度
 */
void medianFilterDataInput(unsigned char *data,unsigned short size);
 
 
/*!
 * \brief 中位值滤波输出，输出的缓存区是滤波完成的数据
 * \param [IN] data 滤波完成数据
 * \retval 滤波输出数据个数
 */
unsigned short medianFilterDataOut(unsigned char *data,unsigned short size);
 
 
#endif
