#include "stdafx.h"

Togekiss::Togekiss()
{
	Move[0] = new ObImage(L"Togekiss/Togekiss_move_E.png");
	Move[1] = new ObImage(L"Togekiss/Togekiss_move_NE.png");
	Move[2] = new ObImage(L"Togekiss/Togekiss_move_N.png");
	Move[3] = new ObImage(L"Togekiss/Togekiss_move_NW.png");
	Move[4] = new ObImage(L"Togekiss/Togekiss_move_W.png");
	Move[5] = new ObImage(L"Togekiss/Togekiss_move_SW.png");
	Move[6] = new ObImage(L"Togekiss/Togekiss_move_S.png");
	Move[7] = new ObImage(L"Togekiss/Togekiss_move_SE.png");

	Hurt[0] = new ObImage(L"Togekiss/Togekiss_hurt_E.png");
	Hurt[1] = new ObImage(L"Togekiss/Togekiss_hurt_NE.png");
	Hurt[2] = new ObImage(L"Togekiss/Togekiss_hurt_N.png");
	Hurt[3] = new ObImage(L"Togekiss/Togekiss_hurt_NW.png");
	Hurt[4] = new ObImage(L"Togekiss/Togekiss_hurt_W.png");
	Hurt[5] = new ObImage(L"Togekiss/Togekiss_hurt_SW.png");
	Hurt[6] = new ObImage(L"Togekiss/Togekiss_hurt_S.png");
	Hurt[7] = new ObImage(L"Togekiss/Togekiss_hurt_SE.png");

	for (int i = 0; i < 8; i++)
	{
		Move[i]->SetParentT(*Cen);
		Move[i]->scale.x = Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = Move[i]->imageSize.y;
		Move[i]->maxFrame.x = 3;
		Move[i]->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
		Move[i]->SetLocalPosY(100.0f);

		Hurt[i]->SetParentT(*Cen);
		Hurt[i]->scale.x = Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = Hurt[i]->imageSize.y;
		Hurt[i]->SetLocalPosY(100.0f);

	}

	Speed = 10.0f;
	FullSpeed = 10.0f;
	SlowSpeed = 5.0f;
	FullHealth = 500;


	Shadow = new ObImage(L"Ui/Shadow.png");
	Shadow->scale = Shadow->imageSize * 0.1f;
	Shadow->SetParentT(*Cen);
	Shadow->SetLocalPos(Vector2(0.0f, 0.0f));

}

Togekiss::~Togekiss()
{
}

void Togekiss::Release()
{
}

void Togekiss::Update()
{
	for (int i = 0; i < 8; i++)
	{
		Move[i]->scale.x = 1.2f * ratio * Move[i]->imageSize.x / 3.0f;
		Move[i]->scale.y = 1.2f * ratio * Move[i]->imageSize.y;
		Hurt[i]->scale.x = 1.2f * ratio * Hurt[i]->imageSize.x / 1.0f;
		Hurt[i]->scale.y = 1.2f * ratio * Hurt[i]->imageSize.y;

	}
	Shadow->Update();

	Bloon::Update();

}

void Togekiss::LateUpdate()
{
}

void Togekiss::Render()
{
	Shadow->Render();
	Bloon::Render();
}
