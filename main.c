#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int length = 0;
size_t lineLim = 256;

char **loadfile(char *fn,int *len){
    FILE *fp = fopen(fn,"r");
    if (!fp){
        printf("can't load");
    }
    char **line = (char **)malloc(lineLim * sizeof(char *));

    char buffer[1000];
    int i = 0;
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
        buffer[strlen(buffer)] = '\0';
        int slen = strlen(buffer);
        char *poly = (char *)malloc((slen + 1) * sizeof(char));
        strcpy(poly,buffer);
        line[i] = poly;
        i++;
    }
    *len = i; // return length of line
    return line;
}

int max(int m, int n) {  
    return (m > n)? m: n; 
}

int *add(int *A, int *B, int m, int n)
{
   int size = max(m, n);
   int *sum = (int*)malloc(size*sizeof(int));
   memset(sum, 0, size*sizeof(sum[0]));
   
   for (int i = 0; i<m; i++)
     sum[i] = A[i];
 
   for (int i=0; i<n; i++)
       sum[i] += B[i];
    
   return sum;
}

int* convert_int(char *arr,int *m){
    int len=strlen(arr),i;
    const char *tok;
    int column = 0;
	int *a=(int*)malloc(len*sizeof(int));
    char* value = strtok(arr, ", ");
    while (value) {
                int sepInt = atoi(value);
                a[column] = sepInt;
                value = strtok(NULL, ", ");
                column++;
            }
    *m = column;
    return a;
}

void printPoly(int* poly, int n)
{
    for (int i=0; i< n; i++){
       printf("%d",poly[i]);
       if (i != 0)
        printf("x^%d",i);
       if (i != n-1)
       printf(" + ");
    }
}   

int main(){
    int poly1_max , poly2_max;
    char **data = loadfile("data.csv",&length);
    int *poly1 = convert_int(data[0],&poly1_max);
    int *poly2 = convert_int(data[1],&poly2_max);    
    int *sum = add(poly1,poly2,poly1_max,poly2_max);
    int size = max(poly1_max,poly2_max);
    printPoly(sum,size);


    return 0;
}
