#include <stdio.h>
#include<stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include<conio.h>
#include<time.h>

int r;
int x[] = { 0,15,15,40 };
int y[] = { 0,5,15,40 };
int z[] = { 0,0,0,0 };

static GLfloat spin = 1.0;
static GLfloat spin_speed = 2;
float spin_x = 0;
float spin_y = 1;
float spin_z = 0;
float translate_x = 0.0;
float translate_y = -4.0;
float translate_z = -30.0;

void makeStand();
//------- custom functions starts -------

void setSpin(float x, float y, float z)
{
	spin_x = x;
	spin_y = y;
	spin_z = z;
}

void reset()
{
	spin_x = 0;
	spin_y = 1;
	spin_z = 0;
	translate_x = 0.0;
	translate_y = -10.0;
	translate_z = 0.0;
}

//------- custom functions ends -------
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(1000.0f, (GLfloat)w / (GLfloat)h, 10.0f, 1000.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void spinDisplay(void)
{
	spin = spin + spin_speed;
	if (spin>360.0)
	{
		spin = spin - 360.0;
	}
	glutPostRedisplay();
}

void spinDisplayReverse(void)
{
	spin = spin - spin_speed;
	if (spin<360.0)
	{
		spin = spin + 360.0;
	}
	glutPostRedisplay();
}


void mouse(int button, int state, int x, int y)
{
	switch (button)
	{
	case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplay);
		break;
	case GLUT_MIDDLE_BUTTON:
		if (state == GLUT_DOWN)
		{
			glutIdleFunc(makeStand);
		}
		break;
	case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
			glutIdleFunc(spinDisplayReverse);
		break;
	default:
		break;
	}
}


void keyboard(unsigned char key, int x, int y)
{
	//-------- spin --------
	if (key == 'x')
	{
		setSpin(1.0, 0.0, 0.0);
		glutPostRedisplay();
	}
	else if (key == 'y')
	{
		setSpin(0.0, 1.0, 0.0);
		glutPostRedisplay();
	}
	else if (key == 'z')
	{
		setSpin(0.0, 0.0, 1.0);
		glutPostRedisplay();
	}
	else if (key == 'a')
	{
		setSpin(1.0, 1.0, 1.0);
		glutPostRedisplay();
	}

	//-------- spin --------

	//-------- zoom --------

	else if (key == 'i')
	{
		translate_z++;
		glutPostRedisplay();
	}
	else if (key == 'o')
	{
		translate_z--;
		glutPostRedisplay();
	}
	//-------- zoom --------
	//-------- reset -------
	else if (key == 'r')
	{
		reset();
		glutPostRedisplay();
	}
	//-------- reset -------
}

void makeFan() 
{
	glColor3f(.1, 1, 0.29);
	glBegin(GL_TRIANGLE_FAN);//001003
	for (int i = 0; i < 3; i++)
	{
		glVertex3f(-x[i], -y[i], z[i]);
	}
	glEnd();

	glColor3f(1, 1, 0.29);
	glBegin(GL_TRIANGLE_FAN);//002004
	for (int i = 0; i < 3; i++)
	{
		int angle = 90;
		double a = cos((angle*3.1428) / 180);
		double b = sin((angle*3.1428) / 180);
		glVertex3f((x[i] * a) - (y[i] * b), (x[i] * b) + (y[i] * a), z[i]);
	}
	glEnd();
	
	glColor3f(1, .21, 0.29);
	glBegin(GL_TRIANGLE_FAN);//003001
	for (int i = 0; i < 3; i++)
	{
		int angle = 90;
		double a = cos((angle*3.1428) / 180);
		double b = sin((angle*3.1428) / 180);
		glVertex3f((-x[i] * a) - (-y[i] * b), (-x[i] * b) + (-y[i] * a), z[i]);
	}
	glEnd();
	
	glColor3f(.31, .1, 0.9);
	glBegin(GL_TRIANGLE_FAN);//004002
	for (int i = 0; i < 3; i++)
	{
		int angle = 180;
		double a = cos((angle*3.1428) / 180);
		double b = sin((angle*3.1428) / 180);
		glVertex3f((-x[i] * a) - (-y[i] * b), (-x[i] * b) + (-y[i] * a), z[i]);
	}
	glEnd();
	
	/*
	glColor3f(.3, .9, 0.9);
	glBegin(GL_POINTS);
	for (int i = 0; i < 3; i++)
	{
		glVertex3f(0, 0, z[i]);
	}
	glEnd();*/

	glFlush(); 
}


