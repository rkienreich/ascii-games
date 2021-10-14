/*
    Progress bar
    Unix version
*/
#include <stdio.h>
#include <locale.h>
#include <time.h>
#include <signal.h>
#include <stdlib.h>

#define ANSI_COLOR_RED     "\x1b[31m"
#define ANSI_COLOR_GREEN   "\x1b[32m"
#define ANSI_COLOR_YELLOW  "\x1b[33m"
#define ANSI_COLOR_BLUE    "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN    "\x1b[36m"
#define ANSI_COLOR_RESET   "\x1b[0m"

#define TSLEEP 2000000L

// UTF-8 Code
#define RECTANGLE 9632

// reset terminal colors at ctrl-c
void  INThandler(int sig)
{
    printf(ANSI_COLOR_RESET "Finished\n");
    exit(0);
}

int main()
{
    signal(SIGINT, INThandler);
    setlocale(LC_ALL,"");
    // delay 30 ms
    struct timespec ts = {0, TSLEEP};
    
    int i;
    int bar[50];
    int size = sizeof(bar)/sizeof(int);
    
    // initialize bar with spaces
    for (i = 0; i < size -1; i++)
        bar[i] = ' ';
    // terminate string
    bar[size - 1] = '\0';

    for(;;) {
        for (i = 0; i < size - 1; i++) {
                bar[i] = RECTANGLE;
                fflush(stdout);
                if (i < size/3)
                    printf(ANSI_COLOR_GREEN "\r%ls", bar);
                else if (i < size/3*2)
                    printf(ANSI_COLOR_YELLOW "\r%ls", bar);
                else
                    printf(ANSI_COLOR_RED "\r%ls", bar);
                nanosleep(&ts, NULL);
        }
        
        for (i = size - 2; i >= 0; i--) {
                bar[i] = ' ';
                fflush(stdout);
                if (i > size/3*2)
                    printf(ANSI_COLOR_RED "\r%ls", bar);
                else if (i > size/3)
                    printf(ANSI_COLOR_YELLOW "\r%ls", bar);
                else
                    printf(ANSI_COLOR_GREEN "\r%ls", bar);
                nanosleep(&ts, NULL);
        }
    }
    return 0;
}

