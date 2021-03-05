/*!
 * @file MedianFilter.h
 * @brief 中位值滤波
 * 输入一组数据，滤除高低位数据，均值得出单个数据输出
 * 输入一组数据，得到中位线，限幅方式滤波去超限数据，输出新的一组数据
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
 * \brief 输入一组数据，输出滤波均值融合后的单个数据
 * \param [IN] inputData 输入数据地址
 * \param [IN] inputSize 输入数据长度
 * \param [IN] ouputData 输出数据
 * \retval 返回MF_ERROR_FLAG标识滤波错误
 */
char medianFilterSingle(unsigned short *inputData,unsigned short inputSize,unsigned short *outputData);
 
 
/*!
 * \brief 输入一组数据，输出滤波后的一组数据
 * \param [IN] inputData 输入数据地址
 * \param [IN] inputSize 输入数据长度
 * \param [IN] ouputData 输出数据地址
 * \param [IN] ouputSize 输出数据长度
 * \retval 返回MF_ERROR_FLAG标识滤波错误，否则返回输出数据个数
 */
char medianFilterMultiple(unsigned short *inputData,unsigned short inputSize,unsigned short *outputData,unsigned short *ouputSize);
 

 
#endif
