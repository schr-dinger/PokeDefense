#include "stdafx.h"

Bulbasaur::Bulbasaur()
{
	//Cen = new GameObject;

	MoveS[0] = new ObImage(L"Bulbasaur/Bulbasaur_move_E.png");
	MoveS[1] = new ObImage(L"Bulbasaur/Bulbasaur_move_NE.png");
	MoveS[2] = new ObImage(L"Bulbasaur/Bulbasaur_move_N.png");
	MoveS[3] = new ObImage(L"Bulbasaur/Bulbasaur_move_NW.png");
	MoveS[4] = new ObImage(L"Bulbasaur/Bulbasaur_move_W.png");
	MoveS[5] = new ObImage(L"Bulbasaur/Bulbasaur_move_SW.png");
	MoveS[6] = new ObImage(L"Bulbasaur/Bulbasaur_move_S.png");
	MoveS[7] = new ObImage(L"Bulbasaur/Bulbasaur_move_SE.png");

	AttackS[0] = new ObImage(L"Bulbasaur/Bulbasaur_move_E.png");
	AttackS[1] = new ObImage(L"Bulbasaur/Bulbasaur_move_NE.png");
	AttackS[2] = new ObImage(L"Bulbasaur/Bulbasaur_move_N.png");
	AttackS[3] = new ObImage(L"Bulbasaur/Bulbasaur_move_NW.png");
	AttackS[4] = new ObImage(L"Bulbasaur/Bulbasaur_move_W.png");
	AttackS[5] = new ObImage(L"Bulbasaur/Bulbasaur_move_SW.png");
	AttackS[6] = new ObImage(L"Bulbasaur/Bulbasaur_move_S.png");
	AttackS[7] = new ObImage(L"Bulbasaur/Bulbasaur_move_SE.png");

	MoveL[0] = new ObImage(L"Venusaur/Venusaur_move_E.png");
	MoveL[1] = new ObImage(L"Venusaur/Venusaur_move_NE.png");
	MoveL[2] = new ObImage(L"Venusaur/Venusaur_move_N.png");
	MoveL[3] = new ObImage(L"Venusaur/Venusaur_move_NW.png");
	MoveL[4] = new ObImage(L"Venusaur/Venusaur_move_W.png");
	MoveL[5] = new ObImage(L"Venusaur/Venusaur_move_SW.png");
	MoveL[6] = new ObImage(L"Venusaur/Venusaur_move_S.png");
	MoveL[7] = new ObImage(L"Venusaur/Venusaur_move_SE.png");

	AttackL[0] = new ObImage(L"Venusaur/Venusaur_move_E.png");
	AttackL[1] = new ObImage(L"Venusaur/Venusaur_move_NE.png");
	AttackL[2] = new ObImage(L"Venusaur/Venusaur_move_N.png");
	AttackL[3] = new ObImage(L"Venusaur/Venusaur_move_NW.png");
	AttackL[4] = new ObImage(L"Venusaur/Venusaur_move_W.png");
	AttackL[5] = new ObImage(L"Venusaur/Venusaur_move_SW.png");
	AttackL[6] = new ObImage(L"Venusaur/Venusaur_move_S.png");
	AttackL[7] = new ObImage(L"Venusaur/Venusaur_move_SE.png");


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
		AttackL[i]->scale.x = AttackL[i]->imageSize.x / 3.0f;
		AttackL[i]->scale.y = AttackL[i]->imageSize.y;
		AttackL[i]->maxFrame.x = 3;
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
	//Cen->SetWorldPosY(-200.0f);



	AtType = TYPE::GrassAttack;

	NormalSp = 0.5f;
	FastSp = 0.2f;
	SlowSp = 1.5f;
	AtSp = NormalSp;

	AtPw = 10;

	for (int i = 0; i < RayN; i++)
	{
		FlowerH[i] = new ObCircle;
		FlowerH[i]->scale = Vector2(40.0f, 40.0f);
		FlowerH[i]->isFilled = false;


		Vines[i] = new ObImage(L"Bulbasaur/Vines.png");
		Vines[i]->SetParentT(*Cen);
		Vines[i]->scale.x = Vines[i]->imageSize.x;
		Vines[i]->scale.y = Vines[i]->imageSize.y * 0.1f;

		Vines[i]->pivot = OFFSET_L;
		Vines[i]->rotation = i * 360.0f / RayN * ToRadian;

		Vines[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);

		Flowers[i] = new ObImage(L"Venusaur/Flower.png");
		Flowers[i]->SetParentRT(*FlowerH[i]);
		Flowers[i]->scale.x = Flowers[i]->imageSize.x / 6.0f;
		Flowers[i]->scale.y = Flowers[i]->imageSize.y;
		Flowers[i]->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		Flowers[i]->color = Color(0.5f, 0.5f, 0.5f, 0.3f);

	}

}

Bulbasaur::~Bulbasaur()
{
}

void Bulbasaur::Release()
{
}

void Bulbasaur::Update()
{
	for (int i = 0; i < 8; i++)
	{
		MoveS[i]->scale.x = ratio * MoveS[i]->imageSize.x / 3.0f;
		MoveS[i]->scale.y = ratio * MoveS[i]->imageSize.y;

		AttackS[i]->scale.x = ratio * AttackS[i]->imageSize.x / 3.0f;
		AttackS[i]->scale.y = ratio * AttackS[i]->imageSize.y;

		MoveL[i]->scale.x = ratio * MoveL[i]->imageSize.x / 3.0f;
		MoveL[i]->scale.y = ratio * MoveL[i]->imageSize.y;

		AttackL[i]->scale.x = ratio * AttackL[i]->imageSize.x / 3.0f;
		AttackL[i]->scale.y = ratio * AttackL[i]->imageSize.y;

	}

	//Ray casting?

	map->Update();

	if (Evolved && !Casted)
	{
		castRays(RayN);
		Casted = true;

	}


	for (int i = 0; i < RayN; i++)
	{
		FlowerH[i]->SetWorldPos(Flowerpos[i]);
		FlowerH[i]->Update();
		Vines[i]->scale.x = (Flowerpos[i] - Cen->GetWorldPos()).Length();
		Vines[i]->Update();
		Flowers[i]->Update();

	}



	Tower::Update();

}

void Bulbasaur::LateUpdate()
{
}

void Bulbasaur::Render()
{
	if (Evolved)
	{
		for (int i = 0; i < RayN; i++)
		{
			//FlowerH[i]->Render();
			//Vines[i]->Render();
			Flowers[i]->Render();
			Flowers[i]->maxFrame.x = 6;
		}

	}

	Tower::Render();

}

void Bulbasaur::castRays(int NumRays)
{
	for (int i = 0; i < NumRays; i++)
	{
		float rayX = cosf(i * 360.0f / NumRays * ToRadian);
		float rayY = sinf(i * 360.0f / NumRays * ToRadian);
		castRay(Cen->GetWorldPos(), rayX, rayY , i);

	}
}

void Bulbasaur::castRay(Vector2 pos, float rayDX, float rayDY , int j)
{
	float posX = static_cast<float>(pos.x);
	float posY = static_cast<float>(pos.y);
	//while (posX >= 0 && posX < map->scale.x  && posY >= 0 && posY < map->scale.y )
	//{
	while (posX < map->scale.x *130 && posY < map->scale.y * 90)
	{
		Int2 temp;
		map->WorldPosToTileIdx(Vector2(posX, posY), temp);
		if (map->GetTileState(temp) == 0)
		{
			Flowerpos[j] = Vector2(posX, posY);
			break;
		}

		posX += rayDX;
		posY += rayDY;
	}


}
