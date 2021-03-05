#include "stdio.h"
#include "medianFilter.h"
#include "limitFilter.h"

void qprint(int* pData, int count)
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

	// int a[10] = {7,4,9,3,2,6,1,5,8,11};
    unsigned short b[10]={1,2,3,4,2,6,7,8,9,10};
   
	// medianFilterDataInput(a,10);
	// unsigned short num = medianFilterDataOut(b,10);

	//限幅滤波
 	// int size=0;
	// size = limitFilterMultiple(a,10,a,10);
	// printf("size=%d\n",size);
	// qprint(a,size);

	unsigned short x=0;
	medianFilterSingle(b,10,&x);
	printf("\n%d\n",x);
	
}