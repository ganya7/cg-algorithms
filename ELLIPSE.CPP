#include<stdio.h>
#include<graphics.h>
#include<conio.h>
#include<math.h>
#include<iostream.h>
#include<dos.h>

float xc,yc,x,y;
void drawellipse()
{
	putpixel(xc+x,yc+y,RED);
	putpixel(xc-x,yc+y,RED);
	putpixel(xc-x,yc-y,RED);
	putpixel(xc+x,yc-y,RED);
	delay(100);
}



void main()
{
	int gd=DETECT,gm;

	float rx,ry,p1,p2;
	initgraph(&gd,&gm,"c:\\TC\\BGI");
 //region 1
	cout<<"\nEnter center x coordinate: ";
	cin>>xc;
	cout<<"\nEnter center y coordinate: ";
	cin>>yc;
	cout<<"\nEnter x-axis radius: ";
	cin>>rx;
	cout<<"\nEnter y-axis radius: ";
	cin>>ry;
	x=0;
	y=ry;
	putpixel(xc+x,yc-y,RED);

	p1=ry*ry-rx*rx*ry+rx*rx*0.25;
	while(pow(ry,2)*x<=pow(rx,2)*y)
	{
		x++;
		if(p1<0)
		{
			drawellipse();
			p1=p1+2*ry*ry*x+ry*ry;
		}
		else
		{
			y--;
			drawellipse();
			p1=p1+2*ry*ry*x-2*rx*rx*y+ry*ry;
		}
	}

//region 2
	p2=ry*ry*pow((x+0.5),2)+rx*rx*pow((y-1),2)-rx*rx*ry*ry;

	while(y>0)
	{
		y--;
		if(p2>0)
		{
			drawellipse();
			p2=p2-2*rx*rx*y+rx*rx;
		}
		else
		{
			x++;
			drawellipse();
			p2=p2+2*ry*ry*x-2*rx*rx*y+rx*rx;
		}
	}
	getch();
	closegraph();
}