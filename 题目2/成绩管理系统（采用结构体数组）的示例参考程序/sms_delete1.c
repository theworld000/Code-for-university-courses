#include "sms_struct.h"
/*ɾ����¼ģ��*/
int delete1(STUDENT *stud,int n)
{
	int i=0;
	char k[5];      /*�����ַ������飬����ȷ��ɾ����Ϣ*/
	char s[15];     /*���ѧ��*/
	printf("������Ҫɾ��ѧ����������\n");      /*��ʾ��ʾ��Ϣ*/
	scanf("%s",s);  /*����Ҫɾ����¼������*/
	while(i<n && strcmp(stud[i].name,s))
	{
		i++;
	}
	if(i==n)                      /**/
		printf("\n��Ҫɾ������%s�����ź������޴��ˣ�\n",s);
	else               /*��ʾ�ҵ��ļ�¼��Ϣ*/
	{
		printf("*********************************** Found *****************************************\n");
		printf("   ѧ��          ����          �ɼ�1���ɼ�2���ɼ�3    �ܷ�   ƽ����  ����\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%5.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  stud[i].no,stud[i].name,stud[i].score[0],stud[i].score[1],
				stud[i].score[2],stud[i].sum,stud[i].average,stud[i].order);
		printf("***********************************************************************************\n");
		
		do{
			printf("��ȷʵҪɾ���˼�¼��?(y/n):");
			scanf("%s",k);
        }while(k[0]!='y'&&k[0]!='n');
		
		if(k[0]!='n')        /*ɾ��ȷ���ж�*/
		{
			for(;i<n;i++)
			{
				strcpy(stud[i].no,stud[i+1].no);
				strcpy(stud[i].name,stud[i+1].name);
				stud[i].score[0]=stud[i+1].score[0];
				stud[i].score[1]=stud[i+1].score[1];
				stud[i].score[2]=stud[i+1].score[2];
				stud[i].sum=stud[i+1].sum;
				stud[i].average=stud[i+1].average;
				stud[i].order=stud[i+1].order-1;
			}
			printf("\n �Ѿ��ɹ�ɾ������Ϊ %s ��ѧ���ļ�¼��\n",s);
		}
	}
	return n-1;
}
