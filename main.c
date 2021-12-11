#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menu.h"
#pragma GCC ignored -Wall

#define filename "data.csv"

char **data;
int length;

int main(){
    data = loadfile(filename,&length);
    main_menu_page(data,length);
}
