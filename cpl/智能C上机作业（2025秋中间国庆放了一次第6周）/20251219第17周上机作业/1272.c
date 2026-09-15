#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct node{
	long num;
	int score;
	struct node *next; 
}NODE;

NODE *creat(void){
	NODE *head=NULL,*p1=NULL,*p2=NULL;
	long num;
	int score;
	int n=0;
	while(1){
		scanf("%ld%d",&num,&score);
		if(num==0)break;
		n++;
		p1=(NODE *)malloc(sizeof(NODE));
		p1->num=num;
		p1->score=score;
		p1->next=NULL;
		if(n==1)
			head=p2=p1;
		else
			p2->next=p1;
			p2=p1;
	}
	return head;
}

NODE *insert(NODE *head,NODE *p0){
	NODE *p1=NULL,*p2=NULL;
	if(head==NULL){
		head=p0;
		p0->next=NULL;
	}
	else{
		p1=head;
		while((p0->num>p1->num)&&(p1->next!=NULL)){
			p2=p1;
			p1=p1->next;
		}
		if(p1==head&&p0->num<=p1->num){//由于有相同项，所以比较时需要加上<= 
			p0->next=head;
			head=p0;
		}
		else if(p0->num<=p1->num){//由于有相同项，所以比较时需要加上<= 
			p2->next=p0;
			p0->next=p1;
		}
		else{
			p1->next=p0;
			p0->next=NULL;
		}
	}
	return head;
}

NODE *sort(NODE *head){
	NODE *p=NULL,*temp=NULL;
	p=head->next;
	head->next=NULL;
	while(p!=NULL){
		temp=p->next;
		head=insert(head,p);
		p=temp;
	}
	return head;
}

void print(NODE *head){
	NODE *p=NULL;
	p=head;
	while(p!=NULL){
		printf("%ld\t%d\n",p->num,p->score);
		p=p->next;
	}
}

NODE *delNODE(NODE *head,NODE *p1,NODE *p2){//p1为要删除的结点，p2为要删除节点的前一个结点 
	if(p1==head){
		head=p1->next;
		free(p1);
	}
	else{
		p2->next=p1->next;
		free(p1);
	}
	return head;	
}

int main(void){
	NODE *p=NULL,*p1=NULL,*p2=NULL,*p3=NULL;
	p=creat();
	p=sort(p);
	p1=p2=p;
	while(p1!=NULL){//由于已经排序，因此只需要前后两两比较删除即可 
		p2=p1->next;
		if(p2==NULL)break;
		if(p1->num==p2->num&&p1->score<=p2->score){
			p=delNODE(p,p1,p3);
			p1=p2;
		}
		else if(p1->num==p2->num&&p1->score>p2->score){
			p=delNODE(p,p2,p1);
		}
		else{
			p3=p1;
			p1=p1->next; 
		}				
	}
	print(p);
}
