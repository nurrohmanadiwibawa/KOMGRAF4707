#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include <cmath>

void tampilan(void){
	glClearColor(1.0,1.0,1.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0.0, 160.0, 0.0, 120.0);
	
}

void aturPixel(GLint xCoordinate, GLint yCoordinate){
	glBegin(GL_POINTS);
	glVertex2i(xCoordinate, yCoordinate);
	glEnd();
	glFlush();
}

void garisDDA(GLint x0, GLint y0, GLint xEnd, GLint yEnd){
	GLint dx = (float) fabs((float) xEnd - x0);
	GLint dy = (float) fabs((float) yEnd - y0);
	GLint p=2 *dy - dx;
	GLint twoDy = 2 * dy;
	GLint twoDyMinusDx = 2 * (dy-dx);
	GLint x, y;
	if(x0 > xEnd){
		x= xEnd;
		y= yEnd;
	}else{
		x=x0;
		y=y0;
	}
	aturPixel(x,y);
	while(x < xEnd){
			x++;
		if (p<0)
			p+= twoDy;
		else {
			y++;
			p+= twoDyMinusDx;
		}
		aturPixel(x,y);
		
	}
	
}

void gambarGaris(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.5, 0.0);
	glPointSize(4.0);
	GLint x0 = 1; //10
	GLint y0 = 2; //5
	GLint xEnd = 7; //80
	GLint yEnd = 7; //75
	
	garisDDA(x0,y0,xEnd,yEnd);
}

int main (int argc, char** argv){
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(400,400);
	glutInitWindowPosition(0,0);
	glutCreateWindow("Garis DDA");
	tampilan();
	glutDisplayFunc(gambarGaris);
	glutMainLoop();
	return 0;
}
 

