#include <stdio.h>

int main()
{
  enum Day
  {
    Monday = 1,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
  } d;
  printf("%d\n", Monday);
  printf("%d\n", Tuesday);
  printf("%d\n", Wednesday);
  printf("%d\n", Thursday);
  printf("%d\n", Friday);
  printf("%d\n", Saturday);
  printf("%d\n", Sunday);

  return 0;
}