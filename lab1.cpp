#include<GL/glut.h>
#include<stdio.h>
int x1,x2,y1,y2;
void init()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(2.0,2.0,2.0,4.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0,1000.0,0.0,1000.0);
}
void draw_pixel(int x,int y)
{
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();
}

void draw_line(int x1,int x2,int y1,int y2)
{
	int dx, dy, i, e;
	int incx,  incy ,incl, inc2;
	int x,y;
	
	dx=x2-x1;
	dy=y2-y1;
	
	if(dx<0)
		dx=-dx;
	if(dy<0)
		dy=-dy;
		
	incx=1;
	
	if(x2<x1)
		incx=-1;
		incy=1;
		
	if(y2<y1)
		incy=-1;
	
	x=x1;
	y=y1;
	
	if(dx>dy)
	{
		draw_pixel(x,y);
		e=2*dy-dx;
		incl=2*(dy-dx);
		inc2=2*dy;
		
		for(i=0;i<dx;i++)
		{
			if(e>=0)
			{
				y+=incy;
				e+=incl;
			}
			else
			{
				e+=inc2;
			}
			x+=incx;
			draw_pixel(x,y);
		}
	}
	else
	{
		draw_pixel(x,y);
		e=2*dx-dy;
		incl=2*(dx-dy);
		inc2=2*dx;
		
		for(i=0;i<dy;i++)
		{
			if(e>=0)
			{
				x+=incx;
				e+=incl;
			}
			else
			{
				e+=inc2;
			}
			y+=incy;
			draw_pixel(x,y);
		}
	}
}
void display()
{
	draw_line(x1,x2,y1,y2);
	glFlush();
}

int main(int argc, char **argv)
{
	printf(" Enter (x1,y1,x2,y2)\n");
	scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Breshanams Line Drawing Algorithm");
	glutDisplayFunc(display);
	init();
	glutMainLoop();
	return 0;
}
	
	
		


