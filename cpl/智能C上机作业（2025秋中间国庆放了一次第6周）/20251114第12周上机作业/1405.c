#include<stdio.h>
#include<math.h>
int ugly(int x) {
    if (x <= 0) {
        return 0;
    }
    while (x % 2 == 0) {
        x /= 2;
    }
    while (x % 3 == 0) {
        x /= 3;
    }
    while (x % 5 == 0) {
        x /= 5;
    }
    return x == 1;
}
int main(void) {
    int count = 0;  //
    int x = 1;      
    while (count <= 100) {
        if (ugly(x)) {
            count++;  
        }
        x++;
    }
    printf("%d\n", x - 1);
    return 0;
}
