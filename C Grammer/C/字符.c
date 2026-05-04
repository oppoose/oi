#include <stdio.h>
#include <string.h>

int main(int argc,char const *argv[])
{   
    int i;
    for (i=0; i<argc; i++){
        printf("%d:%s\n",i,argv[i]);
    }
    return 0;
}