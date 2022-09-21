#include"system_struct.h"
//修改链表某一个结点的函数
Node* change(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 隐私信息修改】----------------------\n");

    char find[50];
    Node* pMove;
    printf("请输入你要修改网站名\n");
    scanf("%s", find);

    pMove = head;
    while (pMove != NULL && strcmp(pMove->position, find))
        pMove = pMove->next;

    if (pMove == NULL)
    {
        printf("当前系统中并未查询到该网站的信息\n");
        return head;
    }
    printf("\n********************************************************************************\n");
    printf("  账号位置         账号描述            账号            密码\n");
    printf("\n  %-20s   %-20s   %-20s   %-20s\n", pMove->position, pMove->description, pMove->account, pMove->password);
    printf("\n********************************************************************************\n");
    printf("请根据提示修改信息\n");
    printf("请输入该网站的新账号描述\n");
    scanf("%s", pMove->description);
    printf("请输入该网站的新账号\n");
    scanf("%s", pMove->account);
    printf("请输入该网站的新密码\n");
    scanf("%s", pMove->password);
    printf("隐私信息修改完成\n");
    printf("\n\n-----------------------------------------------------\n");
    return head;
}