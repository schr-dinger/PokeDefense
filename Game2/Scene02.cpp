#include "stdafx.h"

void Scene02::Init()
{
	Town1 = new ObImage(L"Town/Town.png");
	Town1->scale = Town1->imageSize * 2.5f;

	Town2 = new ObImage(L"Town/Town2.png");
	Town2->scale = Town2->imageSize * 2.5f;


	PlayerS = new ObImage(L"Town/Player_S.png");
	PlayerS->scale = PlayerS->imageSize * 2.0f;
	PlayerS->SetWorldPos(Vector2(-220.0f, 80.0f));
	
	PlayerN = new ObImage(L"Town/Player_N.png");
	PlayerN->scale = PlayerS->imageSize * 2.0f;
	PlayerN->SetWorldPos(Vector2(0.0f, -240.0f));

	TextB = new ObImage(L"TextBar/Poke_text_box.png");
	TextB->scale = TextB->imageSize ;
	TextB->SetWorldPos(Vector2(0.0f, -250.0f));

	TextH = new ObRect;
	TextH->scale = TextB->imageSize;
	TextH->SetWorldPos(Vector2(0.0f, -250.0f));

	LabH = new ObRect;
	LabH->scale = Vector2(280.0f,170.0f);
	LabH->SetWorldPos(Vector2(180.0f, -70.0f));
	LabH->isFilled = false;

	GameH = new ObRect;
	GameH->scale = Vector2(100.0f, 200.0f);
	GameH->SetWorldPos(Vector2(40.0f, 300.0f));
	GameH->isFilled = false;



	Lab = new ObImage(L"Town/Lab.png");
	Lab->scale = Lab->imageSize * 2.5f;

	ProfessorOW = new ObImage(L"Town/Rowan_move_S.png");
	ProfessorOW->scale.x = ProfessorOW->imageSize.x / 4.0f *2.0f;
	ProfessorOW->scale.y = ProfessorOW->imageSize.y * 2.0f;
	ProfessorOW->maxFrame.x = 4;
	ProfessorOW->ChangeAnim(ANIMSTATE::STOP, 0.1f);

	//Professor->scale = Professor->imageSize;
	//Professor->SetWorldPos(Vector2(120.0f, 0.0f));

	Bang = new ObImage(L"Town/Bang.png");
	//Ques = new ObImage(L"Town/Question.png");

	Bang->scale = Bang->imageSize;
	Bang->SetWorldPos(Vector2(0.0f, 40.0f));

	Professor = new ObImage(L"TextBar/Professor_Rowan.png");
	Professor->scale = Professor->imageSize;
	Professor->SetWorldPos(Vector2(250.0f, 0.0f));


	CynthiaS = new ObImage(L"Town/Cynthia_S.png");
	CynthiaN = new ObImage(L"Town/Cynthia_N.png");

	CynthiaS->scale = CynthiaS->imageSize * 2.0f;
	CynthiaS->SetWorldPos(Vector2(0.0f, 0.0f));

	CynthiaN->scale = CynthiaS->imageSize * 2.0f;
	CynthiaN->SetWorldPos(Vector2(0.0f, 0.0f));

	Cynthia = new ObImage(L"TextBar/Cynthia.png");
	Cynthia->scale = Cynthia->imageSize * 0.6f;
	Cynthia->SetWorldPos(Vector2(250.0f, 0.0f));


	for (int i = 0;i < 2;i++)
	{
		Arrow[i] = new ObImage(L"TextBar/Arrow.png");
		Arrow[i] ->scale.x = Arrow[i]->imageSize.x / 4.0f * 0.2f;
		Arrow[i]->scale.y = Arrow[i]->imageSize.y * 0.2f;
		Arrow[i]->maxFrame.x = 4;
		Arrow[i]->ChangeAnim(ANIMSTATE::LOOP, 0.2f);


	}

	Arrow[0]->rotation = 90.0f * ToRadian;
	Arrow[0]->SetWorldPos(Vector2(40.0f, 300.0f));

	Arrow[1]->rotation = - 90.0f * ToRadian;
	Arrow[1]->SetWorldPos(Vector2(180.0f, 0.0f));

	//Sound
	SOUND->AddSound("Starting_Town.wav", "Town_bgm1", true);
	SOUND->AddSound("Lavender_Town.wav", "Town_bgm2", true);
	SOUND->AddSound("Door.wav", "Door");
	SOUND->AddSound("Garchomp.wav", "GarchompScream");
	SOUND->AddSound("Beep.wav", "Beep");

	SOUND->Play("Town_bgm1");

	mouse = new Cursor;

	OrbBase = new ObImage(L"Ui/Ui_base.png");
	OrbBase->scale = OrbBase->imageSize * 3.0f;
	//OrbBase->SetWorldPos(Vector2(-app.GetHalfWidth() + 177.8f + 355.0f, 0.0f));

	Orb = new ObImage(L"Item/Griseous.png");
	Orb->scale = Orb->imageSize * 0.7f;
	//Orb->SetWorldPos(Vector2(-app.GetHalfWidth() + 177.8f + 355.0f, 0.0f));

}

