#include"system_struct.h"
//将当前链表信息储存到文件的函数
Node* load(Node* head)
{
    printf("\n\n-----------------------------------------------------\n");
    printf("--------------【 将文件信息导入系统】----------------------\n");

    FILE* fp;
    char outfile[30];

    printf("请输入你要打开的文件名，例如：d:\\xds\\score.txt:\n");
    scanf("%s", outfile);

    if ((fp = fopen(outfile, "rb")) == NULL)              /*打开一个二进制文件，为读方式*/
    {
        printf("文件打开失败！\n");               /*如不能打开，返回头指针*/
        return head;
    }

    while (!feof(fp))
    {
        Node* p = (Node*)malloc(sizeof(Node));
        if (!p)
        {
            printf("内存申请失败！\n");
            break;
        }
        if (fread(p, sizeof(Node), 1, fp) != 1)
            break;
        
        encrypt(p->password);
        p->next = head;
        head = p;
    }
    fclose(fp);
    printf("已经成功从文件%s导入数据!!!\n", outfile);
    printf("\n\n-----------------------------------------------------\n");

    return head;
}