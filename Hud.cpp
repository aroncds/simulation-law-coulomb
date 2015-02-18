#include "Hud.h"
#include "Graphic.h"
Hud * Hud::Instance;

void CreateCarga(){
	if (MessageBox(NULL, "Gostaria de adicionar uma carga?", "Carga", MB_OKCANCEL)==1){
	//	Input::Instance->createWindow();
		float p, exp;
		std::cout << "Digite o valor da carga: ";
		std::cin >> p >> exp;
		EletricField::Instance->CreateCarga(p, exp);

	//	Input::Instance->closeWindow();
	}
}

bool open = false;

void GenerateGraphic(){
	if (!open){
		Graphic::Instance->visible = true;
		Graphic::Instance->generateGraphic();
		open = true;
	}
	else{
		Graphic::Instance->visible = false;
		open = false;
	}
}

Hud::Hud():Node(5){
	barra = new Sprite("imagens//texture.raw", 800, 40);
	this->addChild(barra);

	_button = (Button **)calloc(5, sizeof(Button));
	_button[0] = new Button("imagens/button_add.raw", "imagens/button_over.raw", "imagens/button_add.raw",96, 32);
	//_button[0]->Scale = vec3(0.7, 0.5, 1);
	_button[0]->Position = vec3(20, 5, 0);
	this->addChild(_button[0]);

	_button[0]->addEvent("CLICK", CreateCarga);

	_button[1] = new Button("imagens/graphic.raw", "imagens/graphic_over.raw", "imagens/graphic.raw", 128, 32);
	_button[1]->Position = vec3(150, 5, 0);
	this->addChild(_button[1]);

	_button[1]->addEvent("CLICK", GenerateGraphic);
}

void Hud::Update(){	
	Node::Update();
}

void Hud::Init(){
	Instance = new Hud();
}

void Hud::onMouse(GLenum state, int x, int y){
	for (int i = 0; i < 2; i++){
		_button[i]->Check(state, x, y);
	}
}

Hud::~Hud()
{//
}
