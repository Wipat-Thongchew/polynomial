#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Poly.h"
#pragma GCC ignored -Wall

void main_menu_page(char **data,int length) {
    while(1){
        int choice;
        printf("What do you want to do\n");
        printf("1) look at polynomial\n");
        printf("2) compute polynomial\n");
        printf("3) Exit\n");
        printf("\nChoice--> ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printAll(data,length);
            break;
        case 2:
            compute_menu(data,length);
            break;
        case 3:
            printf("goodbye\n");
            return;
        }
    }
}

void compute_menu(char **data,int length){
    int choice;
    printf("What do you want to compute\n");
    printf("1) Plus polynomial\n");
    printf("2) Minus polynomial\n");
    printf("3) back to main menu");
    printf("\nChoice--> ");
    scanf("%d",&choice);
    switch(choice){
        case 1:
            plus_poly(data,length);
            break;
        case 2:
            minus_poly(data,length);
            break;
        case 3:
            main_menu_page(data,length);    
            break;
        }
}

void plus_poly(char **data,int length){
    int id1,id2,size;
    int poly1_max,poly2_max;
    int *poly1;
    int *poly2;
    int *sum;
    printAll(data,length);
    printf("Enter id of the first Polynomial\n");
    scanf("%d" , &id1);
    printf("Enter id of the second Polynomial\n");
    scanf("%d" , &id2);
    poly1 = convert_int(data[id1],&poly1_max);
    poly2 = convert_int(data[id2],&poly2_max);
    sum = add(poly1,poly2,poly1_max,poly2_max);
    size = max(poly1_max,poly2_max);
    printf("The sum is: ");
    printPoly(sum,size);
    printf("\n");
}

void minus_poly(char **data,int length){
    int id1,id2,size;
    int poly1_max,poly2_max;
    int *poly1;
    int *poly2;
    int *minu;
    printAll(data,length);
    printf("Enter id of the first Polynomial\n");
    scanf("%d" , &id1);
    printf("Enter id of the second Polynomial\n");
    scanf("%d" , &id2);
    poly1 = convert_int(data[id1],&poly1_max);
    poly2 = convert_int(data[id2],&poly2_max);
    minu = minus(poly1,poly2,poly1_max,poly2_max);
    size = max(poly1_max,poly2_max);
    printf("The minus is: ");
    printPoly(minu,size);
    printf("\n");
}
