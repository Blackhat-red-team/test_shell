#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    if (argc !=3)
    {
        printf("two args required!\n");
        exit(-1);
    }
    
int low = atoi(argv[1]);
int high = atoi(argv[2]);
for (int i = low; i<=high; i++)
{
printf("%d\n",i);
}
//  //printf("argc: %d\n" ,argc);    
//     for (int i = 0; i < argc; i++)
    
//         printf("argv[%d]=%s\n",i,argv[i]);
    return 0;
}
