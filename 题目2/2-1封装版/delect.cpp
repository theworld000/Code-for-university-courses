#include"system_struct.h"
//ɾ������ĳһ�����ĺ���
Node* delect(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ��˽��Ϣ��ѯ��----------------------\n");

    char find[50];               /*��¼��Ҫ���ҵ���վ��*/
    Node* pMove, * pfront;                /*�������ҵ��ƶ�ָ��*/
    printf("\n������Ҫ���ҵ���վ��\n");
    scanf("%s", find);

    pfront = pMove = head;
    while (pMove != NULL && strcmp(pMove->position, find))
    {
        pfront = pMove;
        pMove = pMove->next;
    }

    if (pMove == NULL)
    {
        printf("��δ��ϵͳ���ҵ������վ����Ϣ\n");
        return head;
    }
    else
    {
        printf("\n********************************************************************************\n");
        printf("  �˺�λ��         �˺�����            �˺�            ����\n");
        printf("\n  %-20s   %-20s   %-20s   %-20s\n", pMove->position, pMove->description, pMove->account, pMove->password);
        printf("\n********************************************************************************\n");
    }

    char key_down[5];
    do
    {
        printf("\n�Ƿ���Ҫɾ������վ��Ϣ?( y/n )\n\n");
        scanf("%s", key_down);
        if (key_down[0] != 'y' && key_down[0] != 'n')
            printf("����Ƿ�������������\n");
    } while (key_down[0] != 'y' && key_down[0] != 'n');

    if (key_down[0] == 'n')
        printf("��ǰ��Ϣ��δɾ��,ģ�齫�Զ��˳�\n");
    else
    {
        if (pMove == head)
            head = head->next;
        else
            pfront->next = pMove->next;

        free(pMove);
        pMove = NULL;

        printf("��ǰ��վ��Ϣ�ѳɹ�ɾ��!!\n");
    }
    return head;
    printf("\n\n-----------------------------------------------------\n");
}