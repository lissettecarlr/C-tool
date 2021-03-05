/*!
 * @file limitFilter
 * @brief 限幅滤波，设定上下限，滤除高于或者低于设限的数据
 * @author FZJ
 * @version V0.1
 * @data 2021-03-03
 */

#define LF_DATA_TYPE int
#define LF_UPPER_LIMIT  10
#define LF_LOWER_LIMIT  1
#define LF_ERROR_FLAG   0
/*!
 * \brief 单个数据输入，单个数据输出
 * \param [IN] data 输入数据
 * \retval 滤除则返回LF_ERROR_FLAG，否则返回原数据
 */
 LF_DATA_TYPE limitFilterSingle(LF_DATA_TYPE data);

/*!
 * \brief 输入一组数据，滤出当中超限数据
 * \param [IN] InputData      输入数据地址
 * \param [IN] InputDataSize  输入数据缓冲区尺寸
 * \param [IN] outputData     输出数据地址
 * \param [IN] outputDataSize 输出数据缓冲区尺寸
 * \retval 输出数据数量
 */
 LF_DATA_TYPE limitFilterMultiple(LF_DATA_TYPE *InputData,LF_DATA_TYPE InputDataSize,LF_DATA_TYPE *outputData,LF_DATA_TYPE outputDataSize);