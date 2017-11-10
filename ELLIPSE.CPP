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
	int gd = DETECT,gm;

	float a,b,p1,p2;
	initgraph(&gd,&gm,"c:\\TC\\BGI");
 //region 1
	cout<<"\nEnter center x coordinate: ";
	cin>>xc;
	cout<<"\nEnter center y coordinate: ";
	cin>>yc;
	cout<<"\nEnter x-axis radius: ";
	cin>>a;
	cout<<"\nEnter y-axis radius: ";
	cin>>b;
	x = 0;
	y = b;
	float fx = 2 * b*b * x;
	float fy = 2 * a*a * y;
	putpixel(xc+x,yc-y,RED);//(0,b)
	putpixel(xc-x,yc+y,RED);//(0,-b)



	p1  =  b*b - a*a*b + a*a*0.25;
	// while(pow(b,2)*x <= pow(a,2)*y)
	while(fx < fy) //slope 1
	{
		x++;
		fx = fx + 2*b*b;
		if(p1<0)
		{
			drawellipse();
			// p1 = p1+2*b*b*x+b*b;
			p1 = p1 + fx + b*b;
		}
		else
		{
			y--;
			drawellipse();
			// p1 = p1+2*b*b*x-2*a*a*y+b*b;
			fy = fy - 2*a*a;
			p1 = p1 + fx + b*b - fy;
		}
	}

//region 2
	p2 = b*b*pow((x+0.5),2) + a*a*pow((y-1),2) - a*a*b*b;

	while(y > 0)
	{
		y--;
		fy = fy - 2*a*a;
		if(p2 >= 0)
		{
			drawellipse();
			// p2 = p2-2*a*a*y+a*a;
			p2 = p2 -fy + a*a;
		}
		else
		{
			x++;
			drawellipse();
			// p2 = p2+2*b*b*x-2*a*a*y+a*a;
			fx = fx + 2*b*b;
			p2 = p2 + fx - fy + a*a;
		}
	}
	getch();
	closegraph();
}