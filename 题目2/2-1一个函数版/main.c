//   �ո�   ������͹�
#include <stdio.h>
#include <stdlib.h>
#include<string.h>

typedef struct date
{
    char position[50];
    char description[50];
    char account[50];
    char password[50];
    struct date *next;
} Node;

char system_password[50]= {"123456789"};

void  encrypt(char* str)
{
    int i;
    //��15���ʵ�ָ�λ���䣬����λȡ������
    //����Ҳ�������������
    for(i=0; str[i]; i++)
        str[i]=str[i]^15;
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
        scanf("%d",&user_key);
        if(user_key<1||user_key>9)
            printf("�������ݲ��Ϸ�\n");
    }
    while(user_key<1||user_key>9);

    return user_key;
}

Node* insert(Node* head)
{
    if(head==NULL)
        printf("\n\t��ǰϵͳ��δ�����κ���Ϣ\n");

    Node* info;
    while(1)
    {
        printf("\n\n-----------------------------------------------------\n");
        printf("--------------�� ��˽��Ϣ¼�롿----------------------\n");
        info=(Node*)malloc(sizeof(Node)); /*����ռ�*/
        if(!info)                             /*���ָ��infoΪ��*/
        {
            printf("\n��ǰ�ڴ����ʧ��");
            return head;                        /*����֮ǰ�ɹ������ͷָ��*/
        }

        printf("\t��������ʾ����������Ϣ\n\n");

        printf("�������˺�������վ��ַ\n");
        scanf("%s",info->position);               /*������վ��ַ��У��*/
        printf("\n�����˺�����\n");
        scanf("%s",info->description);          /*�����˺�����*/
        printf("\n������վ�˺���\n");
        scanf("%s",info->account);               /*������վ�˺���*/
        printf("\n������վ��Ӧ������\n");
        scanf("%s",info->password);              /*������վ��Ӧ������*/
        info->next=head;                         /*���ýڵ����ӵ�������*/
        head=info;

        printf("\n��ǰ��վ��Ϣ�ɹ�¼��ϵͳ\n\n");

        char keydown[5];

        do
        {
            printf("�Ƿ����¼����վ�˺���Ϣ( y/n )\n");
            scanf("%s",keydown);
            if(keydown[0]!='y'&&keydown[0]!='n')
                printf("����Ƿ�������������\n");

        }
        while(keydown[0]!='y'&&keydown[0]!='n');

        if(keydown[0]=='y')     printf("\n������������������Ϣ¼��\n\n");
        else if(keydown[0]=='n')
        {
            printf("\n�����ɹ�����Ϣ¼�������ϵͳ���Զ��˳���ǰģ��\n\n");
            break;
        }
    }
    printf("�ɹ�����¼�벽��\n");
    printf("-----------------------------------------------------\n");
    return head;
}

void printfList(Node* head)
{
    printf("\n-----------------------------------------------------\n");
    printf("--------------�� ��˽��Ϣ�����----------------------\n");

    int i=0;          /*��¼���ʱ�ı��*/
    Node* pMove;       /*�ƶ�ָ��*/
    pMove=head;
    if(head==NULL)  /*�ж������Ƿ�Ϊ��*/
    {
        printf("\n��Ǹ����ǰϵͳ�ڲ�δ��ѯ���κ��й�����˺���Ϣ\n\n");
    }
    else
    {
        printf("********************************************************************************\n");
        printf("  ���  ��  �˺�λ��         �˺�����            �˺�            ����\n");
        while(pMove)
        {
            i++;
            printf("\n  %-5d   %-15s   %-15s   %-15s   %-15s\n",i,pMove->position,pMove->description,pMove->account,pMove->password);
            pMove=pMove->next;
        }
        printf("\n********************************************************************************\n");
        //   printf("--------------------------------------------------------------------------------\n");
    }
    printf("-----------------------------------------------------\n\n");
}


