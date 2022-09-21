//   终稿   请叫我猛怪
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
    //与15异或，实现高位不变，低四位取反加密
    //解密也可以用这个函数
    for(i=0; str[i]; i++)
        str[i]=str[i]^15;
}


int menu_select()
{
    printf("-----------------------------------------------------\n");
    printf("--------------【 隐私信息管理系统】------------------\n");
    printf("\t1.个人隐私信息录入\n");
    printf("\t2.浏览个人隐私信息\n");
    printf("\t3.查询隐私信息(支持删除操作)\n");
    printf("\t4.修改隐私信息\n");
    printf("\t5.清空系统内所有隐私信息\n");
    printf("\t6.将所有信息导入文件\n");
    printf("\t7.将文件信息导入系统\n");
    printf("\t8.修改系统登录密码\n");
    printf("\t9.退出隐私系统\n");
    printf("-----------------------------------------------------\n");

    int user_key;
    do
    {
        printf("\t请输入你选择的操作( 1 ~ 9 )\n");
        scanf("%d",&user_key);
        if(user_key<1||user_key>9)
            printf("输入数据不合法\n");
    }
    while(user_key<1||user_key>9);

    return user_key;
}

Node* insert(Node* head)
{
    if(head==NULL)
        printf("\n\t当前系统并未储存任何信息\n");

    Node* info;
    while(1)
    {
        printf("\n\n-----------------------------------------------------\n");
        printf("--------------【 隐私信息录入】----------------------\n");
        info=(Node*)malloc(sizeof(Node)); /*申请空间*/
        if(!info)                             /*如果指针info为空*/
        {
            printf("\n当前内存分配失败");
            return head;                        /*返回之前成功输入的头指针*/
        }

        printf("\t请依照提示输入以下信息\n\n");

        printf("请输入账号所在网站地址\n");
        scanf("%s",info->position);               /*输入网站地址并校验*/
        printf("\n输入账号描述\n");
        scanf("%s",info->description);          /*输入账号描述*/
        printf("\n输入网站账号名\n");
        scanf("%s",info->account);               /*输入网站账号名*/
        printf("\n输入网站对应的密码\n");
        scanf("%s",info->password);              /*输入网站对应的密码*/
        info->next=head;                         /*将该节点连接到链表当中*/
        head=info;

        printf("\n当前网站信息成功录入系统\n\n");

        char keydown[5];

        do
        {
            printf("是否继续录入网站账号信息( y/n )\n");
            scanf("%s",keydown);
            if(keydown[0]!='y'&&keydown[0]!='n')
                printf("输入非法，请重新输入\n");

        }
        while(keydown[0]!='y'&&keydown[0]!='n');

        if(keydown[0]=='y')     printf("\n接下来将继续进行信息录入\n\n");
        else if(keydown[0]=='n')
        {
            printf("\n操作成功，信息录入结束，系统将自动退出当前模块\n\n");
            break;
        }
    }
    printf("成功结束录入步骤\n");
    printf("-----------------------------------------------------\n");
    return head;
}

