#include "sms_struct.h"
/*�����ṹ�����飬�������¼�빦��*/
int Input(STUDENT *stud,int n)
{
	int i,j;
	float s;
	char sign; 
	i=0;
	while(sign!='n'&&sign!='N') 
	{ 
		printf("\n�밴������ʾ���������Ϣ.\n\n");
		printf("����ѧ��:");
		scanf("%s",stud[n+i].no);        /*����ѧ��*/
		printf("��������:");
		scanf("%s",stud[n+i].name);      /*��������*/
		printf("����%d ���ɼ�:\n",N);    /*��ʾ��ʼ����ɼ�*/
		s=0;                                      /*����ÿ��ѧ�����ܷ֣���ֵΪ*/
		for(j=0;j<N;j++)                          /*N�ſγ�ѭ��N��*/
		{
			do{
				printf("score[%d]:",j);                 /*��ʾ����ڼ��ſγ�*/
				scanf("%f",&stud[n+i].score[j]);            /*����ɼ�*/
				if(stud[n+i].score[j]>100||stud[n+i].score[j]<0)/*ȷ���ɼ���~100֮��*/ 
					printf("�Ƿ����ݣ����������룡\n");      /*������ʾ��Ϣ*/
			}while(stud[n+i].score[j]>100||stud[n+i].score[j]<0);
			s=s+stud[n+i].score[j];                        /*�ۼӸ��ſγ̳ɼ�*/
		}
		stud[n+i].sum=s;               /*���ֱܷ���*/
		stud[n+i].average=(float)s/N;  /*���ƽ��ֵ*/
		stud[n+i].order=0;             /*δ����ǰ��ֵΪ*/

		printf("��ѧ�����ܷ�Ϊ��%4.2f\n\tƽ����Ϊ��%4.2f\n",stud[n+i].sum,stud[n+i].average); 
		printf("=====>��ʾ��������Ӽ�¼?(Y/N)"); 
		getchar();		/*�Ѽ��̻������е�ǰ������Ļس�������������Ȼ����sign�������ǻس���*/
		scanf("%c",&sign);
		i++; 
	} 
	return(n+i); 
}
