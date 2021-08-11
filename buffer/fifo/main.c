#include <stdio.h>
#include "fifo.h"
#include <stdlib.h>
#include <string.h>
void test_u8()
{
    unsigned char a[10]={0};
    Fifo_t buffer;
    unsigned char w1=1,w2=2;
    unsigned char r1=0,r2=0;

    fifoInit(&buffer,a,10,DATA_TYPE_U8);
    fifoPush(&buffer,&w1);
    fifoPush(&buffer,&w2);
    printf("test_u8: fifo len:%d\n",fifoLenth(&buffer));
    fifoPop(&buffer,&r1);
    fifoPop(&buffer,&r2);
    printf("test_u8: r1:%d,r2:%d\n",r1,r2);
}

void test_u16()
{
    unsigned short a[10]={0};
    Fifo_t buffer;
    unsigned short w1=0x1234,w2=0x4321;
    unsigned short r1=0,r2=0;

    fifoInit(&buffer,a,10,DATA_TYPE_U16);
    fifoPush(&buffer,&w1);
    fifoPush(&buffer,&w2);
    printf("test_u16: fifo len:%d\n",fifoLenth(&buffer));
    fifoPop(&buffer,&r1);
    fifoPop(&buffer,&r2);
    printf("test_u16: r1:%04X,r2:%04X\n",r1,r2);
}

void test_full()
{
    unsigned char a[4]={0};
    Fifo_t buffer;
    unsigned char w1=1,w2=2,w3=3,w4=4;
    unsigned char r1=0,r2=0,r3=0;

    fifoInit(&buffer,a,4,DATA_TYPE_U8);

    fifoPush(&buffer,&w1);
    printf("test_full: fifo len:%d\n",fifoLenth(&buffer));
    fifoPush(&buffer,&w2);
    printf("test_full: fifo len:%d\n",fifoLenth(&buffer));
    fifoPush(&buffer,&w3);
    printf("test_full: fifo len:%d\n",fifoLenth(&buffer));
    fifoPush(&buffer,&w4);
    printf("test_full: fifo len:%d\n",fifoLenth(&buffer));
    fifoPop(&buffer,&r1);
    fifoPop(&buffer,&r2);
    fifoPop(&buffer,&r3);
    printf("test_full: r1:%d,r2:%d,r3:%d\n",r1,r2,r3);    
}

typedef struct sTest
{
    unsigned short len;
    unsigned char data[0];
}Test_t;


void test_struct()
{
    Test_t* InData = (Test_t *)malloc(sizeof(Test_t)+5);
    printf("Indata:%d\n",sizeof(InData));
    InData->len=5;
    unsigned char data[5]={1,2,3,4,5};
    memcpy(InData->data,data,5);
    printf("InData point:%08X\n",InData);
    Test_t *outData;
    
    Fifo_t buffer;
    unsigned char store[100];
    fifoInit(&buffer,store,100,DATA_TYPE_POINTER);
    //存入
    fifoPush(&buffer,InData);
    //取出
    fifoPop(&buffer,&outData);
    printf("outData point:%08x\n",outData);

    printf("len:%d\n",outData->len);
    printf("data[0]=%d\n",outData->data[0]);
    printf("Outdata:%d\n",sizeof(outData));
    free(outData);

}

int main()
{
    //test_u8();
    //test_u16();
    //test_full();
    test_struct();
}