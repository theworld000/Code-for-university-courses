#include"system_struct.h"
//�����������Ϣ�ĺ���
Node* insert(Node* head)
{
    if (head == NULL)
        printf("\n\t��ǰϵͳ��δ�����κ���Ϣ\n");

    Node* info;
    while (1)
    {
        printf("\n\n-----------------------------------------------------\n");
        printf("--------------�� ��˽��Ϣ¼�롿----------------------\n");
        info = (Node*)malloc(sizeof(Node)); /*����ռ�*/
        if (!info)                             /*���ָ��infoΪ��*/
        {
            printf("\n��ǰ�ڴ����ʧ��");
            return head;                        /*����֮ǰ�ɹ������ͷָ��*/
        }

        printf("\t��������ʾ����������Ϣ\n\n");

        printf("�������˺�������վ��ַ\n");
        scanf("%s", info->position);               /*������վ��ַ��У��*/
        printf("\n�����˺�����\n");
        scanf("%s", info->description);          /*�����˺�����*/
        printf("\n������վ�˺���\n");
        scanf("%s", info->account);               /*������վ�˺���*/
        printf("\n������վ��Ӧ������\n");
        scanf("%s", info->password);              /*������վ��Ӧ������*/
        info->next = head;                         /*���ýڵ����ӵ�������*/
        head = info;

        printf("\n��ǰ��վ��Ϣ�ɹ�¼��ϵͳ\n\n");

        char keydown[5];

        do
        {
            printf("�Ƿ����¼����վ�˺���Ϣ( y/n )\n");
            scanf("%s", keydown);
            if (keydown[0] != 'y' && keydown[0] != 'n')
                printf("����Ƿ�������������\n");

        } while (keydown[0] != 'y' && keydown[0] != 'n');

        if (keydown[0] == 'y')     printf("\n������������������Ϣ¼��\n\n");
        else if (keydown[0] == 'n')
        {
            printf("\n�����ɹ�����Ϣ¼�������ϵͳ���Զ��˳���ǰģ��\n\n");
            break;
        }
    }
    printf("�ɹ�����¼�벽��\n");
    printf("-----------------------------------------------------\n");
    return head;
}