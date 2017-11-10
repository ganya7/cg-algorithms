#include<windows.h>
#include<bits/stdc++.h>
#include <GL/glut.h>

using namespace std;
void init2d(void){
	//glClearColor(r,g,b,0.0);   //or
	glClearColor(1.0, 1.0, 1.0, 0.0); //sets the output window background color
	glMatrixMode (GL_PROJECTION);
	//gluOrtho2D (0.0, 200.0, 0.0, 150.0);
	gluOrtho2D(0.0, 640.0, 0.0, 480.0); //output windows size ie amount of information to be displayed
}
void mydisplay(void)
{	
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0); //sets the color of the points or the lines

	glBegin(GL_LINES);
	glVertex2i(10,10);
	glVertex2i(100,100);
	glEnd();

	glFlush(); //pushes the points/lines stored in buffer on to the output window
}

int main(int argc, char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize (640,480); //window size maximize minimize doesnt change the resoultion
	glutInitWindowPosition (200,150);
	glutCreateWindow("inital gl program");
	init2d();
	glutDisplayFunc(mydisplay);
	glutMainLoop();
	return 0;

}
