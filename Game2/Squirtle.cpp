#include "stdafx.h"

Squirtle::Squirtle()
{
	//Cen = new GameObject;

	MoveS[0] = new ObImage(L"Squirtle/Squirtle_move_E.png");
	MoveS[1] = new ObImage(L"Squirtle/Squirtle_move_NE.png");
	MoveS[2] = new ObImage(L"Squirtle/Squirtle_move_N.png");
	MoveS[3] = new ObImage(L"Squirtle/Squirtle_move_NW.png");
	MoveS[4] = new ObImage(L"Squirtle/Squirtle_move_W.png");
	MoveS[5] = new ObImage(L"Squirtle/Squirtle_move_SW.png");
	MoveS[6] = new ObImage(L"Squirtle/Squirtle_move_S.png");
	MoveS[7] = new ObImage(L"Squirtle/Squirtle_move_SE.png");

	AttackS[0] = new ObImage(L"Squirtle/Squirtle_move_E.png");
	AttackS[1] = new ObImage(L"Squirtle/Squirtle_move_NE.png");
	AttackS[2] = new ObImage(L"Squirtle/Squirtle_move_N.png");
	AttackS[3] = new ObImage(L"Squirtle/Squirtle_move_NW.png");
	AttackS[4] = new ObImage(L"Squirtle/Squirtle_move_W.png");
	AttackS[5] = new ObImage(L"Squirtle/Squirtle_move_SW.png");
	AttackS[6] = new ObImage(L"Squirtle/Squirtle_move_S.png");
	AttackS[7] = new ObImage(L"Squirtle/Squirtle_move_SE.png");

	MoveL[0] = new ObImage(L"Blastoise/Blastoise_move_E.png");
	MoveL[1] = new ObImage(L"Blastoise/Blastoise_move_NE.png");
	MoveL[2] = new ObImage(L"Blastoise/Blastoise_move_N.png");
	MoveL[3] = new ObImage(L"Blastoise/Blastoise_move_NW.png");
	MoveL[4] = new ObImage(L"Blastoise/Blastoise_move_W.png");
	MoveL[5] = new ObImage(L"Blastoise/Blastoise_move_SW.png");
	MoveL[6] = new ObImage(L"Blastoise/Blastoise_move_S.png");
	MoveL[7] = new ObImage(L"Blastoise/Blastoise_move_SE.png");

	AttackL[0] = new ObImage(L"Blastoise/Blastoise_move_E.png");
	AttackL[1] = new ObImage(L"Blastoise/Blastoise_move_NE.png");
	AttackL[2] = new ObImage(L"Blastoise/Blastoise_move_N.png");
	AttackL[3] = new ObImage(L"Blastoise/Blastoise_move_NW.png");
	AttackL[4] = new ObImage(L"Blastoise/Blastoise_move_W.png");
	AttackL[5] = new ObImage(L"Blastoise/Blastoise_move_SW.png");
	AttackL[6] = new ObImage(L"Blastoise/Blastoise_move_S.png");
	AttackL[7] = new ObImage(L"Blastoise/Blastoise_move_SE.png");


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
		MoveL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.8f);

		AttackL[i]->SetParentT(*Cen);
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 2.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 2;
		AttackL[i]->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

	}


	for (int i = 0; i < 3; i++)
	{
		BubbleHit[i] = new ObCircle;
		BubbleHit[i]->scale = Vector2(100.0f, 100.0f);
		BubbleHit[i]->isFilled = false;
		BubbleHit[i]->isVisible = true;

		Bubble[i] = new ObImage(L"Blastoise/Blastois_special_bubble.png");
		Bubble[i]->SetParentT(*BubbleHit[i]);
		Bubble[i]->scale.x = (Bubble[i]->imageSize.x / 5.0f) * 2.0f;
		Bubble[i]->scale.y = (Bubble[i]->imageSize.y) * 2.0f;
		Bubble[i]->maxFrame.x = 5;
		Bubble[i]->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
		Bubble[i]->isVisible = false;

	}
	//Bubble->isAxis = true;





	Range = new ObCircle;
	Range->SetParentT(*Cen);
	Range->scale = Vector2(500.0f, 500.0f);
	Range->isFilled = false;

	Select = new ObCircle;
	Select->SetParentT(*Cen);
	Select->scale = Vector2(50.0f, 50.0f);
	Select->isFilled = false;

	//Cen->SetWorldPosY(200.0f);


	AtType = TYPE::WaterAttack;

	NormalSp = 0.5f;
	FastSp = 0.2f;
	SlowSp = 1.5f;
	AtSp = NormalSp;

	AtPw = 10;

}

