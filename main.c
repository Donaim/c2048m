
#include "helper.c"
#include "screen.c"

int hx = 2, hy = 2;

void hero_move(KEY key) {
    screen[hx][hy] = ' ';
    printf("%d", key);
    switch(key) {
        case KEY_UP: hy--;
        case KEY_DOWN: hy++;
        case KEY_LEFT: hx--;
        case KEY_RIGHT: hx++;
    }
    screen[hx][hy] = 'S';
}

int main() {
    initframe();

    loop_async(printscreen, 10);

    while(true) {
        KEY key = getkey();
        if (key == KEY_ESC) return 0;
        else hero_move(key);
    }

    return 0;
}