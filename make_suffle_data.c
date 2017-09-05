#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

int gMaxData = 100000;

void appendEvent(void *aArg)
{
    FILE*  sFp = (FILE*)aArg;
    int    i=0;
    char   sMachine[128];
    int    sError;
    int    sIndex;
    char*  sMsg[] = {"success", "info", "error"};

    for(i = 0; i < gMaxData ; i++)
    {
        sprintf(sMachine, "%d.%d.%d.%d",rand()%255, rand()%255, rand()%255, rand()%255);
        sError = rand()%8000 - 4000;
        if(sError > 0 )
        {
            sIndex = 1;
        }
        else if( sError == 0 )
        {
            sIndex = 0;
        }
        else
        {
            sIndex = 2;
        }
        fprintf(sFp, "3 %s %d %s\n", sMachine, sError, sMsg[sIndex]);
    }
}

void appendFw2(void *aArg)
{
    char sSrc[128];
    char sDst[128];
    int  i=0;

    FILE* sFp = (FILE*)aArg;

    for(i = 0; i < gMaxData; i++)
    {
        sprintf(sSrc, "%d.%d.%d.%d",rand()%255, rand()%255, rand()%255, rand()%255);
        sprintf(sDst, "%d.%d.%d.%d",rand()%255, rand()%255, rand()%255, rand()%255);
        fprintf(sFp, "2 %s ::%s %d %s ::%s %d %d %d\n",
                sSrc, sSrc, rand()%10000,
                sDst, sDst, rand()%10000,
                rand(), rand()); 
    }
}

void appendFw1(void *aArg)
{
    char sSrc[128];
    char sDst[128];
    int  i=0;

    FILE* sFp = (FILE*)aArg;

    for(i = 0; i < gMaxData; i++)
    {
        sprintf(sSrc, "%d.%d.%d.%d",rand()%255, rand()%255, rand()%255, rand()%255);
        sprintf(sDst, "%d.%d.%d.%d",rand()%255, rand()%255, rand()%255, rand()%255);
        fprintf(sFp, "1 %s ::%s %d %s ::%s %d %d %d\n",
                sSrc, sSrc, rand()%10000,
                sDst, sDst, rand()%10000,
                rand(), rand());
    }
}

int main(int argc, char **argv)
{
    int        i;
    FILE      *sFp;
    pthread_t  sThread[3];
    int        sRC;

    srand(time(NULL));

    if( argc >= 2 )
    {
        gMaxData = atoi(argv[1]);
    }

    printf("Max Data : %d\n", gMaxData);

    sFp = fopen("suffle_data.txt", "wt");
    if( !sFp )
    {
        printf("file open error\n");
        exit(-1);
    }

    pthread_create(&sThread[0], NULL, (void*)&appendFw1, (void*)sFp);
    pthread_create(&sThread[1], NULL, (void*)&appendFw2, (void*)sFp);
    pthread_create(&sThread[2], NULL, (void*)&appendEvent, (void*)sFp);

    for(i = 0;i < 3; i++)
    {
        printf("join %d\n", i);
        sRC = pthread_join(sThread[i], NULL);
        if( sRC < 0 )
        {
            printf("Failed to join hhread [%d]: %d\n", i, sRC);
            exit(-1);
        }
    }

    fclose(sFp);
    return 0;
}

