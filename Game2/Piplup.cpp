#include "stdafx.h"

Piplup::Piplup()
{
	//Cen = new GameObject;

	MoveS[0] = new ObImage(L"Piplup/Piplup_idle_E.png");
	MoveS[1] = new ObImage(L"Piplup/Piplup_idle_NE.png");
	MoveS[2] = new ObImage(L"Piplup/Piplup_idle_N.png");
	MoveS[3] = new ObImage(L"Piplup/Piplup_idle_NW.png");
	MoveS[4] = new ObImage(L"Piplup/Piplup_idle_W.png");
	MoveS[5] = new ObImage(L"Piplup/Piplup_idle_SW.png");
	MoveS[6] = new ObImage(L"Piplup/Piplup_idle_S.png");
	MoveS[7] = new ObImage(L"Piplup/Piplup_idle_SE.png");

	AttackS[0] = new ObImage(L"Piplup/Piplup_attack_E.png");
	AttackS[1] = new ObImage(L"Piplup/Piplup_attack_NE.png");
	AttackS[2] = new ObImage(L"Piplup/Piplup_attack_N.png");
	AttackS[3] = new ObImage(L"Piplup/Piplup_attack_NW.png");
	AttackS[4] = new ObImage(L"Piplup/Piplup_attack_W.png");
	AttackS[5] = new ObImage(L"Piplup/Piplup_attack_SW.png");
	AttackS[6] = new ObImage(L"Piplup/Piplup_attack_S.png");
	AttackS[7] = new ObImage(L"Piplup/Piplup_attack_SE.png");

	MoveL[0] = new ObImage(L"Empoleon/Empoleon_idle_E.png");
	MoveL[1] = new ObImage(L"Empoleon/Empoleon_idle_NE.png");
	MoveL[2] = new ObImage(L"Empoleon/Empoleon_idle_N.png");
	MoveL[3] = new ObImage(L"Empoleon/Empoleon_idle_NW.png");
	MoveL[4] = new ObImage(L"Empoleon/Empoleon_idle_W.png");
	MoveL[5] = new ObImage(L"Empoleon/Empoleon_idle_SW.png");
	MoveL[6] = new ObImage(L"Empoleon/Empoleon_idle_S.png");
	MoveL[7] = new ObImage(L"Empoleon/Empoleon_idle_SE.png");

	AttackL[0] = new ObImage(L"Empoleon/Empoleon_attack_E.png");
	AttackL[1] = new ObImage(L"Empoleon/Empoleon_attack_NE.png");
	AttackL[2] = new ObImage(L"Empoleon/Empoleon_attack_N.png");
	AttackL[3] = new ObImage(L"Empoleon/Empoleon_attack_NW.png");
	AttackL[4] = new ObImage(L"Empoleon/Empoleon_attack_W.png");
	AttackL[5] = new ObImage(L"Empoleon/Empoleon_attack_SW.png");
	AttackL[6] = new ObImage(L"Empoleon/Empoleon_attack_S.png");
	AttackL[7] = new ObImage(L"Empoleon/Empoleon_attack_SE.png");



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
		MoveL[i]->scale.x = MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = MoveL[i]->imageSize.y;
		MoveL[i]->maxFrame.x = 2;
		MoveL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackL[i]->SetParentT(*Cen);
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 3.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 3;
		AttackL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

	}
	//special
	//IceFloor = new ObImage(L"Empoleon/special_ice_floor2.png");
	//IceFloor->SetParentT(*Cen);
	//IceFloor->scale.x = IceFloor->imageSize.x * 1.5f;
	//IceFloor->scale.y = IceFloor->imageSize.y * 1.5f; 
	//IceFloor->SetLocalPosY(-15.0f);
	//IceFloor->isVisible = false;

	IceParticle = new ObImage(L"Empoleon/special_ice_particle.png");
	IceParticle->SetParentT(*Cen);
	IceParticle->scale.x = IceParticle->imageSize.x / 5.0f;
	IceParticle->scale.y = IceParticle->imageSize.y;
	IceParticle->maxFrame.x = 5;
	IceParticle->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	IceParticle->color = Color(0.5f, 0.5f, 0.5f, 0.4f);
	IceParticle->isVisible = false;


	IceHit = new ObCircle;
	IceHit->SetParentT(*Cen);
	IceHit->scale = Vector2(200.0f,200.0f);
	IceHit->isFilled = false;






	Range = new ObCircle;
	Range->SetParentT(*Cen);
	Range->scale = Vector2(500.0f, 500.0f);
	Range->isFilled = false;
	
	Select = new ObCircle;
	Select->SetParentT(*Cen);
	Select->scale = Vector2(50.0f, 50.0f);
	Select->isFilled = false;

	AtType = TYPE::WaterAttack;

	NormalSp = 0.5f;
	FastSp = 0.2f;
	SlowSp = 1.5f;
	AtSp = NormalSp;

	AtPw = 10;

}

Piplup::~Piplup()
{
}

void Piplup::Release()
{
}

void Piplup::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 3.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;
	}

	if (Evolved)
	{
		//IceFloor->isVisible = true;
		IceParticle->isVisible = true;
	}



	//IceFloor->Update();
	IceParticle->Update();
	IceHit->Update();
	Tower::Update();

}

void Piplup::LateUpdate()
{
}

void Piplup::Render()
{
	//IceFloor->Render();
	//IceHit->Render();
	Tower::Render();
	IceParticle->Render();

}
