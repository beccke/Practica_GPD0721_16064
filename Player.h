#pragma once
#include "GameObject.h"
#include "Image.h"


class Player :public GameObject
{
private:
	Image player;
	float deltaTime;
	

public:
	void Init();
	void Draw(int mouseX, int mouseY);
	void acel(int velocidadx_, int aceleracionx_, int velocidady_, int aceleraciony_);
};