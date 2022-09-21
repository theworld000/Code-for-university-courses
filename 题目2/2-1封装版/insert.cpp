#include"system_struct.h"
//给链表插入信息的函数
Node* insert(Node* head)
{
    if (head == NULL)
        printf("\n\t当前系统并未储存任何信息\n");

    Node* info;
    while (1)
    {
        printf("\n\n-----------------------------------------------------\n");
        printf("--------------【 隐私信息录入】----------------------\n");
        info = (Node*)malloc(sizeof(Node)); /*申请空间*/
        if (!info)                             /*如果指针info为空*/
        {
            printf("\n当前内存分配失败");
            return head;                        /*返回之前成功输入的头指针*/
        }

        printf("\t请依照提示输入以下信息\n\n");

        printf("请输入账号所在网站地址\n");
        scanf("%s", info->position);               /*输入网站地址并校验*/
        printf("\n输入账号描述\n");
        scanf("%s", info->description);          /*输入账号描述*/
        printf("\n输入网站账号名\n");
        scanf("%s", info->account);               /*输入网站账号名*/
        printf("\n输入网站对应的密码\n");
        scanf("%s", info->password);              /*输入网站对应的密码*/
        info->next = head;                         /*将该节点连接到链表当中*/
        head = info;

        printf("\n当前网站信息成功录入系统\n\n");

        char keydown[5];

        do
        {
            printf("是否继续录入网站账号信息( y/n )\n");
            scanf("%s", keydown);
            if (keydown[0] != 'y' && keydown[0] != 'n')
                printf("输入非法，请重新输入\n");

        } while (keydown[0] != 'y' && keydown[0] != 'n');

        if (keydown[0] == 'y')     printf("\n接下来将继续进行信息录入\n\n");
        else if (keydown[0] == 'n')
        {
            printf("\n操作成功，信息录入结束，系统将自动退出当前模块\n\n");
            break;
        }
    }
    printf("成功结束录入步骤\n");
    printf("-----------------------------------------------------\n");
    return head;
}