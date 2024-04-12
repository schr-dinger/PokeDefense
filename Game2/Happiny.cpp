#include "stdafx.h"

Happiny::Happiny()
{
	MoveS[0] = new ObImage(L"Happiny/Happiny_move_E.png");
	MoveS[1] = new ObImage(L"Happiny/Happiny_move_NE.png");
	MoveS[2] = new ObImage(L"Happiny/Happiny_move_N.png");
	MoveS[3] = new ObImage(L"Happiny/Happiny_move_NW.png");
	MoveS[4] = new ObImage(L"Happiny/Happiny_move_W.png");
	MoveS[5] = new ObImage(L"Happiny/Happiny_move_SW.png");
	MoveS[6] = new ObImage(L"Happiny/Happiny_move_S.png");
	MoveS[7] = new ObImage(L"Happiny/Happiny_move_SE.png");

	AttackS[0] = new ObImage(L"Happiny/Happiny_move_E.png");
	AttackS[1] = new ObImage(L"Happiny/Happiny_move_NE.png");
	AttackS[2] = new ObImage(L"Happiny/Happiny_move_N.png");
	AttackS[3] = new ObImage(L"Happiny/Happiny_move_NW.png");
	AttackS[4] = new ObImage(L"Happiny/Happiny_move_W.png");
	AttackS[5] = new ObImage(L"Happiny/Happiny_move_SW.png");
	AttackS[6] = new ObImage(L"Happiny/Happiny_move_S.png");
	AttackS[7] = new ObImage(L"Happiny/Happiny_move_SE.png");

	MoveL[0] = new ObImage(L"Blissey/Blissey_move_E.png");
	MoveL[1] = new ObImage(L"Blissey/Blissey_move_NE.png");
	MoveL[2] = new ObImage(L"Blissey/Blissey_move_N.png");
	MoveL[3] = new ObImage(L"Blissey/Blissey_move_NW.png");
	MoveL[4] = new ObImage(L"Blissey/Blissey_move_W.png");
	MoveL[5] = new ObImage(L"Blissey/Blissey_move_SW.png");
	MoveL[6] = new ObImage(L"Blissey/Blissey_move_S.png");
	MoveL[7] = new ObImage(L"Blissey/Blissey_move_SE.png");

	AttackL[0] = new ObImage(L"Blissey/Blissey_move_E.png");
	AttackL[1] = new ObImage(L"Blissey/Blissey_move_NE.png");
	AttackL[2] = new ObImage(L"Blissey/Blissey_move_N.png");
	AttackL[3] = new ObImage(L"Blissey/Blissey_move_NW.png");
	AttackL[4] = new ObImage(L"Blissey/Blissey_move_W.png");
	AttackL[5] = new ObImage(L"Blissey/Blissey_move_SW.png");
	AttackL[6] = new ObImage(L"Blissey/Blissey_move_S.png");
	AttackL[7] = new ObImage(L"Blissey/Blissey_move_SE.png");


	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->SetParentT(*Cen);
		MoveS[i]->scale.x = MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = MoveS[i]->imageSize.y;
		MoveS[i]->maxFrame.x = 3;
		MoveS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackS[i]->SetParentT(*Cen);
		AttackS[i]->scale.x = AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = AttackS[i]->imageSize.y;
		AttackS[i]->maxFrame.x = 3;
		AttackS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		MoveL[i]->SetParentT(*Cen);
		MoveL[i]->scale.x = MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = MoveL[i]->imageSize.y;
		MoveL[i]->maxFrame.x = 2;
		MoveL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackL[i]->SetParentT(*Cen);
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 2;
		AttackL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

	}

	Range = new ObCircle;
	Range->SetParentT(*Cen);
	Range->scale = Vector2(300.0f, 300.0f);
	Range->isFilled = false;

	Select = new ObCircle;
	Select->SetParentT(*Cen);
	Select->scale = Vector2(50.0f, 50.0f);
	Select->isFilled = false;

	//Cen->SetWorldPosX(-200.0f);
	//Cen->SetWorldPosY(-200.0f);



	AtType = TYPE::GrassAttack;

	NormalSp = 100.0f;
	FastSp = 100.0f;
	SlowSp = 100.0f;
	AtSp = NormalSp;

	AtPw = 10;




	FullBuffBar = new ObRect;
	FullBuffBar->SetParentT(*Cen);
	FullBuffBar->scale = Vector2(50.0f, 5.0f);
	FullBuffBar->isFilled = false;
	FullBuffBar->pivot = OFFSET_L;
	FullBuffBar->MoveLocalPos(Vector2(-25.0f, 30.0f));
	FullBuffBar->color = Color(0.0f, 0.0f, 0.0f, 1.0f);

	RealBuffBar = new ObRect;
	RealBuffBar->SetParentT(*Cen);
	RealBuffBar->MoveLocalPos(Vector2(-25.0f, 30.0f));
	RealBuffBar->pivot = OFFSET_L;
	RealBuffBar->scale = Vector2(50.0f, 5.0f);
	RealBuffBar->color = Color(255.0f / 255.0f, 192.0f / 255.0f, 203.0f / 255.0f, 1.0f);

}

Happiny::~Happiny()
{
}

void Happiny::Release()
{
}

void Happiny::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;

	}

	RealBuffBar->scale.x = BuffTimer * 5.0f;



	if (Evolved)
	{
		BuffTimer += DELTA;
	}

	RealBuffBar->Update();
	FullBuffBar->Update();


	Tower::Update();

}

void Happiny::LateUpdate()
{
}

void Happiny::Render()
{
	Tower::Render();
	RealBuffBar->Render();
	FullBuffBar->Render();

}