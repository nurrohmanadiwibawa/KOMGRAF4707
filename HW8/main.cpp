#include <GL/glut.h>
#include <iostream>

float xMin = 50, yMin =30, xMax = 200, yMax = 100;

void cohenSutherlandClipping(float x0, float y0, float x1, float y1) {
    // Region codes
    const int INSIDE = 0; // 0000
    const int LEFT = 1;   // 0001
    const int RIGHT = 2;  // 0010
    const int BOTTOM = 4; // 0100
    const int TOP = 8;    // 1000

    int code0 = INSIDE, code1 = INSIDE;

    // Assign region codes to endpoints
    if (x0 < xMin)
        code0 |= LEFT;
    else if (x0 > xMax)
        code0 |= RIGHT;

    if (y0 < yMin)
        code0 |= BOTTOM;
    else if (y0 > yMax)
        code0 |= TOP;

    if (x1 < xMin)
        code1 |= LEFT;
    else if (x1 > xMax)
        code1 |= RIGHT;

    if (y1 < yMin)
        code1 |= BOTTOM;
    else if (y1 > yMax)
        code1 |= TOP;

    // If both endpoints are inside, draw the line
    if (code0 == INSIDE && code1 == INSIDE) {
        glBegin(GL_LINES);
        glVertex2f(x0, y0);
        glVertex2f(x1, y1);
        glEnd();
    } else {
        // Perform Cohen-Sutherland clipping
        // ...

        // The code above only handles the case where both endpoints are inside,
        // additional code is needed to handle cases where the line partially intersects
        // the clipping window. You may need to implement the clipping algorithm.

    }
}

void display() {
    

    // Draw the clipping window
    glBegin(GL_LINE_LOOP);
    glVertex2f(xMin, yMin);
    glVertex2f(xMax, yMin);
    glVertex2f(xMax, yMax);
    glVertex2f(xMin, yMax);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1., 1., 0.);
    glEnd();
    
    

    // Draw a line and apply clipping
    glColor3f(1.0, 0.0, 0.0); // Red color
    cohenSutherlandClipping(30, 30, 150, 250);
    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 300, 0, 300);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Cohen-Sutherland Clipping in OpenGL");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

