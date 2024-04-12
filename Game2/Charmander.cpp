#include "stdafx.h"

Charmander::Charmander()
{
	//Cen = new GameObject;

	MoveS[0] = new ObImage(L"Charmander/Charmander_move_E.png");
	MoveS[1] = new ObImage(L"Charmander/Charmander_move_NE.png");
	MoveS[2] = new ObImage(L"Charmander/Charmander_move_N.png");
	MoveS[3] = new ObImage(L"Charmander/Charmander_move_NW.png");
	MoveS[4] = new ObImage(L"Charmander/Charmander_move_W.png");
	MoveS[5] = new ObImage(L"Charmander/Charmander_move_SW.png");
	MoveS[6] = new ObImage(L"Charmander/Charmander_move_S.png");
	MoveS[7] = new ObImage(L"Charmander/Charmander_move_SE.png");

	AttackS[0] = new ObImage(L"Charmander/Charmander_attack_E.png");
	AttackS[1] = new ObImage(L"Charmander/Charmander_attack_NE.png");
	AttackS[2] = new ObImage(L"Charmander/Charmander_attack_N.png");
	AttackS[3] = new ObImage(L"Charmander/Charmander_attack_NW.png");
	AttackS[4] = new ObImage(L"Charmander/Charmander_attack_W.png");
	AttackS[5] = new ObImage(L"Charmander/Charmander_attack_SW.png");
	AttackS[6] = new ObImage(L"Charmander/Charmander_attack_S.png");
	AttackS[7] = new ObImage(L"Charmander/Charmander_attack_SE.png");

	MoveL[0] = new ObImage(L"Charizard/Charizard_move_E.png");
	MoveL[1] = new ObImage(L"Charizard/Charizard_move_NE.png");
	MoveL[2] = new ObImage(L"Charizard/Charizard_move_N.png");
	MoveL[3] = new ObImage(L"Charizard/Charizard_move_NW.png");
	MoveL[4] = new ObImage(L"Charizard/Charizard_move_W.png");
	MoveL[5] = new ObImage(L"Charizard/Charizard_move_SW.png");
	MoveL[6] = new ObImage(L"Charizard/Charizard_move_S.png");
	MoveL[7] = new ObImage(L"Charizard/Charizard_move_SE.png");

	AttackL[0] = new ObImage(L"Charizard/Charizard_special_E.png");
	AttackL[1] = new ObImage(L"Charizard/Charizard_special_NE.png");
	AttackL[2] = new ObImage(L"Charizard/Charizard_special_N.png");
	AttackL[3] = new ObImage(L"Charizard/Charizard_special_NW.png");
	AttackL[4] = new ObImage(L"Charizard/Charizard_special_W.png");
	AttackL[5] = new ObImage(L"Charizard/Charizard_special_SW.png");
	AttackL[6] = new ObImage(L"Charizard/Charizard_special_S.png");
	AttackL[7] = new ObImage(L"Charizard/Charizard_special_SE.png");


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
		AttackS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

		MoveL[i]->SetParentT(*Cen);
		MoveL[i]->scale.x = MoveL[i]->imageSize.x / 3.0f;
		MoveL[i]->scale.y = MoveL[i]->imageSize.y;
		MoveL[i]->maxFrame.x = 3;
		MoveL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.8f);

		AttackL[i]->SetParentT(*Cen);
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 2;
		AttackL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.25f);

	}

	Range = new ObCircle;
	Range->SetParentT(*Cen);
	Range->scale = Vector2(500.0f, 500.0f);
	Range->isFilled = false;

	Select = new ObCircle;
	Select->SetParentT(*Cen);
	Select->scale = Vector2(50.0f, 50.0f);
	Select->isFilled = false;

	//Cen->SetWorldPosY(-200.0f);

	FireEffect = new ObImage(L"Charizard/Charizard_special_fire.png");
	FireEffect->SetParentRT(*Cen);
	FireEffect->scale.x = FireEffect->imageSize.x /2 ;
	FireEffect->scale.y = FireEffect->imageSize.y *0.8f;
	FireEffect->maxFrame.x = 5;
	FireEffect->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	FireEffect->SetLocalPosX(150.0f);
	FireEffect->color = Color(0.5f, 0.5f, 0.5f, 0.35f);

	BreathHit = new ObRect;
	BreathHit->SetParentRT(*Cen);
	BreathHit->scale.x = FireEffect->imageSize.x / 3;
	BreathHit->scale.y = FireEffect->imageSize.y * 0.4f;
	BreathHit->SetLocalPosX(150.0f);
	BreathHit->isFilled = false;



	AtType = TYPE::FireAttack;

	NormalSp = 0.5f;
	FastSp = 0.2f;
	SlowSp = 1.5f;
	AtSp = NormalSp;

	AtPw = 10;

}

Charmander::~Charmander()
{
}

void Charmander::Release()
{
}

void Charmander::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 3.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;

	}


	if (isShooting&&Evolved)
	{
		FireEffect->isVisible = true;
	}
	else
	{
		FireEffect->isVisible = false;
	}

	BreathHit->Update();
	FireEffect->Update();
	Tower::Update();
}

void Charmander::LateUpdate()
{
}

void Charmander::Render()
{
	//BreathHit->Render();
	FireEffect->Render();
	Tower::Render();
}
