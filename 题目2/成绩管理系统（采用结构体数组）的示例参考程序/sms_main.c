#include "sms_struct.h"
/*�˵�����������ֵΪ����*/
int menu_select()
{
	char s[3];
	int c;
	printf("\n         ***************���˵�**************\n");
	printf("             1. �����¼\n"); 
	printf("             2. ��ʾ���м�¼\n"); 
	printf("             3. �����м�¼��������\n"); 
	printf("             4. ���������Ҽ�¼����ʾ\n"); 
	printf("             5. �����¼\n"); 
	printf("             6. ɾ����¼\n"); 
	printf("             7. �����м�¼���浽�ļ�\n"); 
	printf("             8. ���ļ��ж������м�¼\n"); 
	printf("             9. �˳�\n"); 
	printf("         ***********************************\n\n"); 

	do
	{ 
		printf("         ��ѡ�����(1-9):"); 
		scanf("%s",s);
		c=atoi(s);
	}while(c<0||c>9); /*ѡ�����~9֮������*/
	return(c); /*����ѡ�����������ݸ���������Ӧ�ĺ���*/ 
}


/******��������ʼ*******/

main()
{
	int n=0;
	STUDENT student[20];        /*����ṹ����*/
//	system("color 5e");             /*����*/
	for(;;)               /*����ѭ��*/
	{
		switch(menu_select())               /*�������˵�����������ֵ������������������*/
		{
			 case 1: n=Input(student,n);break;        /*�½���¼*/
			 case 2: print(student,n);break;          /*��ʾȫ����¼*/
			 case 3: sort(student,n);break;      /*����*/
			 case 4: search(student,n);break;         /*���Ҽ�¼*/
			 case 5: n=insert(student,n);break;  /*�����¼*/
			 case 6: n=delete1(student,n);break;    /*ɾ����¼*/
			 case 7: save(student,n);break;           /*�����ļ�*/
			 case 8: n=load(student);break;         /*���ļ�*/
			 case 9: exit(0);                    /*�������*/
		}
	}
}
