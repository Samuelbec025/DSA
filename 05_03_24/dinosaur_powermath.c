#include <stdio.h>
#include <math.h>

float surfacearea(float length, float width)
{
    float ans, ecc;
    ecc = sqrt(1 - (pow(length,2) / pow(width,2)));
    ans = ((2 * 3.14 * pow(width,2)) + ((2 * 3.14 * length * width * asin(ecc)) / ecc));
    return ans;
}

float calculator(float result_1)
{
    float cal_1;
    return 380.66 / result_1;
}

int main(){
    float num1, num2, num3, num4, result_1, result_2;
    printf("Enter the length of the egg: ");
    scanf("%f",&num1);
    printf("Enter the width of the egg: ");
    scanf("%f",&num2);
    num3 = num1 / 2;
    num4 = num2 / 2;
    result_1 = surfacearea(num1, num2);
    result_2 = calculator(result_1);
    printf("The Surface area of the Egg: %f\n",result_1);
    printf("The number of Eggs: %f",result_2);
    return 0;
}
