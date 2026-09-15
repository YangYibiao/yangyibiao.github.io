#include <stdio.h>

int main() {
    float height, weight, age;
    char gender;
    double bmr;
    double chocolates;
    scanf("%f %f %f %c", &height, &weight, &age, &gender);

    if (gender == 'M') {
        bmr = 66 + (6.3 * weight * 2.2) + (12.9 * height * 0.39) - (6.8 * age);
    } else if (gender == 'F') {
        bmr = 655 + (4.3 * weight * 2.2) + (4.7 * height * 0.39) - (4.7 * age);
    }
    chocolates = bmr / 230;
    printf("ÏûºÄ%.2f¿éÇÉ¿ËÁ¦\n", chocolates);
    
    return 0;
}