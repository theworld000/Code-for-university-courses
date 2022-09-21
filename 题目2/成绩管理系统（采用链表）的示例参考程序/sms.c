/******ͷ�ļ���.h��***********/
#include "stdio.h"     /*printf()��scanf()��I/O����*/
#include "malloc.h"    /*malloc()�ڴ���亯��*/
#include "stdlib.h"    /*atoi()��exit()��system()�Ⱥ���*/
#include "string.h"    /*strcpy()��strlen()��strcmp()�Ⱥ���*/

#define N 3            /*���峣��*/

typedef struct stu     /*����ṹ������*/
{
	char no[11];
	char name[15];
	float score[N];
	float sum;
	float average;
	int order;
	struct stu *next;
}STUDENT;

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
	}while(c<0||c>9); /*ѡ�����0~9֮������*/
	return(c); /*����ѡ�����������ݸ���������Ӧ�ĺ���*/ 
}


/*���������������¼�빦�ܣ��½���ڱ�ͷ����*/
STUDENT *create()
{
	int i; 
	float s;
	STUDENT *h=NULL,*info;             /*h:ͷ���ָ�룻info:�½��ָ��*/
	for(;;)
	{
		info=(STUDENT *)malloc(sizeof(STUDENT));  /*����ռ�*/
		if(!info)                                 /*���ָ��infoΪ��*/
		{
			 printf("\n�ڴ����ʧ��");                 
			 return NULL;                         /*���ؿ�ָ��*/
		}
		printf("\n�밴������ʾ���������Ϣ.\n\n");
		printf("����ѧ�ţ�����'#'������:");
		scanf("%s",info->no);    /*����ѧ�Ų�У��*/
		if(info->no[0]=='#') break;               /*���ѧ�����ַ�Ϊ#���������*/
		printf("��������:");
		scanf("%s",info->name);      /*����������������У��*/
		printf("����%d ���ɼ�:\n",N);    /*��ʾ��ʼ����ɼ�*/
		s=0;                                      /*����ÿ��ѧ�����ܷ֣���ֵΪ0*/
		for(i=0;i<N;i++)                          /*N�ſγ�ѭ��N��*/
		{
			do{
				printf("score[%d]:",i);                 /*��ʾ����ڼ��ſγ�*/
				scanf("%f",&info->score[i]);            /*����ɼ�*/
				if(info->score[i]>100||info->score[i]<0)/*ȷ���ɼ���0~100֮��*/ 
					printf("�Ƿ����ݣ����������룡\n");      /*������ʾ��Ϣ*/
			}while(info->score[i]>100||info->score[i]<0);
			s=s+info->score[i];                        /*�ۼӸ��ſγ̳ɼ�*/
		}
		info->sum=s;               /*���ֱܷ���*/
		info->average=(float)s/N;  /*���ƽ��ֵ*/
		info->order=0;             /*δ����ǰ��ֵΪ0*/
		info->next=h;              /*��ͷ�����Ϊ��������ĺ�̽��*/
		h=info;            /*��������Ϊ�µ�ͷ���*//*û����ǰ,����������ݽ���������*/
	}
	return(h);                    /*����ͷָ��*/
}


/*��ʾģ��*/
void print(STUDENT *h)
{
	int i=0;               /* ͳ�Ƽ�¼����*/
	STUDENT *p;            /*�ƶ�ָ��*/
	p=h;                   /*��ֵΪͷָ��*/
	if(p==NULL)
	{
		printf("\n    ���ź����ձ���û���κμ�¼�ɹ���ʾ��\n");
	}
	else
	{
		printf("********************************** STUDENT ****************************************\n");
		printf("  ��¼�š�  ѧ��          ����      �ɼ�1���ɼ�2���ɼ�3    �ܷ�   ƽ����  ����\n");
		printf("-----------------------------------------------------------------------------------\n");
		while(p!=NULL)
		{
			i++;
			printf("    %-4d %-11s%-15s%6.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n", i, p->no,p->name,p->score[0],p->score[1],
					p->score[2],p->sum,p->average,p->order);
			p=p->next;
		}
		printf("***********************************************************************************\n\n");
	}
}

