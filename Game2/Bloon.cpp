#include "stdafx.h"

Bloon::Bloon()
{
	Cen = new GameObject;
	Cen->SetWorldPos(StartP);

	for (int i = 0; i < 8; i++)
	{
		Move[i] = NULL;
		Hurt[i] = NULL;
	}

	
	BlHit = new ObCircle;
	BlHit->SetParentT(*Cen);
	BlHit->scale = Vector2(50.0f, 50.0f);
	BlHit->isFilled = false;

	FullHpBar = new ObRect;
	FullHpBar->SetParentT(*Cen);
	FullHpBar->scale = Vector2(50.0f, 5.0f);
	FullHpBar->isFilled = false;
	FullHpBar->pivot = OFFSET_L;
	FullHpBar->MoveLocalPos(Vector2(-25.0f, 30.0f));
	FullHpBar->color = Color(0.0f, 0.0f, 0.0f, 1.0f);

	RealHpBar = new ObRect;
	RealHpBar->SetParentT(*Cen);
	RealHpBar->MoveLocalPos(Vector2(-25.0f, 30.0f));
	RealHpBar->pivot = OFFSET_L;
	RealHpBar->scale = Vector2(50.0f, 5.0f);
	RealHpBar->color = Color(128.0f / 256.0f, 128.0f / 256.0f, 128.0f / 256.0f, 1.0f);

	BurnEffect = new ObImage(L"Effect/Burning.png");	
	BurnEffect->SetParentT(*Cen);
	BurnEffect->scale.x = BurnEffect->imageSize.x / 6;
	BurnEffect->scale.y = BurnEffect->imageSize.y;
	BurnEffect->maxFrame.x = 6;
	BurnEffect->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	BurnEffect->SetLocalPosY(10.0f);
	BurnEffect->color = Color(0.5f, 0.5f, 0.5f, 0.45f);
	BurnEffect->isVisible = false;

	DefenseDown = new ObImage(L"Effect/StatusEffectIcon_DefenseDown.png");
	DefenseDown->scale = DefenseDown->imageSize * 0.5f;
	DefenseDown->SetParentT(*Cen);
	DefenseDown->SetLocalPos(Vector2(30.0f, 20.0f));
	DefenseDown->isVisible = false;


}

Bloon::~Bloon()
{
}

void Bloon::Release()
{
}

void Bloon::Update()
{

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
	ratio = -(Cen->GetWorldPos().y) / 650.0f + 2;

	if (Health < 1)
	{
		Dead = true;
	}
	else
	{
		//Dead = false;
	}

	//Hp Bar
	RealHpBar->scale = Vector2(50.0f*Health/FullHealth, 5.0f);
	RealHpBar->scale.x = Utility::Saturate(RealHpBar->scale.x, 0.0f, 50.0f);

	//길찾기
	if (Go)
	{
		if (Calculate)
		{
			//   출발점, 도착점
			Int2 sour, dest;
			//찾았는가?
			bool isFind;
			isFind = map->WorldPosToTileIdx(Cen->GetWorldPos(), sour);
			isFind &= map->WorldPosToTileIdx(EndP, dest);

			if (isFind)
			{
				if (map->PathFinding(sour, dest, Way))
				{
					//길 사이즈만큼 반복
					g = 0.0f;
					Sour = Cen->GetWorldPos();
					Way.pop_back(); //출발지 빼기
					Dest = Way.back()->Pos;
				}
			}
			Calculate = false;
		}

		//가야될 길이 존재할 때
		if (!Way.empty())
		{
			Cen->SetWorldPos(StartP);
			Cen->SetWorldPos(Utility::Lerp(Sour, Dest, g));
			g += DELTA * Speed;
			Cen->rotation = Utility::DirToRadian(Dest - Sour);

			//도착지를 지났을때
			if (g > 1.0f)
			{
				g = 0.0f;
				Sour = Dest;
				Way.pop_back(); //맨뒷길 빼기

				if (!Way.empty())
					Dest = Way.back()->Pos;
			}
		}

	}

	//깜빡깜빡
	if (Dead)
	{
		Go = false;
		Way.clear();
		isBurning = false;
		g = 0.0f;
		DeadTimer += DELTA;
		if (DeadTimer < 0.2f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
			}
		}
		else if(DeadTimer > 0.2f && DeadTimer < 0.4f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			}
		}
		else if (DeadTimer > 0.4f && DeadTimer < 0.6f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
			}
		}
		else if (DeadTimer > 0.8f && DeadTimer < 1.0f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			}

		}
		else if (DeadTimer > 1.2f && DeadTimer < 1.4f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
			}

		}
		else if (DeadTimer > 1.6f && DeadTimer < 1.8f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.5f);
			}

		}
		else if (DeadTimer > 1.8f && DeadTimer < 2.0f)
		{
			for (int i = 0; i < 8; i++)
			{
				Hurt[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);
				Hurt[i]->isVisible = false;
			}
			Cen->SetWorldPos(Vector2(5000.0f, 0.0f));

		}
	}

	//화상
	if (isBurning)
	{
		BurnEffect->isVisible = true;
		BurnTimer += DELTA;
		Health -= DELTA * 5.0f;
		if (BurnTimer > 10.0f)
		{
			BurnEffect->isVisible = false;
			BurnTimer = 0.0f;
			isBurning = false;
		}
	}

	if (DefenseLowered)
	{
		DefenseDown->isVisible = true;
		DefenseTimer += DELTA;

		Defense = 1.2f;

		if (DefenseTimer > 3.0f)
		{
			DefenseDown->isVisible = false;
			DefenseTimer = 0.0f;
			DefenseLowered = false;
		}

	}
	else
	{
		Defense = 1.0f;
	}



	Cen->Update();
	map->Update();
	for (int i = 0; i < 8; i++)
	{
		Move[i]->Update();
		Hurt[i]->Update();
	}
	BlHit->Update();
	FullHpBar->Update();
	RealHpBar->Update();
	BurnEffect->Update();
	DefenseDown->Update();
}

void Bloon::LateUpdate()
{
}

void Bloon::Render()
{
	if (Go)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->Render();
		}
	}
	

	for (int i = 0; i < 8; i++)
	{
		Hurt[i]->Render();
	}

	BlHit->Render();
	FullHpBar->Render();
	RealHpBar->Render();
	BurnEffect->Render();
	DefenseDown->Render();

}

void Bloon::E()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible=false;
			Hurt[i]->isVisible=false;
		}

		Hurt[0]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[0]->isVisible = true;

	}

}

void Bloon::NE()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[1]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[1]->isVisible = true;

	}

}

void Bloon::N()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[2]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[2]->isVisible = true;

	}

}

void Bloon::NW()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[3]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[3]->isVisible = true;

	}

}

void Bloon::W()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[4]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[4]->isVisible = true;

	}

}

void Bloon::SW()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[5]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[5]->isVisible = true;

	}

}

void Bloon::S()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[6]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[6]->isVisible = true;

	}

}

void Bloon::SE()
{
	if (Dead)
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Hurt[7]->isVisible = true;
	}
	else
	{
		for (int i = 0; i < 8; i++)
		{
			Move[i]->isVisible = false;
			Hurt[i]->isVisible = false;
		}

		Move[7]->isVisible = true;

	}

}

void Bloon::Reset()
{
	Go = false;
	Cen->SetWorldPos(StartP);
	Health = FullHealth;
	Dead = false;
	DeadTimer = 0.0f;
	Calculate = true;
	isBurning = false;
}
