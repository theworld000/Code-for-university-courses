#include"system_struct.h"
//删除链表某一个结点的函数
Node* delect(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 隐私信息查询】----------------------\n");

    char find[50];               /*记录需要查找的网站名*/
    Node* pMove, * pfront;                /*用来查找的移动指针*/
    printf("\n输入你要查找的网站名\n");
    scanf("%s", find);

    pfront = pMove = head;
    while (pMove != NULL && strcmp(pMove->position, find))
    {
        pfront = pMove;
        pMove = pMove->next;
    }

    if (pMove == NULL)
    {
        printf("并未在系统中找到相关网站的信息\n");
        return head;
    }
    else
    {
        printf("\n********************************************************************************\n");
        printf("  账号位置         账号描述            账号            密码\n");
        printf("\n  %-20s   %-20s   %-20s   %-20s\n", pMove->position, pMove->description, pMove->account, pMove->password);
        printf("\n********************************************************************************\n");
    }

    char key_down[5];
    do
    {
        printf("\n是否需要删除该网站信息?( y/n )\n\n");
        scanf("%s", key_down);
        if (key_down[0] != 'y' && key_down[0] != 'n')
            printf("输入非法，请重新输入\n");
    } while (key_down[0] != 'y' && key_down[0] != 'n');

    if (key_down[0] == 'n')
        printf("当前信息并未删除,模块将自动退出\n");
    else
    {
        if (pMove == head)
            head = head->next;
        else
            pfront->next = pMove->next;

        free(pMove);
        pMove = NULL;

        printf("当前网站信息已成功删除!!\n");
    }
    return head;
    printf("\n\n-----------------------------------------------------\n");
}