#include <GL/glut.h>
#include <iostream>
#include <Math.h>

int punto = 0;
int xuno, xdos, yuno, ydos;
int x,y;
int Ay, Ax, b;
float m, Xk, Yk;
 
void Inicio(void) {
	glClearColor(1.0,1.0,1.0,1.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, 640.0, 0.0, 480.0);
}

void Raton(int click, int estado, int CoordX, int CoordY){
	if(click==GLUT_LEFT_BUTTON && estado==GLUT_DOWN){
		x= CoordX;
		y= 480 - CoordY;
		
		xuno= CoordX;
		yuno= 480 - CoordY;;
	}
	else if (click==GLUT_RIGHT_BUTTON && estado==GLUT_DOWN){
		punto = 1;
		x= CoordX;
		y= 480 - CoordY;
		
		xdos= CoordX;
		ydos= 480 - CoordY;
	}
	glutPostRedisplay();
}

void PintarPixel(int x, int y){
	glBegin(GL_POINTS);
	glVertex2i(x,y);
	glEnd();               
}   

void Display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);
	glPointSize(5);
	if(punto==1){
		
		m = (ydos-yuno)/(xdos-xuno);
		Ax= xdos-xuno;
		Ay= ydos-yuno;
		
		if(m>=1){
			Xk= xuno + (1/m);
			x = round(Xk);
			y = yuno;
			for (int i = 0; i < Ay; i++){	
				PintarPixel(x, y);
				Xk= Xk + (1/m);
				x = round(Xk);
				y++;
			}
		}
		else{
	   		Yk= yuno + m;
			y = round(Yk);
			x = xuno;	
			for (int i = 0; i < Ax; i++){
				PintarPixel(x, y);
				Yk= Yk + m;
				y = round(Yk);
				x++;
		}
		}
	}
	glFlush();
}
int main(int argc, char** argv) {
	glutInit(&argc,argv); //INICIALIZA OpenGL
	glutInitWindowSize(640,480); //TAMAÑO DE PANTALLA
	glutInitWindowPosition(400,100); //POSICION DE INICIO DE LA PANTALLA
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //CANTIDAD DE GLUTS Y COLORES
	glutCreateWindow("Dos pixeles"); //TITULO DE LA PANTRALLA
	Inicio();  
	glutDisplayFunc(Display);
	glutMouseFunc(Raton);
	glutMainLoop();
	return 0;
}
