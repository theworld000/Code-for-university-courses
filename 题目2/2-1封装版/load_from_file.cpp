#include"system_struct.h"
//����ǰ������Ϣ���浽�ļ��ĺ���
Node* load(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ���ļ���Ϣ����ϵͳ��----------------------\n");

    FILE* fp;
    char outfile[30];

    printf("��������Ҫ�򿪵��ļ��������磺d:\\xds\\score.txt:\n");
    scanf("%s", outfile);

    if ((fp = fopen(outfile, "rb")) == NULL)              /*��һ���������ļ���Ϊ����ʽ*/
    {
        printf("�ļ���ʧ�ܣ�\n");               /*�粻�ܴ򿪣�����ͷָ��*/
        return head;
    }

    while (!feof(fp))
    {
        Node* p = (Node*)malloc(sizeof(Node));
        if (!p)
        {
            printf("�ڴ�����ʧ�ܣ�\n");
            break;
        }
        if (fread(p, sizeof(Node), 1, fp) != 1)
            break;
        
        encrypt(p->password);
        p->next = head;
        head = p;
    }
    fclose(fp);
    printf("�Ѿ��ɹ����ļ�%s��������!!!\n", outfile);
    printf("\n\n-----------------------------------------------------\n");

    return head;
}