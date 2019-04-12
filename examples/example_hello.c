// #include <rtthread.h>
// #include <finsh.h>

// #include <hello.h>

// int hello_test(int argc, char** argv)
// {
//     hello_func();

//     return 0;
// }

// MSH_CMD_EXPORT(hello_test, hello API test);

//eg
// #include "stdio.h"

// void main(void)
// {
//    unsigned char test_data[10] = {11,22,33,44,55,66,77,88,99,0};
//    unsigned short crc = modbus_crc(test_data,10);
//    //printf("%x \t %x",(char)((crc&0xff00)>>2),(char)(crc&0x00ff));
//    printf("%02x \n",(unsigned char)((crc&0xff00)>>8));
//    printf("%02X \n",(unsigned char)(crc&0x00ff));
// }


#include "../include/software_tool_api.h"

int main()
{
    return 0 ;
}
