#pragma once
#include "Node.h"
#include "Button.h"
#include "EletricField.h"
#include <Windows.h>
#include "Input.h"
#include "Sprite.h"

class Hud :
	public Node
{
private:
	Sprite *barra;
	Button **_button;
public:
	virtual void Update() override;
	void onMouse(GLenum state, int x, int y);
	static void Init();
	static Hud * Instance;
	Hud();
	~Hud();
};