/*����ģ�飬ʵ�ָ����ܷ�sum��ֵ������������������*/
STUDENT *sort(STUDENT *h)
{
   int i=0;                         /*������������*/
   STUDENT *p,*q,*t,*h1;            /*������ʱָ��*/
   h1=h->next;                      /*��ԭ���ͷָ����ָ����һ�������ͷָ��*/
   h->next=NULL;                    /*�Ͽ�ԭ������ͷ�����������������*/
   while(h1!=NULL)                  /*��ԭ��Ϊ��ʱ����������*/
   {
	  t=h1;                         /*ȡԭ���ͷ���*/
      h1=h1->next;                  /*ԭ��ͷ���ָ�����*/
      p=h;                          /*�趨�ƶ�ָ��p����ͷָ�뿪ʼ*/
      q=h;                          /*�趨�ƶ�ָ��q��Ϊp��ǰ������ֵΪͷָ��*/
      while(p!=NULL&&t->sum<p->sum) /*���ֱܷȽ�*/
      {
		  q=p;                      /*�������ֵС�����±�ָ�����*/
		  p=p->next;
	  }

      if(p==q)                      /*p==q�������whileû��ִ�У�Ҳ����������ͷָ�룬�˵�Ӧ������λ*/
      { 
		  t->next=p;                /*�������ĺ��Ϊp*/
          h=t;                      /*��ͷ���Ϊ�������*/
      }
      else                          /*�������Ӧ������q��p֮�䣬��pΪ������β��*/
      {		   
		  t->next=p;                /*t�ĺ����p*/
          q->next=t;                /*q�ĺ����t*/
      }
   }								/*�����������У��������*/
    
   //���������Ѿ��ź�������ֻҪ��ͷָ�뿪ʼ�����������κż���
   p=h;                             /*���ź����ͷָ�븳��p*/
   while(p!=NULL)                   /*����������������*/
   {
      i++;                          /*������*/
      p->order=i;                   /*�����θ�ֵ*/
      p=p->next;                    /*ָ�����*/
   }
   printf("���ִܷӸߵ��������ɹ�!!!\n");      /*����ɹ�*/
   return (h);                      /*����ͷָ��*/
}

/*���Ҽ�¼ģ��*/
void search(STUDENT *h)
{
	STUDENT *p;                      /*�ƶ�ָ��*/
	char s[15];                      /*����������ַ�����*/
	printf("��������Ҫ���ҵ�ѧ������:\n");
	scanf("%s",s);                   /*��������*/
	p=h;                             /*��ͷָ�븳��p*/
	while(p!=NULL&&strcmp(p->name,s))/*����¼����������Ҫ�ҵģ�����ָ�벻Ϊ��ʱ*/
		p=p->next;                   /*�ƶ�ָ�룬ָ����һ��㣬��������*/
	if(p==NULL)                      /*ָ��Ϊ�գ�˵��δ���ҵ���Ҫ�Ľ��*/
		printf("\n��Ҫ���ҵ���%s�����ź������޴��ˣ�\n",s);
	else                             /*��ʾ�ҵ��ļ�¼��Ϣ*/
	{  
		printf("*********************************** Found *****************************************\n");
		printf("   ѧ��          ����          �ɼ�1���ɼ�2���ɼ�3    �ܷ�   ƽ����  ����\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%6.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  p->no,p->name,p->score[0],p->score[1],
				p->score[2],p->sum,p->average,p->order);
		printf("***********************************************************************************\n");
	}
}

