#include<stdio.h>
#include<conio.h>
#include<graphics.h>
void put(int x, int y){
    int xx = x;
    int yy = y;
    for(;xx<x+10;xx++){
        for(yy=y;yy<y+10;yy++){
            putpixel(xx, yy, RED);
            //printf("%d %d\n",xx,yy);
        }
    }

}

int main(){
      int gd = DETECT, gm;
      int dx, dy, p, end;
      int x1, x2, y1, y2, x, y,k = 1,pp,ck=0;
      initgraph(&gd, &gm, "c:\tc\bgi");
      printf("Enter Value of X1  Y1 : ");
      scanf("%d %d", &x1,&y1);
      printf("Enter Value of X2  Y2 : ");
      scanf("%d  %d", &x2, &y2);
      dx = abs(x1 - x2);
      dy = abs(y1 - y2);
      p = 2 * dy - dx;
      pp=p;
      if(x1 > x2){
        x = x2;
        y = y2;
        end = x1;
      }
      else{
        x = x1;
        y = y1;
        end = x2;
      }
      put(x,y);

      printf("\nk   P(k)  (X(k+1),Y(k+1))\n");
      //printf("%d  %3d      (%d,%d)\n",k++,pp,x-(k*10),y-(k*10));
      while(x < end){
            x = x + 1;
            pp=p;
            if(p < 0){
                p = p + 2 * dy;
                x = x+10;

                //y = y+10;
            }
            else{
                y = y + 1;
                p = p + 2 * (dy - dx);
                x = x+10;
                y = y+10;
                ck++;
            }
            put(x,y);

            end = end+10;
            //putpixel(x, y, RED);
            printf("%d  %3d      (%d,%d)\n",k-1,pp,x-(k*10),y-(10*ck));
            k++;
      }
      getch();
      closegraph();
}
