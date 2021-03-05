#include "queue.h"


//出队列
int OutputQueueBuffer(BufferQueue_t *buffer,void *data)
{
    if (buffer->tail == buffer->head) //为空
    {
        return -1;
    }
    else
    {
        if(data ==0) //如果为空则是单纯抛弃一个数据
        {
            buffer->head = (buffer->head+1) & buffer->maxSize;
            return 1;
        }

        if(buffer->type == DATA_TYPE_U8)
        {
            *(unsigned char *)data = ((unsigned char*)(buffer->data))[buffer->head];
        }
        else if(buffer->type == DATA_TYPE_U16)
        {
            *(unsigned short*)data = ((unsigned short*)(buffer->data))[buffer->head];
        }
        else
        {}
        buffer->head = (buffer->head+1) % buffer->maxSize;
    }
    return 0;
}


//进队列
int inputQueueBuffer(BufferQueue_t *buffer,void *data)
{
    if((buffer->tail +1) %buffer->maxSize == buffer->head)//满
    {
        OutputQueueBuffer(buffer,0);
    }
    if(buffer->type == DATA_TYPE_U8)
    {
       ((unsigned char *)(buffer->data))[buffer->tail] = *(unsigned char*)(data);
    }
    else if(buffer->type == DATA_TYPE_U16)
    {   
       ((unsigned short *)(buffer->data))[buffer->tail] = *(unsigned short*)(data);
    }
    else
    {
    }

    buffer->tail = (buffer->tail+1)%buffer->maxSize;
    return 0;
}

void initQueueBuffer(BufferQueue_t *buffer,void *data,unsigned int maxSize,dataType_t type)
{
    buffer->data = data;
    buffer->maxSize = maxSize;
    buffer->type = type;
    buffer->head = buffer->tail=0;
}

void clearQueueBuffer(BufferQueue_t *buffer)
{
    buffer->head = buffer->tail=0;
}

