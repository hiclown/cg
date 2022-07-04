#include<GL/glut.h>
#include<stdio.h>
int x,y;
int where_to_rotate=0;      // don't rotate initially
float rotate_angle=0;          // initial angle
float translate_x=0,translate_y=0;  // initial translation

void draw_pixel(float x1, float y1)
{
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2f(x1,y1);      // plot a single point
    glEnd();
}

void triangle(int x, int y)
{
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);    // drawing a Triangle
        glVertex2f(x,y);
        glVertex2f(x+400,y+300);
        glVertex2f(x+300,y+0);
    glEnd();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1,1,1);               // mark origin point as white dot
    draw_pixel(0,0);              // plot origin - white colour

    if (where_to_rotate == 1) //Rotate Around origin
    {
        translate_x = 0;            // no translation for rotation around origin
        translate_y = 0;
        rotate_angle += 1;        // the amount of rotation angle
    }

    if (where_to_rotate == 2) //Rotate Around Fixed Point
    {
        translate_x = x;        // SET the translation to wherever the customer says
        translate_y = y;
        rotate_angle += 1;     // the amount of rotation angle
        glColor3f(0,0,1);       // mark the customer coordinate as blue dot
        draw_pixel(x,y);        // plot the customer coordinate - blue colour
    }

    glTranslatef(translate_x, translate_y, 0);    // ACTUAL translation +ve
    glRotatef(rotate_angle, 0, 0, 1);                      // rotate
    glTranslatef(-translate_x, -translate_y, 0);  // ACTUAL translation -ve

    triangle(translate_x,translate_y);                  // what to rotate? - TRIANGLE

    glutPostRedisplay();                 // call display function again and again
    glutSwapBuffers();                  
}

void init()
{
    glClearColor(0,0,0,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800, 800, -800, 800);
    glMatrixMode(GL_MODELVIEW);
}

void rotateMenu (int option)
{
    if(option==1)
        where_to_rotate=1;     

    if(option==2)
        where_to_rotate=2;      

    if(option==3)
        where_to_rotate=3;      
}

int main(int argc, char **argv)
{
    printf( "Enter Fixed Points (x,y) for Rotation: \n");
    scanf("%d %d", &x, &y);                 

    glutInit(&argc, argv);                      
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB);  
    glutInitWindowSize(800, 800);    
    glutInitWindowPosition(0, 0);       
    glutCreateWindow("Create and Rotate Triangle");     
    init();                                               

    glutDisplayFunc(display);          
    glutCreateMenu(rotateMenu);     
    glutAddMenuEntry("Rotate around ORIGIN",1);
    glutAddMenuEntry("Rotate around FIXED POINT",2);
    glutAddMenuEntry("Stop Rotation",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

    glutMainLoop();                             
}