void makeStand(void)
{
	/*glColor3f(.1, .23, 0.06);
	glBegin(GL_POLYGON);//001003

	glVertex2f(-3, 0);
	glVertex2f(3, 0);
	glVertex2f(3, 25);
	glVertex2f(-3, 25);

	glEnd();


	glColor3f(.21, .43, 0.06);
	glBegin(GL_POLYGON);//001003

	glVertex2f(-5, 25);
	glVertex2f(5, 25);
	glVertex2f(11, 30);
	glVertex2f(-11, 30);

	glEnd();*/


	int b[]={0,-4,4,-4,4,2};
	int c[]={0,4,-4,-4,4,2};

	glColor3f(.21, .43, 0.6);
	glBegin(GL_POINTS);//001003
	srand(time(NULL));
	r=rand()%6+1;

	for (int i = 0; i < r; i++)
	{
		
		glVertex2f(b[i], c[i]);
	}

	glEnd();
	glFlush();
}

void makeCoil()
{
	glColor3f(0, 1, 1);
/*	glBegin(GL_POLYGON);//001003

	glVertex2f(-5, -5);
	glVertex2f(-5, 5);
	glVertex2f(5, 5);
	glVertex2f(5, -5);

	glEnd();
	glFlush();*/

	///////////////////////
	glBegin(GL_LINE_STRIP);
	// top
	//glColor3f(1, 0, 0);
	//glNormal3f(0, 1, 0);
	glVertex3f(-5, 5, 5);
	glVertex3f(5, 5, 5);
	glVertex3f(5, 5, -5);
	glVertex3f(-5, 5, -5);
 
	glEnd();
 
	glBegin(GL_LINE_STRIP);
	// front
	//glColor3f(0.0, 1.0, 0.0);
	//glNormal3f(0.0, 0.0, 1.0);
	glVertex3f(-5, -5, 5);
	glVertex3f(5, -5, 5);
	glVertex3f(5, 5, 5);
	glVertex3f(-5, 5, 5);
 
	glEnd();
 
	glBegin(GL_LINE_STRIP);
	// right
	//glColor3f(0.0, 0.0, 1.0);
	//glNormal3f(1.0, 0.0, 0.0);
	glVertex3f(5, -5, 5);
	glVertex3f(5, -5, -5);
	glVertex3f(5, 5, -5);
	glVertex3f(5, 5, 5);
 
	glEnd();
 
	glBegin(GL_LINE_STRIP);
	// left
	//glColor3f(0.0, 0.0, 0.5);
	//glNormal3f(-1.0, 0.0, 0.0);
	glVertex3f(-5, -5, 5);
	glVertex3f(-5, 5, 5);
	glVertex3f(-5, 5, -5);
	glVertex3f(-5, -5, -5);
 
	glEnd();
 
	glBegin(GL_LINE_STRIP);
	// bottom
	//glColor3f(0.5, 0.0, 0.0);
	//glNormal3f(0.0, -1.0, 0.0);
	glVertex3f(-5, -5, 5);
	glVertex3f(5, -5, 5);
	glVertex3f(5, -5, -5);
	glVertex3f(-5, -5, -5);
 
	glEnd();
 
	glBegin(GL_LINE_STRIP);
	// back
	//glColor3f(0.0, 0.5, 0.0);
	//glNormal3f(0.0, 0.0, -1.0);
	glVertex3f(5, 5, -5);
	glVertex3f(5, -5, -5);
	glVertex3f(-5, -5, -5);
	glVertex3f(-5, 5, -5);
 
	glEnd();
	glFlush();
}


void myDisplay(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	glTranslatef(translate_x, translate_y, translate_z);

	glRotatef(spin, spin_x, spin_y, spin_z);
	
	

		
	makeCoil();
	
	
}

void myInit(void)
{
	glClearColor(0.5, 0.5, 0.5, 0.5);

	/*glShadeModel(GL_SMOOTH); // Enable Smooth Shading
	glClearDepth(1.0f); // Depth
	glEnable(GL_DEPTH_TEST);*/

	glColor3f(0.0f, 0.0f, 0.0f);
	glPointSize(8.0);
	glMatrixMode(GL_PROJECTION);

	glLoadIdentity();
	gluOrtho2D(-1840, 1840.0, -1840, 1840.0);
}


void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1420, 820);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("my first attempt");

	//glutDisplayFunc(makeStand);
	glutDisplayFunc(myDisplay);

	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);

	myInit();
	setSpin(0, 1000000, 0);
	reshape(40, 20);

	glutMainLoop();
}