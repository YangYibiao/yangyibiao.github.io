#include <stdio.h>

struct Point
{
  int x;
  int y;
};

struct Rectangle
{
  struct Point p1;
  struct Point p2;
};

void PrintRect(struct Rectangle r)
{
  printf("<%d, %d> to <%d, %d>\n", r.p1.x, r.p1.y, r.p2.x, r.p2.y);
}

void PrintRectPoint(struct Rectangle *p)
{
  printf("<%d, %d> to <%d, %d>\n", p->p1.x, p->p1.y, p->p2.x, p->p2.y);
}

int main()
{
  struct Rectangle recs[] = {
      {{1, 1}, {2, 2}},
      {{3, 3}, {4, 4}}};

  struct Rectangle *rp = &recs[0];
  printf("%d\n", recs[0].p1.x);
  printf("%d\n", rp->p1.x);
  printf("%d\n", (rp->p1).x);
  printf("%d\n", (recs[0].p1).x);

  for (int i = 0; i < 2; i++)
  {
    PrintRect(recs[i]);
    PrintRectPoint(&recs[i]);
  }

  return 0;
}