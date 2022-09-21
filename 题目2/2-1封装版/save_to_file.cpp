#include"system_struct.h"
//清空链表结点的函数
void save(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 将所有信息导入文件】----------------------\n");

    if (head == NULL)           // 处理当前系统不含信息的情况
    {
        printf("当前系统内未包含任何数据\n");
        printf("储存信息到文件失败\n");
        return;
    }

    FILE* fp;
    Node* pMove;
    char outfile[30];

    printf("请输入导出文件名，例如：d:\\xds\\score.txt:\n");
    scanf("%s", outfile);

    if ((fp = fopen(outfile, "wb")) == NULL)             /*为输出打开一个二进制文件，如没有则建立*/
    {
        printf("不能打开文件，文件保存失败！\n");
    }
    else
    {
        pMove = head;                                       /*移动指针从头指针开始*/
        while (pMove != NULL)                             /*如p不为空*/
        {
            encrypt(pMove->password);
            fwrite(pMove, sizeof(Node), 1, fp);         /*写入一条记录*/
            encrypt(pMove->password);
            pMove = pMove->next;                              /*指针后移*/
        }
        fclose(fp);                                /*关闭文件*/
        printf("-----所有记录已经成功保存至文件%s中!!-----\n", outfile);   /*显示保存成功*/
    }
    printf("\n\n-----------------------------------------------------\n");
}