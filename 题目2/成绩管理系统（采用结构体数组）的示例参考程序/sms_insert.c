#include "sms_struct.h"
/*��ָ��λ�ò����¼*/
int insert(STUDENT *stud,int n)
{
	int i=0,j;
	float s;
	int position;
	printf("����������¼��λ�ã�\n");      /*��ʾ��ʾ��Ϣ*/
	scanf("%d",&position);  /*��������¼��λ��*/
	while(position<0 || position>n)
	{
		printf("����λ��������������������¼��λ�ã�\n");      /*��ʾ��ʾ��Ϣ*/
		scanf("%d",position);  /*����Ҫɾ����¼������*/
	}
	
	//������λ�ÿ�ʼ�����м�¼����ƶ�
	for(i=n-1;i>=position;i--)
	{
		strcpy(stud[i+1].no,stud[i].no);
		strcpy(stud[i+1].name,stud[i].name);
		stud[i+1].score[0]=stud[i].score[0];
		stud[i+1].score[1]=stud[i].score[1];
		stud[i+1].score[2]=stud[i].score[2];
		stud[i+1].sum=stud[i].sum;
		stud[i+1].average=stud[i].average;
		stud[i+1].order=stud[i].order;
	}

	//¼���¼������
	i=position;
	printf("\n�밴������ʾ���������Ϣ.\n\n");
	printf("����ѧ��:");
	scanf("%s",stud[i].no);        /*����ѧ��*/
	printf("��������:");
	scanf("%s",stud[i].name);      /*��������*/
	printf("����%d ���ɼ�:\n",N);    /*��ʾ��ʼ����ɼ�*/
	s=0;                                      /*����ÿ��ѧ�����ܷ֣���ֵΪ*/
	for(j=0;j<N;j++)                          /*N�ſγ�ѭ��N��*/
	{
		do{
			printf("score[%d]:",j);                 /*��ʾ����ڼ��ſγ�*/
			scanf("%f",&stud[i].score[j]);            /*����ɼ�*/
			if(stud[i].score[j]>100||stud[i].score[j]<0)/*ȷ���ɼ���~100֮��*/ 
				printf("�Ƿ����ݣ����������룡\n");      /*������ʾ��Ϣ*/
		}while(stud[i].score[j]>100||stud[i].score[j]<0);
		s=s+stud[i].score[j];                        /*�ۼӸ��ſγ̳ɼ�*/
	}
	stud[i].sum=s;               /*���ֱܷ���*/
	stud[i].average=(float)s/N;  /*���ƽ��ֵ*/
	stud[i].order=0;             /*δ����ǰ��ֵΪ*/

	printf("\n �Ѿ���λ�óɹ������¼�¼��\n",position);
	return n+1;
}
