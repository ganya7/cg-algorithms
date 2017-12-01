#include<conio.h>
#include<iostream.h>
#include<graphics.h>
int LEFT=1,RIGHT=2,BOTTOM=4,TOP=8;
int xmin,ymin,xmax,ymax;
int getcode(int x,int y){
	int code = 0;
	if(y > ymax)
		code = code | TOP;
	if(y < ymin)
		code = code | BOTTOM;
	if(x < xmin)
		code = code | LEFT;
	if(x > xmax)
		code = code | RIGHT;
	return code;
}
void main()
{
	int gdriver = DETECT,gmode;
	initgraph(&gdriver,&gmode,"C:\\TC\\BGI");
	setcolor(YELLOW);
	cout<<"Enter co-ordinates of clipping window: ";
	cout<<"\nBottom: ";
	cin>>xmin;
	cout<<"\nLeft: ";
	cin>>ymin;
	cout<<"\nTop: ";
	cin>>xmax;
	cout<<"\nRight: ";
	cin>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	int x1,y1,x2,y2;
	cout<<"Enter the start point of the line: ";
	cin>>x1>>y1;
	cout<<"Enter the end point of the line: ";
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	getch();
	
	int outcode1=getcode(x1,y1);
	int outcode2=getcode(x2,y2);
	int accept = 0;
	while(1){
		float m =(float)(y2-y1)/(x2-x1);
		if(outcode1==0 && outcode2==0){
			accept = 1;
			break;
		}
		else if((outcode1 & outcode2)!=0){
			setcolor(BLACK);
			line(x1,y1,x2,y2);
			break;
		}else{
			int x,y;
			int temp;
			if(outcode1==0)
				temp = outcode2;
			else
				temp = outcode1;
			if(temp & TOP){
				x = x1+ (ymax-y1)/m;
				y = ymax;
			}
			else if(temp & BOTTOM){
				x = x1+ (ymin-y1)/m;
				y = ymin;
			}else if(temp & LEFT){
				x = xmin;
				y = y1+ m*(xmin-x1);
			}else if(temp & RIGHT){
				x = xmax;
				y = y1+ m*(xmax-x1);
			}
			if(temp == outcode1){
				x1 = x;
				y1 = y;
				outcode1 = getcode(x1,y1);
			}else{
				x2 = x;
				y2 = y;
				outcode2 = getcode(x2,y2);
			}
		}
	}
	setcolor(RED);
	cout<<"After clipping:";
	if(accept)
		line(x1,y1,x2,y2);
	getch();
	closegraph();
}