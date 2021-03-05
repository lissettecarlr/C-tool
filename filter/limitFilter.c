/*!
 * @file limitFilter
 * @brief 限幅滤波，设定上下限，滤除高于或者低于设限的数据
 * @author FZJ
 * @version V0.1
 * @data 2021-03-03
 */

#include "limitFilter.h"

 LF_DATA_TYPE limitFilterSingle(LF_DATA_TYPE data)
 {
     if(data < LF_UPPER_LIMIT && data>LF_LOWER_LIMIT)
     {
         return data;
     }
     else
     {
         return LF_ERROR_FLAG;
     }
 }

 LF_DATA_TYPE limitFilterMultiple(LF_DATA_TYPE *InputData,LF_DATA_TYPE InputDataSize,LF_DATA_TYPE *outputData,LF_DATA_TYPE outputDataSize)
 {
     LF_DATA_TYPE retNumber=0;
     if(outputDataSize <InputDataSize)
     {
         InputDataSize = outputDataSize;
     }
     for(int i=0;i<InputDataSize;i++)
     {
         if(limitFilterSingle(InputData[i]) == LF_ERROR_FLAG)
         {
            continue;
            
         }
         else
         {
            outputData[retNumber++] = InputData[i];
         }
     }
     return retNumber;
 }