void printfList(Node* head)
{
    printf("\n-----------------------------------------------------\n");
    printf("--------------【 隐私信息浏览】----------------------\n");

    int i=0;          /*记录输出时的编号*/
    Node* pMove;       /*移动指针*/
    pMove=head;
    if(head==NULL)  /*判断链表是否为空*/
    {
        printf("\n抱歉，当前系统内并未查询到任何有关你的账号信息\n\n");
    }
    else
    {
        printf("********************************************************************************\n");
        printf("  编号  　  账号位置         账号描述            账号            密码\n");
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
    printf("--------------【 隐私信息查询】----------------------\n");

    char find[50];               /*记录需要查找的网站名*/
    Node *pMove,*pfront;                /*用来查找的移动指针*/
    printf("\n输入你要查找的网站名\n");
    scanf("%s",find);

    pfront=pMove=head;
    while(pMove!=NULL&&strcmp(pMove->position,find))
    {
        pfront=pMove;
        pMove=pMove->next;
    }

    if(pMove==NULL)
    {
        printf("并未在系统中找到相关网站的信息\n");
        return head;
    }
    else
    {
        printf("\n********************************************************************************\n");
        printf("  账号位置         账号描述            账号            密码\n");
        printf("\n  %-20s   %-20s   %-20s   %-20s\n",pMove->position,pMove->description,pMove->account,pMove->password);
        printf("\n********************************************************************************\n");
    }

    char key_down[5];
    do
    {
        printf("\n是否需要删除该网站信息?( y/n )\n\n");
        scanf("%s",key_down);
        if(key_down[0]!='y'&&key_down[0]!='n')
            printf("输入非法，请重新输入\n");
    }
    while(key_down[0]!='y'&&key_down[0]!='n');

    if(key_down[0]=='n')
        printf("当前信息并未删除,模块将自动退出\n");
    else
    {
        if(pMove==head)
            head=head->next;
        else
            pfront->next=pMove->next;

        free(pMove);
        pMove=NULL;

        printf("当前网站信息已成功删除!!\n");
    }
    return head;
    printf("\n\n-----------------------------------------------------\n");
}

Node* change(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 隐私信息修改】----------------------\n");

    char find[50];
    Node *pMove;
    printf("请输入你要修改网站名\n");
    scanf("%s",find);

    pMove=head;
    while(pMove!=NULL&&strcmp(pMove->position,find))
        pMove=pMove->next;

    if(pMove==NULL)
    {
        printf("当前系统中并未查询到该网站的信息\n");
        return head;
    }
    printf("\n********************************************************************************\n");
    printf("  账号位置         账号描述            账号            密码\n");
    printf("\n  %-20s   %-20s   %-20s   %-20s\n",pMove->position,pMove->description,pMove->account,pMove->password);
    printf("\n********************************************************************************\n");
    printf("请根据提示修改信息\n");
    printf("请输入该网站的新账号描述\n");
    scanf("%s",pMove->description);
    printf("请输入该网站的新账号\n");
    scanf("%s",pMove->account);
    printf("请输入该网站的新密码\n");
    scanf("%s",pMove->password);
    printf("隐私信息修改完成\n");
    printf("\n\n-----------------------------------------------------\n");
    return head;
}

void clear(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 清空隐私信息】----------------------\n");

    Node* pMove,*nowNode;
    pMove=nowNode=head;
    while(pMove!=NULL)
    {
        nowNode=pMove;              /*nowNode用来记录需要删除的节点*/
        pMove=pMove->next;          /*pMove作为移动节点,用来遍历整个链表*/
        free(nowNode);
    }

    printf("所有信息已成功删除，内存已释放!\n");
    printf("\n\n-----------------------------------------------------\n");
}

void save(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 将所有信息导入文件】----------------------\n");

    if(head==NULL)           // 处理当前系统不含信息的情况
    {
        printf("当前系统内未包含任何数据\n");
        printf("储存信息到文件失败\n");
        return;
    }

    FILE *fp;
    Node *pMove;
    char outfile[30];

    printf("请输入导出文件名，例如：d:\\xds\\score.txt:\n");
    scanf("%s",outfile);

    if((fp=fopen(outfile,"wb"))==NULL)             /*为输出打开一个二进制文件，如没有则建立*/
    {
        printf("不能打开文件，文件保存失败！\n");
    }
    else
    {
        pMove=head;                                       /*移动指针从头指针开始*/
        while(pMove!=NULL)                             /*如p不为空*/
        {
            encrypt(pMove->password);
            fwrite(pMove,sizeof(Node),1,fp);         /*写入一条记录*/
            encrypt(pMove->password);
            pMove=pMove->next;                              /*指针后移*/
        }
        fclose(fp);                                /*关闭文件*/
        printf("-----所有记录已经成功保存至文件%s中!!-----\n",outfile);   /*显示保存成功*/
    }
    printf("\n\n-----------------------------------------------------\n");
}

Node* load(Node *head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 将文件信息导入系统】----------------------\n");

    FILE *fp;
    char outfile[30];

    printf("请输入你要打开的文件名，例如：d:\\xds\\score.txt:\n");
    scanf("%s",outfile);

    if((fp=fopen(outfile,"rb"))==NULL)              /*打开一个二进制文件，为读方式*/
    {
        printf("文件打开失败！\n");               /*如不能打开，返回头指针*/
        return head;
    }

    while(!feof(fp))
    {
        Node* p=(Node*)malloc(sizeof(Node));
        if(!p)
        {
            printf("内存申请失败！\n");
            break;
        }
        if(fread(p,sizeof(Node),1,fp)!=1)
            break;
        encrypt(p->password);
        p->next=head;
        head=p;
    }
    fclose(fp);
    printf("已经成功从文件%s导入数据!!!\n",outfile);
    printf("\n\n-----------------------------------------------------\n");

    return head;
}
void change_system_password()
{
    char password[50];
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 修改系统登录密码】----------------------\n");

    int num=3;
    do
    {
        printf("请输入原密码(你还有%d次机会)\n",num);
        scanf("%s",password);
        if(strcmp(password,system_password))
        {
            num--;
            printf("原密码错误,请重新输入\n");
        }
        if(!num)
        {
            printf("\n您的错误次数已经达到3次，程序自动结束\n");
            exit(0);
        }
    }
    while(strcmp(password,system_password));
    printf("原密码输入正确\n");
    printf("请输入新密码\n");
    scanf("%s",system_password);
    printf("系统登录密码修改成功\n");

    FILE *fp;
    if((fp=fopen("system_password.txt","wb"))==NULL)              /*打开一个二进制文件，为写方式*/
    {
        printf("系统密码保存失败！\n");               /*如不能打开，返回头指针*/
        return;
    }
    encrypt(system_password);
    fprintf(fp,"%s\n",system_password);
}

int main()
{
    system("color 9f");

    FILE *fp;
    if((fp=fopen("system_password.txt","rb"))==NULL)              /*打开系统密码所在的文件，为读方式*/
    {
        printf("系统密码读取失败！\n");
        return 0;
    }

    fscanf(fp,"%s\n",system_password);                  //读取系统密码

    encrypt(system_password);                          //解密系统密码

    int try_time=3;
    char ans[50];
    printf("请输入隐私密码管理系统的密码:\n");
    while(try_time--)
    {
        scanf("%s",ans);
        if(!strcmp(ans,system_password))
        {
            printf("口令正确！\n");
            break;
        }
        if(try_time!=0)
            printf("密码输入错误，请重新输入\n");
        else
        {
            printf("您是非法用户！\n");
            printf("程序将自动关闭\n");
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
            printf("成功退出隐私信息管理系统\n");
            exit(0);
        }

        system("pause");//防止闪屏
        system("cls");  //清空屏幕
    }
}
