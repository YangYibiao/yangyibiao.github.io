#include<stdio.h>

enum {Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec};

int main()
{
    int month;
    scanf("%d", &month);
    switch (month) //int
    {
      case Jan:    printf("Janurary"); break;
      case Feb:    printf("Februrary"); break;
      case Mar:    printf("March"); break;
      case Apr:    printf("April"); break;
      case May:    printf("May"); break;
      case Jun:    printf("June"); break;
      case Jul:    printf("July"); break;
      case Aug:    printf("August"); break;
      case Sep:    printf("September"); break;
      case Oct:    printf("October"); break;
      case Nov:    printf("November"); break;
      case Dec:    printf("December"); break;
      
      default:
          printf("Wrong month entered.\n");
          break;
    }
    return 0;
}