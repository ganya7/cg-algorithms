#include<iostream.h>
#include<graphics.h>
#include<math.h>
#include<conio.h>
#include<dos.h>

void main()
{
	int gd=DETECT,gm;
	int xmin,ymin,xmax,ymax;
	initgraph(&gd,&gm,"c:\\tc\\bgi");
	cout<<"\nEnter window xmin ymin: ";
	cin>>xmin>>ymin;
	cout<<"\nEnter window xmax ymax: ";
	cin>>xmax>>ymax;
	rectangle(xmin,ymin,xmax,ymax);
	int x1,y1,x2,y2;
	cout<<"\nEnter start point: ";
	cin>>x1>>y1;
	cout<<"\nEnter end point: ";
	cin>>x2>>y2;
	line(x1,y1,x2,y2);
	int dx = x2 - x1;
	int dy = y2 - y1;
	float p[4],q[4];
	p[0] = -dx;
	p[1] = dx;
	p[2] = -dy;
	p[3] = dy;
	q[0] = x1 - xmin;
	q[1] = xmax - x1;
	q[2] = y1 - ymin;
	q[3] = ymax - y1;
	int i;
	int flag = 0;
	for(i = 0; i < 4; i++){
		if(p[i] == 0){
			cout<<"\nLine is parallel to one of the side of clipping window";
			if(q[i] >= 0){
				if(i < 2){	//parallel to left:p0 and right:p1
					if(y1 < ymin)
						y1 = ymin;
					if(y2 > ymax)
						y2 = ymax;
					setcolor(RED);
					getch();
					cout<<"\nAfter clipping: ";
					line(x1,y1,x2,y2);
				}
				if(i > 1){	//parallel bottom:p2 and top:p3
					if(x1 < xmin)
						x1 = xmin;
					if(x2 > xmax)
						x2 = xmax;
					setcolor(RED);
					getch();
					cout<<"\nAfter clipping: ";
					line(x1,y1,x2,y2);
				}
			}	//q[i] >= 0
		flag = 1;
		}	// p[i] == 0
	}	//for
	int xx1,xx2,yy1,yy2;
	float temp;
	float t1=0,t2=1;		
	if(!flag){
		for(i = 0; i < 4; i++){
			temp = q[i] / p[i];
			if(p[i] < 0){
				if(t1 < temp)
					t1 = temp;
			}
			else{
				if(t2 > temp)
					t2 = temp;
			}
		}	//for
		if(t1 < t2){
			xx1 = x1 + t1 * p[1];
			xx2 = x1 + t2 * p[1];
			yy1 = y1 + t1 * p[3];
			yy2 = y1 + t2 * p[3];
			getch();
			cout<<"\nAfter clipping: ";
			setcolor(RED);
			line(xx1,yy1,xx2,yy2);
			getch();
		}	/// t1 < t2
	}	//flag if
	closegraph();
}