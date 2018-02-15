
#include "helper.c"
#include "screen.c"
#include "test.c"

void parse_key(KEY key) {
    // printf("%d", key);
    switch(key) {
        case KEY_UP: 
            break;
        case KEY_DOWN: 
            break;
        case KEY_LEFT: 
            break;
        case KEY_RIGHT: 
            break;
    }
}

int main() {
    init_screen();
    init_logics();
    // randomize_table();
    
    while(true) {
        spawn_cell();
        printscreen();
        
        KEY key = getkey();
        if (key == KEY_ESC) return 0;
        else parse_key(key);
    }

    return 0;
}