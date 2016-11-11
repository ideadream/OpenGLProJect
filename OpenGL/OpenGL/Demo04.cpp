#include "Demo04.h"
#include "GL/glut.h"
#include <math.h>

Demo04* Demo04::_shareInstance = nullptr;

Demo04::Demo04()
{
	_shareInstance = this;
}

Demo04::~Demo04()
{
	if (_shareInstance)
		_shareInstance = nullptr;
}


Demo04* Demo04::getInstance()
{
	if (_shareInstance == nullptr)
	{
		_shareInstance = new Demo04();
	}

	return _shareInstance;
}

void RenderSceneNew()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f,0.0f,0.0f);

	glPointSize(9);

	glBegin(GL_POINTS);

	{
		glVertex3f(0.0f, 0.0f, 0.0f);
	}

	glEnd();

	glColor3f(0.0f, 1.0f, 0.0f);

	glPointSize(3);

	glBegin(GL_POINTS);
	{
#define PI 3.14159f
#define RADIUS 50.f
		GLfloat x = 0, y = 0, angle = 0.0;
		for (angle = 0; angle <= 2.0f*PI; angle += 0.1f)
		{
			x = RADIUS*sin(angle);
			y = RADIUS*cos(angle);
			glVertex3f(x, y, 0);
		}
	}

	glEnd();
	glutSwapBuffers();
}


void Demo04::SetupRC()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);
	glColor3f(1.f, 0.f, 0.f);
}

void ChangeSizeNew(GLsizei w, GLsizei h)
{
	GLfloat nRange = 100.0f;

	// Prevent a divide by zero

	if (h == 0)
		h = 1;

	// Set Viewport to window dimensions

	glViewport(0, 0, w, h);

	// Reset projection matrix stack

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Establish clipping volume (left, right, bottom, top, near, far)

	if (w <= h)
		glOrtho(-nRange, nRange, -nRange*h / w, nRange*h / w, -nRange, nRange);
	else
		glOrtho(-nRange*w / h, nRange*w / h, -nRange, nRange, -nRange, nRange);

	// Reset Model view matrix stack

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void Demo04::showEffectView(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(400, 300);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Point examples");
	glutDisplayFunc(RenderSceneNew);
	glutReshapeFunc(ChangeSizeNew);
	SetupRC();
	glutMainLoop();
}

