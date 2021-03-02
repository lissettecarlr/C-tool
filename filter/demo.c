#include "stdio.h"
#include "medianFilter.h"

void qprint(unsigned char* pData, int count)
{
    printf("\n");
	for (int i = 0; i< count; i++) 
    {
        printf("[%X] ",pData[i]);
	}
    printf("\n");
}

void main()
{

	unsigned char a[10] = {7,4,9,3,2,6,1,5,8,11};
    unsigned char b[10];
	medianFilterDataInput(a,10);
	unsigned short num = medianFilterDataOut(b,10);
	qprint(b,num);
}