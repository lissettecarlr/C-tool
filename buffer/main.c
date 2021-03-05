#include "stdio.h"
#include "NormalBuffer.h"
NormalBuffer_t buffer,buffer2;
unsigned short a[10]={0};
unsigned char b[10]={0};

void main()
{
    creatNormalBuffer(&buffer,a,10,DATA_TYPE_U16);
    creatNormalBuffer(&buffer2,b,10,DATA_TYPE_U8);

    unsigned short x=0x0102;
    unsigned char y=0x03;
    inputNormalBuffer(&buffer,&x);
    inputNormalBuffer(&buffer2,&y);

    printf("0:%d\n",buffer.size);
    printf("1:%d\n",buffer2.size);

    printf("%d,%d\n",*(unsigned char *)a,*((unsigned char *)a+1));
    printf("%d",a[0]);

}