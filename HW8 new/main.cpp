#include <GL/glut.h>
#include <math.h>

void garis();
int main(int argc,char **argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(600,800);;
	glutInitWindowPosition(100,100);
	glutCreateWindow("Clipping");
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-300.0, 300.0, -400.0, 400.0);
	glutIdleFunc(garis);
	glutDisplayFunc(garis);
	glutMainLoop();
	return 0;
}

void garis(){
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_LINES);
	glColor3f(0.0,0.0,1.0);
	glVertex2f(-100,-200);
	glColor3f(0.0,0.0,0.1);
	glVertex2f(700,800);
	
	glColor3f(1.0,0.0,0.0);
	glVertex2f(-200,-300);
	glColor3f(1.0,0.0,0.0);
	glVertex2f(400,500);
	
	glColor3f(0.0,1.0,0.0);
	glVertex2f(-100,-800);
	glColor3f(0.0,1.0,0.0);
	glVertex2f(200,400);
	
	glColor3f(1.0,0.0,1.0);
	glVertex2f(-100,-300);
	glColor3f(1.0,0.0,1.0);
	glVertex2f(600,700);
	glEnd();
	
	glBegin(GL_LINE_LOOP);
	glColor4f(0.0,0.0,0.0,0.0);
	glVertex2f(100,100);
	glVertex2f(100,600);
	glVertex2f(100,700);
	glVertex2f(100,100);
	
	glEnd();
	glFinish();
	
	
	
}