/*������ͷ����Ӽ�¼*/
STUDENT  *insert(STUDENT *h)
{  
	STUDENT *info;                   /*pָ�����λ�ã�q����ǰ����infoָ�²����¼*/
	int i,n=0;
	float s1;
	printf("\n������¼�¼��\n");
	info=(STUDENT *)malloc(sizeof(STUDENT)); /*����ռ�*/
	if(!info)
	{  
		printf("\n�ڴ����ʧ�ܣ�"); 
		return NULL;                         /*���ؿ�ָ��*/
	}
	printf("����ѧ��:");
	scanf("%s",info->no);  /*�����Ǵ��������ݵ�¼��ʹ�������ͬ����ģ��ͬ*/
	printf("��������:");
	scanf("%s",info->name);
	printf("���� %d ���ɼ���\n",N);
	s1=0;
	for(i=0;i<N;i++)
	{
		do{
			 printf("score[%d]:",i);
			 scanf("%f",&info->score[i]);
			 if(info->score[i]>100||info->score[i]<0)
				printf("�Ƿ����ݣ����������룡\n");
		}while(info->score[i]>100||info->score[i]<0);
		s1=s1+info->score[i];                  
	}
	info->sum=s1;                             
	info->average=(float)s1/N;   
	info->order=0;             /*δ����ǰ��ֵΪ*/
	info->next=NULL;           /*����ָ��Ϊ��*/

	info->next=h;              /*��ָ�븳ֵ��p*/
	h=info;                    /*��ָ�븳ֵ��q*/

    printf("\n ----�Ѿ���� %s ������ͷ����----\n",info->name);
    return(h);                 /*����ͷָ��*/
}

/*ɾ����¼ģ��*/
STUDENT *delete1(STUDENT *h)
{
	char k[5];					/*�����ַ������飬����ȷ��ɾ����Ϣ*/
	STUDENT *p,*q;				/*pΪ���ҵ�Ҫɾ���Ľ��ָ�룬qΪ��ǰ��ָ��*/
	char s[11];					/*���ѧ��*/
	printf("������Ҫɾ��ѧ����ѧ�ţ�\n");      /*��ʾ��ʾ��Ϣ*/
	scanf("%s",s);				/*����Ҫɾ����¼��ѧ��*/
	q=p=h;						/*��q��p����ֵͷָ��*/
	while(p!=NULL&&strcmp(p->no,s))   /*����¼��ѧ�Ų���Ҫ�ҵģ���ָ�벻Ϊ��ʱ*/
	{  
		q=p;					/*��pָ��ֵ����q��Ϊp��ǰ��ָ��*/
		p=p->next;				/*��pָ��ָ����һ����¼*/
	}
	if(p==NULL)					/*���pΪ�գ�˵��������û�иý��*/
		printf("\n���ź���������û����Ҫɾ����ѧ��Ϊ %s ��ѧ����\n",s);
	else						/*p��Ϊ�գ���ʾ�ҵ��ļ�¼��Ϣ*/
	{
		printf("*********************************** Found *****************************************\n");
		printf("   ѧ��          ����          �ɼ�1���ɼ�2���ɼ�3    �ܷ�   ƽ����  ����\n");
		printf("-----------------------------------------------------------------------------------\n");
		printf("    %-11s%-15s%6.2f%7.2f%7.2f %9.2f  %6.2f  %3d \n",  p->no,p->name,p->score[0],p->score[1],
				p->score[2],p->sum,p->average,p->order);
		printf("***********************************************************************************\n");
		
		do{
			printf("��ȷʵҪɾ���˼�¼��?(y/n):");
			scanf("%s",k);
        }while(k[0]!='y'&&k[0]!='n');
		
		if(k[0]!='n')				/*ɾ��ȷ���ж�*/
		{
			if(p==h)				/*���p==h��˵����ɾ�����ͷ���*/
				h=p->next;			/*�޸�ͷָ��ָ����һ����¼*/
			else
				q->next=p->next;    /*����ͷָ�룬��p�ĺ�̽����Ϊq�ĺ�̽��*/
			free(p);				/*�ͷ�p��ָ���ռ�*/
			printf("\n �Ѿ��ɹ�ɾ��ѧ��Ϊ %s ��ѧ���ļ�¼��\n",s);
		}
	}
	return(h);						/*����ͷָ��*/
}

