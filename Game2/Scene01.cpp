#include "stdafx.h"

void Scene01::Init()
{

	map = new ObTileMap();
	map->SetWorldPos(Vector2(-app.GetHalfWidth(), -app.GetHalfHeight()));
	map->file = "TileMap_poke_place.txt";
	map->Load();
	map->CreateTileCost();


	//Tower
	if (text->TurnN == -1)
	{
		towers[0] = new Chimchar;
		towers[1] = new Turtwig;
		towers[2] = new Piplup;
		towers[3] = new Charmander;
		towers[4] = new Bulbasaur;
		towers[5] = new Squirtle;
		towers[6] = new Caterpie;
		towers[7] = new Happiny;
		towers[8] = new Delibird;

	}
		dynamic_cast<Bulbasaur*>(towers[4])->map = map;


	//Bloon

	//magby
	for (int i = 0; i < 10; i++)
	{
		bloons[i] = new Magby;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}

	//bellsprout
	for (int i = 10; i < 20; i++)
	{
		bloons[i] = new Bellsprout;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}

	//psyduck
	for (int i = 20; i < 30; i++)
	{
		bloons[i] = new Psyduck;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}

	//rattata
	for (int i = 30; i < 40; i++)
	{
		bloons[i] = new Rattata;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}

	//magmator
	for (int i = 40; i < 50; i++)
	{
		bloons[i] = new Magmator;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}

	//victreebel
	for (int i = 50; i < 60; i++)
	{
		bloons[i] = new Victreebel;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}

	//golduck
	for (int i = 60; i < 70; i++)
	{
		bloons[i] = new Golduck;
		bloons[i]->Calculate = true;
		bloons[i]->map = map;
	}


	bloons[70] = new Purugly;
	bloons[70]->Calculate = true;
	bloons[70]->map = map;

	bloons[71] = new Skuntank;
	bloons[71]->Calculate = true;
	bloons[71]->map = map;

	bloons[72] = new Crobat;
	bloons[72]->Calculate = true;
	bloons[72]->map = map;

	bloons[73] = new Ninetails;
	bloons[73]->Calculate = true;
	bloons[73]->map = map;

	bloons[74] = new Roserade;
	bloons[74]->Calculate = true;
	bloons[74]->map = map;

	bloons[75] = new Milotic;
	bloons[75]->Calculate = true;
	bloons[75]->map = map;

	bloons[77] = new Togekiss;
	bloons[77]->Calculate = true;
	bloons[77]->map = map;

	bloons[76] = new Garchomp;
	bloons[76]->Calculate = true;
	bloons[76]->map = map;



	RealMap = new ObImage(L"ParkPath_No_UI_CHESS.png");
	RealMap->scale = RealMap->imageSize * 1.5;
	RealMap->SetWorldPosX(-150.0f);
	RealMap->color = Vector4(0.5f, 0.5f, 0.5f, 0.5f);

	RealMap2 = new ObImage(L"ParkPath_No_UI_CHESS2.png");
	RealMap2->scale = RealMap2->imageSize * 1.5;
	RealMap2->SetWorldPosX(-150.0f);
	RealMap2->color = Vector4(0.5f, 0.5f, 0.5f, 0.5f);



	//Ui
	//ui = new Ui;
	//text = new TextBar;

	IceFloor = new ObImage(L"Empoleon/special_ice_floor2.png");
	IceFloor->SetParentT(*(towers[2]->Cen));
	IceFloor->scale.x = IceFloor->imageSize.x * 1.5f;
	IceFloor->scale.y = IceFloor->imageSize.y * 1.5f;
	IceFloor->SetLocalPosY(-15.0f);

	mouse = new Cursor;
	

	//
	SOUND->AddSound("Route_1.wav", "Base", true);
	SOUND->Play("Base");
	SOUND->AddSound("Galactic.wav", "mboss", true);
	SOUND->AddSound("Beep.wav", "Beep");
	SOUND->AddSound("Cyrus.wav", "FakeBoss", true);
	SOUND->AddSound("Bossmusic.wav", "TrueBoss", true);


}

void Scene01::Release()
{
	SafeDelete(map);
}

