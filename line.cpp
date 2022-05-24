#include<stdio.h>
#include<conio.h>
#include<graphics.h>


int main(){
      int gd = DETECT, gm;
      int dx, dy, p, end;
      int x1, x2, y1, y2, x, y,k = 0,pp,ck=0;
      initgraph(&gd, &gm, "c:\tc\bgi");


      printf("Enter X1  Y1 : ");
      scanf("%d %d", &x1,&y1);
      printf("Enter X2  Y2 : ");
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


      printf("\nk   P(k)  (X(k+1),Y(k+1))\n");
      //printf("%d  %3d      (%d,%d)\n",k++,pp,x-(k*10),y-(k*10));
      while(x < end){
            x = x + 1;
            pp=p;
            if(p < 0){
                p = p + 2 * dy;

            }
            else{
                y = y + 1;
                p = p + 2 * (dy - dx);

            }

            putpixel(x, y, RED);
            printf("%d  %3d      (%d,%d)\n",k++,pp,x,y);
      }
      getch();
      closegraph();
}