void Scene02::Release()
{
	SafeDelete(LabH);
	SafeDelete(GameH);
	SafeDelete(TextH);
	SafeDelete(TextB);
	SafeDelete(Town1);
	SafeDelete(Town2);
	SafeDelete(PlayerS);
	SafeDelete(PlayerN);

	SafeDelete(Lab);
	SafeDelete(ProfessorOW);
	SafeDelete(Bang);
	SafeDelete(Professor);
	SafeDelete(CynthiaS);
	SafeDelete(CynthiaN);
	SafeDelete(Cynthia);
}

void Scene02::Update()
{
	Lab->SetWorldPos(Vector2(0.0f,0.0f));

	if (TextN == -1 && INPUT->KeyDown(VK_LBUTTON))
	{
		SOUND->Play("Door");
		SOUND->Play("Beep");
		TextN = 0;
	}

	if (mesIndex == battleMes.size() && TextN ==  0 && TextH->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyUp(VK_LBUTTON) && TextB->isVisible)
	{
		TextN++;
	}

	if (TextN == 1 && !LabH->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyUp(VK_LBUTTON))
	{
		SOUND->Play("Beep");
		//mesIndex = 0;
		mesIndex = 15;
		TextN = 2;
	}

	if (mesIndex == battleMes.size() && TextN == 2 && TextH->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyUp(VK_LBUTTON) && TextB->isVisible)
	{
		TextN = 1;
	}


	if (TextN == 1 && LabH->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyUp(VK_LBUTTON))
	{
		inLab = true;
		TextN = 3;
		SOUND->Play("Door");

	}

	if (TextN == 3 && INPUT->KeyDown(VK_LBUTTON))
	{
		TextN = 4;
	}

	if (TextN == 4)
	{
		ProfessorOW->MoveWorldPos(DOWN * 100.0f * DELTA);
		if (ProfessorOW->GetWorldPos().y < -200.0f)
		{
			SOUND->Play("Beep");
			TextN = 5;
		}
	}

	if (TextN == 5 && mesIndex == battleMes.size() && INPUT->KeyUp(VK_LBUTTON))
	{
		SOUND->Play("Beep");
		SOUND->Play("GarchompScream");
		mesIndex = 15;
		TextN = 6;
	}

	if (TextN == 6)
	{
		Lab->SetWorldPosX(0.0f + RANDOM->Float(-5.0f, 5.0f));
		Lab->Update();

		if (mesIndex == battleMes.size() && INPUT->KeyUp(VK_LBUTTON))
		{
			mesIndex = 15;
			TextN = 7;
		}

	}

	if (TextN == 7)
	{
		inLab = false;
		PlayerN->SetWorldPos(Vector2(0.0f, -180.0f));
		if (INPUT->KeyDown(VK_LBUTTON))
		{
			SOUND->Play("Beep");
			mesIndex = 15;
			TextN = 8;
		}
	}

	if (TextN == 8)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			SOUND->Play("Beep");
			mesIndex = 7;
			TextN = 9;
		}
	}

	if (TextN == 9)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			SOUND->Play("Beep");
			mesIndex = 7;
			TextN = 10;
		}
	}

	if (TextN == 10)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 0;
			TextN = 11;
		}
	}

	if (TextN == 11)
	{
		if (GameH->Intersect(INPUT->GetMouseWorldPos()) && INPUT->KeyDown(VK_LBUTTON))
		{
			SOUND->Stop("Town_bgm1");
			SCENE->ChangeScene("Loading", 0.0f);
			TextN = 12;
			return;

		}
		else
		{
			mesIndex = 0;
			TextN = 11;
		}
	}

	if (TextN == 12)
	{
		SOUND->Stop("Town_bgm1");
		SOUND->Play("Town_bgm2");
		PlayerS->SetWorldPos(Vector2(40.0f, 280.0f));

		if (INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 0;
			TextN = 13;
		}

	}



	if (TextN == 13) 
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 7;
			TextN = 14;
		}
	}

	if (TextN == 14)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 7;
			TextN = 15;
		}

	}

	if (TextN == 15)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 7;
			TextN = 16;
		}

	}

	if (TextN == 16)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 7;
			TextN = 17;
		}

	}

	if (TextN == 17)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 7;
			TextN = 18;
		}

	}

	if (TextN == 18)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 0;
			TextN = 19;
		}

	}

	if (TextN == 19)
	{
		if (mesIndex == battleMes.size() && INPUT->KeyDown(VK_LBUTTON))
		{
			mesIndex = 0;
			TextN = 20;
			SOUND->Stop("Town_bgm2");
			SCENE->ChangeScene("Scene01", 0.0f);
			TextN = 20;
			return;

		}

	}



	if (INPUT->KeyDown('Q'))
	{
		SOUND->Stop("Town_bgm1");
		SCENE->ChangeScene("Scene01", 0.0f);
		return;
	}


	LabH->Update();
	GameH->Update();
	TextH->Update();
	TextB->Update();
	Town1->Update();
	Town2->Update();
	PlayerS->Update();

	PlayerN->Update();
	Lab->Update();
	ProfessorOW->Update();
	Bang->Update();
	Professor->Update();

	CynthiaS->Update();
	CynthiaN->Update();
	Cynthia->Update();
	for (int i = 0;i < 2;i++)
	{
		Arrow[i]->Update();
	}
	mouse->Update();
	Orb->Update();
	OrbBase->Update();

}

