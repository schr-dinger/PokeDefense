#include "stdafx.h"

Turtwig::Turtwig()
{
	//Cen = new GameObject;

	MoveS[0] = new ObImage(L"Turtwig/Turtwig_idle_E.png");
	MoveS[1] = new ObImage(L"Turtwig/Turtwig_idle_NE.png");
	MoveS[2] = new ObImage(L"Turtwig/Turtwig_idle_N.png");
	MoveS[3] = new ObImage(L"Turtwig/Turtwig_idle_NW.png");
	MoveS[4] = new ObImage(L"Turtwig/Turtwig_idle_W.png");
	MoveS[5] = new ObImage(L"Turtwig/Turtwig_idle_SW.png");
	MoveS[6] = new ObImage(L"Turtwig/Turtwig_idle_S.png");
	MoveS[7] = new ObImage(L"Turtwig/Turtwig_idle_SE.png");

	AttackS[0] = new ObImage(L"Turtwig/Turtwig_att_E.png");
	AttackS[1] = new ObImage(L"Turtwig/Turtwig_att_NE.png");
	AttackS[2] = new ObImage(L"Turtwig/Turtwig_att_N.png");
	AttackS[3] = new ObImage(L"Turtwig/Turtwig_att_NW.png");
	AttackS[4] = new ObImage(L"Turtwig/Turtwig_att_W.png");
	AttackS[5] = new ObImage(L"Turtwig/Turtwig_att_SW.png");
	AttackS[6] = new ObImage(L"Turtwig/Turtwig_att_S.png");
	AttackS[7] = new ObImage(L"Turtwig/Turtwig_att_SE.png");

	MoveL[0] = new ObImage(L"Torterra/Torterra_idle_E.png");
	MoveL[1] = new ObImage(L"Torterra/Torterra_idle_NE.png");
	MoveL[2] = new ObImage(L"Torterra/Torterra_idle_N.png");
	MoveL[3] = new ObImage(L"Torterra/Torterra_idle_NW.png");
	MoveL[4] = new ObImage(L"Torterra/Torterra_idle_W.png");
	MoveL[5] = new ObImage(L"Torterra/Torterra_idle_SW.png");
	MoveL[6] = new ObImage(L"Torterra/Torterra_idle_S.png");
	MoveL[7] = new ObImage(L"Torterra/Torterra_idle_SE.png");

	AttackL[0] = new ObImage(L"Torterra/Torterra_idle_E.png");
	AttackL[1] = new ObImage(L"Torterra/Torterra_idle_NE.png");
	AttackL[2] = new ObImage(L"Torterra/Torterra_idle_N.png");
	AttackL[3] = new ObImage(L"Torterra/Torterra_idle_NW.png");
	AttackL[4] = new ObImage(L"Torterra/Torterra_idle_W.png");
	AttackL[5] = new ObImage(L"Torterra/Torterra_idle_SW.png");
	AttackL[6] = new ObImage(L"Torterra/Torterra_idle_S.png");
	AttackL[7] = new ObImage(L"Torterra/Torterra_idle_SE.png");


	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->SetParentT(*Cen);
		MoveS[i]->scale.x = MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = MoveS[i]->imageSize.y;
		MoveS[i]->maxFrame.x = 3;
		MoveS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.4f);

		AttackS[i]->SetParentT(*Cen);
		AttackS[i]->scale.x = AttackS[i]->imageSize.x / 2.0f;
		AttackS[i]->scale.y = AttackS[i]->imageSize.y;
		AttackS[i]->maxFrame.x = 2;
		AttackS[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

		MoveL[i]->SetParentT(*Cen);
		MoveL[i]->scale.x = MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = MoveL[i]->imageSize.y;
		MoveL[i]->maxFrame.x = 2;
		MoveL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.8f);

		AttackL[i]->SetParentT(*Cen);
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 2;
		AttackL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);

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

	Earthquake = new ObImage(L"Torterra/special_earthquake_floor.png");
	Earthquake->SetParentT(*Cen);
	Earthquake->scale.x = Earthquake->imageSize.x/2;
	Earthquake->scale.y = Earthquake->imageSize.y/2;
	Earthquake->color = Color(0.5f, 0.5f, 0.5f, 0.35f);
	Earthquake->isVisible = false;


	AtType = TYPE::GrassAttack;

	NormalSp = 0.5f;
	FastSp = 0.2f;
	SlowSp = 1.5f;
	AtSp = NormalSp;

	AtPw = 10;

}

Turtwig::~Turtwig()
{
}

void Turtwig::Release()
{
}

void Turtwig::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 2.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 2.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;

	}


	if (Evolved)
	{
		QuakeTimer += DELTA;
		if (QuakeTimer > 9.0f && QuakeTimer < 10.0f)
		{
			isJumping = true;
		}
		else if (QuakeTimer > 10.0f && QuakeTimer < 12.0f)
		{
			isJumping = false;
			gravity = 0.0f;
			isQuaking = true;

		}
		else if (QuakeTimer > 12.0f)
		{
			isQuaking = false;
			QuakeTimer = 0.0f;
		}
	}

	if (isJumping)
	{
		gravity += 800.0f*DELTA;
		for (int i = 0; i < 8; i++)
		{
			MoveL[i]->MoveLocalPos((UP * 400.0f  + DOWN *gravity )* DELTA);
			AttackL[i]->MoveLocalPos((UP * 400.0f + DOWN * gravity )* DELTA);

		}
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			MoveL[i]->SetWorldPos(Cen->GetWorldPos());
			AttackL[i]->SetWorldPos(Cen->GetWorldPos());

		}


	}

	if (isQuaking)
	{
		Earthquake->isVisible = true;
	}
	else
	{
		Earthquake->isVisible = false;
	}



	Earthquake->Update();
	Tower::Update();
}

void Turtwig::LateUpdate()
{
}

void Turtwig::Render()
{
	Earthquake->Render();
	Tower::Render();
}
