
#include <string.h>
#include "helper.c"
#include "screen.c"
#include "logics.c"
#include "test.c"

void parse_key(KEY key) {
    switch(key) {
        case KEY_UP: 
            shift(0, -1);
            break;
        case KEY_DOWN: 
            shift(0, +1);
            break;
        case KEY_LEFT: 
            shift(-1, 0);
            break;
        case KEY_RIGHT: 
            shift(+1, 0);
            break;
    }
}
int atoi_s(char * str) {
    int re = 0;
    for (int i = strlen(str) - 1, p = 1; i >= 0; i--, p *= 10) {
        char c = str[i];
        if (c >= '0' && c <= '9') {
            int d = c - '0';
            re += d * p;
        }
        else {
            fprintf(stderr, "Cannot parse \"%s\" to int: unexpected symbol \'%c\'\n", str, c);
            fflush(stderr);
            exit(1);
        }
    }
    return re;
}
void parse_args(int argc, char ** argv) {
    if (argc > 1) { W = atoi_s(argv[1]); }
    else { W = 6; } 
    if (argc > 2) { H = atoi_s(argv[2]); }
    else { H = 6; }
}

int main(int argc, char ** argv) {
    parse_args(argc, argv);
    init_screen();
    init_logics();
    
    while(true) {
        printscreen();
        spawn_cell();
        
        KEY key = getkey();
        if (key == KEY_ESC) return 0;
        else parse_key(key);
    }

    return 0;
}