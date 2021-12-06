#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int length = 0;
size_t lineLim = 256;
int data[10];

char **loadfile(char *fn,int *len){
    FILE *fp = fopen(fn,"r");
    if (!fp){
        printf("can't load");
    }
    char **line = (char **)malloc(lineLim * sizeof(char *));

    char *end;
    char buffer[1000];
    int i = 0;
    size_t n = 0;
    while (fgets(buffer,lineLim,fp))
    {

        //check line array if full increase if over limited increase it 
        if (i == lineLim){
            lineLim *= 2;
            char **line = realloc(line, lineLim * sizeof(char*));
            if (!line){
                printf("can't allocate ");
            }
        }
        // this section suppose to get int from string inside int array

        line[i] = // here is to insert data which idk how to 
        i++;
    }
    *len = i; // return length of line
    return line;
}

int main(){
    
    
    char **data = loadfile("data.csv",&length);
    printf("%d\n" ,length);
    for (int i = 0;i < length; i++){
        printf("%s \n", data[i]);
    }
    return 0;
}