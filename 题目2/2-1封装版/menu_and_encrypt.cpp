#include"system_struct.h"
//���ܺ�����˵�����

void  encrypt(char* str)
{
    int i;
    //��15���ʵ�ָ�λ���䣬����λȡ������
    //����Ҳ�������������
    for (i = 0; str[i]; i++)
        str[i] = str[i] ^ 15;
}

int menu_select()
{
    printf("-----------------------------------------------------\n");
    printf("--------------�� ��˽��Ϣ����ϵͳ��------------------\n");
    printf("\t1.������˽��Ϣ¼��\n");
    printf("\t2.���������˽��Ϣ\n");
    printf("\t3.��ѯ��˽��Ϣ(֧��ɾ������)\n");
    printf("\t4.�޸���˽��Ϣ\n");
    printf("\t5.���ϵͳ��������˽��Ϣ\n");
    printf("\t6.��������Ϣ�����ļ�\n");
    printf("\t7.���ļ���Ϣ����ϵͳ\n");
    printf("\t8.�޸�ϵͳ��¼����\n");
    printf("\t9.�˳���˽ϵͳ\n");
    printf("-----------------------------------------------------\n");

    int user_key;
    do
    {
        printf("\t��������ѡ��Ĳ���( 1 ~ 9 )\n");
        scanf("%d", &user_key);
        if (user_key < 1 || user_key>9)
            printf("�������ݲ��Ϸ�\n");
    } while (user_key < 1 || user_key>9);

    return user_key;
}