void Scene02::LateUpdate()
{
}

void Scene02::Render()
{
	if (TextN < 12)
	{
		if (!inLab)
		{
			Town1->Render();
		}
		else
		{
			Lab->Render();
		}

	}
	else
	{
		Town2->Render();
	}


	//LabH->Render();
	//GameH->Render();


	switch (TextN)
	{
	case 0:
		PlayerS->Render();

		TextB->Render();
		battleMes = L"\n\nI'm finally 10!\nI gonna visit the Professor and \nget my first POKEMON\nRIGHT AWAY!!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));
		//TextB->Render();
		//DWRITE->RenderText(L"I'm finally 10!\nI gonna visit the Professor and get my first POKEMON\nRIGHT AWAY!!", RECT{ 350, 600, 1200, 700 }, 25.0f,
		//	L"배달의민족 주아", Color(0.0f, 0.0f, 0.0f, 1.0f),
		//	DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
		//	DWRITE_FONT_STRETCH_EXPANDED);
		break;
	case 1:
		PlayerS->Render();
		Arrow[1]->Render();

		break;
	case 2:
		PlayerS->Render();
		Arrow[1]->Render();
		TextB->Render();
		battleMes = L"\n\nRIGHT AWAY!!\nTo the Lab!!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		//TextB->Render();
		//DWRITE->RenderText(L"RIGHT AWAY!!\nTo the Lab!!", RECT{ 350, 600, 1200, 700 }, 25.0f,
		//	L"배달의민족 주아", Color(0.0f, 0.0f, 0.0f, 1.0f),
		//	DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
		//	DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 3:		
		Bang->Render();
		PlayerN->Render();
		ProfessorOW->Render();

		break;
	case 4:
		ProfessorOW->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
		ProfessorOW->Render();
		PlayerN->Render();
		break;
	case 5:
		ProfessorOW->ChangeAnim(ANIMSTATE::STOP, 0.1f);
		ProfessorOW->Render();
		PlayerN->Render();
		Professor->Render();
		TextB->Render();

		battleMes = L"Professor Rowan\n\nYou are 10 Already?.. Time flys fast..\nI'll let you choose your first POKEMON";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		break;
	case 6:
		ProfessorOW->Render();
		PlayerN->Render();
		Professor->Render();
		TextB->Render();

		battleMes = L"Professor Rowan\n\nWhat was that noise??\nWhat is happening outside?\nWe should check";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;
	case 7:
		CynthiaN->Render();
		Bang->Render();
		PlayerN->Render();
		break;
	case 8:
		CynthiaS->Render();
		Professor->Render();
		TextB->Render();

		battleMes = L"Professor Rowan\n\nIt's the Champion!\nWhat is happening here?";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 9:
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		battleMes = L"Cynthia\n\nIt's Ex - Champion now..\nPokemons are invading the Town!\nI stopped them for now\nbut they keep on coming!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		break;

	case 10:
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		battleMes = L"Cynthia\n\n(Hm.. that boy.. He reminds me of Him)\nKid! Help me protect this Town\nI'll be gaurding the Town.. You can stop\nPokemons from ROUTE 1.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 11:
		CynthiaS->Render();
		PlayerN->Render();
		Arrow[0]->Render();
		break;

	case 12:

		PlayerS->Render();
		CynthiaS->Render();

		break;
	case 13:
		PlayerS->Render();
		CynthiaS->Render();
		TextB->Render();

		battleMes = L"\n\nWhat..?\nWh..What happened here?\nWhat happened to EVERYONE?\nHELLO? ANYONE THERE??";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 14:
		PlayerS->Render();
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		battleMes = L"Cynthia\n\n\nI'm afraid NO ONE can answer you..\n..I needed their life force..";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.05))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 15:
		PlayerS->Render();
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		battleMes = L"Cynthia\n\nWhen I was in the DISTORTION WORLD\nI watched a kid catch A GOD and leave.\nNow that was an world changing event.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 16:
		PlayerS->Render();
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		battleMes = L"Cynthia\n\nBUT NOTHING HAPPEND!\nI thought to myself all the legends \nand myths are they REAL?\nAM I REAL?  IS ANYTHING REAL?";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 17:
		PlayerS->Render();
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		OrbBase->Render();
		Orb->Render();

		//insert image here
		battleMes = L"Cynthia\n\nThen I found THIS!\nIt contained GIRATINA'S POWER..\nNow that God is gone\nmaybe I can be a NEW ONE..";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 18:
		PlayerS->Render();
		CynthiaS->Render();
		Cynthia->Render();
		TextB->Render();

		OrbBase->Render();
		Orb->Render();


		battleMes = L"Cynthia\n\nbut It needed more POWER..\nSorry about your home town..\nI'll spare you since you helped me.\nNOW MOVE.. I STILL NEED MORE POWER..";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;

	case 19:
		PlayerS->Render();
		CynthiaS->Render();
		TextB->Render();

		battleMes = L"\n\nNO!\n\nI CAN'T LET YOU LEAVE!\nGIVE THEM BACK!!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}

		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 350, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		break;


	default:
		break;
	}









	mouse->Render();



}

void Scene02::ResizeScreen()
{
}