Node* delect(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ��˽��Ϣ��ѯ��----------------------\n");

    char find[50];               /*��¼��Ҫ���ҵ���վ��*/
    Node *pMove,*pfront;                /*�������ҵ��ƶ�ָ��*/
    printf("\n������Ҫ���ҵ���վ��\n");
    scanf("%s",find);

    pfront=pMove=head;
    while(pMove!=NULL&&strcmp(pMove->position,find))
    {
        pfront=pMove;
        pMove=pMove->next;
    }

    if(pMove==NULL)
    {
        printf("��δ��ϵͳ���ҵ������վ����Ϣ\n");
        return head;
    }
    else
    {
        printf("\n********************************************************************************\n");
        printf("  �˺�λ��         �˺�����            �˺�            ����\n");
        printf("\n  %-20s   %-20s   %-20s   %-20s\n",pMove->position,pMove->description,pMove->account,pMove->password);
        printf("\n********************************************************************************\n");
    }

    char key_down[5];
    do
    {
        printf("\n�Ƿ���Ҫɾ������վ��Ϣ?( y/n )\n\n");
        scanf("%s",key_down);
        if(key_down[0]!='y'&&key_down[0]!='n')
            printf("����Ƿ�������������\n");
    }
    while(key_down[0]!='y'&&key_down[0]!='n');

    if(key_down[0]=='n')
        printf("��ǰ��Ϣ��δɾ��,ģ�齫�Զ��˳�\n");
    else
    {
        if(pMove==head)
            head=head->next;
        else
            pfront->next=pMove->next;

        free(pMove);
        pMove=NULL;

        printf("��ǰ��վ��Ϣ�ѳɹ�ɾ��!!\n");
    }
    return head;
    printf("\n\n-----------------------------------------------------\n");
}

Node* change(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ��˽��Ϣ�޸ġ�----------------------\n");

    char find[50];
    Node *pMove;
    printf("��������Ҫ�޸���վ��\n");
    scanf("%s",find);

    pMove=head;
    while(pMove!=NULL&&strcmp(pMove->position,find))
        pMove=pMove->next;

    if(pMove==NULL)
    {
        printf("��ǰϵͳ�в�δ��ѯ������վ����Ϣ\n");
        return head;
    }
    printf("\n********************************************************************************\n");
    printf("  �˺�λ��         �˺�����            �˺�            ����\n");
    printf("\n  %-20s   %-20s   %-20s   %-20s\n",pMove->position,pMove->description,pMove->account,pMove->password);
    printf("\n********************************************************************************\n");
    printf("�������ʾ�޸���Ϣ\n");
    printf("���������վ�����˺�����\n");
    scanf("%s",pMove->description);
    printf("���������վ�����˺�\n");
    scanf("%s",pMove->account);
    printf("���������վ��������\n");
    scanf("%s",pMove->password);
    printf("��˽��Ϣ�޸����\n");
    printf("\n\n-----------------------------------------------------\n");
    return head;
}

void clear(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� �����˽��Ϣ��----------------------\n");

    Node* pMove,*nowNode;
    pMove=nowNode=head;
    while(pMove!=NULL)
    {
        nowNode=pMove;              /*nowNode������¼��Ҫɾ���Ľڵ�*/
        pMove=pMove->next;          /*pMove��Ϊ�ƶ��ڵ�,����������������*/
        free(nowNode);
    }

    printf("������Ϣ�ѳɹ�ɾ�����ڴ����ͷ�!\n");
    printf("\n\n-----------------------------------------------------\n");
}

void save(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ��������Ϣ�����ļ���----------------------\n");

    if(head==NULL)           // ����ǰϵͳ������Ϣ�����
    {
        printf("��ǰϵͳ��δ�����κ�����\n");
        printf("������Ϣ���ļ�ʧ��\n");
        return;
    }

    FILE *fp;
    Node *pMove;
    char outfile[30];

    printf("�����뵼���ļ��������磺d:\\xds\\score.txt:\n");
    scanf("%s",outfile);

    if((fp=fopen(outfile,"wb"))==NULL)             /*Ϊ�����һ���������ļ�����û������*/
    {
        printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
    }
    else
    {
        pMove=head;                                       /*�ƶ�ָ���ͷָ�뿪ʼ*/
        while(pMove!=NULL)                             /*��p��Ϊ��*/
        {
            encrypt(pMove->password);
            fwrite(pMove,sizeof(Node),1,fp);         /*д��һ����¼*/
            encrypt(pMove->password);
            pMove=pMove->next;                              /*ָ�����*/
        }
        fclose(fp);                                /*�ر��ļ�*/
        printf("-----���м�¼�Ѿ��ɹ��������ļ�%s��!!-----\n",outfile);   /*��ʾ����ɹ�*/
    }
    printf("\n\n-----------------------------------------------------\n");
}

