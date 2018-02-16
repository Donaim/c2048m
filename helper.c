#pragma once

#include <stdlib.h>
#include <stdio.h>

#include "platform.h"

char readchar() {
    char c = 0;
    switch(__PLATFORM_CURRENT) {
        case __PLATFORM_WINDOWS: {
            c = getchar();
            break;
        }
        case __PLATFORM_LINUX:
        case __PLATFORM_BSD: {
            system ("/bin/stty raw");
            c = getchar();
            system ("/bin/stty cooked");
            break;
        }
        default:
            fprintf(stderr, "dont know how to read a char on this os");
            fflush(stderr);
            break;
    }
    if (__PLATFORM_CURRENT)
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
            fprintf(stderr, "dont know how to clear the screen on this os");
            fflush(stderr);
            return;
    }
}