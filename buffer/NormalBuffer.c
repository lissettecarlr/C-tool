
#include "NormalBuffer.h"


void creatNormalBuffer(NormalBuffer_t *buffer,void *data,unsigned int maxSize,dataType_t type)
{
    buffer->data = data;
    buffer->maxSize = maxSize;
    buffer->size=0;
    buffer->type = type;
}
void inputNormalBuffer(NormalBuffer_t *buffer,void *data)
{
     if(buffer==0 || (buffer->size >= buffer->maxSize))
     {
         return;
     }
     if(buffer->type == DATA_TYPE_U8) 
     {
        ((unsigned char*)(buffer->data))[buffer->size++] = *((unsigned char*)data);
     }
     else if(buffer->type == DATA_TYPE_U16) 
     {
         ((unsigned short*)(buffer->data))[buffer->size++] = *((unsigned short*)data);
     }
     else
     {
     }
}

void clearNormalBuffer(NormalBuffer_t *buffer)
{
    buffer->size=0;
}


