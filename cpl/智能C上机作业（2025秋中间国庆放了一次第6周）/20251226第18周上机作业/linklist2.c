/* 下列程序把一个int型数组的各元素值作为一个结点插入到一个链表中去。
如果数组元素的值已经出现在链表中，则不插入。否则，如果数组元素值小于0，
按该数组元素生成的结点总是被插入到链表的表头；如果数组元素值大于0，
按该数组元素生成的结点总是被插入到链表的表尾；如果数组元素值等于0，
则不插入到链表中。程序运行后输出结果是
“  -31  -45  -10   -7    3   12   20”。
*/

#include<stdio.h>
#include<stdlib.h>  

typedef struct node{
    int data;
    struct node *next;
}NODE;

/******************************/
________ insert(NODE *head , int n)
/******************************/
{ 	
	NODE *p=NULL,*p1=head;
   	if(n==0) return head;
	while(p1!=NULL){
		if(p1->data==n) return head;
		p1=p1->next;
	}
	p1=head;
	
	/******************************/
	p=__________________;
	/******************************/
	
	if(p==NULL)exit(0);
	p->data=n;
	p->next=0;
	if(!p1) head =p;
  	else{
		if(p->data<0){
			p->next=head;
			head=p;
		}
	  	else{
			while(p1->next)
	    			p1=p1->next;
			/******************************/
	 	 	______________________;
			/******************************/
		}
	}
	return head;
}
void main( )
{  NODE *head=NULL,*p;
   int i,num[10]={3,-7,-10,12,3,-45,12,-31,0,20};
   for(i=0;i<10; i++)
	/******************************/
	________________________;
	/******************************/
   p=head;
   while(p){
        printf("%5d",p->data);
	 p=p->next;
   }
}
