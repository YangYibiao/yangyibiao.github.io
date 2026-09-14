#include<stdio.h>

#pragma pack() // 强制按一个字节对齐

struct record_tag {
    int num;
    double score; // 结构体中最大的类型进行对齐
    char id;
};

typedef struct {
    int num;
    double score;
    char id;
} record;

void Print1(struct record_tag r);
void Print1_pointer(struct record_tag *p);
void Print2(record r);

record initialize_record()
{
    record r = {10, 98.5, 'M'};
    return r;
}

int main()
{
    struct record_tag stu = {12, 92.0, 'M'};

    printf("%lu\n", sizeof(stu));
    printf("%p\n", &stu);
    printf("%p: %d\n", &stu.num, stu.num);
    printf("%p: %f\n", &stu.score, stu.score);
    printf("%p: %c\n", &stu.id, stu.id);

    Print1(stu);
    Print1_pointer(&stu);

    record stu2 = initialize_record();
    Print2(stu2);
    return 0;
}

void Print1(struct record_tag r)
{
    printf("1-[%d, %f, %c]\n", r.num, r.score, r.id);
    printf("%p\n", &r);
    printf("%p: %d\n", &r.num, r.num);
    printf("%p: %f\n", &r.score, r.score);
    printf("%p: %c\n", &r.id, r.id);
}

void Print1_pointer(struct record_tag *p)
{
    printf("1-pointer[%d, %f, %c]\n", (*p).num, (*p).score, (*p).id);
    printf("1-pointer[%d, %f, %c]\n", p->num, p->score, p->id);
    printf("%p\n", &(*p));
    printf("%p: %d\n", &p->num, p->num);
    printf("%p: %f\n", &p->score, p->score);
    printf("%p: %c\n", &p->id, p->id);
}

void Print2(record r)
{
    printf("2-[%d, %f, %c]\n", r.num, r.score, r.id);
}