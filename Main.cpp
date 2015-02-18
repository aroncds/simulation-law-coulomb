/*
Author: Aron de Castro Coelho
Email: aronxgames@yahoo.com.br
Date: 03/06/2014

Ponto de excução de todo o codigo criado, incialização, atualização e renderização

Por favor, caso a utilização do codigo, mantenha meus direitos!
*/
#include <Windows.h>
#include <math.h>

#include "myFramework.h"
#include "EletricField.h"
#include "Input.h"
#include "Graphic.h"

#define WIDTH					800
#define HEIGHT					600
#define TITLE					"TIDIR - Lei de Coulomb"
#define MAXCARGAS				2

struct Mouse{
	float x = 0;
	float y = 0;
	float z = 0;

	int state = GLUT_UP;
	vec3 get(){ return vec3(x, y, z); }
};

void onDisplay();
void Update();
void Render();
void Tick(int a);
void onMouse(int button, int state, int x, int y);
void onMouseMotion(int x, int y);
void Init();

bool initialize = false;

Sprite *sp;
Object *points;
Camera camera;

Text *t;
Text *force_text;

Mouse mouse;

int main(int argc, char ** argv){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH | GLUT_RGBA);
	glutInitWindowSize((int)WIDTH, (int)HEIGHT);
	glutCreateWindow(TITLE);
	
	GLenum err = glewInit();
	if (err != GLEW_OK) return 0;
	
	Init();
	//Input::Init(GetModuleHandle(NULL), FindWindow(argv[0], TITLE));

	glEnable(GL_CW);
	//glEnable(GL_BLEND);
	//glEnable(GL_CULL_FACE);
	//glCullFace(GL_BACK);

	glutDisplayFunc(onDisplay);
	glutMouseFunc(onMouse);
	glutMotionFunc(onMouseMotion);
	glutPassiveMotionFunc(onMouseMotion);
	//glutSetCursor(GLUT_CURSOR_NONE);

	force_text = new Text();
	force_text->InsertText("NULL", 35, 35);
	force_text->Position = vec3(90, 550, 0);
	
	//glutFullScreen();

	glutMainLoop();
	return 0;
}

void Init(){
	points = new Point(true);
	camera.setOrtographic(0, WIDTH, 0, HEIGHT, 0.1, 1);

	Hud::Init();
	Graphic::Init(300,200);
	EletricField::Init(MAXCARGAS);
	
	Graphic::Instance->Position = vec3(WIDTH - 325, HEIGHT - 225, 0);

	t = new Text();
	t->InsertText("Force: ", 35, 35);
	t->Position = vec3(10, 550, 0);

	std::cout.precision(3);
}

void onDisplay(){
	if (!initialize){
		glutTimerFunc(1000 / 450, Tick, 0);
		initialize = true;
	}
}

void Tick(int a){
	Update();
	Render();
	glutTimerFunc(1000 / 500, Tick, a);
}


void Update(){
	points->Update();
	Hud::Instance->Update();

	if (mouse.state == GLUT_DOWN && mouse.y > 40 && mouse.y < 600 && mouse.x >0 && mouse.x < 800)
		EletricField::Instance->onSelectedCarga(mouse.x, mouse.y);

	EletricField::Instance->Update();
	Graphic::Instance->Update();

	t->Update();
	force_text->Update();
}

void Render(){
	glClearColor(1, 1, 1, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	points->Render(camera.getMatrix());
	EletricField::Instance->Render(camera.getMatrix());
	Hud::Instance->Render(camera.getMatrix());
	
	if (Graphic::Instance->visible)
		Graphic::Instance->Render(camera.getMatrix());

	t->Render(camera.getMatrix());
	force_text->Render(camera.getMatrix());

	glutSwapBuffers();
}

void onMouse(int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON){
		if (state == GLUT_DOWN){
			mouse.state = GLUT_DOWN;
			mouse.x = x;
			mouse.y = y;
		}
		else if (state == GLUT_UP){
			mouse.state = GLUT_UP;
		}
		Hud::Instance->onMouse(state, x, y);
	}
}

void onMouseMotion(int x, int y){
	mouse.x = x;
	mouse.y = y;
	Hud::Instance->onMouse(GLUT_UP, x, y);
}