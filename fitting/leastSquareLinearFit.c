#include "stdio.h"

/*!
 * \brief 最小二乘法线性拟合求出斜率和偏移  y=ax+b
 *        a= ( N(∑xiyi) -(∑xi)(∑yi) ) / ( N(∑xixi) - (∑xiyi)(∑xiyi) )
 *        b= ( (∑xixi)(∑yi) -(∑xi)(∑xiyi) ) / ( N(∑xixi) - (∑xiyi)*(∑xiyi) )
 * \param [IN] x 横坐标数据
 * \param [IN] y 纵坐标数据
 * \param [IN] num 坐标个数
 * \param [IN] 拟合线的斜率
 * \param [IN] 拟合线的偏移
 */
void leastSquareLinearFit(float x[],float y[],const int num,float *a,float *b)
{
    float sum_x2 = 0.0;
    float sum_y  = 0.0;
    float sum_x  = 0.0;
    float sum_xy = 0.0;
    for (int i = 0; i < num; ++i) 
    {  
        sum_x2 += x[i]*x[i];
        sum_y  += y[i];
        sum_x  += x[i];
        sum_xy += x[i]*y[i];
    }    
    printf("X=%f,X2=%f,y=%f,xy=%f",sum_x,sum_x2,sum_y,sum_xy);
    *a = (num*sum_xy - sum_x*sum_y)/(num*sum_x2 - sum_x*sum_x);
    *b= (sum_x2*sum_y - sum_x*sum_xy)/(num*sum_x2-sum_x*sum_x);
}


#define DEBUG 1
// http://www.ab126.com/shuxue/3154.html
#if DEBUG
// float x[10] = {1,2,3,4,5,6,7,8,9,10};
// float y[10] = {2,3,4,5,6,7,8,9,10,11};

float xx[10] = {1,2,3,4,5,6,7,8,9,10};
float yy[10] = {3,2,5,4,7,6,9,8,11,10};

float xxx[4] = {1,2,3,4};
float yyy[4] = {2,1,4,3};

int main()
{
    float a,b;
    // leastSquareLinearFit(x,y,10,&a,&b);
    // printf("y=%fx+%f\n",a,b);
    // leastSquareLinearFit(xx,yy,10,&a,&b);
    // printf("y=%fx+%f\n",a,b);   
    leastSquareLinearFit(xxx,yyy,4,&a,&b);
    printf("y=%fx+%f\n",a,b);  
}
#endif
