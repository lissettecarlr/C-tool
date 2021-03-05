typedef enum 
{
    DATA_TYPE_U8=1,
    DATA_TYPE_U16=2,
}dataType_t;


typedef struct sBufferQueue
{
    void *data;
    unsigned int maxSize;
    unsigned int tail;
    unsigned int head;
    dataType_t type;
}BufferQueue_t;


//出队列
int OutputQueueBuffer(BufferQueue_t *buffer,void *data);

//进队列
int inputQueueBuffer(BufferQueue_t *buffer,void *data);

//初始化
void initQueueBuffer(BufferQueue_t *buffer,void *data,unsigned int maxSize,dataType_t type);
void clearQueueBuffer(BufferQueue_t *buffer);