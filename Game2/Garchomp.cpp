#include "stdafx.h"

Garchomp::Garchomp()
{
	Move[0] = new ObImage(L"Garchomp/Garchomp_move_E.png");
	Move[1] = new ObImage(L"Garchomp/Garchomp_move_NE.png");
	Move[2] = new ObImage(L"Garchomp/Garchomp_move_N.png");
	Move[3] = new ObImage(L"Garchomp/Garchomp_move_NW.png");
	Move[4] = new ObImage(L"Garchomp/Garchomp_move_W.png");
	Move[5] = new ObImage(L"Garchomp/Garchomp_move_SW.png");
	Move[6] = new ObImage(L"Garchomp/Garchomp_move_S.png");
	Move[7] = new ObImage(L"Garchomp/Garchomp_move_SE.png");

	Hurt[0] = new ObImage(L"Garchomp/Garchomp_hurt_E.png");
	Hurt[1] = new ObImage(L"Garchomp/Garchomp_hurt_NE.png");
	Hurt[2] = new ObImage(L"Garchomp/Garchomp_hurt_N.png");
	Hurt[3] = new ObImage(L"Garchomp/Garchomp_hurt_NW.png");
	Hurt[4] = new ObImage(L"Garchomp/Garchomp_hurt_W.png");
	Hurt[5] = new ObImage(L"Garchomp/Garchomp_hurt_SW.png");
	Hurt[6] = new ObImage(L"Garchomp/Garchomp_hurt_S.png");
	Hurt[7] = new ObImage(L"Garchomp/Garchomp_hurt_SE.png");

	Burrow[0] = new ObImage(L"Garchomp/Garchomp_special_E.png");
	Burrow[1] = new ObImage(L"Garchomp/Garchomp_special_NE.png");
	Burrow[2] = new ObImage(L"Garchomp/Garchomp_special_N.png");
	Burrow[3] = new ObImage(L"Garchomp/Garchomp_special_NW.png");
	Burrow[4] = new ObImage(L"Garchomp/Garchomp_special_W.png");
	Burrow[5] = new ObImage(L"Garchomp/Garchomp_special_SW.png");
	Burrow[6] = new ObImage(L"Garchomp/Garchomp_special_S.png");
	Burrow[7] = new ObImage(L"Garchomp/Garchomp_special_SE.png");

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

		Burrow[i]->SetParentT(*Cen);
		Burrow[i]->scale.x = Burrow[i]->imageSize.x / 3.0f;
		Burrow[i]->scale.y = Burrow[i]->imageSize.y;
		Burrow[i]->maxFrame.x = 3;
		Burrow[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		Burrow[i]->SetLocalPosY(Burrow[i]->imageSize.y / 2.0f);

	}


	Speed = 10.0f;
	FullSpeed = 10.0f;
	SlowSpeed = 5.0f;
	FullHealth = 500;

	DefType = DEFTYPE::DragonType;
	RealHpBar->color = Color(75.0f / 255.0f, 0.0f / 255.0f, 130.0f / 255.0f, 1.0f);

}

Garchomp::~Garchomp()
{
}

void Garchomp::Release()
{
}

void Garchomp::Update()
{
	for (int i = 0; i < 8; i++)
	{
		Move[i]->scale.x = 1.5f * ratio * Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = 1.5f * ratio * Move[i]->imageSize.y;
		Hurt[i]->scale.x = 1.5f * ratio * Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = 1.5f * ratio * Hurt[i]->imageSize.y;
		Burrow[i]->scale.x = 1.5f * ratio * Burrow[i]->imageSize.x / 3.0f;
		Burrow[i]->scale.y = 1.5f * ratio * Burrow[i]->imageSize.y;

		Burrow[i]->Update();

	}

	if (Go)
	{
		BurrowTimer += DELTA;
		if (BurrowTimer > 0.0f && BurrowTimer < 5.0f)
		{
			Burrowed = true;
		}
		else if (BurrowTimer > 5.0f && BurrowTimer < 13.0f)
		{
			Burrowed = false;
		}
		else if (BurrowTimer > 13.0f)
		{
			BurrowTimer = 0.0f;
		}

	}

	Bloon::Update();

}

void Garchomp::LateUpdate()
{
}

void Garchomp::Render()
{
	if (Burrowed)
	{
		switch (state)
		{
		case NEWS::E:
			Burrow[0]->Render();
			break;
		case NEWS::NE:
			Burrow[1]->Render();
			break;
		case NEWS::N:
			Burrow[2]->Render();
			break;
		case NEWS::NW:
			Burrow[3]->Render();
			break;
		case NEWS::W:
			Burrow[4]->Render();
			break;
		case NEWS::SW:
			Burrow[5]->Render();
			break;
		case NEWS::S:
			Burrow[6]->Render();
			break;
		case NEWS::SE:
			Burrow[7]->Render();
			break;
		}
	}
	else
	{
		Bloon::Render();
	}
}
