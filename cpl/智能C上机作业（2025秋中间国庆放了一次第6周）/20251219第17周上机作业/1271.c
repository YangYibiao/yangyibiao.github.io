#include<stdio.h>
typedef struct{
		long id;
       	char name[10];
       	char sex[2];
}PS;

int delete(PS *p1, int m, PS *p2,int n);
int merge(PS *p1,int m, PS *p2 ,int n);
void sort(PS *p,int n);
void display(PS *p,int n);

int main(void)
{
	PS a[10]={{101, "tom","m"},{103,"mary","f"},{104,"mark","m"},
 {105,"julia","f"},{106, "sara","f"}},
	   b[10]={{102, "mark","m"},{104,"mark","m"}};
	int na=5,nb=2;

	puts("a:");
	display(a,na);
	puts("b:");
	display(b,nb);
	na=delete(a,na,b,nb);
	puts("a:");
	display(a,na);
	nb=merge(b,nb,a,na);
	puts("b:");
	display(b,nb);
	sort(a,na);
	puts("a:");
	display(a,na);
	return 0;
}
int delete(PS *p1, int m, PS *p2,int n)
{
	int i,j,flag;
	for(i=0;i<m;){
		flag=0;
		for(j=0;j<n;j++)
			if(p1[i].id==p2[j].id){	
                            flag=1;break;}
		if(flag){
			for(j=i;j<m-1;j++)
				p1[j]=p1[j+1];
			m--;
		}
		else i++;
	}
	return m;
}
int merge(PS *p1,int m, PS *p2 ,int n)
{
	int i,j;
	for(j=0;j<n;j++){
		for(i=m-1;i>=0&&p1[i].id>p2[j].id;i--) p1[i+1]=p1[i];
		p1[i+1]=p2[j];
		m++;
	}
	return m;
}
void sort(PS *p,int n)
{
	PS t;
	int i,j;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		if(strcmp(p[j].sex,p[j+1].sex)>0||strcmp(p[j].sex,p[j+1].sex)==0&&strcmp(p[j].name,p[j+1].name)>0) {
				t=p[j];p[j]=p[j+1];p[j+1]=t;}
}
void display(PS *p,int n)
{
	int i;
	puts("ID\tNAME\tSEX");
	for(i=0;i<n;i++)
		printf("%ld\t%s\t%s\n",p[i].id,p[i].name,p[i].sex);
		//或者printf("%ld\t%s\t%s\n",p->id,p->name,p->sex);p++;
}
