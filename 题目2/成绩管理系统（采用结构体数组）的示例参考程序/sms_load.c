#include "sms_struct.h"

/*������Ϣģ��*/
int load(STUDENT *stud)
{
   int i;
   FILE *fp;                                      /* ����ָ���ļ���ָ��*/
   char infile[20];                               /*�����ļ���*/
   printf("�����뵼���ļ��������磺G:\\f1\\score.txt:\n");
   scanf("%s",infile);                            /*�����ļ���*/
   if((fp=fopen(infile,"rb"))==NULL)              /*��һ���������ļ���Ϊ����ʽ*/
   {  
		printf("�ļ���ʧ�ܣ�\n");             
		return 0;
   }
   i=0;
   while(!feof(fp))                               /*ѭ��������ֱ���ļ�β����*/
   {
	   if(1!=fread(&stud[i],sizeof(STUDENT),1,fp))
			break;                                       /*���û�������ݣ�����ѭ��*/
	   i++;
   }
	fclose(fp);                                    /*�ر��ļ�*/
	printf("�Ѿ��ɹ����ļ�%s��������!!!\n",infile);
	return i;
}
