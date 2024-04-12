#include "stdafx.h"

TextBar::TextBar()
{
	TextBase = new ObImage(L"TextBar/Poke_text_box.png");
	Professor = new ObImage(L"TextBar/Professor_Rowan.png");
	Cynthia = new ObImage(L"TextBar/Cynthia.png");
	Mars = new ObImage(L"TextBar/Mars.png");
	Jupiter = new ObImage(L"TextBar/Jupiter.png");
	Cyrus = new ObImage(L"TextBar/Cyrus.png");


	TextBase->scale = TextBase->imageSize;
	TextBase->SetWorldPos(Vector2(-150.0f, -250.0f));

	Professor->scale = Professor->imageSize;
	Professor->SetWorldPos(Vector2(120.0f, 0.0f));

	Mars->scale = Mars->imageSize * 0.75f;
	Mars->SetWorldPos(Vector2(120.0f, 0.0f));

	Jupiter->scale = Jupiter->imageSize * 0.65f;
	Jupiter->SetWorldPos(Vector2(120.0f, 50.0f));

	Cyrus->scale = Cyrus->imageSize * 0.75f;
	Cyrus->SetWorldPos(Vector2(100.0f, 0.0f));

	Cynthia->scale = Cynthia->imageSize * 0.6f;
	Cynthia->SetWorldPos(Vector2(120.0f, 0.0f));


	for (int i = 0; i < 2; i++)
	{
		Arrow[i] = new ObImage(L"TextBar/Arrow.png");
		Arrow[i]->scale.x = Arrow[i]->imageSize.x / 4.0f * 0.2f;
		Arrow[i]->scale.y = Arrow[i]->imageSize.y * 0.2f;
		Arrow[i]->maxFrame.x = 4;
		Arrow[i]->ChangeAnim(ANIMSTATE::LOOP, 0.2f);

	}

	Arrow[0]->SetWorldPos(Vector2(300.0f, 160.0f));
	Arrow[1]->SetWorldPos(Vector2(300.0f, -340.0f));

	HomeButton = new ObImage(L"Ui/Home.PNG");
	HomeButton->scale = HomeButton->imageSize * 0.3f;
	HomeButton->SetWorldPos(Vector2(595.0f, -341.0f));


	Giratina = new ObImage(L"TextBar/Giratina.png");
	Giratina->scale.x = Giratina->imageSize.x / 11.0f * 7.0f;
	Giratina->scale.y = Giratina->imageSize.y * 7.0f;
	Giratina->maxFrame.x = 11;
	Giratina->ChangeAnim(ANIMSTATE::LOOP, 0.2f);
	Giratina->SetWorldPos(Vector2(-300.0f, -50.0f));

	GiraEnter = new ObImage(L"TextBar/Giratina_Enter.png");
	GiraEnter->scale.x = GiraEnter->imageSize.x / 10.0f * 3.0f;
	GiraEnter->scale.y = GiraEnter->imageSize.y * 3.0f;
	GiraEnter->maxFrame.x = 10;
	GiraEnter->ChangeAnim(ANIMSTATE::ONCE, 0.5f);

	Lucas = new ObImage(L"TextBar/Lucas.png");
	Lucas->scale = Lucas->imageSize * 0.3f;
	Lucas->SetWorldPos(Vector2(100.0f, 0.0f));

	OrbBase = new ObImage(L"Ui/Ui_base.png");
	OrbBase ->scale = OrbBase->imageSize * 3.0f;
	OrbBase->SetWorldPos(Vector2(-app.GetHalfWidth() + 177.8f + 355.0f, 0.0f));

	Orb = new ObImage(L"Item/Griseous.png");
	Orb->scale = Orb->imageSize * 0.7f;
	Orb->SetWorldPos(Vector2(-app.GetHalfWidth() + 177.8f + 355.0f, 0.0f));

	Ending = new ObImage(L"TextBar/Ending.jpg");
	Ending->scale = Ending->imageSize * 1.2f;

}

TextBar::~TextBar()
{
}

void TextBar::Release()
{
}

void TextBar::Update()
{
	Cyrus->Update();
	Jupiter->Update();
	Mars->Update();
	Professor->Update();
	TextBase->Update();
	Arrow[0]->Update();
	Arrow[1]->Update();
	HomeButton->Update();
	Cynthia->Update();
	Lucas->Update();
	Giratina->Update();
	GiraEnter->Update();
	Orb->Update();
	OrbBase->Update();
	Ending->Update();

}

void TextBar::LateUpdate()
{
}

