#include "GL/glut.h"
#include "Define_Header.h"

int main(int argc, char* argv[])
{
	glutInit(&argc, argv);

	//Demo01::getInstance()->showEffectView(argc, argv);
	Demo02::getInstance()->showEffectView(argc, argv);
	Demo03::getInstance()->showEffectView(argc, argv);
	Demo04::getInstance()->showEffectView(argc, argv);

}