	#include <stdio.h>
	#include <GL/glut.h>
	#include <math.h>
		static GLfloat spin = 0.0;
		static GLfloat spin_speed = 1.0;
		float spin_x = 0;
		float spin_y = 1;
		float spin_z = 0;
		float translate_x = 0.0;
		float translate_y = 0.0;
		float translate_z = -30.0;
	// assuming work-window width=50unit, height=25unit;
		void init(){
			glClearColor(1.0, 1.0, 1.0, 0.0);
			glColor3f(0.0f, 0.0f, 0.0f);
			glPointSize(8.0);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D(00, 1000.0, 00, 1000);// Enables Depth Testing
		}
	//------- custom functions starts -------
	
		void setSpin(float x, float y, float z){
			spin_x = x;
			spin_y = y;
			spin_z = z;
			}
		void reset(){
			spin_x = 0;
			spin_y = 1;
			spin_z = 0;
			translate_x = 0.0;
			translate_y = 0.0;
			translate_z = -30.0;
			}
	//------- custom functions ends -------

	
		void reshape(int w,int h){
			glViewport(0,0, (GLsizei)w,(GLsizei)h);
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluPerspective(100.0f, (GLfloat)w/(GLfloat)h, 1.0f, 100.0f);
			glMatrixMode(GL_MODELVIEW);
			glLoadIdentity();
			}
		void Display(void)
		{
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.0, 0.0, 0.0);
			glPointSize(8.0);

			glColor3f(1, 0, 0.29);
			glBegin(GL_LINE_STRIP);
			glVertex2f(10, 20);
			glVertex2f(40, 50);
	
			glEnd();
			glFlush();
		}
		void myDisplay()
		{

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			/*glLoadIdentity();
			glTranslatef(translate_x, translate_y, translate_z);
			glRotatef(spin,spin_x,spin_y,spin_z);
	 //******************************************
	//------- custom code starts -------

	//------- custom code ends -------
	 //******************************************
			glutSwapBuffers();*/
			
			glLoadIdentity();
			glTranslatef(translate_x, translate_y, translate_z);
			glRotatef(spin,spin_x,spin_y,spin_z);
	

		
			glClear(GL_COLOR_BUFFER_BIT);
			glColor3f(0.0, 0.0, 0.0);
			glPointSize(8.0);
			glColor3f(1, 0, 0.29);

			glBegin(GL_POLYGON);
			glVertex2f(0, 0);
			glVertex2f(10, 10);
			glVertex2f(10, 20);
			//glVertex2f(34, 200);
	
			glEnd();
			//glFlush();

			glColor3f(1, 0.34, 0.29);

			glBegin(GL_POLYGON);
			glVertex2f(0, 0);
			glVertex2f(-10,-10);
			glVertex2f(-10, -20);
			//glVertex2f(34, 200);
	
			glEnd();
			//glFlush();



			
			glColor3f(0, 1, 0.29);
			glBegin(GL_POLYGON);
			double a= cos((90*3.1428)/180);
			double b=sin((90*3.1428)/180);
			glVertex2f(0, 0);
			glVertex2f((-10 *a) - ((-10)* b), (-10 * b) + (-10 * a));
			glVertex2f((-10 *a) - ((-20)* b), (-10 * b) + (-20 * a));
			
			glEnd();
//			glFlush();

			glColor3f(0, 1, 0.29);
			glBegin(GL_POLYGON);
			glVertex2f(0, 0);
			glVertex2f((10 *a) - ((10)* b), (10 * b) + (10 * a));
			glVertex2f((10 *a) - ((20)* b), (10 * b) + (20 * a));
			
			glEnd();
			glFlush();



	


		}
		void spinDisplay(void){
		spin=spin+spin_speed;
		if(spin>360.0)
			{
				spin=spin-360.0;
			}
		glutPostRedisplay();
		}
		void spinDisplayReverse(void)
		{
			spin=spin-spin_speed;
			if(spin<360.0)
			{
				spin=spin+360.0;
			}
			glutPostRedisplay();
		}
		void mouse(int button,int state,int x,int y){
			switch(button)
		{
		case GLUT_LEFT_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(spinDisplay);
				break;
		case GLUT_MIDDLE_BUTTON:
			if(state==GLUT_DOWN)
				{
				glutIdleFunc(NULL);
				}
		break;
		case GLUT_RIGHT_BUTTON:
			if(state==GLUT_DOWN)
				glutIdleFunc(spinDisplayReverse);
		break;
		default:
			break;
		}
	}
	void keyboard(unsigned char key, int x, int y)
	{
	//-------- spin --------
	if(key=='x')
	{
	setSpin(1.0,0.0,0.0);
	glutPostRedisplay();
	}
	else if(key=='y')
	{
	setSpin(0.0,1.0,0.0);
	glutPostRedisplay();
	}
	else if(key=='z')
	{
	setSpin(0.0,0.0,1.0);
	glutPostRedisplay();
	}
	else if(key=='a')
	{
	setSpin(1.0,1.0,1.0);
	glutPostRedisplay();
	}
	//-------- spin --------
	//-------- zoom --------
	else if(key=='i')
	{
	translate_z++;
	glutPostRedisplay();
	}
	else if(key=='o')
	{
	translate_z--;
	glutPostRedisplay();
	}
	//-------- zoom --------
	//-------- reset -------
	else if(key=='r')
	{
	reset();
	glutPostRedisplay();
	}
	//-------- reset -------
	}	void main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(1024, 768); 
	glutInitWindowPosition(100, 100);





	glutCreateWindow("my first attempt");
	glutDisplayFunc(myDisplay);
	glutMouseFunc(mouse);
	glutKeyboardFunc(keyboard);
	//spinDisplay();
	init();
	setSpin(1,1,1);
	reshape(1,1);
	//spinDisplay();
	//spinDisplayReverse();
	//glutDisplayFunc(Display);
	//init();
	glutMainLoop();
	
}	 	
