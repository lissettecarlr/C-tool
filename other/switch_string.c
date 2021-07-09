/**
 * @file switch_string.c
 * @brief 在switch中实现比对字符串的方式
 * @details 问题发生在接收JOSN数据后，需要通过比对命令字符串来区分是何种类型，一般方式是写一堆if else，但是感觉太难看了，尝试用switch实现
 * @author lissettecarlr
 * @email lissettecarlr@163.com
 * @version 1.0
 * @date 2021年7月9日
 */


#include <string.h>
#include <stdio.h>

/**
 * @brief 枚举出命令的类型
*/
typedef enum eCmdTyep{
    GetLog=0,
    SetWiFi,
    GetOfflineData,
    DownloadFirmware,
    UpdateFirmware,
}eCmdTyep_t;

///罗列出需要匹配的字符串，顺序需要和上面的枚举相同
const char * const type[] ={"GetLog","SetWiFi","GetOfflineData","DownloadFirmware","UpdateFirmware"};


/**
 * @brief 比对字符串，返回下标
*/
int getPos(const char * s)
{
    for(int i=0; i<UpdateFirmware+1; i++)
    if( strcmp(s,type[i]) ==0 )
        return i;
    return -1;
}

void main()
{
    char *test = "UpdateFirmware";
    switch (getPos(test))
    {
    case GetLog:
        printf("GetLog");
        break;
    case SetWiFi:
        printf("SetWiFi");
        break;
    case GetOfflineData:
        printf("GetOfflineData");
        break;
    case DownloadFirmware:
        printf("DownloadFirmware");
        break;
    case UpdateFirmware:
        printf("UpdateFirmware");
        break;
    default:
        printf("not find");
        break;
    }
}