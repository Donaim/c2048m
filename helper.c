#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include <stdio.h>

#include "platform.h"

int nsleep(int ms) {
    int sec = ms / 1000;
    ms %= 1000;

    struct timespec ts;
    ts.tv_sec = sec;
    ts.tv_nsec = ms * 1000000L;
    return nanosleep(&ts, NULL);
}

typedef struct {
    int interval;
    void (* func) ();
} __loop_props;

void * __loop_async(void * obj) {
    __loop_props * p = (__loop_props*) obj;
    int interval = p->interval;
    void (* func) () = p->func;

    while(1) {
        func();
        nsleep(interval);
    }

    return NULL;
}

void loop_async(void (*f)(), int interval) {
    pthread_t th;

    __loop_props * p = (__loop_props*) malloc(sizeof(__loop_props));
    p->interval = interval;
    p->func = f;

    pthread_create(&th, NULL, __loop_async, p);
}

char readchar() {
    system ("/bin/stty raw");
    char c = getchar();
    system ("/bin/stty cooked");
    return c;
}
typedef enum { KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT, KEY_ESC, KEY_UNKNOWN } KEY;
KEY getkey() {
    char c = readchar();
    switch(c) {
        case 'W':
        case 'w': return KEY_UP;
        case 'S':
        case 's': return KEY_DOWN;
        case 'A':
        case 'a': return KEY_LEFT;
        case 'D':
        case 'd': return KEY_RIGHT;

        case 27: return KEY_ESC;
        
        default: return KEY_UNKNOWN;
    }
}

// #include <unistd.h>
// void clearscreen() /* https://stackoverflow.com/questions/2347770/how-do-you-clear-the-console-screen-in-c */
// {
//   const char *CLEAR_SCREEN_ANSI = "\e[1;1H\e[2J";
//   write(STDOUT_FILENO, CLEAR_SCREEN_ANSI, 12);
// }
// #include <curses.h> // need -l ncurses
// void clearscreen() {
//     move(0, 0);
// }
void clearscreen() {
    switch(__PLATFORM_CURRENT) {
        case __PLATFORM_WINDOWS: {
            system("cls");
            return;
        }
        case __PLATFORM_LINUX:
        case __PLATFORM_BSD: {
            system("clear");
            return;
        }
        default:
            system("echo \"dont know how to clear the screen\"");
            return;
    }
}