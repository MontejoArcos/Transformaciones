//librerias
#include <stdlib.h>
#include <GL/glut.h>

//Declaracion de variables
GLfloat trazlacion = 0.0f;
GLfloat escalamiento = 0.0f;
GLfloat rotacion = 0.0f;

//pocicion de cubo
void polarView(GLfloat distance, GLfloat trazlacion, GLfloat escalamiento, GLfloat rotacion)
{
	glTranslated(0.1, 0.1, -distance);
	glRotated(+ trazlacion, 0.0, 0.0, 1.0);
	glRotated(+ escalamiento, 1.0, 0.0, 00);
	glRotated(+ rotacion, 0.0, 0.0, 1.0);
}

//Inicializa las propiedades de la fuente de colores
static void init(void)
{
	GLfloat light_ambient[] = { 0.75, 0.75, 0.75, 1.0 };
	GLfloat light_diffuse[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_specular[] = { 1.0, 1.0, 1.0, 1.0 };
	GLfloat light_position[] = { 0.0, 0.0, 1.0, 0.0 };

	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
	glLightfv(GL_LIGHT0, GL_POSITION, light_position);

	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glDepthFunc(GL_LESS);
	glEnable(GL_DEPTH_TEST);
}

void display(void)
{
	
	//Defino un color  Azul
	GLfloat mat_ambient_cubo[] = { 0.1, 0.1, 0.1, 1.0f };
	GLfloat mat_diffuse_cubo[] = { 0.0, 0.0, 0.8, 1.0f };
	GLfloat mat_specular_cubo[] = { 0.9, 0.9, 0.9, 1.0f };


	GLfloat zExtent, xExtent, xLocal, zLocal;
	int loopX, loopZ;

	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW_MATRIX);
	glLoadIdentity();
	polarView(15.0f, rotacion, escalamiento, trazlacion);

	//.........................................................................


	//Dibuja el cubo
	glMaterialfv(GL_FRONT, GL_AMBIENT, mat_ambient_cubo);
	glMaterialfv(GL_FRONT, GL_DIFFUSE, mat_diffuse_cubo);
	glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular_cubo);
	glMaterialf(GL_FRONT, GL_SHININESS, 10.0f);
	glPushMatrix();
	glTranslatef(1.0, 1.0, 1.0);
	glRotatef(15.0, 0.0, 1.0, 0.0);
	glutSolidCube(2.0);
	glPopMatrix();


	glFlush();
}
//tamaño del cubo
void reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei)w, (GLsizei)h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50, (GLfloat)w / (GLfloat)h, 10.0, 20.0);
	glMatrixMode(GL_MODELVIEW);
}




void keyboard(unsigned char key, int x, int y)
{
	switch (key) {
	case 'w':
	case 'W':
		escalamiento = escalamiento + 10.0f;
		glutPostRedisplay();
		break;
	case 'a':
	case 'A':
		escalamiento = escalamiento - 10.0;
		glutPostRedisplay();
		break;
	case 's':
	case 'S':
		trazlacion = trazlacion + 10.0f;
		glutPostRedisplay();
		break;
	case 'd':
	case 'D':
		rotacion = rotacion - 10.0f;
		glutPostRedisplay();
		break;
	

	case '0':
		exit(0);
		break;
	}
}

//tamaño del display
int main(int argc, char **argv)
{
	glutInitWindowSize(800, 600);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutCreateWindow(argv[0]);
	init();
	glutReshapeFunc(reshape);
	glutKeyboardFunc(keyboard);
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}