#include "stdafx.h"

Delibird::Delibird()
{
	MoveS[0] = new ObImage(L"Delibird/Delibird_move_E.png");
	MoveS[1] = new ObImage(L"Delibird/Delibird_move_NE.png");
	MoveS[2] = new ObImage(L"Delibird/Delibird_move_N.png");
	MoveS[3] = new ObImage(L"Delibird/Delibird_move_NW.png");
	MoveS[4] = new ObImage(L"Delibird/Delibird_move_W.png");
	MoveS[5] = new ObImage(L"Delibird/Delibird_move_SW.png");
	MoveS[6] = new ObImage(L"Delibird/Delibird_move_S.png");
	MoveS[7] = new ObImage(L"Delibird/Delibird_move_SE.png");

	AttackS[0] = new ObImage(L"Delibird/Delibird_move_E.png");
	AttackS[1] = new ObImage(L"Delibird/Delibird_move_NE.png");
	AttackS[2] = new ObImage(L"Delibird/Delibird_move_N.png");
	AttackS[3] = new ObImage(L"Delibird/Delibird_move_NW.png");
	AttackS[4] = new ObImage(L"Delibird/Delibird_move_W.png");
	AttackS[5] = new ObImage(L"Delibird/Delibird_move_SW.png");
	AttackS[6] = new ObImage(L"Delibird/Delibird_move_S.png");
	AttackS[7] = new ObImage(L"Delibird/Delibird_move_SE.png");

	MoveL[0] = new ObImage(L"Delibird/Delibird_move_E.png");
	MoveL[1] = new ObImage(L"Delibird/Delibird_move_NE.png");
	MoveL[2] = new ObImage(L"Delibird/Delibird_move_N.png");
	MoveL[3] = new ObImage(L"Delibird/Delibird_move_NW.png");
	MoveL[4] = new ObImage(L"Delibird/Delibird_move_W.png");
	MoveL[5] = new ObImage(L"Delibird/Delibird_move_SW.png");
	MoveL[6] = new ObImage(L"Delibird/Delibird_move_S.png");
	MoveL[7] = new ObImage(L"Delibird/Delibird_move_SE.png");

	AttackL[0] = new ObImage(L"Delibird/Delibird_move_E.png");
	AttackL[1] = new ObImage(L"Delibird/Delibird_move_NE.png");
	AttackL[2] = new ObImage(L"Delibird/Delibird_move_N.png");
	AttackL[3] = new ObImage(L"Delibird/Delibird_move_NW.png");
	AttackL[4] = new ObImage(L"Delibird/Delibird_move_W.png");
	AttackL[5] = new ObImage(L"Delibird/Delibird_move_SW.png");
	AttackL[6] = new ObImage(L"Delibird/Delibird_move_S.png");
	AttackL[7] = new ObImage(L"Delibird/Delibird_move_SE.png");


	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->SetParentT(*Cen);
		MoveS[i]->scale.x = MoveS[i]->imageSize.x / 2.0f;
		MoveS[i]->scale.y = MoveS[i]->imageSize.y;
		MoveS[i]->maxFrame.x = 2;
		MoveS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackS[i]->SetParentT(*Cen);
		AttackS[i]->scale.x = AttackS[i]->imageSize.x / 2.0f;
		AttackS[i]->scale.y = AttackS[i]->imageSize.y;
		AttackS[i]->maxFrame.x = 2;
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
	Range->scale = Vector2(500.0f, 500.0f);
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


	FullCandyBar = new ObRect;
	FullCandyBar->SetParentT(*Cen);
	FullCandyBar->scale = Vector2(50.0f, 5.0f);
	FullCandyBar->isFilled = false;
	FullCandyBar->pivot = OFFSET_L;
	FullCandyBar->MoveLocalPos(Vector2(-25.0f, 30.0f));
	FullCandyBar->color = Color(0.0f, 0.0f, 0.0f, 1.0f);

	RealCandyBar = new ObRect;
	RealCandyBar->SetParentT(*Cen);
	RealCandyBar->MoveLocalPos(Vector2(-25.0f, 30.0f));
	RealCandyBar->pivot = OFFSET_L;
	RealCandyBar->scale = Vector2(50.0f, 5.0f);
	RealCandyBar->color = Color(255.0f / 255.0f, 192.0f / 255.0f, 203.0f / 255.0f, 1.0f);



}

Delibird::~Delibird()
{
}

void Delibird::Release()
{
}

void Delibird::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 2.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 2.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;

	}

	RealCandyBar->scale.x = CandyTimer * 1.0f;

	RealCandyBar->Update();
	FullCandyBar->Update();


	Tower::Update();

}

void Delibird::LateUpdate()
{
}

void Delibird::Render()
{
	Tower::Render();
	RealCandyBar->Render();
	FullCandyBar->Render();

}