Node* load(Node *head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� ���ļ���Ϣ����ϵͳ��----------------------\n");

    FILE *fp;
    char outfile[30];

    printf("��������Ҫ�򿪵��ļ��������磺d:\\xds\\score.txt:\n");
    scanf("%s",outfile);

    if((fp=fopen(outfile,"rb"))==NULL)              /*��һ���������ļ���Ϊ����ʽ*/
    {
        printf("�ļ���ʧ�ܣ�\n");               /*�粻�ܴ򿪣�����ͷָ��*/
        return head;
    }

    while(!feof(fp))
    {
        Node* p=(Node*)malloc(sizeof(Node));
        if(!p)
        {
            printf("�ڴ�����ʧ�ܣ�\n");
            break;
        }
        if(fread(p,sizeof(Node),1,fp)!=1)
            break;
        encrypt(p->password);
        p->next=head;
        head=p;
    }
    fclose(fp);
    printf("�Ѿ��ɹ����ļ�%s��������!!!\n",outfile);
    printf("\n\n-----------------------------------------------------\n");

    return head;
}
void change_system_password()
{
    char password[50];
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------�� �޸�ϵͳ��¼���롿----------------------\n");

    int num=3;
    do
    {
        printf("������ԭ����(�㻹��%d�λ���)\n",num);
        scanf("%s",password);
        if(strcmp(password,system_password))
        {
            num--;
            printf("ԭ�������,����������\n");
        }
        if(!num)
        {
            printf("\n���Ĵ�������Ѿ��ﵽ3�Σ������Զ�����\n");
            exit(0);
        }
    }
    while(strcmp(password,system_password));
    printf("ԭ����������ȷ\n");
    printf("������������\n");
    scanf("%s",system_password);
    printf("ϵͳ��¼�����޸ĳɹ�\n");

    FILE *fp;
    if((fp=fopen("system_password.txt","wb"))==NULL)              /*��һ���������ļ���Ϊд��ʽ*/
    {
        printf("ϵͳ���뱣��ʧ�ܣ�\n");               /*�粻�ܴ򿪣�����ͷָ��*/
        return;
    }
    encrypt(system_password);
    fprintf(fp,"%s\n",system_password);
}

int main()
{
    system("color 9f");

    FILE *fp;
    if((fp=fopen("system_password.txt","rb"))==NULL)              /*��ϵͳ�������ڵ��ļ���Ϊ����ʽ*/
    {
        printf("ϵͳ�����ȡʧ�ܣ�\n");
        return 0;
    }

    fscanf(fp,"%s\n",system_password);                  //��ȡϵͳ����

    encrypt(system_password);                          //����ϵͳ����

    int try_time=3;
    char ans[50];
    printf("��������˽�������ϵͳ������:\n");
    while(try_time--)
    {
        scanf("%s",ans);
        if(!strcmp(ans,system_password))
        {
            printf("������ȷ��\n");
            break;
        }
        if(try_time!=0)
            printf("���������������������\n");
        else
        {
            printf("���ǷǷ��û���\n");
            printf("�����Զ��ر�\n");
            exit(0);
        }
    }

    Node* head=NULL;
    while(1)
    {
        switch(menu_select())
        {
        case 1:

            head=insert(head);
            break;
        case 2:
            printfList(head);
            break;
        case 3:
            head=delect(head);
            break;
        case 4:
            head=change(head);
            break;
        case 5:
            clear(head);
            head=NULL;
            break;
        case 6:
            save(head);
            break;
        case 7:
            head=load(head);
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
