#include "stdafx.h"

Ui::Ui()
{
	BaseUi = new ObImage(L"Ui/Ui_edit.png");
	BaseUi->scale.x = BaseUi->imageSize.x * 1.2f;
	BaseUi->scale.y = BaseUi->imageSize.y;
	BaseUi->SetWorldPosX(534.0f);

	SelectedPos[0] = Vector2(456.0f, 170.0f);
	SelectedPos[1] = Vector2(581.0f, 170.0f);
	SelectedPos[2] = Vector2(456.0f, 0.0f);
	SelectedPos[3] = Vector2(581.0f, 0.0f);
	SelectedPos[4] = Vector2(456.0f, -170.0f);
	SelectedPos[5] = Vector2(581.0f, -170.0f);

	//Roar = new ObImage(L"Effect/Roar_of_Time.png");
	//Roar->scale.x = Roar->imageSize.x / 12.0f *2.0f;
	//Roar->scale.y = Roar->imageSize.y * 2.0f;
	//Roar->maxFrame.x = 12;
	//Roar->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	//Roar->color = Color(0.5f, 0.5f, 0.5f, 0.4f);
	//Roar->SetWorldPosX(-100.0f);

	TowerUi[0] = new ObImage(L"Ui/Chimchar_Ui.png");
	TowerUi[1] = new ObImage(L"Ui/Turtwig_Ui.png");
	TowerUi[2] = new ObImage(L"Ui/Piplup_Ui.png");
	TowerUi[3] = new ObImage(L"Ui/Charmander_Ui.png");
	TowerUi[4] = new ObImage(L"Ui/Bulbasaur_Ui.png");
	TowerUi[5] = new ObImage(L"Ui/Squirtle_Ui.png");
	TowerUi[6] = new ObImage(L"Ui/Caterpie_Ui.png");
	TowerUi[7] = new ObImage(L"Ui/Happiny_Ui.png");
	TowerUi[8] = new ObImage(L"Ui/Delibird_Ui.png");

	for (int i = 0; i < MaxT; i++)
	{
		UiHit[i] = new ObCircle;
		UiHit[i]->scale = Vector2(90.0f, 90.0f);
		UiHit[i]->isFilled = false;
		TowerUi[i]->SetParentRT(*UiHit[i]);
		TowerUi[i]->scale.x = TowerUi[i]->imageSize.x / 2.0f;
		TowerUi[i]->scale.y = TowerUi[i]->imageSize.y / 1.0f;
		TowerUi[i]->uv = uvbase;
		TowerUi[i]->isVisible = false;
	}

	for (int i = 0; i < 3; i++)
	{
		TowerUiBase[i] = new ObImage(L"Ui/Ui_base.png");
		TowerUiBase[i]->scale = TowerUiBase[i]->imageSize * 3.0f;
		TowerUiBase[i]->isVisible = false;
	}

	TowerUiBase[0]->SetWorldPos(First);
	TowerUiBase[1]->SetWorldPos(Second);
	TowerUiBase[2]->SetWorldPos(Third);


	Selectable.resize(0);
	TempSelected.resize(0);
	Selected.resize(0);

	for (int i = 0; i < MaxT; i++)
	{
		Selectable.push_back(i);
	}


	for (int i = 0;i < 3;i++)
	{
		SelectUi[i] = new ObRect;
		SelectUi[i]->scale = TowerUiBase[i]->imageSize * 3.0f;
	}

	SelectUi[0]->SetWorldPos(First);
	SelectUi[1]->SetWorldPos(Second);
	SelectUi[2]->SetWorldPos(Third);


	NextWave = new ObRect;
	NextWave->scale = Vector2(120.0f, 100.0f);
	NextWave->SetWorldPos(Vector2(595.0f, -341.0f));
	NextWave->isFilled = false;


	CandyHit = new ObRect;
	CandyHit->scale = Vector2(120.0f, 100.0f);
	CandyHit->SetWorldPos(Vector2(445.0f, -341.0f));
	CandyHit->isFilled = false;

	CandyCen = new GameObject;
	CandyCen->SetParentRT(*CandyHit);

	Candy = new ObImage(L"Item/Rare_candy.png");
	Candy->scale = Candy->imageSize * 3.0f;
	Candy->SetParentRT(*CandyHit);
	//Candy->SetWorldPos(Vector2(445.0f, -341.0f));
	
	uiCandy = new ObImage(L"Item/Rare_candy.png");
	uiCandy->scale = Candy->imageSize * 3.0f;
	uiCandy->SetWorldPos(Vector2(-450.0f, 350.0f));

	Heart = new ObImage(L"Ui/heart.png");
	Heart->scale = Candy->imageSize * 3.0f;
	Heart->SetWorldPos(Vector2(-650.0f, 350.0f));

}

Ui::~Ui()
{
}

void Ui::Release()
{
}

