//随机数发生器
//2018年7月19日10:15:23

//eg1
#include "stdlib.h"

//send :随机数种子，传入不同的值使其随机数不同。
//max :随机数的最大值
//min :随机数的最小值
//void srand(unsigned int seed) 随机数初始化函数
//返回随机数
unsigned int random(unsigned int seed,unsigned int max,unsigned min)
{
  unsigned int value;
  srand(seed);
  value = rand() % (max + 1 - min)+ min;
  return value;
}