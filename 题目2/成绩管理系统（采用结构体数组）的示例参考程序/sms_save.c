#include "sms_struct.h"

/*�������ݵ��ļ�ģ��*/
void save(STUDENT *stud,int n)
{
   FILE *fp;                                      /*����ָ���ļ���ָ��*/
   int i=0;
   char outfile[20];                              /*��������ļ���*/
   printf("�����뵼���ļ��������磺G:\\f1\\score.txt:\n");
   scanf("%s",outfile);
   if((fp=fopen(outfile,"wb"))==NULL)             /*Ϊ�����һ���������ļ�����û������*/
   {
      printf("Can not open file\n");
      exit(1);
   }
   while(i<n)                                 
   {
      fwrite(&stud[i],sizeof(STUDENT),1,fp);             /*д��һ����¼*/
      i++;                                 
   }
   fclose(fp);                                    /*�ر��ļ�*/
   printf("-----���м�¼�Ѿ��ɹ��������ļ�%s��!-----\n",outfile);          /*��ʾ����ɹ�*/
}