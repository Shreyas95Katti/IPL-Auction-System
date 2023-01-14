#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "IPLheaderfile.h"
int main()
{
    int c;
    char cha;//for getch()
    do
    {
        printf("Welcome to the IPL auction portal!!\nPlease choose your role:\n");
        printf("1.Admin\n2.User\n3.Exit\nEnter your choice\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            admin();
            break;
            case 2:
            user();
            break;
            case 3:
            exit(0);
            default:
            printf("Cannot recognize given input.Please enter an option from the given list.");
        }
    }while(1);
    return 0;
}