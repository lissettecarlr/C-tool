#include "stdio.h"
#include <ctype.h>  //toupper  isxdigit

//byte流转化为字符串
void ByteToHexStr(const unsigned char *source, char* dest, int sourceLen)
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
	char *cp = dest;
	while(*cp!='\0') ++cp;
 
	while((*cp++=*str++)!='\0')
	{
	}
	return dest;
}

//int main()
//{
//    char dest[100] = {"abc"};
//    strcat_m(dest,"llala");
//    printf("%s",dest);
//}
void insert(char s[], char t, int i)
{
    char string[100];
    if (!strlen(s))
        string[0] = t;
    else
    {
        strncpy(string, s, i);
        string[i] = t;
        string[i + 1] = '\0';
        strcat(string, (s + i));
        strcpy(s, string);
    }
}

//转换为字符串
char *itoa(int num, char *str, int radix)
{ /*索引表*/
    char index[] = "0123456789ABCDEF";
    unsigned unum; /*中间变量*/
    int i = 0, j, k;
    /*确定unum的值*/
    if (radix == 10 && num < 0) /*十进制负数*/
    {
        unum = (unsigned)-num;
        str[i++] = '-';
    }
    else
        unum = (unsigned)num; /*其他情况*/
    /*转换*/
    do
    {
        str[i++] = index[unum % (unsigned)radix];
        unum /= radix;
    } while (unum);
    str[i] = '\0';
    /*逆序*/
    if (str[0] == '-')
        k = 1; /*十进制负数*/
    else
        k = 0;
    char temp;
    for (j = k; j <= (i - 1) / 2; j++)
    {
        temp = str[j];
        str[j] = str[i - 1 + k - j];
        str[i - 1 + k - j] = temp;
    }
    return str;
}


void StrToHex(char *pbDest, char *pbSrc, int nLen)
{
    char h1,h2;
    char s1,s2;
    int i;

    for (i=0; i<nLen; i++)
    {
        h1 = pbSrc[2*i];
        h2 = pbSrc[2*i+1];

        s1 = toupper(h1) - 0x30;
        if (s1 > 9) 
            s1 -= 7;

        s2 = toupper(h2) - 0x30;
        if (s2 > 9) 
            s2 -= 7;

        pbDest[i] = s1*16 + s2;
    }
}


