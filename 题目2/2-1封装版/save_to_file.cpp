#include"system_struct.h"
//���������ĺ���
void save(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ��������Ϣ�����ļ���----------------------\n");

    if (head == NULL)           // ����ǰϵͳ������Ϣ�����
    {
        printf("��ǰϵͳ��δ�����κ�����\n");
        printf("������Ϣ���ļ�ʧ��\n");
        return;
    }

    FILE* fp;
    Node* pMove;
    char outfile[30];

    printf("�����뵼���ļ��������磺d:\\xds\\score.txt:\n");
    scanf("%s", outfile);

    if ((fp = fopen(outfile, "wb")) == NULL)             /*Ϊ�����һ���������ļ�����û������*/
    {
        printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
    }
    else
    {
        pMove = head;                                       /*�ƶ�ָ���ͷָ�뿪ʼ*/
        while (pMove != NULL)                             /*��p��Ϊ��*/
        {
            encrypt(pMove->password);
            fwrite(pMove, sizeof(Node), 1, fp);         /*д��һ����¼*/
            encrypt(pMove->password);
            pMove = pMove->next;                              /*ָ�����*/
        }
        fclose(fp);                                /*�ر��ļ�*/
        printf("-----���м�¼�Ѿ��ɹ��������ļ�%s��!!-----\n", outfile);   /*��ʾ����ɹ�*/
    }
    printf("\n\n-----------------------------------------------------\n");
}