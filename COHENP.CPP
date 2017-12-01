#include <iostream.h>
#include <conio.h>
#include <graphics.h>
#include <dos.h>


int LEFT = 1, RIGHT = 2, BOTTOM = 4, TOP = 8;
int xmin,ymin,xmax,ymax;

int getcode(int x, int y){
	int code = 0;
	if(x < xmin)
		code = code | LEFT;
	else if(x > xmax)
		code = code | RIGHT;
	else if(y < ymin)
		code = code | BOTTOM;
	else if(y > ymax)
		code = code | TOP;
	return code;
}

void main(){
	int gd=DETECT,gm;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cout<<"\nLeft: ";
	cin>>xmin;
	cout<<"\nRight: ";
	cin>>xmax;
	cout<<"\nBottom: ";
	cin>>ymin;
	cout<<"\nTop: ";
	cin>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	int x1,y1,x2,y2;
	cout<<"\nEnter start point: ";
	cin>>x1>>y1;
	cout<<"\nEnter end point: ";
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	int outcode1 = getcode(x1,y1);
	int outcode2 = getcode(x2,y2);
	int accept = 0;
	while(1){
		float m = (float)(y2 - y1) / (x2 - x1);
		if(outcode1 == 0 && outcode2 == 0){
			accept = 1;
			break;
		}
		else if((outcode1 & outcode2) != 0){
			cout<<"\nLine outside clipping window";
			break;
		}
		else{
			int x,y;
			int temp;
			if(outcode1 == 0)
				temp = outcode2;
			else
				temp = outcode1;
			if(temp & TOP){
				y = ymax;
				x = x1 + ((ymax - y1) / m);
			}
			else if(temp & BOTTOM){
				y = ymin;
				x = x1 + (ymin - y1) / m;
			}
			else if(temp & LEFT){
				x = xmin;
				y = y1 + m * (xmin - x1);
			}
			else if(temp & RIGHT){
				x = xmax;
				y = y1 + m * (xmax - x1);
			}
			if(temp == outcode1){
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1,y1);
			}
			else{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2,y2);
			}
		}
		
	}
	setcolor(RED);
	delay(3000);
	cout<<"\nAfter clipping: ";
	if(accept)
		line(x1,y1,x2,y2);
	getch();
	closegraph();
}
// 100 100 300 300 
// 120 80 320 350