#include "stdafx.h"

Ninetails::Ninetails()
{
	Move[0] = new ObImage(L"Ninetails/Ninetails_move_E.png");
	Move[1] = new ObImage(L"Ninetails/Ninetails_move_NE.png");
	Move[2] = new ObImage(L"Ninetails/Ninetails_move_N.png");
	Move[3] = new ObImage(L"Ninetails/Ninetails_move_NW.png");
	Move[4] = new ObImage(L"Ninetails/Ninetails_move_W.png");
	Move[5] = new ObImage(L"Ninetails/Ninetails_move_SW.png");
	Move[6] = new ObImage(L"Ninetails/Ninetails_move_S.png");
	Move[7] = new ObImage(L"Ninetails/Ninetails_move_SE.png");

	Hurt[0] = new ObImage(L"Ninetails/Ninetails_hurt_E.png");
	Hurt[1] = new ObImage(L"Ninetails/Ninetails_hurt_NE.png");
	Hurt[2] = new ObImage(L"Ninetails/Ninetails_hurt_N.png");
	Hurt[3] = new ObImage(L"Ninetails/Ninetails_hurt_NW.png");
	Hurt[4] = new ObImage(L"Ninetails/Ninetails_hurt_W.png");
	Hurt[5] = new ObImage(L"Ninetails/Ninetails_hurt_SW.png");
	Hurt[6] = new ObImage(L"Ninetails/Ninetails_hurt_S.png");
	Hurt[7] = new ObImage(L"Ninetails/Ninetails_hurt_SE.png");

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

	Speed = 10.0f;
	FullSpeed = 10.0f;
	SlowSpeed = 5.0f;
	FullHealth = 500;

	DefType = DEFTYPE::FireType;
	RealHpBar->color = Color(220.0f / 255.0f, 20.0f / 255.0f, 60.0f / 255.0f, 1.0f);

}

Ninetails::~Ninetails()
{
}

void Ninetails::Release()
{
}

void Ninetails::Update()
{

	for (int i = 0; i < 8; i++)
	{
		Move[i]->scale.x = 1.5f * ratio * Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = 1.5f * ratio * Move[i]->imageSize.y;
		Hurt[i]->scale.x = 1.5f * ratio * Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = 1.5f * ratio * Hurt[i]->imageSize.y;

	}

	Bloon::Update();

}

void Ninetails::LateUpdate()
{
}