void TextBar::Render()
{
	switch (TurnN)
	{
	case 0:
		Professor->Render();
		TextBase->Render();

		battleMes = L"Professor Rowan\n\nHere! Choose your starter POKEMON.\nYou will meet more POKEMONs\nas you progress.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
		L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
		DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
		DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 1:
		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 2:

		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 3:		
		Professor->Render();
		TextBase->Render();
		Arrow[0]->Render();

		battleMes = L"Professor Rowan\n\nNice One!\nHope you two meet more friends\nNow drag your POKEMON on the map\nUsing the mouse.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 4:
		Arrow[0]->Render();

		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 5:
		Professor->Render();
		TextBase->Render();
		Arrow[1]->Render();


		battleMes = L"Professor Rowan\n\nGreat Job!\nNow click the green button\nand protect the town!\nGood Luck!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 6:
		Arrow[1]->Render();
		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 7:
		DWRITE->RenderText(L"WAVE 1", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 8:
		DWRITE->RenderText(L"WAVE 2", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 9:
		DWRITE->RenderText(L"WAVE 2", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 10:
		DWRITE->RenderText(L"WAVE 3", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 11:
		Mars->Render();
		TextBase->Render();

		battleMes = L"Mars\n\nWho are you?\nGet out of my way chump.\nOr my PURUGLY will make you.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 3", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 12:
		DWRITE->RenderText(L"WAVE 3", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 13:
		DWRITE->RenderText(L"WAVE 4", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 14:
		DWRITE->RenderText(L"WAVE 4", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);


		break;
	case 15:
		DWRITE->RenderText(L"WAVE 5", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 16:
		DWRITE->RenderText(L"WAVE 5", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 17:
		DWRITE->RenderText(L"WAVE 6", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 18:
		Jupiter->Render();
		TextBase->Render();

		battleMes = L"Jupiter\n\nWhere is Mars?\nI got orders..\nMove out of the way kid.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 6", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;
	case 19:
		DWRITE->RenderText(L"WAVE 6", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 20:
		DWRITE->RenderText(L"WAVE 7", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 21:
		DWRITE->RenderText(L"WAVE 8", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 22:
		DWRITE->RenderText(L"WAVE 8", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 23:
		Cyrus->Render();
		TextBase->Render();

		battleMes = L"Cyrus\n\n...Move.\nI don't want unnecessary trouble.\n...I got places to be.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 9", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 24:
		DWRITE->RenderText(L"WAVE 9", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 25:
		Cyrus->Render();
		TextBase->Render();

		battleMes = L"Cyrus\n\n...This cannot be...\n...We need to STOP HER...";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 9", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 26:
		TextBase->Render();
		HomeButton->Render();

		battleMes = L"\n\nI wonder what he meant by that..\nIt seems the attack has stopped!\nI should check on the town.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));

		DWRITE->RenderText(L"WAVE 9", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 27:
		Cynthia->Render();
		TextBase->Render();

		battleMes = L"Cynthia\n\nYou think you can STOP ME?\nYou should have ran when I gave a chance";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 28:

		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 29:

		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 30:
		Cynthia->Render();
		TextBase->Render();

		battleMes = L"Cynthia\n\nI got bested by A KID again?\n\n.....";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 31:
		Cynthia->Render();
		TextBase->Render();
		//item image 
		OrbBase->Render();
		Orb->Render();

		battleMes = L"Cynthia\n\nIt doesn't matter..\nI can just use THIS!\n\n....WHAT...?";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);

		break;

	case 32:
		GiraEnter->Render();
		break;

	case 33:
		Cynthia->Render();
		TextBase->Render();
		//item image 
		battleMes = L"Cynthia\n\nGIRATINA?\nI thought you were gone!?";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;


	case 34:
		Lucas->Render();
		TextBase->Render();
		//item image 
		battleMes = L"Lucas\n\nI'M HERE!\nThis has to STOP!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 35:
		Lucas->Render();
		TextBase->Render();
		//item image 
		battleMes = L"Lucas\n\nGIRATINA sensed trouble and\nwe came as soon as we could.";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 36:
		Giratina->Render();
		TextBase->Render();
		//item image 
		battleMes = L"\n\nGIRATINA used SHADOW DIVE";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 37:
		Giratina->Render();
		TextBase->Render();
		//item image 
		battleMes = L"\n\nGIRATINA used SHADOW DIVE";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 38:
		Giratina->Render();
		TextBase->Render();
		//item image 
		battleMes = L"\n\nGIRATINA used SHADOW DIVE";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 39:
		TextBase->Render();
		battleMes = L"\n\nEverything returned to Normal!";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 40:
		Giratina->Render();
		TextBase->Render();
		battleMes = L"GIRATINA\n\n(Your thrist for knowledge \n has consumed you..)\n(Your ancestor walked the same path..)";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 41:
		Cynthia->Render();
		TextBase->Render();

		battleMes = L"Cynthia\n\nGiratina is right..\nI'm sorry.. to you and your town.\nI'll have to go apologies..\nAfter that you do what you must do..";
		if (mesIndex < battleMes.size())
		{
			if (TIMER->GetTick(mesTime, 0.02))
			{
				mesIndex++;
			}
		}
		DWRITE->RenderText(battleMes.substr(0, mesIndex), RECT{ 200, 560, 1200, 700 }, 25.0f, L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f));


		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;

	case 42:
		Ending->Render();

		DWRITE->RenderText(L"WAVE 10", RECT{ 1150, 25, 1500, 100 }, 25.0f,
			L"PKMN RBYGSC", Color(0.0f, 0.0f, 0.0f, 1.0f),
			DWRITE_FONT_WEIGHT_BOLD, DWRITE_FONT_STYLE_ITALIC,
			DWRITE_FONT_STRETCH_EXPANDED);
		break;


	default:
		break;
	}
}
