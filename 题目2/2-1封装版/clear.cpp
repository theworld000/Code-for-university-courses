#include"system_struct.h"
//清空链表结点的函数
void clear(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 清空隐私信息】----------------------\n");

    Node* pMove, * nowNode;
    pMove = nowNode = head;
    while (pMove != NULL)
    {
        nowNode = pMove;              /*nowNode用来记录需要删除的节点*/
        pMove = pMove->next;          /*pMove作为移动节点,用来遍历整个链表*/
        free(nowNode);
    }

    printf("所有信息已成功删除，内存已释放!\n");
    printf("\n\n-----------------------------------------------------\n");
}