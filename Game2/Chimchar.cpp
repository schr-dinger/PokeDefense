#include "stdafx.h"

Chimchar::Chimchar()
{
	//Cen = new GameObject;

	MoveS[0] = new ObImage(L"Chimchar/Chimchar_idle_E.png");
	MoveS[1] = new ObImage(L"Chimchar/Chimchar_idle_NE.png");
	MoveS[2] = new ObImage(L"Chimchar/Chimchar_idle_N.png");
	MoveS[3] = new ObImage(L"Chimchar/Chimchar_idle_NW.png");
	MoveS[4] = new ObImage(L"Chimchar/Chimchar_idle_W.png");
	MoveS[5] = new ObImage(L"Chimchar/Chimchar_idle_SW.png");
	MoveS[6] = new ObImage(L"Chimchar/Chimchar_idle_S.png");
	MoveS[7] = new ObImage(L"Chimchar/Chimchar_idle_SE.png");

	AttackS[0] = new ObImage(L"Chimchar/Chimchar_attack_E.png");
	AttackS[1] = new ObImage(L"Chimchar/Chimchar_attack_NE.png");
	AttackS[2] = new ObImage(L"Chimchar/Chimchar_attack_N.png");
	AttackS[3] = new ObImage(L"Chimchar/Chimchar_attack_NW.png");
	AttackS[4] = new ObImage(L"Chimchar/Chimchar_attack_W.png");
	AttackS[5] = new ObImage(L"Chimchar/Chimchar_attack_SW.png");
	AttackS[6] = new ObImage(L"Chimchar/Chimchar_attack_S.png");
	AttackS[7] = new ObImage(L"Chimchar/Chimchar_attack_SE.png");

	MoveL[0] = new ObImage(L"Infernape/Infernape_idle_E.png");
	MoveL[1] = new ObImage(L"Infernape/Infernape_idle_NE.png");
	MoveL[2] = new ObImage(L"Infernape/Infernape_idle_N.png");
	MoveL[3] = new ObImage(L"Infernape/Infernape_idle_NW.png");
	MoveL[4] = new ObImage(L"Infernape/Infernape_idle_W.png");
	MoveL[5] = new ObImage(L"Infernape/Infernape_idle_SW.png");
	MoveL[6] = new ObImage(L"Infernape/Infernape_idle_S.png");
	MoveL[7] = new ObImage(L"Infernape/Infernape_idle_SE.png");

	AttackL[0] = new ObImage(L"Infernape/Infernape_attack_E.png");
	AttackL[1] = new ObImage(L"Infernape/Infernape_attack_NE.png");
	AttackL[2] = new ObImage(L"Infernape/Infernape_attack_N.png");
	AttackL[3] = new ObImage(L"Infernape/Infernape_attack_NW.png");
	AttackL[4] = new ObImage(L"Infernape/Infernape_attack_W.png");
	AttackL[5] = new ObImage(L"Infernape/Infernape_attack_SW.png");
	AttackL[6] = new ObImage(L"Infernape/Infernape_attack_S.png");
	AttackL[7] = new ObImage(L"Infernape/Infernape_attack_SE.png");

	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->SetParentT(*Cen);
		MoveS[i]->scale.x = MoveS[i]->imageSize.x / 2.0f;
		MoveS[i]->scale.y = MoveS[i]->imageSize.y;
		MoveS[i]->maxFrame.x = 2;
		MoveS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackS[i]->SetParentT(*Cen);
		AttackS[i]->scale.x = AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = AttackS[i]->imageSize.y;
		AttackS[i]->maxFrame.x = 3;
		AttackS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

		MoveL[i]->SetParentT(*Cen);
		MoveL[i]->scale.x = MoveL[i]->imageSize.x / 3.0f;
		MoveL[i]->scale.y = MoveL[i]->imageSize.y;
		MoveL[i]->maxFrame.x = 3;
		MoveL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackL[i]->SetParentT(*Cen);
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 2;
		AttackL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	}

	FireUp = new ObImage(L"Infernape/Inernape_special.png");
	FireUp->SetParentT(*Cen);
	FireUp->MoveLocalPos(Vector2(0.0f,-20.0f));
	FireUp->color = Color(0.5f, 0.5f, 0.5f, 0.4f);
	FireUp->scale.x = FireUp->imageSize.x / 4.0f;
	FireUp->scale.y = FireUp->imageSize.y *1.5f;
	FireUp->maxFrame.x = 4;
	FireUp->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	FireUp->isVisible = false;

	Range = new ObCircle;
	Range->SetParentT(*Cen);
	Range->scale = Vector2(500.0f, 500.0f);
	Range->isFilled = false;

	Select = new ObCircle;
	Select->SetParentT(*Cen);
	Select->scale = Vector2(50.0f, 50.0f);
	Select->isFilled = false;
	//Cen->SetWorldPosX(+200.0f);

	range = 500.0f;
	AtType = TYPE::FireAttack;

	NormalSp = 0.5f;
	FastSp = 0.2f;
	SlowSp = 1.5f;
	AtSp = NormalSp;

	AtPw = 10;
}

Chimchar::~Chimchar()
{
}

void Chimchar::Release()
{
}

void Chimchar::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 2.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 3.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;

	}

	if (Evolved)
	{
		UpTimer += DELTA;
		if (UpTimer > 0.0f && UpTimer < 2.0f)
		{
			Firing = true;
		}
		else if (UpTimer > 2.0f&&UpTimer<6.0f)
		{
			Firing = false;
		}
		else if (UpTimer > 6.0f)
		{
			UpTimer = 0.0f;
		}

		if (Firing)
		{
			FireUp->isVisible = true;
			AtSp = FastSp;
		}
		else
		{
			FireUp->isVisible = false;
			AtSp = NormalSp;
		}

	}



	Tower::Update();
	FireUp->Update();

}

void Chimchar::LateUpdate()
{
}

void Chimchar::Render()
{
	Tower::Render();
	FireUp->Render();
}
