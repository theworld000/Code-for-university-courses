#include"system_struct.h"
//加密函数与菜单函数

void  encrypt(char* str)
{
    int i;
    //与15异或，实现高位不变，低四位取反加密
    //解密也可以用这个函数
    for (i = 0; str[i]; i++)
        str[i] = str[i] ^ 15;
}

int menu_select()
{
    printf("-----------------------------------------------------\n");
    printf("--------------【 隐私信息管理系统】------------------\n");
    printf("\t1.个人隐私信息录入\n");
    printf("\t2.浏览个人隐私信息\n");
    printf("\t3.查询隐私信息(支持删除操作)\n");
    printf("\t4.修改隐私信息\n");
    printf("\t5.清空系统内所有隐私信息\n");
    printf("\t6.将所有信息导入文件\n");
    printf("\t7.将文件信息导入系统\n");
    printf("\t8.修改系统登录密码\n");
    printf("\t9.退出隐私系统\n");
    printf("-----------------------------------------------------\n");

    int user_key;
    do
    {
        printf("\t请输入你选择的操作( 1 ~ 9 )\n");
        scanf("%d", &user_key);
        if (user_key < 1 || user_key>9)
            printf("输入数据不合法\n");
    } while (user_key < 1 || user_key>9);

    return user_key;
}
