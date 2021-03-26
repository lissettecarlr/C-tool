#include "fifo.h"

/*!
 * \brief 存入数据
 * \param [IN]fifo 执行的队列
 * \param [IN]data 需要存入的数据
 */
int fifoPush(Fifo_t *fifo,void *data)
{
    if(isFifoFull(fifo) == 1)
    {
        //此宏用于启动队列满时新数据挤掉旧数据的功能
#ifdef RING_OUT_THE_OLD
        //定义一个局部变量来去旧数据
        unsigned short temp;
        fifoPop(fifo,&temp);
#endif        
    }

    if(fifo->type == DATA_TYPE_U8)
    {
       ((unsigned char *)(fifo->data))[fifo->posW] = *(unsigned char*)(data);
    }
    else if(fifo->type == DATA_TYPE_U16)
    {   
       ((unsigned short *)(fifo->data))[fifo->posW] = *(unsigned short*)(data);
    }
    else
    {
        return -1;
    }
    //更新下一次存储位置
    fifo->posW = (fifo->posW+1)%fifo->size;
    return 0;
}


/*!
 * \brief 取出数据
 * \param [IN]  fifo 执行的队列
 * \param [OUT] data 取出的数据,当传入为0时表示抛弃一个数据
 */
int fifoPop(Fifo_t *fifo,void *data)
{
    if( isFifoEmpty(fifo) == 1 )//为空
    {
        return -1;
    }

    if(fifo->type == DATA_TYPE_U8)
    {
        *(unsigned char *)data = ((unsigned char*)(fifo->data))[fifo->posR];
    }
    else if(fifo->type == DATA_TYPE_U16)
    {
        *(unsigned short*)data = ((unsigned short*)(fifo->data))[fifo->posR];
    }
    else
    {}
    fifo->posR = (fifo->posR+1) % fifo->size;
}

/*!
 * \brief 初始化队列
 * \param [IN] fifo 执行的队列
 * \param [IN] data 用于存储的区域
 * \param [IN] size 存储区域大小
 * \param [IN] type 存储数据类型
 */
void fifoInit(Fifo_t *fifo,void *data,unsigned int size,dataType_t type)
{
    fifo->data = data;
    fifo->size = size;
    fifo->type = type;
    fifo->posR = 0;
    fifo->posW = 0;
}

/*!
 * \brief 清空队列
 * \param [IN] fifo 执行的队列
 */
void fifoClear(Fifo_t *fifo)
{
    fifo->posR = 0;
    fifo->posW = 0;
}

/*!
 * \brief 获取队列长度
 * \param [IN] fifo 执行的队列
 */
unsigned int fifoLenth(Fifo_t *fifo)
{
    unsigned int len;

    len = (fifo->posW + fifo->size - fifo->posR) % fifo->size;

    return len;
}






