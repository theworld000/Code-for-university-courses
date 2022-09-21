//   终稿   请叫我猛怪
#include"system_struct.h"

//定义系统密码
char system_password[50] = { "123456789" };
//默认为123456789，要是忘记了密码，可以取消从文件读取，直接用123456789
int main()
{
    system("color 9f");

    FILE* fp;
    if ((fp = fopen("system_password.txt", "rb")) == NULL)              /*打开系统密码所在的文件，为读方式*/
    {
        printf("系统密码读取失败！\n");
        return 0;
    }

    fscanf(fp, "%s\n", system_password);                  //读取系统密码

    encrypt(system_password);                          //解密系统密码

    int try_time = 3;
    char ans[50];
    printf("请输入隐私密码管理系统的密码:\n");
    while (try_time--)
    {
        scanf("%s", ans);
        if (!strcmp(ans, system_password))
        {
            printf("口令正确！\n");
            break;
        }
        if (try_time != 0)
            printf("密码输入错误，请重新输入\n");
        else
        {
            printf("您是非法用户！\n");
            printf("程序将自动关闭\n");
            exit(0);
        }
    }

    Node* head = NULL;
    while (1)
    {
        switch (menu_select())
        {
        case 1:

            head = insert(head);
            break;
        case 2:
            printfList(head);
            break;
        case 3:
            head = delect(head);
            break;
        case 4:
            head = change(head);
            break;
        case 5:
            clear(head);
            head = NULL;
            break;
        case 6:
            save(head);
            break;
        case 7:
            head = load(head);
            break;
        case 8:
            change_system_password();
            break;
        case 9:
            printf("成功退出隐私信息管理系统\n");
            exit(0);
        }

        system("pause");//防止闪屏
        system("cls");  //清空屏幕
    }
}


void change_system_password()
{
    char password[50];
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 修改系统登录密码】----------------------\n");

    int num = 3;
    do
    {
        printf("请输入原密码(你还有%d次机会)\n", num);
        scanf("%s", password);
        if (strcmp(password, system_password))
        {
            num--;
            printf("原密码错误,请重新输入\n");
        }
        if (!num)
        {
            printf("\n您的错误次数已经达到3次，程序自动结束\n");
            exit(0);
        }
    } while (strcmp(password, system_password));
    printf("原密码输入正确\n");
    printf("请输入新密码\n");
    scanf("%s", system_password);
    printf("系统登录密码修改成功\n");

    FILE* fp;
    if ((fp = fopen("system_password.txt", "wb")) == NULL)              /*打开一个二进制文件，为写方式*/
    {
        printf("系统密码保存失败！\n");               /*如不能打开，返回头指针*/
        return;
    }
    encrypt(system_password);
    fprintf(fp, "%s\n", system_password);
}