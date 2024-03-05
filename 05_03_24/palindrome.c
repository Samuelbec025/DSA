#include <stdio.h>

int reverse(int num)
{
	int rev;
    while (num > 0){
        rev = rev * 10 + num % 10;
        num /= 10;
    }
    return rev;
}

int main(){
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    if(num == reverse(num)) {
        printf("%d is a palindrome.\n",num);
    }
    else{
        printf("%d is not a palindrome.\n",num);
    }
    return 0;
}
