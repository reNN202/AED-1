#include <stdio.h>
int main(){

    int x=1,y=3 ;
    int *px=&y, *py=&x;
    *px=*px+*py;

    printf("x=%d, y=%d\n", x, y);
    printf("*px=%d, *py=%d\n", *px, *py);
    printf("px=%p, py=%p\n", px, py);
    printf("&x=%p, &y=%p\n", &x, &y);
    
    return 0;   
}//main