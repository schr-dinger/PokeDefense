#include "stdafx.h"

Tower::Tower()
{
	Cen = new GameObject;

	//mapT = new ObTileMap();
	//mapT->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	//mapT->file = "TileMap_poke_place.txt";
	//mapT->Load();
	//mapT->color = Color(0.5f, 0.5f, 0.5f, 0.2f);


	for (int i = 0; i < 8; i++)
	{
		MoveS[i] = NULL;
		AttackS[i] = NULL;
		MoveL[i] = NULL;
		AttackL[i] = NULL;
	}

	Range = new ObCircle;
	Range->SetParentT(*Cen);
	Range->scale = Vector2(500.0f, 500.0f);
	Range->isFilled = false;

	Select = new ObCircle;
	Select->SetParentT(*Cen);
	Select->scale = Vector2(50.0f, 50.0f);
	Select->isFilled = false;

	FireHit = new ObCircle;
	FireHit->isFilled = false;
	FireHit->SetWorldPos(Cen->GetWorldPos());
	FireHit->scale = Vector2(50.0f, 50.0f);
	FireHit->isVisible = false;

	FireA = new ObImage(L"Effect/FireAttack.png");
	GrassA = new ObImage(L"Effect/LeafAttack.png");
	WaterA = new ObImage(L"Effect/WaterAttack.png");

	FireA->SetParentT(*FireHit);
	FireA->scale.x = (FireA->imageSize.x / 4.0f) * 0.8f;
	FireA->scale.y = (FireA->imageSize.y) * 0.8f;
	FireA->maxFrame.x = 4;
	FireA->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	FireA->isVisible = false;

	GrassA->SetParentT(*FireHit);
	GrassA->scale.x = (GrassA->imageSize.x / 9.0f) * 3.0f;
	GrassA->scale.y = (GrassA->imageSize.y) * 3.0f;
	GrassA->maxFrame.x = 9;
	GrassA->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	GrassA->isVisible = false;

	WaterA->SetParentT(*FireHit);
	WaterA->scale.x = (WaterA->imageSize.x / 4.0f) * 0.25f;
	WaterA->scale.y = (WaterA->imageSize.y) * 0.25f;
	WaterA->maxFrame.x = 4;
	WaterA->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	WaterA->isVisible = false;

	Cen->SetWorldPosX(-2000.0f);
	Cen->SetWorldPosY(-2000.0f);

	PowerUp = new ObImage(L"Effect/StatusEffectIcon_AttackUp.png");
	PowerUp->scale = PowerUp->imageSize * 0.5f;
	PowerUp->SetParentT(*Cen);
	PowerUp->SetLocalPos(Vector2(30.0f, 20.0f));
	PowerUp->isVisible = false;

}

Tower::~Tower()
{
}

void Tower::Release()
{
}

void Tower::Update()
{
	//mapT->WorldPosToTileIdx(INPUT->GetMouseWorldPos(), tile);
	

	//로테이션 리셋
	if (Cen->rotation > 2 * PI)
	{
		Cen->rotation -= 2 * PI;
	}
	if (Cen->rotation < 0)
	{
		Cen->rotation += 2 * PI;
	}

	//로테이션에 따른 상태
	if (Cen->rotation >= 0.0f * ToRadian && Cen->rotation < 22.5f * ToRadian)
	{
		state = NEWS::E;
	}
	else if (Cen->rotation >= 22.5f * ToRadian && Cen->rotation < 67.5f * ToRadian)
	{
		state = NEWS::NE;
	}
	else if (Cen->rotation >= 67.5f * ToRadian && Cen->rotation < 112.5f * ToRadian)
	{
		state = NEWS::N;
	}
	else if (Cen->rotation >= 112.5f * ToRadian && Cen->rotation < 157.5f * ToRadian)
	{
		state = NEWS::NW;
	}
	else if (Cen->rotation >= 157.5f * ToRadian && Cen->rotation < 202.5f * ToRadian)
	{
		state = NEWS::W;
	}
	else if (Cen->rotation >= 202.5f * ToRadian && Cen->rotation < 247.5f * ToRadian)
	{
		state = NEWS::SW;
	}
	else if (Cen->rotation >= 247.5f * ToRadian && Cen->rotation < 292.5f * ToRadian)
	{
		state = NEWS::S;
	}
	else if (Cen->rotation >= 292.5f * ToRadian && Cen->rotation < 337.5f * ToRadian)
	{
		state = NEWS::SE;
	}
	else if (Cen->rotation >= 337.5f * ToRadian && Cen->rotation < 360.0f * ToRadian)
	{
		state = NEWS::E;
	}

	switch (state)
	{
	case NEWS::E:
		E();
		break;
	case NEWS::NE:
		NE();
		break;
	case NEWS::N:
		N();
		break;
	case NEWS::NW:
		NW();
		break;
	case NEWS::W:
		W();
		break;
	case NEWS::SW:
		SW();
		break;
	case NEWS::S:
		S();
		break;
	case NEWS::SE:
		SE();
		break;
	}

	//크기 조정
	ratio = -(Cen->GetWorldPos().y) / 650.0f + 3;

	//드래그
	if (INPUT->KeyPress(VK_LBUTTON) && Select->Intersect(INPUT->GetMouseWorldPos()) && !Placed )
	{
		Cen->SetWorldPos(INPUT->GetMouseWorldPos());
	}

	//if (INPUT->KeyUp(VK_LBUTTON) && Select->Intersect(INPUT->GetMouseWorldPos()))
	//{
	//	if (mapT->GetTileState(tile) == 2)
	//	{
	//		Placed = true;
	//	}
	//	else
	//	{
	//		Cen->MoveWorldPos(Vector2(3000.0f, 0.0f));
	//	}
	//}


	//공격
	if (!Target.empty())
	{
		if (Range->Intersect(Target.front()->Cen) && !Target.front()->Dead && Placed)
		{
			isShooting = true;
			Cen->rotation = Utility::DirToRadian(Target.front()->Cen->GetWorldPos() - Cen->GetWorldPos());

		}
		else
		{
			Target.pop();
			isShooting = false;
		}
	}

	if (isShooting)
	{
		AtTimer += DELTA;
		if (AtTimer > AtSp)
		{
			switch (AtType)
			{
			case TYPE::FireAttack:
				Cen->Update();
				ShootFire();
				break;
			case TYPE::GrassAttack:
				Cen->Update();
				ShootGrass();

				break;
			case TYPE::WaterAttack:
				Cen->Update();
				ShootWater();
				break;
			}
			AtTimer = 0.0f;
		}

	}


	if (FireHit->isVisible)
	{
		Vector2 velocity = dir * 900.0f;
		FireHit->MoveWorldPos(velocity* DELTA);
		FireHit->Update();
		//거리비교
		Vector2 dis = FireHit->GetWorldPos() - Cen->GetWorldPos();
		if (dis.Length() > 500.0f)
		{
			FireHit->isVisible = false;
			FireA->isVisible = false;
			GrassA->isVisible = false;
			WaterA->isVisible = false;
		}

	}

	
	if (PowerUped)
	{
		PowerUp->isVisible = true;
		PowerUpTimer += DELTA;

		PowerMulti = 2.0f;

		if (PowerUpTimer > 5.0f)
		{
			PowerUp->isVisible = false;
			PowerUpTimer = 0.0f;
			PowerUped = false;
		}

	}
	else
	{
		PowerMulti = 1.0f;
	}


	if (Select->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyPress(VK_RBUTTON))
	{
		RangeCheck = true;
	}
	else
	{
		RangeCheck = false;
	}

	Cen->Update();
	//mapT->Update();


	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->Update();
		AttackS[i]->Update();
		MoveL[i]->Update();
		AttackL[i]->Update();

	}

	Range->Update();
	Select->Update();
	FireHit->Update();
	FireA->Update();
	GrassA->Update();
	WaterA->Update();
	PowerUp->Update();
}

