#include <graphics.h>

double xmin, xmax, ymin, ymax;
const int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
double x0, y0, x1, y1;

int codeGen(double x, double y){
    int code = 0;
    if(x<xmin) code |= LEFT;
    else if(x>xmax) code |= RIGHT;
    if(y<ymin) code |= BOTTOM;
    else if(y>ymax) code |= TOP;
    return code;
}

void cohenSutherland(double x0, double y0, double x1, double y1){
    double p0=x0,q0=y0,p1=x1,q1=y1;
    int point1 = codeGen(x0,y0);
    int point2 = codeGen(x1,y1);
    int accept = 0;
    double x,y;
    while(1){
        if(!(point1|point2)){
            accept = 1;
            break;
        } else if(point1&point2){
            break;
        } else{
            int code = point1 ? point1 : point2;
            if(code & TOP){
                x = x0 + (x1-x0)/(y1-y0)*(ymax-y0);
                y = ymax;
            }else if(code & BOTTOM){
                x = x0 + (x1-x0)/(y1-y0)*(ymin-y0);
                y = ymin;
            }else if(code & RIGHT){
                y = y0 + (y1-y0)/(x1-x0)*(xmax-x0);
                x = xmax;
            }else if(code & LEFT){
                y = y0 + (y1-y0)/(x1-x0)*(xmin-x0);
                x = xmin;
            }
            if(code==point1){
                x0 = x;
                y0 = y;
                point1 = codeGen(x0,y0);
            }
            else{
                x1 = x;
                y1 = y;
                point2 = codeGen(x1,y1);
            }
        }
    }

    if(accept){

        //printf("x0,y0 = %.1f,%.1f   x1,y1 = %.1f,%.1f\n",x0,y0,x1,y1);
        printf("(%.1f,%.1f) (%.1f,%.1f) Accept new point = ",p0,q0,p1,q1);
        printf("(%.1f,%.1f) (%.1f,%.1f)\n",x0,y0,x1,y1);
        setcolor(RED);
		rectangle(xmin, ymin, xmax, ymax);
		setcolor(GREEN);
		line(x0, y0, x1, y1);
    }
    else{
        printf("(%.1f,%.1f) (%.1f,%.1f) Not in Window\n",p0,q0,p1,q1);
    }
}

int main() {
    int gd = DETECT, gm = DETECT;
    int test = 20;
    initgraph(&gd, &gm, "");
	setbkcolor(WHITE);


    xmin = 100;
    xmax = 500;
    ymin = 10;
    ymax = 300;


    while(test--){
        x0 = 50, y0 = rand(), x1 = 600, y1 = 90;
        cohenSutherland(x0,y0,x1,y1);
        delay(10);
    }
    getch();
    closegraph();
    return 0;
}
