//   �ո�   ������͹�
#include"system_struct.h"

//����ϵͳ����
char system_password[50] = { "123456789" };
//Ĭ��Ϊ123456789��Ҫ�����������룬����ȡ�����ļ���ȡ��ֱ����123456789
int main()
{
    system("color 9f");

    FILE* fp;
    if ((fp = fopen("system_password.txt", "rb")) == NULL)              /*��ϵͳ�������ڵ��ļ���Ϊ����ʽ*/
    {
        printf("ϵͳ�����ȡʧ�ܣ�\n");
        return 0;
    }

    fscanf(fp, "%s\n", system_password);                  //��ȡϵͳ����

    encrypt(system_password);                          //����ϵͳ����

    int try_time = 3;
    char ans[50];
    printf("��������˽�������ϵͳ������:\n");
    while (try_time--)
    {
        scanf("%s", ans);
        if (!strcmp(ans, system_password))
        {
            printf("������ȷ��\n");
            break;
        }
        if (try_time != 0)
            printf("���������������������\n");
        else
        {
            printf("���ǷǷ��û���\n");
            printf("�����Զ��ر�\n");
            exit(0);
        }
    }

    Node* head = NULL;
    while (1)
    {
        switch (menu_select())
        {
        case 1:

            head = insert(head);
            break;
        case 2:
            printfList(head);
            break;
        case 3:
            head = delect(head);
            break;
        case 4:
            head = change(head);
            break;
        case 5:
            clear(head);
            head = NULL;
            break;
        case 6:
            save(head);
            break;
        case 7:
            head = load(head);
            break;
        case 8:
            change_system_password();
            break;
        case 9:
            printf("�ɹ��˳���˽��Ϣ����ϵͳ\n");
            exit(0);
        }

        system("pause");//��ֹ����
        system("cls");  //�����Ļ
    }
}


void change_system_password()
{
    char password[50];
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� �޸�ϵͳ��¼���롿----------------------\n");

    int num = 3;
    do
    {
        printf("������ԭ����(�㻹��%d�λ���)\n", num);
        scanf("%s", password);
        if (strcmp(password, system_password))
        {
            num--;
            printf("ԭ�������,����������\n");
        }
        if (!num)
        {
            printf("\n���Ĵ�������Ѿ��ﵽ3�Σ������Զ�����\n");
            exit(0);
        }
    } while (strcmp(password, system_password));
    printf("ԭ����������ȷ\n");
    printf("������������\n");
    scanf("%s", system_password);
    printf("ϵͳ��¼�����޸ĳɹ�\n");

    FILE* fp;
    if ((fp = fopen("system_password.txt", "wb")) == NULL)              /*��һ���������ļ���Ϊд��ʽ*/
    {
        printf("ϵͳ���뱣��ʧ�ܣ�\n");               /*�粻�ܴ򿪣�����ͷָ��*/
        return;
    }
    encrypt(system_password);
    fprintf(fp, "%s\n", system_password);
}