Squirtle::~Squirtle()
{
}

void Squirtle::Release()
{
}

void Squirtle::Update()
{
	for (int i = 0; i < 3; i++)
	{
		BubbleHit[i]->rotation = Cen->rotation;
	}
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


	if (Evolved&&isShooting)
	{
		BubbleTimer += DELTA;
		if (BubbleTimer > 3.0f)
		{
			ShootBubble1();
		}
		if (BubbleTimer > 6.0f)
		{
			ShootBubble2();
		}
		if (BubbleTimer > 9.0f)
		{
			ShootBubble3();
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (Bubble[i]->isVisible)
		{
			Vector2 velocity = Bubbledir[i] * 600.0f;
			BubbleHit[i]->MoveWorldPos(velocity * DELTA);
			BubbleHit[i]->Update();
		}
		else
		{
			BubbleHit[i]->SetWorldPos(Cen->GetWorldPos());
		}


		//º®Ãæµ¹
		if (BubbleHit[i]->GetWorldPos().x < CAM->position.x - app.GetHalfWidth()&&Evolved)
		{
			BubbleHit[i]->SetWorldPosX(CAM->position.x - app.GetHalfWidth());
			Bubbledir[i] = Vector2(cosf(3 * PI - Utility::DirToRadian(Bubbledir[i])), sinf(3 * PI - Utility::DirToRadian(Bubbledir[i])));
		}
		else if (BubbleHit[i]->GetWorldPos().x > CAM->position.x + app.GetHalfWidth() / 2 && Evolved)
		{
			BubbleHit[i]->SetWorldPosX(CAM->position.x + app.GetHalfWidth() / 2);
			Bubbledir[i] = Vector2(cosf(3 * PI - Utility::DirToRadian(Bubbledir[i])), sinf(3 * PI - Utility::DirToRadian(Bubbledir[i])));
		}

		if (BubbleHit[i]->GetWorldPos().y < CAM->position.y - app.GetHalfHeight() && Evolved) 
		{
			BubbleHit[i]->SetWorldPosY(CAM->position.y - app.GetHalfHeight());
			Bubbledir[i] = Vector2(cosf(2 * PI - Utility::DirToRadian(Bubbledir[i])), sinf(2 * PI - Utility::DirToRadian(Bubbledir[i])));
		}
		else if (BubbleHit[i]->GetWorldPos().y > CAM->position.y + app.GetHalfHeight() && Evolved)
		{
			BubbleHit[i]->SetWorldPosY(CAM->position.y + app.GetHalfHeight());
			Bubbledir[i] = Vector2(cosf(2 * PI - Utility::DirToRadian(Bubbledir[i])), sinf(2 * PI - Utility::DirToRadian(Bubbledir[i])));
		}


		BubbleHit[i]->Update();
		Bubble[i]->Update();

	}

	Tower::Update();

}

void Squirtle::LateUpdate()
{
}

void Squirtle::Render()
{
	for (int i = 0; i < 3; i++)
	{
		//BubbleHit[i]->Render();
		Bubble[i]->Render();
	}
	Tower::Render();
}

bool Squirtle::ShootBubble1()
{
	if (!Bubble[0]->isVisible)
	{
		Bubble[0]->isVisible = true;
		BubbleHit[0]->SetWorldPos(Cen->GetWorldPos());
		Bubbledir[0] = Cen->GetRight();
		return true;

	}

	return false;

}

bool Squirtle::ShootBubble2()
{
	if (!Bubble[1]->isVisible)
	{
		Bubble[1]->isVisible = true;
		BubbleHit[1]->SetWorldPos(Cen->GetWorldPos());
		Bubbledir[1] = Cen->GetRight();
		return true;

	}

	return false;
}

bool Squirtle::ShootBubble3()
{
	if (!Bubble[2]->isVisible)
	{
		Bubble[2]->isVisible = true;
		BubbleHit[2]->SetWorldPos(Cen->GetWorldPos());
		Bubbledir[2] = Cen->GetRight();
		return true;

	}

	return false;
}