void Ui::Update()
{
	//Roar->Update();
	if (TempSelected.size())
	{
		if (SelectUi[0]->Intersect(INPUT->GetMouseWorldPos())&&INPUT->KeyUp(VK_LBUTTON))
		{
			k = 0;
		}
		else if (SelectUi[1]->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyUp(VK_LBUTTON))
		{
			k = 1;
		}
		else if (SelectUi[2]->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyUp(VK_LBUTTON))
		{
			k = 2;
		}
	}

	switch (k)
	{
	case 0:
		Selected.push_back(TempSelected[0]);
		Selectable.push_back(TempSelected[1]);
		Selectable.push_back(TempSelected[2]);

		TowerUi[TempSelected[1]]->isVisible = false;
		TowerUi[TempSelected[2]]->isVisible = false;

		for (int i = 0; i < 3; i++)
		{
			TowerUiBase[i]->isVisible = false;
		}


		TempSelected.clear();


		k = -1;
		isChoosing = false;
		break;
	case 1 :
		Selected.push_back(TempSelected[1]);
		Selectable.push_back(TempSelected[0]);
		Selectable.push_back(TempSelected[2]);

		TowerUi[TempSelected[0]]->isVisible = false;
		TowerUi[TempSelected[2]]->isVisible = false;

		for (int i = 0; i < 3; i++)
		{
			TowerUiBase[i]->isVisible = false;
		}


		TempSelected.clear();


		k = -1;
		isChoosing = false;

		break;
	case 2:
		Selected.push_back(TempSelected[2]);
		Selectable.push_back(TempSelected[0]);
		Selectable.push_back(TempSelected[1]);

		TowerUi[TempSelected[0]]->isVisible = false;
		TowerUi[TempSelected[1]]->isVisible = false;

		for (int i = 0; i < 3; i++)
		{
			TowerUiBase[i]->isVisible = false;
		}

		TempSelected.clear();

		k = -1;
		isChoosing = false;

		break;
	default:
		break;
	}



	//타워 셀렉위치
	for (int i = 0; i< Selected.size();i++)
	{
		TowerUi[Selected[i]]->isVisible = true;

		UiHit[Selected[i]]->SetWorldPos(SelectedPos[i]);
	}


	if (CandyN > 0 && CandyHit->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyPress(VK_LBUTTON))
	{
		CandyHit->SetWorldPos(INPUT->GetMouseWorldPos());
	}
	else
	{
		CandyHit->SetWorldPos(Vector2(445.0f, -341.0f));
	}



	for (int i = 0; i < MaxT; i++)
	{
		UiHit[i]->Update();
		TowerUi[i]->Update();
	}

	for (int i = 0; i < 3; i++)
	{
		TowerUiBase[i]->Update();
	}

	for (int i = 0;i < 3;i++)
	{
		SelectUi[i]->Update();
	}



	BaseUi->Update();
	NextWave->Update();
	CandyCen->Update();
	CandyHit->Update();
	Candy->Update();
	uiCandy->Update();
	Heart->Update();
}

void Ui::LateUpdate()
{
}

void Ui::Render()
{
	for (int i = 0; i < 3; i++)
	{
		TowerUiBase[i]->Render();
	}


	BaseUi->Render();
	//CandyHit->Render();

	//NextWave->Render();

	for (int i = 0; i < MaxT; i++)
	{
		//UiHit[i]->Render();
		TowerUi[i]->Render();
	}

	//Roar->Render();
	//for (int i = 0;i < 3;i++)
	//{
	//	SelectUi[i]->Render();
	//}
	if (CandyN > 0)
	{
		Candy->Render();
	}
	CandyCen->Render();
	uiCandy->Render();
	Heart->Render();

	DWRITE->RenderText(L" x " + to_wstring(Life), RECT{80, 30, 200, 200}, 30.0f,
		L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
		DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
		DWRITE_FONT_STRETCH_EXPANDED);

	DWRITE->RenderText(L" x " + to_wstring(CandyN), RECT{ 280 , 30, 500, 500 }, 30.0f,
		L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
		DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
		DWRITE_FONT_STRETCH_EXPANDED);

}

void Ui::TempSelection()
{
	isChoosing = true;
	TempSelected.clear();
	if (Firstturn)
	{
		for (int i = 0; i < 3; i++)
		{
			TowerUiBase[i]->isVisible = true;
			TempSelected.push_back(Selectable[0]);
			Selectable.erase(Selectable.begin());
		}

		TowerUi[TempSelected[0]]->isVisible = true;
		TowerUi[TempSelected[1]]->isVisible = true;
		TowerUi[TempSelected[2]]->isVisible = true;

		UiHit[TempSelected[0]]->SetWorldPos(First);
		UiHit[TempSelected[1]]->SetWorldPos(Second);
		UiHit[TempSelected[2]]->SetWorldPos(Third);

		Firstturn = false;
	}
	else
	{
		for (int i = 0; i < 3; i++)
		{
			TowerUiBase[i]->isVisible = true;
			int r = RANDOM->Int(0, Selectable.size() - 1);
			TempSelected.push_back(Selectable[r]);
			Selectable.erase(Selectable.begin() + r);
		}

		TowerUi[TempSelected[0]]->isVisible = true;
		TowerUi[TempSelected[1]]->isVisible = true;
		TowerUi[TempSelected[2]]->isVisible = true;

		UiHit[TempSelected[0]]->SetWorldPos(First);
		UiHit[TempSelected[1]]->SetWorldPos(Second);
		UiHit[TempSelected[2]]->SetWorldPos(Third);

	}


}

int Ui::MouseSelect()
{
	return 0;
}
