#include <graphics.h>

void plotpixel(int xcenter,int ycenter,int x,int y){
    putpixel(xcenter+x,ycenter+y,RED);
    putpixel(xcenter-x,ycenter+y,RED);
    putpixel(xcenter+x,ycenter-y,RED);
    putpixel(xcenter-x,ycenter-y,RED);
    putpixel(xcenter+y,ycenter+x,RED);
    putpixel(xcenter-y,ycenter+x,RED);
    putpixel(xcenter+y,ycenter-x,RED);
    putpixel(xcenter-y,ycenter-x,RED);
}

void midpointCircle(int xcenter,int ycenter,int r){
    int p,x,y;
    p = 1-r;
    x = 0;
    y = r;
    while(x<y){
        x++;
        plotpixel(xcenter,xcenter,x,y);
        if(p<0){
            p += 2*x + 1;
        }
        else{
            y--;
            p += 2*x + 1 - 2*y;
        }
    }
}



int main() {
    int gd=DETECT, gm=DETECT;
    initgraph(&gd,&gm,"");

    int x,y,r;
    printf("Enter center x & y : ");
    scanf("%d %d", &x, &y);
    printf("Enter radius r : ");
    scanf("%d",&r);
    midpointCircle(x,y,r);

    getch();
    closegraph();
    return 0;
}