/*�������ݵ��ļ�ģ��*/
void save(STUDENT *h)
{
   FILE *fp;                                      /*����ָ���ļ���ָ��*/
   STUDENT *p;                                    /*�����ƶ�ָ��*/
   char outfile[20];                              /*��������ļ���*/
   printf("�����뵼���ļ��������磺d:\\xds\\score.txt:\n");
   scanf("%s",outfile);
   if((fp=fopen(outfile,"wb"))==NULL)             /*Ϊ�����һ���������ļ�����û������*/
   {
      printf("���ܴ��ļ����ļ�����ʧ�ܣ�\n");
   }
   else
   {
	   p=h;                                       /*�ƶ�ָ���ͷָ�뿪ʼ*/
	   while(p!=NULL)                             /*��p��Ϊ��*/
	   {
		  fwrite(p,sizeof(STUDENT),1,fp);         /*д��һ����¼*/
		  p=p->next;                              /*ָ�����*/
	   }
	   fclose(fp);                                /*�ر��ļ�*/
	   printf("-----���м�¼�Ѿ��ɹ��������ļ�%s��!-----\n",outfile);   /*��ʾ����ɹ�*/
   }
}

/*������Ϣģ��*/
STUDENT *load()
{
   STUDENT *p,*q,*h=NULL;                         /*�����¼ָ�����*/
   FILE *fp;                                      /* ����ָ���ļ���ָ��*/
   char infile[20];                               /*�����ļ���*/
   printf("�����뵼���ļ��������磺d:\\xds\\score.txt:\n");
   scanf("%s",infile);                            /*�����ļ���*/
   if((fp=fopen(infile,"rb"))==NULL)              /*��һ���������ļ���Ϊ����ʽ*/
   {  
		printf("�ļ���ʧ�ܣ�\n");               /*�粻�ܴ򿪣�����ͷָ��*/
		return h;
   }
   p=(STUDENT *)malloc(sizeof(STUDENT));          /*����ռ�*/
   if(!p)
   {  
		printf("�ڴ����ʧ��!\n");                /*��û�����뵽�����ڴ����*/
		return h;                                 /*���ؿ�ͷָ��*/
   }
   h=p;                                           /*���뵽�ռ䣬������Ϊͷָ��*/
   while(!feof(fp))                               /*ѭ��������ֱ���ļ�β����*/
   {
	   if(1!=fread(p,sizeof(STUDENT),1,fp))
			break;                                  /*���û�������ݣ�����ѭ��*/
		p->next=(STUDENT *)malloc(sizeof(STUDENT)); /*Ϊ��һ���������ռ�*/
		if(!p->next)
		{
			 printf("�ڴ����ʧ��!\n");             /*��û�����뵽�����ڴ����*/
			 return h;
		}
		q=p;                                        /*���浱ǰ����ָ�룬��Ϊ��һ����ǰ��*/
		p=p->next;                                  /*ָ����ƣ��¶�������������ǰ��β*/
	}
	q->next=NULL;                                  /*���һ�����ĺ��ָ��Ϊ��*/
	fclose(fp);                                    /*�ر��ļ�*/
	printf("�Ѿ��ɹ����ļ�%s��������!!!\n",infile);
	return h;                                      /*����ͷָ��*/
}

/******��������ʼ*******/
int main()
{
	STUDENT *head = NULL;       /*������ͷָ��*/
	system("color 5e");         /*��DOS��������������color ?����鿴�����ʽ*/
	for(;;)						/*����ѭ��*/
	{
		switch(menu_select())   /*�������˵�����������ֵ������������������*/
		{
			 case 1: head=create();break;        /*��������*/
			 case 2: print(head);break;          /*��ʾȫ����¼*/
			 case 3: head=sort(head);break;      /*����*/
			 case 4: search(head);break;         /*���Ҽ�¼*/
			 case 5: head=insert(head);break;	 /*�����¼*/
			 case 6: head=delete1(head);break;   /*ɾ����¼*/
			 case 7: save(head);break;           /*�����ļ�*/
			 case 8: head=load();break;          /*���ļ�*/
			 case 9: exit(0);                    /*�������*/
		}
	} 
}
