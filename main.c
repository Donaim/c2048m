
#include "helper.c"
#include "screen.c"
#include "logics.c"
#include "test.c"

void parse_key(KEY key) {
    // printf("%d", key);
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

int main() {
    init_screen();
    init_logics();
    // randomize_table();
    
    while(true) {
        printscreen();
        spawn_cell();
        
        KEY key = getkey();
        if (key == KEY_ESC) return 0;
        else parse_key(key);
    }

    return 0;
}