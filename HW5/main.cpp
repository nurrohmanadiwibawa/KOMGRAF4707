#include <gl/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <stdarg.h>
#include <GL/glut.h>

void translasi(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glTranslatef(-0.50, 0.50, 0); //Translasi
	glColor3f(1.0,0.0,0.0);
	glRectf(-0.25, 0.25, 0.25, -0.25);
	glFlush();
}

void skala(){
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glClear(GL_COLOR_BUFFER_BIT);
	glScalef(2.0f, 2.0f, 2.0f); //Skala
	glColor3f(1.0,0.0,0.0);
	glRectf(-0.18, 0.18, 0.18, -0.18);
	glFlush();
}

void rotasi(){
	glBegin(GL_POLYGON); // membuat Persegi
	glVertex2f(0.0, 0.0);
	glVertex2f(0.0, 50.0);
	glVertex2f(200.0, 50.0);
	glVertex2f(200.0, 0.0);
	glEnd();
}

void baling(){
	glColor3f(0., 1., 0.);
	rotasi();
	glRotatef(-90,0,0,1); //Rotasi Objek Berdasarkan Sudut xyz
	glColor3f(1., 0., 0.);
	glFlush();
}

int main (int argc, char**argv){
	glutInit(&argc,argv);
	glutInitWindowSize(640,480);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutCreateWindow("Transformasi 2D");
//	gluOrtho2D(-320.0, 320.0, -320.0, 320.0); //untuk Rotasi Saja
	glutDisplayFunc(skala);
	glutMainLoop();
	return 0;
}