void Tower::LateUpdate()
{

}

void Tower::Render()
{
	FireHit->Render();
	FireA->Render();
	GrassA->Render();
	WaterA->Render();


	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->Render();
		AttackS[i]->Render();
		MoveL[i]->Render();
		AttackL[i]->Render();

	}

	if (!Placed)
	{
		Range->Render();
	}

	if (RangeCheck)
	{
		Range->Render();
	}

	//Select->Render();
	PowerUp->Render();


}

void Tower::E()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[0]->isVisible = true;
		}
		else
		{
			AttackS[0]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[0]->isVisible = true;
		}
		else
		{
			MoveS[0]->isVisible = true;
		}

	}
}

void Tower::NE()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[1]->isVisible = true;
		}
		else
		{
			AttackS[1]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[1]->isVisible = true;
		}
		else
		{
			MoveS[1]->isVisible = true;
		}

	}

}

void Tower::N()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[2]->isVisible = true;
		}
		else
		{
			AttackS[2]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[2]->isVisible = true;
		}
		else
		{
			MoveS[2]->isVisible = true;
		}

	}

}

void Tower::NW()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[3]->isVisible = true;
		}
		else
		{
			AttackS[3]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[3]->isVisible = true;
		}
		else
		{
			MoveS[3]->isVisible = true;
		}

	}
}

void Tower::W()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[4]->isVisible = true;
		}
		else
		{
			AttackS[4]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[4]->isVisible = true;
		}
		else
		{
			MoveS[4]->isVisible = true;
		}

	}
}

void Tower::SW()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[5]->isVisible = true;
		}
		else
		{
			AttackS[5]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[5]->isVisible = true;
		}
		else
		{
			MoveS[5]->isVisible = true;
		}

	}

}

void Tower::S()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[6]->isVisible = true;
		}
		else
		{
			AttackS[6]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[6]->isVisible = true;
		}
		else
		{
			MoveS[6]->isVisible = true;
		}

	}
}

void Tower::SE()
{
	if (isShooting)
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			AttackL[7]->isVisible = true;
		}
		else
		{
			AttackS[7]->isVisible = true;
		}

	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			AttackS[i]->isVisible = false;
			MoveS[i]->isVisible = false;
			AttackL[i]->isVisible = false;
			MoveL[i]->isVisible = false;

		}

		if (Evolved)
		{
			MoveL[7]->isVisible = true;
		}
		else
		{
			MoveS[7]->isVisible = true;
		}

	}
}

bool Tower::ShootFire()
{
	if (!FireHit->isVisible)
	{
		FireHit->isVisible = true;
		FireA->isVisible = true;
		FireHit->SetWorldPos(Cen->GetWorldPos());
		dir = Cen->GetRight();
		return true;

	}

	return false;
}

bool Tower::ShootGrass()
{
	if (!FireHit->isVisible)
	{
		FireHit->isVisible = true;
		GrassA->isVisible = true;
		FireHit->SetWorldPos(Cen->GetWorldPos());
		dir = Cen->GetRight();
		return true;

	}

	return false;
}

bool Tower::ShootWater()
{
	if (!FireHit->isVisible)
	{
		FireHit->isVisible = true;
		WaterA->isVisible = true;
		FireHit->SetWorldPos(Cen->GetWorldPos());
		dir = Cen->GetRight();
		return true;

	}

	return false;
}

