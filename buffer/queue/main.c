#include <stdio.h>
#include "queue.h"

unsigned char a[10]={0};
unsigned short b[10]={0};
BufferQueue_t buffer;
BufferQueue_t buffer2;
unsigned char x=1,y=2,xx=0,yy=0;
unsigned short h=0x0102,g=0x0201;
unsigned short h1=0,g1=0; 

int main()
{
    initQueueBuffer(&buffer,a,10,DATA_TYPE_U8);
    initQueueBuffer(&buffer2,b,10,DATA_TYPE_U16);

    inputQueueBuffer(&buffer,&x);
    inputQueueBuffer(&buffer,&y);

    inputQueueBuffer(&buffer2,&h);
    inputQueueBuffer(&buffer2,&g);
    
    OutputQueueBuffer(&buffer,&xx);
    OutputQueueBuffer(&buffer,&yy);

    OutputQueueBuffer(&buffer2,&h1);
    OutputQueueBuffer(&buffer2,&g1);

    printf("%d,%d\n",xx,yy);
    printf("%d,%d\n",h1,g1);   
}