#include<stdio.h>

union Ip
{
    unsigned int num;
    struct
    {
        unsigned char c1;
        unsigned char c2;
        unsigned char c3;
        unsigned char c4;
    }ip;
};

int main()
{
    union Ip my_ip;
    my_ip.num = 0xffeeaabb;
    if(my_ip.ip.c1 == 0xbb) {
      printf("big");
    } else {
      printf("little");
    }
    printf("sizeof(char) = %ld", sizeof(char));
    printf("sizeof(int) = %ld", sizeof(int));
    printf("%d.%d.%d.%d", my_ip.ip.c1, my_ip.ip.c2, my_ip.ip.c3, my_ip.ip.c4);
        return 0;
}