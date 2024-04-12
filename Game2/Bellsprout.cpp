#include "stdafx.h"

Bellsprout::Bellsprout()
{
	Move[0] = new ObImage(L"Bellsprout/Bellsprout_move_E.png");
	Move[1] = new ObImage(L"Bellsprout/Bellsprout_move_NE.png");
	Move[2] = new ObImage(L"Bellsprout/Bellsprout_move_N.png");
	Move[3] = new ObImage(L"Bellsprout/Bellsprout_move_NW.png");
	Move[4] = new ObImage(L"Bellsprout/Bellsprout_move_W.png");
	Move[5] = new ObImage(L"Bellsprout/Bellsprout_move_SW.png");
	Move[6] = new ObImage(L"Bellsprout/Bellsprout_move_S.png");
	Move[7] = new ObImage(L"Bellsprout/Bellsprout_move_SE.png");

	Hurt[0] = new ObImage(L"Bellsprout/Bellsprout_hurt_E.png");
	Hurt[1] = new ObImage(L"Bellsprout/Bellsprout_hurt_NE.png");
	Hurt[2] = new ObImage(L"Bellsprout/Bellsprout_hurt_N.png");
	Hurt[3] = new ObImage(L"Bellsprout/Bellsprout_hurt_NW.png");
	Hurt[4] = new ObImage(L"Bellsprout/Bellsprout_hurt_W.png");
	Hurt[5] = new ObImage(L"Bellsprout/Bellsprout_hurt_SW.png");
	Hurt[6] = new ObImage(L"Bellsprout/Bellsprout_hurt_S.png");
	Hurt[7] = new ObImage(L"Bellsprout/Bellsprout_hurt_SE.png");

	for (int i = 0; i < 8; i++)
	{
		Move[i]->SetParentT(*Cen);
		Move[i]->scale.x = Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = Move[i]->imageSize.y;
		Move[i]->maxFrame.x = 3;
		Move[i]->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
		Move[i]->SetLocalPosY(Move[i]->imageSize.y / 2.0f);

		Hurt[i]->SetParentT(*Cen);
		Hurt[i]->scale.x = Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = Hurt[i]->imageSize.y;
		Hurt[i]->SetLocalPosY(Hurt[i]->imageSize.y / 2.0f);


	}

	state = NEWS::E;
	Speed = 10.0f;
	FullHealth = 150;

	DefType = DEFTYPE::GrassType;
}

Bellsprout::~Bellsprout()
{
}

void Bellsprout::Release()
{
}

void Bellsprout::Update()
{
	RealHpBar->color = Color(0.0f / 256.0f, 128.0f / 255.0f, 0.0f / 255.0f, 1.0f);

	for (int i = 0; i < 8; i++)
	{
		Move[i]->scale.x = ratio * Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = ratio * Move[i]->imageSize.y;
		Hurt[i]->scale.x = ratio * Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = ratio * Hurt[i]->imageSize.y;

	}

	Bloon::Update();
}

void Bellsprout::LateUpdate()
{
}

void Bellsprout::Render()
{
	Bloon::Render();
}
