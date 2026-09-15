/* 3．以下程序的功能是统计从键盘输入的一组字符中不同字符各自出现的次数，
将统计结果保存在一个链表中，并按照字符ASCII码值从大到小的顺序输出统计结果。
例如，当输入abcdefabc时，程序输出：f:1，e:1，d:1，c:2，b:2，a:2。
链表结点的数据结构定义如下：
struct node{
	char data;            
	int count;            
	struct node *next;
};
函数insert的参数head接收一个链表的头指针，该链表保存统计结果，全部结点按照data成员的值从大到小有序。
函数insert的功能是对参数ch中保存的字符做下述处理：如果该字符已保存在head指向的链表中，则对保存该字符的
结点中的count成员做加1运算；如果该字符不在链表中，则生成一个新结点用于保存该字符的统计结果，并将新结点
插入链表，插入新结点后链表中的结点仍然按照data成员的值从大到小有序。*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	char data;            
	int count;            
	struct node *next;
};

struct node *insert(struct node *head, char ch)
{	struct node *p1=NULL,*p2=NULL, *p=NULL;
	int flag;
	/*****************************************/
	p=(struct node *)malloc(_____________);  
	/*****************************************/
	
	p->data=ch;	p->count=1;
	
	if(head==NULL){
	/*****************************************/
		_____________; 
	/*****************************************/
		p->next=NULL; 
		flag=0;
	}
	else{	p1=head;
		while(p1->data>ch && p1->next!=NULL){
			p2=p1; 
			p1=p1->next;
		}
		if(p1->data==ch){	
			/*****************************************/
			________________;		
			/*****************************************/
			flag=1;  	
		}
		else	
			if(p1->data<ch){
				if(head==p1) head=p;
				else	p2->next=p;  
				p->next=p1;
				flag=0;
			}
			else{	
				p1->next=p;	
				p->next=NULL; 
				flag=0;		
			}
		}
		/*****************************************/
		if(_______________)	
			free(p);
		/*****************************************/
	 return head;
}
int main(void)
{	char ch;
	struct node *head=NULL,*p;
	while((ch=getchar())!='\n')	head=insert(head,ch);
	p=head;
	while(p!=NULL){
		printf("%c:%d\n",p->data,p->count);
		p=p->next;
	}
}
