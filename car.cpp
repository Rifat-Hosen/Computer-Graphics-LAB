#include<iostream>
#include<graphics.h>
#include<math.h>
using namespace std;

int main(){
    int gd=DETECT,gm;
    initgraph(&gd,&gm,"");

    int x1=100,y1=400,x2=400,y2=400;
    int x3=250,y3=200;
    for(int i=1;i<1000;i++){
        cleardevice();
        setcolor(3);
        circle(x1+i,y1,50);
        line(x1+i,y1,x2+i,y2);
        line(x1+i,y1,x3+i,y3);
        line(x3+i,y3,x2+i,y2);
        circle(x2+i,y2,50);
        delay(5);
    }

    getch();

    return 0;
}
