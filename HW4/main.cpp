#include <GL/glut.h>
#include <iostream>

int x1, y1, x2, y2;

void drawLineBresenham(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y2 - y1;

    int x = x1;
    int y = y1;

    int twoDy = 2 * dy;
    int twoDyMinusDx = 2 * (dy - dx);
    int p = 2 * dy - dx;

    glBegin(GL_POINTS);
    glVertex2i(x, y);

    while (x < x2) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y++;
            p += twoDyMinusDx;
        }
        glVertex2i(x, y);
    }

    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0, 0.0, 0.0);

    drawLineBresenham(x1, y1, x2, y2);

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
    std::cout << "Masukkan Koordinat Titik Pertama (x1 y1): ";
    std::cin >> x1 >> y1;

    std::cout << "Masukkan Koordinat Titik Kedua (x2 y2): ";
    std::cin >> x2 >> y2;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}

