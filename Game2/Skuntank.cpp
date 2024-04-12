#include "stdafx.h"

Skuntank::Skuntank()
{
	Move[0] = new ObImage(L"Skuntank/Skuntank_move_E.png");
	Move[1] = new ObImage(L"Skuntank/Skuntank_move_NE.png");
	Move[2] = new ObImage(L"Skuntank/Skuntank_move_N.png");
	Move[3] = new ObImage(L"Skuntank/Skuntank_move_NW.png");
	Move[4] = new ObImage(L"Skuntank/Skuntank_move_W.png");
	Move[5] = new ObImage(L"Skuntank/Skuntank_move_SW.png");
	Move[6] = new ObImage(L"Skuntank/Skuntank_move_S.png");
	Move[7] = new ObImage(L"Skuntank/Skuntank_move_SE.png");

	Hurt[0] = new ObImage(L"Skuntank/Skuntank_hurt_E.png");
	Hurt[1] = new ObImage(L"Skuntank/Skuntank_hurt_NE.png");
	Hurt[2] = new ObImage(L"Skuntank/Skuntank_hurt_N.png");
	Hurt[3] = new ObImage(L"Skuntank/Skuntank_hurt_NW.png");
	Hurt[4] = new ObImage(L"Skuntank/Skuntank_hurt_W.png");
	Hurt[5] = new ObImage(L"Skuntank/Skuntank_hurt_SW.png");
	Hurt[6] = new ObImage(L"Skuntank/Skuntank_hurt_S.png");
	Hurt[7] = new ObImage(L"Skuntank/Skuntank_hurt_SE.png");

	for (int i = 0; i < 8; i++)
	{
		Move[i]->SetParentT(*Cen);
		Move[i]->scale.x = Move[i]->imageSize.x / 2.0f;
		Move[i]->scale.y = Move[i]->imageSize.y;
		Move[i]->maxFrame.x = 2;
		Move[i]->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
		Move[i]->SetLocalPosY(Move[i]->imageSize.y / 2.0f);

		Hurt[i]->SetParentT(*Cen);
		Hurt[i]->scale.x = Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = Hurt[i]->imageSize.y;
		Hurt[i]->SetLocalPosY(Hurt[i]->imageSize.y / 2.0f);

	}

	Fart = new ObImage(L"Skuntank/Skuntank_fog.png");
	Fart->SetParentT(*Cen);
	Fart->scale.x = (Fart->imageSize.x / 6.0f) * 2.0f;;
	Fart->scale.y = (Fart->imageSize.y) * 2.0f;
	Fart->maxFrame.x = 6;
	Fart->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
	Fart->color = Color(0.5f, 0.5f, 0.5f, 0.3f);

	FartHit  = new ObCircle;
	FartHit ->SetParentT(*Cen);
	FartHit->scale = Vector2(250.0f, 250.0f);
	FartHit->isFilled = false;



	Speed = 10.0f;
	FullSpeed = 10.0f;
	SlowSpeed = 5.5f;
	FullHealth = 300;

}

Skuntank::~Skuntank()
{
}

void Skuntank::Release()
{
}

void Skuntank::Update()
{
	for (int i = 0; i < 8; i++)
	{
		Move[i]->scale.x = ratio * Move[i]->imageSize.x / 2.0f;
		Move[i]->scale.y = ratio * Move[i]->imageSize.y;
		Hurt[i]->scale.x = ratio * Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = ratio * Hurt[i]->imageSize.y;

	}

	Fart->Update();
	FartHit->Update();
	Bloon::Update();

}

void Skuntank::LateUpdate()
{
}

void Skuntank::Render()
{
	FartHit->Render();
	if (Go)
	{
		Fart->Render();
	}
	Bloon::Render();
}
