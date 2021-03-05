typedef enum 
{
    DATA_TYPE_U8=1,
    DATA_TYPE_U16=2,
}dataType_t;


typedef struct sNormalBuffer
{
    void *data;
    unsigned int maxSize;
    unsigned int size;
    dataType_t type;
}NormalBuffer_t;

void creatNormalBuffer(NormalBuffer_t *buffer,void *data,unsigned int maxSize,dataType_t type);
void inputNormalBuffer(NormalBuffer_t *buffer,void *data);
void clearNormalBuffer(NormalBuffer_t *buffer);