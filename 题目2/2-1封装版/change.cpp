#include"system_struct.h"
//�޸�����ĳһ�����ĺ���
Node* change(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ��˽��Ϣ�޸ġ�----------------------\n");

    char find[50];
    Node* pMove;
    printf("��������Ҫ�޸���վ��\n");
    scanf("%s", find);

    pMove = head;
    while (pMove != NULL && strcmp(pMove->position, find))
        pMove = pMove->next;

    if (pMove == NULL)
    {
        printf("��ǰϵͳ�в�δ��ѯ������վ����Ϣ\n");
        return head;
    }
    printf("\n********************************************************************************\n");
    printf("  �˺�λ��         �˺�����            �˺�            ����\n");
    printf("\n  %-20s   %-20s   %-20s   %-20s\n", pMove->position, pMove->description, pMove->account, pMove->password);
    printf("\n********************************************************************************\n");
    printf("�������ʾ�޸���Ϣ\n");
    printf("���������վ�����˺�����\n");
    scanf("%s", pMove->description);
    printf("���������վ�����˺�\n");
    scanf("%s", pMove->account);
    printf("���������վ��������\n");
    scanf("%s", pMove->password);
    printf("��˽��Ϣ�޸����\n");
    printf("\n\n-----------------------------------------------------\n");
    return head;
}