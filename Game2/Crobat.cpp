#include "stdafx.h"

Crobat::Crobat()
{
	Move[0] = new ObImage(L"Crobat/Crobat_move_E.png");
	Move[1] = new ObImage(L"Crobat/Crobat_move_NE.png");
	Move[2] = new ObImage(L"Crobat/Crobat_move_N.png");
	Move[3] = new ObImage(L"Crobat/Crobat_move_NW.png");
	Move[4] = new ObImage(L"Crobat/Crobat_move_W.png");
	Move[5] = new ObImage(L"Crobat/Crobat_move_SW.png");
	Move[6] = new ObImage(L"Crobat/Crobat_move_S.png");
	Move[7] = new ObImage(L"Crobat/Crobat_move_SE.png");

	Hurt[0] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[1] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[2] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[3] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[4] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[5] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[6] = new ObImage(L"Crobat/Crobat_hurt_S.png");
	Hurt[7] = new ObImage(L"Crobat/Crobat_hurt_S.png");

	for (int i = 0; i < 8; i++)
	{
		Move[i]->SetParentT(*Cen);
		Move[i]->scale.x = Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = Move[i]->imageSize.y;
		Move[i]->maxFrame.x = 3;
		Move[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		Move[i]->SetLocalPosY(Move[i]->imageSize.y / 2.0f);

		Hurt[i]->SetParentT(*Cen);
		Hurt[i]->scale.x = Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = Hurt[i]->imageSize.y;
		Hurt[i]->SetLocalPosY(Hurt[i]->imageSize.y / 2.0f);

	}

	Absorb = new ObImage(L"Crobat/Crobat_special.png");
	Absorb -> SetParentT(*Cen);
	Absorb->scale.x = Absorb->imageSize.x / 13.0f * 1.5f;
	Absorb->scale.y = Absorb->imageSize.y * 1.5f;
	Absorb->maxFrame.x = 13;
	Absorb->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	Absorb->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
	//Absorb->SetLocalPosY(Move[i]->imageSize.y / 2.0f);

	Speed = 20.0f;
	FullSpeed = 20.0f;
	SlowSpeed = 10.0f;
	FullHealth = 300;

}

Crobat::~Crobat()
{
}

void Crobat::Release()
{
}

void Crobat::Update()
{
	Health = Utility::Saturate(Health, 0.0f, FullHealth);

	for (int i = 0; i < 8; i++)
	{
		Move[i]->scale.x = ratio * Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = ratio * Move[i]->imageSize.y;
		Hurt[i]->scale.x = ratio * Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = ratio * Hurt[i]->imageSize.y;

	}

	if (Go)
	{
		Absorb->isVisible = true;
	}
	else
	{
		Absorb->isVisible = false;
	}
	Absorb->Update();
	Bloon::Update();

	if (!Dead)
	{
		Health += 30.0f * DELTA;
	}

}

void Crobat::LateUpdate()
{
}

void Crobat::Render()
{
	Absorb->Render();

	Bloon::Render();
}
