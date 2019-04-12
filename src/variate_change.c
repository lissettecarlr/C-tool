#include "stdio.h"

//byte流转化为字符串
void ByteToHexStr(const unsigned char* source, char* dest, int sourceLen)
{
    short i;
    unsigned char highByte, lowByte;

    for (i = 0; i < sourceLen; i++)
    {
        highByte = source[i] >> 4;
        lowByte = source[i] & 0x0f ;

        highByte += 0x30;

        if (highByte > 0x39)
                dest[i * 2] = highByte + 0x07;
        else
                dest[i * 2] = highByte;

        lowByte += 0x30;
        if (lowByte > 0x39)
            dest[i * 2 + 1] = lowByte + 0x07;
        else
            dest[i * 2 + 1] = lowByte;
    }
    return ;
}

// int main ()
// {
//      char data[5] ={0x01,0x11,0xA1,0xf0,0x00};
//      char str[100];
//      ByteToHexStr(data,str,5);
//      printf("%s",str);
// }

#include "string.h"
//插入字符串
char *strcat_m(char *dest,const char *str)
{
	char *cp=dest;
	while(*cp!='\0') ++cp;
 
	while((*cp++=*str++)!='\0')
	{
	}
	return dest;
}

int main()
{
    char dest[100] = {"abc"};
    strcat_m(dest,"llala");
    printf("%s",dest);
}