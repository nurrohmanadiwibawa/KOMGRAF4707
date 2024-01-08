
#include <math.h> 
#include <GL/glut.h> 
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

float angle=0.0, deltaAngle = 0.0, ratio; 
float x=0.0f,y=1.75f,z=15.0f; // posisi awal kamera 
float lx=0.0f,ly=0.0f,lz=-1.0f; 
int deltaMove = 0,h,w; 
int bitmapHeight=12; 

void Reshape(int w1, int h1) 
{ 
 // Fungsi reshape 
 if(h1 == 0) h1 = 1; 
 w = w1; 
 h = h1; 
 ratio = 1.0f * w / h; 
 glMatrixMode(GL_PROJECTION); 
 glLoadIdentity(); 
 glViewport(0, 0, w, h); 
 gluPerspective(45,ratio,0.1,1000); 
 glMatrixMode(GL_MODELVIEW); 
 glLoadIdentity(); 
 gluLookAt(
 x, y, z, 
 x + lx,y + ly,z + lz, 
 0.0f,1.0f,0.0f); 
} 
void orientMe(float ang) 
{ 
 // Fungsi ini untuk memutar arah kamera (tengok kiri/kanan) 
 lx = sin(ang); 
 lz = -cos(ang); 
 glLoadIdentity(); 
 gluLookAt(x, y, z, 
 x + lx,y + ly,z + lz, 
 0.0f,1.0f,0.0f); 
} 
void moveMeFlat(int i) 
{ 
 // Fungsi ini untuk maju mundur kamera 
 x = x + i*(lx)*0.1; 
 z = z + i*(lz)*0.1; 
 glLoadIdentity();
 gluLookAt(x, y, z, 
 x + lx,y + ly,z + lz, 
 0.0f,1.0f,0.0f); 
} 
void Grid() { 
	 // Fungsi untuk membuat grid di "lantai" 
	 double i; 
	 const float Z_MIN = -50, Z_MAX = 50; 
	 const float X_MIN = -50, X_MAX = 50; 
	 const float gap = 1.5; 
	 glColor3f(0.5, 0.5, 0.5); // set warna ke abu-abu
	 glBegin(GL_LINES); 
	 for(i=Z_MIN;i<Z_MAX;i+=gap) 
		 { 
		 glVertex3f(i, 0, Z_MIN); 
		 glVertex3f(i, 0, Z_MAX); 
		 } 
	 for(i=X_MIN;i<X_MAX;i+=gap) 
		 { 
		 glVertex3f(X_MIN, 0, i); 
		 glVertex3f(X_MAX, 0, i); 
		 } 
	 glEnd(); 
} 
void Transformasi() 
{ 
	// Kubus sebelum ditransformasi
	
	// sisi depan kubus
	glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(0.929, 0.278, 0.207); glVertex3f(2.0f,2.0f,1.0f); // set warna ke merah muda dan membuat sebuah titik
		 glColor3f(0.929, 0.862, 0.207); glVertex3f(2.0f,1.0f,1.0f); // set warna ke kuning muda dan membuat sebuah titik
		 glColor3f(0.207, 0.929, 0.294); glVertex3f(2.0f,1.0f,2.0f); // set warna ke hijau muda dan membuat sebuah titik
		 glColor3f(0.207, 0.6, 0.929); glVertex3f(2.0f,2.0f,2.0f); // set warna ke biru muda dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi kiri kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(0.929, 0.278, 0.207); glVertex3f(2.0f,1.0f,2.0f); // set warna ke merah muda dan membuat sebuah titik
		 glColor3f(0.929, 0.862, 0.207); glVertex3f(2.0f,2.0f,2.0f); // set warna ke kuning muda dan membuat sebuah titik
		 glColor3f(0.207, 0.929, 0.294); glVertex3f(1.0f,2.0f,2.0f); // set warna ke hijau muda dan membuat sebuah titik
		 glColor3f(0.207, 0.6, 0.929); glVertex3f(1.0f,1.0f,2.0f);  // set warna ke biru muda dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi belakang kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(0.929, 0.278, 0.207); glVertex3f(1.0f,2.0f,1.0f); // set warna ke merah muda dan membuat sebuah titik
		 glColor3f(0.929, 0.862, 0.207); glVertex3f(1.0f,1.0f,1.0f); // set warna ke kuning muda dan membuat sebuah titik
		 glColor3f(0.207, 0.929, 0.294); glVertex3f(1.0f,1.0f,2.0f); // set warna ke hijau muda dan membuat sebuah titik
		 glColor3f(0.207, 0.6, 0.929); glVertex3f(1.0f,2.0f,2.0f);  // set warna ke biru muda dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi kanan kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(0.929, 0.278, 0.207); glVertex3f(1.0f,2.0f,1.0f); // set warna ke merah muda dan membuat sebuah titik
		 glColor3f(0.929, 0.862, 0.207); glVertex3f(2.0f,2.0f,1.0f); // set warna ke kuning muda dan membuat sebuah titik
		 glColor3f(0.207, 0.929, 0.294); glVertex3f(2.0f,1.0f,1.0f); // set warna ke hijau muda dan membuat sebuah titik
		 glColor3f(0.207, 0.6, 0.929); glVertex3f(1.0f,1.0f,1.0f);  // set warna ke biru muda dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi atas kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(0.929, 0.278, 0.207); glVertex3f(2.0f,1.0f,1.0f); // set warna ke merah muda dan membuat sebuah titik
		 glColor3f(0.929, 0.862, 0.207); glVertex3f(2.0f,1.0f,2.0f); // set warna ke kuning muda dan membuat sebuah titik
		 glColor3f(0.207, 0.929, 0.294); glVertex3f(1.0f,1.0f,2.0f); // set warna ke hijau muda dan membuat sebuah titik
		 glColor3f(0.207, 0.6, 0.929); glVertex3f(1.0f,1.0f,1.0f);  // set warna ke biru muda dan membuat sebuah titik
		 glEnd();
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi bawah kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(0.929, 0.278, 0.207); glVertex3f(1.0f,2.0f,1.0f); // set warna ke merah muda dan membuat sebuah titik
		 glColor3f(0.929, 0.862, 0.207); glVertex3f(2.0f,2.0f,1.0f); // set warna ke kuning muda dan membuat sebuah titik
		 glColor3f(0.207, 0.929, 0.294); glVertex3f(2.0f,2.0f,2.0f); // set warna ke hijau muda dan membuat sebuah titik
		 glColor3f(0.207, 0.6, 0.929); glVertex3f(1.0f,2.0f,2.0f);  // set warna ke biru muda dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
 glPushMatrix(); // menghapus matriks identitas
 
 // Hapus salah satu komentar transformasi di bawah
 //glTranslatef(1.0f,2.0f,3.0f);
 //glScalef(2.0f,2.0f,2.0f); 
 glRotatef(180,0.0f,0.0f,1.0f);
 
 // Kubus setelah di transformasi
	 // sisi depan kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(1.0, 1.0, 0.0); glVertex3f(2.0f,2.0f,1.0f); // set warna ke kuning dan membuat sebuah titik
		 glColor3f(0.0, 0.0, 1.0); glVertex3f(2.0f,1.0f,1.0f); // set warna ke biru dan membuat sebuah titik
		 glColor3f(0.0, 1.0, 0.0); glVertex3f(2.0f,1.0f,2.0f); // set warna ke hijau dan membuat sebuah titik
		 glColor3f(1.0, 0.0, 1.0); glVertex3f(2.0f,2.0f,2.0f); // set warna ke ungu dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi kiri kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(1.0, 1.0, 0.0); glVertex3f(2.0f,1.0f,2.0f); // set warna ke kuning dan membuat sebuah titik
		 glColor3f(0.0, 0.0, 1.0); glVertex3f(2.0f,2.0f,2.0f); // set warna ke biru dan membuat sebuah titik
		 glColor3f(0.0, 1.0, 0.0); glVertex3f(1.0f,2.0f,2.0f); // set warna ke hijau dan membuat sebuah titik
		 glColor3f(1.0, 0.0, 1.0); glVertex3f(1.0f,1.0f,2.0f); // set warna ke ungu dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi belakang kubus 
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(1.0, 1.0, 0.0); glVertex3f(1.0f,2.0f,1.0f); // set warna ke kuning dan membuat sebuah titik
		 glColor3f(0.0, 0.0, 1.0); glVertex3f(1.0f,1.0f,1.0f); // set warna ke biru dan membuat sebuah titik
		 glColor3f(0.0, 1.0, 0.0); glVertex3f(1.0f,1.0f,2.0f); // set warna ke hijau dan membuat sebuah titik
		 glColor3f(1.0, 0.0, 1.0); glVertex3f(1.0f,2.0f,2.0f); // set warna ke ungu dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi kanan kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(1.0, 1.0, 0.0); glVertex3f(1.0f,2.0f,1.0f); // set warna ke kuning dan membuat sebuah titik
		 glColor3f(0.0, 0.0, 1.0); glVertex3f(2.0f,2.0f,1.0f); // set warna ke biru dan membuat sebuah titik
		 glColor3f(0.0, 1.0, 0.0); glVertex3f(2.0f,1.0f,1.0f); // set warna ke hijau dan membuat sebuah titik
		 glColor3f(1.0, 0.0, 1.0); glVertex3f(1.0f,1.0f,1.0f); // set warna ke ungu dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi atas kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(1.0, 1.0, 0.0); glVertex3f(2.0f,1.0f,1.0f); // set warna ke kuning dan membuat sebuah titik
		 glColor3f(0.0, 0.0, 1.0); glVertex3f(2.0f,1.0f,2.0f); // set warna ke biru dan membuat sebuah titik
		 glColor3f(0.0, 1.0, 0.0); glVertex3f(1.0f,1.0f,2.0f); // set warna ke hijau dan membuat sebuah titik
		 glColor3f(1.0, 0.0, 1.0); glVertex3f(1.0f,1.0f,1.0f); // set warna ke ungu dan membuat sebuah titik
		 glEnd();
	 glPopMatrix(); // menghapus matriks identitas
	 
	 // sisi bawah kubus
	 glPushMatrix(); // menyalin matriks identitas
		 glBegin(GL_QUADS); 
		 glColor3f(1.0, 1.0, 0.0); glVertex3f(1.0f,2.0f,1.0f); // set warna ke kuning dan membuat sebuah titik
		 glColor3f(0.0, 0.0, 1.0); glVertex3f(2.0f,2.0f,1.0f); // set warna ke biru dan membuat sebuah titik
		 glColor3f(0.0, 1.0, 0.0); glVertex3f(2.0f,2.0f,2.0f); // set warna ke hijau dan membuat sebuah titik
		 glColor3f(1.0, 0.0, 1.0); glVertex3f(1.0f,2.0f,2.0f); // set warna ke ungu dan membuat sebuah titik
		 glEnd(); 
	 glPopMatrix(); // menghapus matriks identitas
	glPopMatrix(); // menghapus matriks identitas
} 
void display() { 
 // Kalau move dan angle tidak nol, gerakkan kamera... 
 if (deltaMove) 
 moveMeFlat(deltaMove); 
 if (deltaAngle) { 
 angle += deltaAngle; 
 orientMe(angle); 
 } 
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
 // Gambar grid 
 Grid(); 
 // Gambar objek  
 Transformasi(); 
 glutSwapBuffers(); 
 glFlush(); 
} 
void pressKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tombol keyboard ditekan dan 
 // Selama tombol ditekan, variabel angle dan move diubah => kamera 
 switch (key) { 
 case GLUT_KEY_LEFT : deltaAngle = -0.01f;break; 
 case GLUT_KEY_RIGHT : deltaAngle = 0.01f;break; 
 case GLUT_KEY_UP : deltaMove = 1;break; 
 case GLUT_KEY_DOWN : deltaMove = -1;break; 
 } 
} 
void releaseKey(int key, int x, int y) { 
 // Fungsi ini akan dijalankan saat tekanan tombol keyboard dilepas 
 // Saat tombol dilepas, variabel angle dan move diset nol =>
 switch (key) { 
 case GLUT_KEY_LEFT : 
 if (deltaAngle < 0.0f) 
 deltaAngle = 0.0f; 
 break; 
 case GLUT_KEY_RIGHT : if (deltaAngle > 0.0f) 
 deltaAngle = 0.0f; 
 break; 
 case GLUT_KEY_UP : if (deltaMove > 0) 
 deltaMove = 0; 
 break; 
 case GLUT_KEY_DOWN : if (deltaMove < 0) 
 deltaMove = 0; 
 break; 
 } 
} 
// Variable untuk pencahayaan 
const GLfloat light_ambient[] = { 0.5f, 0.5f, 0.5f, 0.0f }; 
const GLfloat light_diffuse[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat light_position[] = { 0.0f, 20.0f, 10.0f, 1.0f }; 
const GLfloat mat_ambient[] = { 0.7f, 0.7f, 0.7f, 1.0f }; 
const GLfloat mat_diffuse[] = { 0.8f, 0.8f, 0.8f, 1.0f }; 
const GLfloat mat_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f }; 
const GLfloat high_shininess[] = { 100.0f }; 
void lighting(){ 
 // Fungsi mengaktifkan pencahayaan 
 glEnable(GL_DEPTH_TEST); 
 glDepthFunc(GL_LESS); 
 glEnable(GL_LIGHT0); 
 glEnable(GL_NORMALIZE); 
 glEnable(GL_COLOR_MATERIAL); 
 glEnable(GL_LIGHTING); 
 glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient); 
 glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse); 
 glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular); 
 glLightfv(GL_LIGHT0, GL_POSITION, light_position); 
 glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient); 
 glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse); 
 glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular); 
 glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess); 
} 
void init(void) 
{ 
 glEnable (GL_DEPTH_TEST); 
 glPolygonMode(GL_FRONT_AND_BACK, GL_FILL); 
} 
int main(int argc, char **argv) 
{ 
 glutInit(&argc, argv); 
 glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA); 
 glutInitWindowPosition(100,100); 
 glutInitWindowSize(640,480); 
 glutCreateWindow("Transformasi Objek 3D"); 
 glutIgnoreKeyRepeat(1); // Mengabaikan key repeat (saat tombol 
 glutSpecialFunc(pressKey);
 glutSpecialUpFunc(releaseKey); 
 glutDisplayFunc(display); 
 glutIdleFunc(display); // Fungsi display-nya dipanggil terusmenerus 
 glutReshapeFunc(Reshape); 
 lighting(); 
 init(); 
 glutMainLoop(); 
 return(0); 
}

