#include"system_struct.h"
//���������ĺ���
void clear(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� �����˽��Ϣ��----------------------\n");

    Node* pMove, * nowNode;
    pMove = nowNode = head;
    while (pMove != NULL)
    {
        nowNode = pMove;              /*nowNode������¼��Ҫɾ���Ľڵ�*/
        pMove = pMove->next;          /*pMove��Ϊ�ƶ��ڵ�,����������������*/
        free(nowNode);
    }

    printf("������Ϣ�ѳɹ�ɾ�����ڴ����ͷ�!\n");
    printf("\n\n-----------------------------------------------------\n");
}