void Scene01::Update()
{
	cout << text->TurnN << endl;
	RealMap->SetWorldPosX(-150.0f);

	//Towers Evolve
	for (int j = 0; j < MaxTN - 1; j++)
	{
		if (ui->CandyCen->Intersect(towers[j]->Select) && INPUT->KeyUp(VK_LBUTTON) && towers[j]->Placed && !towers[j]->Evolved)
		{
			towers[j]->Evolved = true;
			towers[j]->AtPw *= 2.0f;
			ui->CandyN--;
			ui->TowerUi[j]->uv = ui->uvevolved;
		}

	}

	if (ImGui::Button("Candy"))
	{
		ui->CandyN++;
	}


	if (ImGui::Button("evolve1"))
	{
		towers[0]->AtPw *= 2.0f;
		towers[0]->Evolved = true;
	}

	if (ImGui::Button("evolve2"))
	{
		towers[1]->AtPw *= 2.0f;
		towers[1]->Evolved = true;
	}

	if (ImGui::Button("evolve3"))
	{
		towers[2]->AtPw *= 2.0f;
		towers[2]->Evolved = true;
	}

	if (ImGui::Button("evolve4"))
	{
		towers[3]->AtPw *= 2.0f;
		towers[3]->Evolved = true;
	}

	if (ImGui::Button("evolve5"))
	{
		towers[4]->AtPw *= 2.0f;
		towers[4]->Evolved = true;
	}

	if (ImGui::Button("evolve6"))
	{
		towers[5]->AtPw *= 2.0f;
		towers[5]->Evolved = true;
	}

	if (ImGui::Button("evolve7"))
	{
		towers[6]->AtPw *= 2.0f;
		towers[6]->Evolved = true;
	}

	if (ImGui::Button("evolve8"))
	{
		towers[7]->AtPw *= 2.0f;
		towers[7]->Evolved = true;
	}

	if (ImGui::Button("evolve9"))
	{
		towers[8]->AtPw *= 2.0f;
		towers[8]->Evolved = true;
	}


	if (ImGui::Button("Select"))
	{
		ui->TempSelection();
	}



	if (ImGui::Button("W0") || INPUT->KeyPress(VK_SPACE))
	{
		wave = WAVE::wave0;
		GameStart = true;
	}

	if (ImGui::Button("W1"))
	{
		wave = WAVE::wave1;
	}

	if (ImGui::Button("W2"))
	{
		wave = WAVE::wave2;
	}

	if (ImGui::Button("W3"))
	{
		wave = WAVE::wave3;
	}

	if (ImGui::Button("W4"))
	{
		wave = WAVE::wave4;
	}

	if (ImGui::Button("W5"))
	{
		wave = WAVE::wave5;
	}

	if (ImGui::Button("W6"))
	{
		wave = WAVE::wave6;
	}

	if (ImGui::Button("W7"))
	{
		wave = WAVE::wave7;
	}

	if (ImGui::Button("W8"))
	{
		wave = WAVE::wave8;
	}

	if (ImGui::Button("W9"))
	{
		wave = WAVE::wave9;
	}

	if (ImGui::Button("W10"))
	{
		wave = WAVE::wave10;
	}


	//Ui 조작
	for (int i = 0; i < ui->Selected.size(); i++)
	{
		if (ui->UiHit[ui->Selected[i]]->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyPress(VK_LBUTTON))
		{
			if (!towers[ui->Selected[i]]->Placed)
			{
				towers[ui->Selected[i]]->Cen->SetWorldPos(INPUT->GetMouseWorldPos());
			}
		}
	}

	map->WorldPosToTileIdx(INPUT->GetMouseWorldPos(), tile);

	for (int j = 0; j < MaxTN; j++)
	{
		if (INPUT->KeyUp(VK_LBUTTON) && towers[j]->Select->Intersect(INPUT->GetMouseWorldPos()))
		{
			if (map->GetTileState(tile) == 2)
			{
				towers[j]->Placed = true;
			}
			else
			{
				if (!towers[j]->Placed)
				{
					towers[j]->Cen->MoveWorldPos(Vector2(3000.0f, 0.0f));
				}
			}
		}




	}

	if (INPUT->KeyPress(VK_LBUTTON) && 
		((towers[0]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[0]->Placed)
		||(towers[1]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[1]->Placed)
		|| (towers[2]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[2]->Placed)
		|| (towers[3]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[3]->Placed)
		|| (towers[4]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[4]->Placed)
		|| (towers[5]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[5]->Placed)
		|| (towers[6]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[6]->Placed)
		|| (towers[7]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[7]->Placed)
		|| (towers[8]->Select->Intersect(INPUT->GetMouseWorldPos()) && !towers[8]->Placed)
		))
	{
		Placing = true;
	}
	else
	{
		Placing = false;
	}
	



	if (Placing)
	{
		RealMap->color = Color(0.5f, 0.5f, 0.5f, 0.4f);
	}
	else
	{
		RealMap->color = Color(0.5f, 0.5f, 0.5f, 1.0f);
	}


	//테스트

	switch (wave)
	{
	case WAVE::wave0:
		//Wave0();
		WaveTimer = 0.0f;
		//Bloon Reset
		for (int i = 0; i < MaxBN; i++)
		{
			bloons[i]->Reset();
		}

		//Target reset
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target = queue<Bloon*>();
		}
		//Blastoise special reset
		for (int i = 0; i < 3; i++)
		{
			dynamic_cast<Squirtle*>(towers[5])->Bubble[i]->isVisible = false;
			dynamic_cast<Squirtle*>(towers[5])->BubbleTimer = 0.0f;
		}

		break;
	case WAVE::wave1:
		//Wave1();

		for (int i = 30; i < 33; i++)
		{
			for (int j = 0; j < MaxTN; j++)
			{
				towers[j]->Target.push(bloons[i]);
			}
		}

		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[30]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[31]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[32]->Go = true;
		}

		//end
		if (bloons[32]->Dead && bloons[31]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}

		break;
	case WAVE::wave2:
		//Wave2();

		for (int i = 30; i < 36; i++)
		{
			for (int j = 0; j < MaxTN; j++)
			{
				towers[j]->Target.push(bloons[i]);
			}
		}

		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[30]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[31]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[32]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[33]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[34]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[35]->Go = true;
		}

		//end
		if (bloons[35]->Dead && bloons[34]->Dead && bloons[33]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}

		break;
	case WAVE::wave3:

		for (int i = 30; i < 40; i++)
		{
			for (int j = 0; j < MaxTN; j++)
			{
				towers[j]->Target.push(bloons[i]);
			}
		}

		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[70]);
		}



		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[30]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[31]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[32]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[33]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[34]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[35]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[36]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[37]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[38]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[39]->Go = true;
		}
		if (WaveTimer > 10.0f)
		{
			bloons[70]->Go = true;
		}

		if (bloons[70]->Dead && bloons[39]->Dead && bloons[38]->Dead && bloons[37]->Dead && bloons[36]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}


		break;
	case WAVE::wave4:

		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[0]);
			towers[j]->Target.push(bloons[10]);
			towers[j]->Target.push(bloons[20]);
			towers[j]->Target.push(bloons[1]);
			towers[j]->Target.push(bloons[11]);
			towers[j]->Target.push(bloons[21]);
		}


		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[0]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[10]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[20]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[1]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[11]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[21]->Go = true;
		}

		if (bloons[21]->Dead && bloons[11]->Dead && bloons[1]->Dead && bloons[20]->Dead && bloons[10]->Dead && bloons[0]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}

		break;
	case WAVE::wave5:
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[0]);
			towers[j]->Target.push(bloons[1]);
			towers[j]->Target.push(bloons[2]);
			towers[j]->Target.push(bloons[40]);

			towers[j]->Target.push(bloons[10]);
			towers[j]->Target.push(bloons[11]);
			towers[j]->Target.push(bloons[12]);
			towers[j]->Target.push(bloons[50]);

			towers[j]->Target.push(bloons[20]);
			towers[j]->Target.push(bloons[21]);
			towers[j]->Target.push(bloons[22]);
			towers[j]->Target.push(bloons[60]);

		}


		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[0]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[1]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[2]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[40]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[10]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[11]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[12]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[50]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[20]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[21]->Go = true;
		}
		if (WaveTimer > 10.0f)
		{
			bloons[22]->Go = true;
		}
		if (WaveTimer > 11.0f)
		{
			bloons[60]->Go = true;
		}

		if (bloons[60]->Dead && bloons[22]->Dead && bloons[21]->Dead && bloons[20]->Dead && bloons[50]->Dead && bloons[12]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}



		break;
	case WAVE::wave6:
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[30]);
			towers[j]->Target.push(bloons[31]);
			towers[j]->Target.push(bloons[32]);

			towers[j]->Target.push(bloons[40]);
			towers[j]->Target.push(bloons[41]);

			towers[j]->Target.push(bloons[50]);
			towers[j]->Target.push(bloons[51]);

			towers[j]->Target.push(bloons[60]);
			towers[j]->Target.push(bloons[61]);

			towers[j]->Target.push(bloons[33]);
			towers[j]->Target.push(bloons[34]);
			towers[j]->Target.push(bloons[35]);

			towers[j]->Target.push(bloons[71]);

		}


		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[30]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[31]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[32]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[40]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[41]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[50]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[12]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[50]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[51]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[60]->Go = true;
		}
		if (WaveTimer > 10.0f)
		{
			bloons[61]->Go = true;
		}
		if (WaveTimer > 11.0f)
		{
			bloons[33]->Go = true;
		}
		if (WaveTimer > 12.0f)
		{
			bloons[34]->Go = true;
		}
		if (WaveTimer > 13.0f)
		{
			bloons[35]->Go = true;
		}
		if (WaveTimer > 14.0f)
		{
			bloons[71]->Go = true;
		}


		if (bloons[71]->Dead && bloons[35]->Dead && bloons[34]->Dead && bloons[33]->Dead && bloons[61]->Dead && bloons[60]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}

		break;
	case WAVE::wave7:
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[0]);
			towers[j]->Target.push(bloons[1]);
			towers[j]->Target.push(bloons[2]);
			towers[j]->Target.push(bloons[3]);
			towers[j]->Target.push(bloons[4]);

			towers[j]->Target.push(bloons[40]);
			towers[j]->Target.push(bloons[41]);
			towers[j]->Target.push(bloons[42]);


			towers[j]->Target.push(bloons[10]);
			towers[j]->Target.push(bloons[11]);
			towers[j]->Target.push(bloons[12]);
			towers[j]->Target.push(bloons[13]);
			towers[j]->Target.push(bloons[14]);

			towers[j]->Target.push(bloons[50]);
			towers[j]->Target.push(bloons[51]);
			towers[j]->Target.push(bloons[52]);

			towers[j]->Target.push(bloons[20]);
			towers[j]->Target.push(bloons[21]);
			towers[j]->Target.push(bloons[22]);
			towers[j]->Target.push(bloons[23]);
			towers[j]->Target.push(bloons[24]);

			towers[j]->Target.push(bloons[60]);
			towers[j]->Target.push(bloons[61]);
			towers[j]->Target.push(bloons[62]);



		}
		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[0]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[1]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[2]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[3]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[4]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[40]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[41]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[42]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[10]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[11]->Go = true;
		}
		if (WaveTimer > 10.0f)
		{
			bloons[12]->Go = true;
		}
		if (WaveTimer > 11.0f)
		{
			bloons[13]->Go = true;
		}
		if (WaveTimer > 12.0f)
		{
			bloons[14]->Go = true;
		}
		if (WaveTimer > 13.0f)
		{
			bloons[50]->Go = true;
		}
		if (WaveTimer > 14.0f)
		{
			bloons[51]->Go = true;
		}
		if (WaveTimer > 15.0f)
		{
			bloons[52]->Go = true;
		}
		if (WaveTimer > 16.0f)
		{
			bloons[20]->Go = true;
		}
		if (WaveTimer > 17.0f)
		{
			bloons[21]->Go = true;
		}
		if (WaveTimer > 18.0f)
		{
			bloons[22]->Go = true;
		}
		if (WaveTimer > 19.0f)
		{
			bloons[23]->Go = true;
		}
		if (WaveTimer > 20.0f)
		{
			bloons[24]->Go = true;
		}
		if (WaveTimer > 21.0f)
		{
			bloons[60]->Go = true;
		}
		if (WaveTimer > 22.0f)
		{
			bloons[61]->Go = true;
		}
		if (WaveTimer > 23.0f)
		{
			bloons[62]->Go = true;
		}


		if (bloons[62]->Dead && bloons[61]->Dead && bloons[60]->Dead && bloons[24]->Dead && bloons[23]->Dead && 
			bloons[22]->Dead && bloons[21]->Dead && bloons[20]->Dead && bloons[52]->Dead && bloons[51]->Dead &&
			bloons[50]->Dead && bloons[14]->Dead && bloons[13]->Dead && bloons[12]->Dead && bloons[11]->Dead )
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}


		break;
	case WAVE::wave8:
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[40]);
			towers[j]->Target.push(bloons[41]);
			towers[j]->Target.push(bloons[42]);
			towers[j]->Target.push(bloons[43]);
			towers[j]->Target.push(bloons[44]);

			towers[j]->Target.push(bloons[51]);
			towers[j]->Target.push(bloons[52]);
			towers[j]->Target.push(bloons[53]);
			towers[j]->Target.push(bloons[54]);
			towers[j]->Target.push(bloons[55]);


			towers[j]->Target.push(bloons[61]);
			towers[j]->Target.push(bloons[62]);
			towers[j]->Target.push(bloons[63]);
			towers[j]->Target.push(bloons[64]);
			towers[j]->Target.push(bloons[65]);

			towers[j]->Target.push(bloons[30]);
			towers[j]->Target.push(bloons[31]);
			towers[j]->Target.push(bloons[32]);
			towers[j]->Target.push(bloons[33]);
			towers[j]->Target.push(bloons[34]);
		}

		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[40]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[41]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[42]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[43]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[44]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[51]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[52]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[53]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[54]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[55]->Go = true;
		}
		if (WaveTimer > 10.0f)
		{
			bloons[61]->Go = true;
		}
		if (WaveTimer > 11.0f)
		{
			bloons[62]->Go = true;
		}
		if (WaveTimer > 12.0f)
		{
			bloons[63]->Go = true;
		}
		if (WaveTimer > 13.0f)
		{
			bloons[64]->Go = true;
		}
		if (WaveTimer > 14.0f)
		{
			bloons[65]->Go = true;
		}
		if (WaveTimer > 15.0f)
		{
			bloons[30]->Go = true;
		}
		if (WaveTimer > 16.0f)
		{
			bloons[31]->Go = true;
		}
		if (WaveTimer > 17.0f)
		{
			bloons[32]->Go = true;
		}
		if (WaveTimer > 18.0f)
		{
			bloons[33]->Go = true;
		}
		if (WaveTimer > 19.0f)
		{
			bloons[34]->Go = true;
		}


		if (bloons[34]->Dead && bloons[33]->Dead && bloons[32]->Dead && bloons[31]->Dead && bloons[30]->Dead && 
			bloons[65]->Dead && bloons[64]->Dead && bloons[63]->Dead && bloons[62]->Dead && bloons[61]->Dead&&
			bloons[55]->Dead && bloons[54]->Dead && bloons[53]->Dead && bloons[52]->Dead && bloons[51]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}

		break;
	case WAVE::wave9:
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[72]);


			towers[j]->Target.push(bloons[40]);
			towers[j]->Target.push(bloons[41]);
			towers[j]->Target.push(bloons[42]);
			towers[j]->Target.push(bloons[43]);
			towers[j]->Target.push(bloons[44]);

			towers[j]->Target.push(bloons[50]);
			towers[j]->Target.push(bloons[51]);
			towers[j]->Target.push(bloons[52]);
			towers[j]->Target.push(bloons[53]);
			towers[j]->Target.push(bloons[54]);

			towers[j]->Target.push(bloons[60]);
			towers[j]->Target.push(bloons[61]);
			towers[j]->Target.push(bloons[62]);
			towers[j]->Target.push(bloons[63]);
			towers[j]->Target.push(bloons[64]);

			towers[j]->Target.push(bloons[70]);

			towers[j]->Target.push(bloons[45]);
			towers[j]->Target.push(bloons[46]);
			towers[j]->Target.push(bloons[47]);
			towers[j]->Target.push(bloons[48]);
			towers[j]->Target.push(bloons[49]);

			towers[j]->Target.push(bloons[55]);
			towers[j]->Target.push(bloons[56]);
			towers[j]->Target.push(bloons[57]);
			towers[j]->Target.push(bloons[58]);
			towers[j]->Target.push(bloons[59]);

			towers[j]->Target.push(bloons[65]);
			towers[j]->Target.push(bloons[66]);
			towers[j]->Target.push(bloons[67]);
			towers[j]->Target.push(bloons[68]);
			towers[j]->Target.push(bloons[69]);
		}

		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[72]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[40]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[41]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[42]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[43]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[44]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[50]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[51]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[52]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[53]->Go = true;
		}
		if (WaveTimer > 10.0f)
		{
			bloons[54]->Go = true;
		}
		if (WaveTimer > 11.0f)
		{
			bloons[60]->Go = true;
		}
		if (WaveTimer > 12.0f)
		{
			bloons[61]->Go = true;
		}
		if (WaveTimer > 13.0f)
		{
			bloons[62]->Go = true;
		}
		if (WaveTimer > 14.0f)
		{
			bloons[63]->Go = true;
		}
		if (WaveTimer > 15.0f)
		{
			bloons[64]->Go = true;
		}
		if (WaveTimer > 16.0f)
		{
			bloons[70]->Go = true;
		}
		if (WaveTimer > 17.0f)
		{
			bloons[45]->Go = true;
		}
		if (WaveTimer > 18.0f)
		{
			bloons[46]->Go = true;
		}
		if (WaveTimer > 19.0f)
		{
			bloons[47]->Go = true;
		}
		if (WaveTimer > 20.0f)
		{
			bloons[48]->Go = true;
		}
		if (WaveTimer > 21.0f)
		{
			bloons[49]->Go = true;
		}
		if (WaveTimer > 22.0f)
		{
			bloons[55]->Go = true;
		}
		if (WaveTimer > 23.0f)
		{
			bloons[56]->Go = true;
		}
		if (WaveTimer > 24.0f)
		{
			bloons[57]->Go = true;
		}
		if (WaveTimer > 25.0f)
		{
			bloons[58]->Go = true;
		}
		if (WaveTimer > 26.0f)
		{
			bloons[59]->Go = true;
		}
		if (WaveTimer > 27.0f)
		{
			bloons[65]->Go = true;
		}
		if (WaveTimer > 28.0f)
		{
			bloons[66]->Go = true;
		}
		if (WaveTimer > 29.0f)
		{
			bloons[67]->Go = true;
		}
		if (WaveTimer > 30.0f)
		{
			bloons[68]->Go = true;
		}
		if (WaveTimer > 31.0f)
		{
			bloons[69]->Go = true;
		}



		if (bloons[69]->Dead && bloons[68]->Dead && bloons[67]->Dead && bloons[66]->Dead && bloons[65]->Dead && 
			bloons[59]->Dead && bloons[58]->Dead && bloons[57]->Dead && bloons[56]->Dead && bloons[55]->Dead &&
			bloons[49]->Dead && bloons[48]->Dead && bloons[47]->Dead && bloons[46]->Dead && bloons[45]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}


		break;
	case WAVE::wave10:
		for (int j = 0; j < MaxTN; j++)
		{
			towers[j]->Target.push(bloons[30]);
			towers[j]->Target.push(bloons[31]);
			towers[j]->Target.push(bloons[32]);
			towers[j]->Target.push(bloons[33]);
			towers[j]->Target.push(bloons[34]);
			towers[j]->Target.push(bloons[35]);
			towers[j]->Target.push(bloons[36]);
			towers[j]->Target.push(bloons[37]);
			towers[j]->Target.push(bloons[38]);
			towers[j]->Target.push(bloons[39]);


			towers[j]->Target.push(bloons[73]);
			towers[j]->Target.push(bloons[74]);
			towers[j]->Target.push(bloons[75]);
			towers[j]->Target.push(bloons[77]);
			towers[j]->Target.push(bloons[76]);

		}

		WaveTimer += DELTA;
		if (WaveTimer > 0.0f)
		{
			bloons[30]->Go = true;
		}
		if (WaveTimer > 1.0f)
		{
			bloons[31]->Go = true;
		}
		if (WaveTimer > 2.0f)
		{
			bloons[32]->Go = true;
		}
		if (WaveTimer > 3.0f)
		{
			bloons[33]->Go = true;
		}
		if (WaveTimer > 4.0f)
		{
			bloons[34]->Go = true;
		}
		if (WaveTimer > 5.0f)
		{
			bloons[35]->Go = true;
		}
		if (WaveTimer > 6.0f)
		{
			bloons[36]->Go = true;
		}
		if (WaveTimer > 7.0f)
		{
			bloons[37]->Go = true;
		}
		if (WaveTimer > 8.0f)
		{
			bloons[38]->Go = true;
		}
		if (WaveTimer > 9.0f)
		{
			bloons[39]->Go = true;
		}
		if (WaveTimer > 16.0f)
		{
			bloons[73]->Go = true;
		}
		if (WaveTimer > 17.0f)
		{
			bloons[74]->Go = true;
		}
		if (WaveTimer > 18.0f)
		{
			bloons[75]->Go = true;
		}
		if (WaveTimer > 19.0f)
		{
			bloons[77]->Go = true;
		}
		if (WaveTimer > 20.0f)
		{
			bloons[76]->Go = true;
		}


		if (bloons[77]->Dead && bloons[76]->Dead && bloons[75]->Dead && bloons[74]->Dead && bloons[73]->Dead &&
			bloons[39]->Dead && bloons[38]->Dead && bloons[37]->Dead && bloons[36]->Dead && bloons[35]->Dead &&
			bloons[34]->Dead && bloons[33]->Dead && bloons[32]->Dead && bloons[31]->Dead && bloons[30]->Dead)
		{
			ResetTimer += DELTA;
			if (ResetTimer > 2.0f)
			{
				wave = WAVE::wave0;
			}
		}
		else
		{
			ResetTimer = 0.0f;
		}

		break;

	}
	

	//for the Flow
	if (text->TurnN == -1 && INPUT->KeyDown(VK_LBUTTON))
	{
		SOUND->Play("Beep");
		text->mesIndex = 15;
		text->TurnN = 0;
		
	}

	if (text->TurnN == 0 && INPUT->KeyDown(VK_LBUTTON) && text->mesIndex == text->battleMes.size())
	{
		text->mesIndex = 0;
		text->TurnN = 1;
	}

	if (text->TurnN == 1 && INPUT->KeyDown(VK_LBUTTON) && !ui->isChoosing && ui->Selected.size() == 0)
	{
		ui->TempSelection();
		text->TurnN = 2;
	}

	if (text->TurnN == 2 && INPUT->KeyUp(VK_LBUTTON) && ui->Selected.size() == 1)
	{
		SOUND->Play("Beep");
		text->mesIndex = 15;
		text->TurnN = 3;
	}


	if (text->TurnN == 3 && text->mesIndex == text->battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
	{
		text->TurnN = 4;
	}

	if (text->TurnN == 4 && INPUT->KeyUp(VK_LBUTTON) && (towers[0]->Placed|| towers[1]->Placed || towers[2]->Placed))
	{
		SOUND->Play("Beep");
		text->mesIndex = 15;
		text->TurnN = 5;
	}

	if (text->TurnN == 5 && text->mesIndex == text->battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
	{
		text->mesIndex = 15;
		text->TurnN = 6;
		wave = WAVE::wave0;
	}

	if (text->TurnN==6 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
	{
		wave = WAVE::wave1;
		text->TurnN = 7;
	}

	if (text->TurnN == 7 && wave == WAVE::wave0 && ui->Selected.size() == 1)
	{
		ui->TempSelection();
		text->TurnN = 8;
	}


	if (text->TurnN == 8 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)) && wave == WAVE::wave0)
	{
		wave = WAVE::wave2;
		text->TurnN = 9;
	}

	if (text->TurnN == 9 && wave == WAVE::wave0 && ui->Selected.size() == 2)
	{
		ui->TempSelection();
		text->TurnN = 10;
	}

	if (text->TurnN == 10 && ui->Selected.size() == 3)
	{
		text->TurnN = 11;
		text->mesIndex = 4;
		SOUND->Stop("Base");
		SOUND->Play("mboss");

	}

	if (text->TurnN == 11 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)) && wave == WAVE::wave0 && text->mesIndex == text->battleMes.size())
	{
		wave = WAVE::wave3;
		text->TurnN = 12;
	}

	if (text->TurnN == 12 && wave == WAVE::wave0 && ui->Selected.size() == 3)
	{
		SOUND->Stop("mboss");
		SOUND->Play("Base");
		ui->TempSelection();
		text->TurnN = 13;
		ui->CandyN++;
	}

	if (text->TurnN == 13 && wave == WAVE::wave0 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
	{
		wave = WAVE::wave4;
		text->TurnN = 14;
	}

	if (text->TurnN == 14 && wave == WAVE::wave0 && ui->Selected.size() == 4)
	{
		ui->TempSelection();
		text->TurnN = 15;
	}


	if (text->TurnN == 15 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)) && wave == WAVE::wave0)
	{
		wave = WAVE::wave5;
		text->TurnN = 16;
	}

	if (text->TurnN == 16 && wave == WAVE::wave0 && ui->Selected.size() == 5)
	{
		ui->TempSelection();
		text->TurnN = 17;
	}

	if (text->TurnN == 17 && ui->Selected.size() == 6)
	{
		text->TurnN = 18;
		text->mesIndex = 7;
		SOUND->Stop("Base");
		SOUND->Play("mboss");

	}

	if (text->TurnN == 18 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)) && wave == WAVE::wave0 && text->mesIndex == text->battleMes.size())
	{
		wave = WAVE::wave6;
		text->TurnN = 19;
	}

	if (text->TurnN == 19 && wave == WAVE::wave0 && ui->Selected.size() == 6)
	{
		SOUND->Stop("mboss");
		SOUND->Play("Base");
		text->TurnN = 20;
		ui->CandyN++;
	}

	if (text->TurnN == 20 && wave == WAVE::wave0 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
	{
		wave = WAVE::wave7;
		text->TurnN = 21;
	}

	if (text->TurnN == 21 && wave == WAVE::wave0 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
	{
		wave = WAVE::wave8;
		text->TurnN = 22;

	}

	if (text->TurnN == 22 && wave == WAVE::wave0 )
	{
		text->TurnN = 23;
		text->mesIndex = 5;
		SOUND->Stop("Base");
		SOUND->Play("FakeBoss");

	}

	if (text->TurnN == 23 && wave == WAVE::wave0 && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
	{
		wave = WAVE::wave9;
		text->TurnN = 24;

	}

	if (text->TurnN == 24 && wave == WAVE::wave0)
	{
		SOUND->Stop("FakeBoss");
		SOUND->Play("Base");
		text->mesIndex = 5;
		text->TurnN = 25;
		ui->CandyN++;
	}

	if (text->TurnN == 25 && text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
	{
		text->mesIndex = 0;
		text->TurnN = 26;
	}

	if (text->TurnN == 26)
	{
		if (text->mesIndex == text->battleMes.size() && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
		{
			text->mesIndex = 7;
			SOUND->Stop("Base");
			SCENE->ChangeScene("Scene02", 0.0f);
			text->TurnN = 27;
			return;

		}
		else
		{
			text->TurnN = 26;
		}
	}

	if (text->TurnN == 27)
	{
		SOUND->Stop("Base");
		SOUND->Play("TrueBoss");
		if (text->mesIndex == text->battleMes.size() && ui->NextWave->Intersect(INPUT->GetMouseWorldPos()) && (INPUT->KeyDown(VK_LBUTTON)))
		{

			text->TurnN = 28;
			wave = WAVE::wave0;
		}
		else
		{
			for (int i = 0; i < MaxBN; i++)
			{
				bloons[i]->StartP = Vector2(500.0f, 46.0f);
				bloons[i]->EndP = Vector2(285.0f,400.0f);
				bloons[i]->Cen->SetWorldPos(StartP);
			}
		}
	}

	if (text->TurnN == 28)
	{
		wave = WAVE::wave10;
		text->TurnN = 29;
	}

	if (text->TurnN == 29 && wave == WAVE::wave0)
	{
		text->mesIndex = 7;
		text->TurnN = 30;
	}

	if (text->TurnN == 30 && text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
	{
		text->mesIndex = 7;
		text->TurnN = 31;
	}

	if (text->TurnN == 31 && text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
	{
		SOUND->Stop("TrueBoss");
		text->TurnN = 32;
	}

	if (text->TurnN == 32 )
	{
		text->GiraTimer += DELTA;

		if (text->GiraTimer > 5.0f)
		{
			text->mesIndex = 7;
			text->TurnN = 33;

		}
	}

	if (text->TurnN == 33 && text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
	{
		text->mesIndex = 5;
		text->TurnN = 34;
	}

	if (text->TurnN == 34 && text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
	{
		text->mesIndex = 5;
		text->TurnN = 35;
	}

	if (text->TurnN == 35 && text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
	{
		text->mesIndex = 0;
		text->TurnN = 36;
	}

	if (text->TurnN == 36 && text->mesIndex == text->battleMes.size())
	{
		text->TurnN = 37;
	}

	if (text->TurnN == 37)
	{
		LIGHT->light.lights[0].radius -= DELTA * 1000.0f;
		if (LIGHT->light.lights[0].radius < 0.0f)
		{
			text->TurnN = 38;
		}
	}

	if (text->TurnN == 38)
	{
		LIGHT->light.lights[0].radius += DELTA * 1000.0f;
		if (LIGHT->light.lights[0].radius > 2000.0f)
		{
			text->mesIndex = 0;
			text->TurnN = 39;
		}
	}

	if (text->TurnN == 39)
	{
		SOUND->Play("Base");
		if (text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
		{
			text->mesIndex = 8;
			text->TurnN = 40;
		}
	}

	if (text->TurnN == 40)
	{
		if (text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
		{
			text->mesIndex = 7;
			text->TurnN = 41;
		}
	}

	if (text->TurnN == 41)
	{
		if (text->mesIndex == text->battleMes.size() && (INPUT->KeyDown(VK_LBUTTON)))
		{
			text->mesIndex = 0;
			text->TurnN = 42;
		}
	}


	//스킵용
	if (INPUT->KeyPress('R'))
	{
		text->TurnN = 27;
	}








	//Life
	for (int i = 0; i < MaxBN; i++)
	{

		switch (wave)
		{
		case WAVE::wave0:
			break;
		case WAVE::wave1:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave2:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave3:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave4:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave5:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave6:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave7:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave8:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave9:
			if (bloons[i]->Cen->GetWorldPos().x > 440.0f && bloons[i]->Dead == false && text->TurnN < 27)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		case WAVE::wave10:
			if (bloons[i]->Cen->GetWorldPos().y > 395.0f && bloons[i]->Dead == false)
			{
				ui->Life--;
				bloons[i]->Dead = true;
			}

			break;
		default:
			break;
		}


	}







	map->Update();

	for (int i = 0;i < MaxBN;i++)
	{
		bloons[i]->Update();
	}

	for (int i = 0;i < MaxTN;i++)
	{
		towers[i]->Update();
	}



	RealMap->Update();
	RealMap2->Update();
	ui->Update();
	text->Update();
	IceFloor->Update();
	mouse->Update();
}

void Scene01::LateUpdate()
{
	OgCam = RealMap->GetWorldPos();

	//type attacks
	for (int i = 0; i < MaxBN; i++)
	{
		for (int j = 0; j < MaxTN; j++)
		{
			if (bloons[i]->BlHit->Intersect(towers[j]->FireHit)&&!bloons[i]->Dead && towers[j]->FireHit->isVisible)
			{
				towers[j]->FireHit->MoveWorldPos(Vector2(2000.0f, 0.0f));

				switch (bloons[i]->DefType)
				{
				case Bloon::DEFTYPE::NormalType:
					switch (towers[j]->AtType)
					{
					case Tower::TYPE::FireAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense ;
						break;
					case Tower::TYPE::GrassAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense;
						break;
					case Tower::TYPE::WaterAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense;
						break;
					}

					break;


				case Bloon::DEFTYPE::FireType:
					switch (towers[j]->AtType)
					{
					case Tower::TYPE::FireAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense *0.5f;
						break;
					case Tower::TYPE::GrassAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense *0.5f;
						break;
					case Tower::TYPE::WaterAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense *2.0f;
						break;
					}

					break;

				case Bloon::DEFTYPE::GrassType:
					switch (towers[j]->AtType)
					{
					case Tower::TYPE::FireAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 2.0f;
						break;

					case Tower::TYPE::GrassAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						break;

					case Tower::TYPE::WaterAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						break;
					}

					break;

				case Bloon::DEFTYPE::WaterType:
					switch (towers[j]->AtType)
					{
					case Tower::TYPE::FireAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						break;

					case Tower::TYPE::GrassAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 2.0f;
						break;

					case Tower::TYPE::WaterAttack:
						bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						break;
					}

				case Bloon::DEFTYPE::DragonType:
					switch (towers[j]->AtType)
					{
					case Tower::TYPE::FireAttack:
						if (!(dynamic_cast<Garchomp*>(bloons[76])->Burrowed))
						{
							bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						}
						break;

					case Tower::TYPE::GrassAttack:
						if (!(dynamic_cast<Garchomp*>(bloons[76])->Burrowed))
						{
							bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						}
						break;

					case Tower::TYPE::WaterAttack:
						if (!(dynamic_cast<Garchomp*>(bloons[76])->Burrowed))
						{
							bloons[i]->Health -= (towers[j]->AtPw * towers[j]->PowerMulti) * bloons[i]->Defense * 0.5f;
						}
						break;
					}

					break;

				default:
					break;
				}




			}

		}
	}





	//Towers Specials

	//Piplup special
	for (int i = 0; i < MaxBN-1;i++)
	{
		if (dynamic_cast<Piplup*>(towers[2])->IceHit->Intersect(bloons[i]->Cen)&& dynamic_cast<Piplup*>(towers[2])->Evolved)
		{
			bloons[i]->Speed = bloons[i]->SlowSpeed;
		}
		else
		{
			bloons[i]->Speed = bloons[i]->FullSpeed;
		}
	}

	//Turtwig special
	if (dynamic_cast<Turtwig*>(towers[1])->isQuaking)
	{

		RealMap->SetWorldPosX(OgCam.x + RANDOM->Float(-5.0f, 5.0f));
		//RealMap->SetWorldPosY(OgCam.y + RANDOM->Float(-2.0f, 2.0f));
		RealMap->Update();
		for (int i = 0; i < MaxBN-1; i++)
		{
			bloons[i]->Speed = bloons[i]->StunSpeed;
		}
	}
	else
	{
		RealMap->SetWorldPos(Vector2(-150.0f, 0.0f));
		for (int i = 0; i < MaxBN-1; i++)
		{
			if (!dynamic_cast<Piplup*>(towers[2])->IceHit->Intersect(bloons[i]->Cen) && dynamic_cast<Piplup*>(towers[2])->Evolved)
			{
				bloons[i]->Speed = bloons[i]->FullSpeed;

			}
		}
	}

	//Charizard special
	for (int i = 0; i < MaxBN-1; i++)
	{
		if (dynamic_cast<Charmander*>(towers[3])->BreathHit->Intersect(bloons[i]->BlHit) && towers[3]->Evolved && towers[3]->isShooting)
		{
			bloons[i]->isBurning = true;
		}
	}

	//Venusaur special
	for (int i = 0; i < MaxBN-1; i++)
	{
		for (int j = 0; j < RayN; j++)
		{
			if (dynamic_cast<Bulbasaur*>(towers[4])->FlowerH[j]->Intersect(bloons[i]->BlHit) && dynamic_cast<Bulbasaur*>(towers[4])->Evolved && bloons[i]->Go)
			{
				bloons[i]->Health -= 5.0f * DELTA;
			}
		}
	}


	//Blastoise special
	for (int i = 0; i < MaxBN-1; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (dynamic_cast<Squirtle*>(towers[5])->BubbleHit[j]->Intersect(bloons[i]->BlHit)&& dynamic_cast<Squirtle*>(towers[5])->Evolved)
			{
				bloons[i]->Health -= 30.0f * DELTA;
			}
		}
	}

	//Butterfree special
	for (int i = 0; i < MaxBN-1; i++)
	{
		if (dynamic_cast<Caterpie*>(towers[6])->PoisonHit->Intersect(bloons[i]->BlHit) && towers[6]->Evolved && dynamic_cast<Caterpie*>(towers[6])->Poison->isVisible)
		{
			bloons[i]->DefenseLowered = true;
		}
	}

	//Blissey special
	if (dynamic_cast<Happiny*>(towers[7])->BuffTimer > 10.0f)
	{
		towers[0]->PowerUped = true;
		towers[1]->PowerUped = true;
		towers[2]->PowerUped = true;
		towers[3]->PowerUped = true;
		towers[4]->PowerUped = true;
		towers[5]->PowerUped = true;
		towers[6]->PowerUped = true;
		towers[7]->PowerUped = true;
		towers[8]->PowerUped = true;

		dynamic_cast<Happiny*>(towers[7])->BuffTimer = 0.0f;
	}

	//Delibird special
	if (dynamic_cast<Delibird*>(towers[8])->Placed && !(wave == WAVE::wave0))
	{
		dynamic_cast<Delibird*>(towers[8])->CandyTimer += DELTA;
		if (dynamic_cast<Delibird*>(towers[8])->CandyTimer > 50.0f)
		{
			ui->CandyN++;
			dynamic_cast<Delibird*>(towers[8])->CandyTimer = 0.0f;
		}
	}


	//Bloons Specials

	//Skuntank special
	for (int j = 0; j < MaxTN; j++)
	{
		if (dynamic_cast<Skuntank*>(bloons[71])->FartHit->Intersect(towers[j]->Cen))
		{
			towers[j]->AtSp = towers[j]->SlowSp;
		}
		else
		{
			towers[j]->AtSp = towers[j]->NormalSp;
		}
	}

	EntityManager::GetInstance()->Sort();
}

void Scene01::Render()
{

	map->Render();
	if (26 < text->TurnN && text->TurnN < 38)
	{
		RealMap2->Render();
	}
	else
	{
		RealMap->Render();
	}

	if (towers[2]->Evolved)
	{
		IceFloor->Render();
	}

	if (towers[4]->Evolved)
	{
		for (int i = 0;i < RayN;i++)
		{
			dynamic_cast<Bulbasaur*>(towers[4])->Vines[i]->Render();
		}
	}

	
	EntityManager::GetInstance()->Render();

	ui->Render();
	text->Render();
	//map->Render();
	mouse->Render();

}

void Scene01::ResizeScreen()
{
}

//bool Scene01::CheckDead()
//{
//	for (int i = 0; i < MaxBN; i++)
//	{
//		if (!bloons[i]->Dead)
//		{
//			return false;
//		}
//
//	}
//
//	return true;
//
//}

//void Scene01::Wave0()
//{
//}
//
//void Scene01::Wave1()
//{
//}
//
//void Scene01::Wave2()
//{
//}
