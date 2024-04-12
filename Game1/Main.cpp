#include "stdafx.h"
#include "Main.h"

void Main::Init()
{
	bg1 = new ObImage(L"C_bg1.png");
	bg1->scale = Vector2(bg1->imageSize) * 2.0f;
	bg1->SetWorldPosY(50.0f);
	bg1->space = SPACE::SCREEN;
	
	bg2 = new ObImage(L"C_bg2.png");
	bg2->scale = Vector2(bg2->imageSize) * 2.0f;
	bg2->SetWorldPosY(50.0f);
	bg2->space = SPACE::SCREEN;

	for (int i = 0; i < FMAX; i++)
	{
		floors[i] = new ObImage(L"C_floor.png");
		//floors[i]->scale = Vector2(124.0f, 140.0f);
		floors[i]->scale = Vector2(floors[i]->imageSize.x, floors[i]->imageSize.y);
		floors[i]->pivot = OFFSET_LT;
		floors[i]->SetWorldPosY(-app.GetHalfHeight() + floors[i]->imageSize.y);
		floors[i]->SetWorldPosX(-app.GetHalfWidth() + floors[i]->scale.x * i);
	}

	for (int i = 0; i < JMAX; i++)
	{
		jelly[i] = new ObImage(L"C_jelly.png");
		jelly[i]->scale = Vector2(jelly[i]->imageSize.x, jelly[i]->imageSize.y);
		jelly[i]->SetWorldPosY(sinf(i * 18.0f * ToRadian) * 200.0f);
		jelly[i]->SetWorldPosX(80.0f * i);
	}

	sparkle = new Cookie;
	sparkle->col->SetWorldPosX(-300.0f);
	sparkle->col->SetWorldPosY(-app.GetHalfHeight() + floors[0]->imageSize.y);

	timer = 0.0f;
	test = 1.0f;
}

void Main::Release()
{
	for (int i = 0; i < FMAX; i++)
	{
		SafeDelete(floors[i]);
	}
	for (int i = 0; i < JMAX; i++)
	{
		SafeDelete(jelly[i]);
	}
	SafeDelete(sparkle);
	SafeDelete(bg1);
	SafeDelete(bg2);
}

void Main::Update()
{
	/*
	ImGui::SliderFloat("Test", &test, 0.1f, 10.0f);
	floors[0]->scale = Vector2(floors[0]->imageSize.x, 
		floors[0]->imageSize.y) * test;*/

	ImGui::SliderFloat2("LightPos0", (float*)&LIGHT->light.lights[0].screenPos, 0.0f, 1200.0f);
	ImGui::SliderFloat("Radius0", &LIGHT->light.lights[0].radius, 0.0f, 2000.0f);

	ImGui::SliderFloat2("LightPos1", (float*)&LIGHT->light.lights[1].screenPos, 0.0f, 1200.0f);
	ImGui::SliderFloat("Radius1", &LIGHT->light.lights[1].radius, 0.0f, 2000.0f);


	ImGui::ColorEdit3("inColor", (float*)&LIGHT->light.inColor, ImGuiColorEditFlags_PickerHueWheel);
	ImGui::ColorEdit3("outColor", (float*)&LIGHT->light.outColor, ImGuiColorEditFlags_PickerHueWheel);
	ImGui::SliderFloat("Select", &LIGHT->light.select.x, 0.0f, 1.0f);

	bg1->uv.x += DELTA / bg1->scale.x * 50.0f;
	bg1->uv.z += DELTA / bg1->scale.x * 50.0f;

	bg2->uv.x += DELTA / bg1->scale.x * 100.0f;
	bg2->uv.z += DELTA / bg1->scale.x * 100.0f;

	//ImGui::SliderFloat("DeltaScale", &app.deltaScale, 1.0f, 8.0f);
	//app.deltaScale += 0.1f * TIMER->GetDelta();
	//Utility::Saturate(app.deltaScale, 1.0f, 8.0f);

	//CAM->position += RIGHT * 100.0f * DELTA;

	for (int i = 0; i < FMAX; i++)
	{
		floors[i]->Update();
	}
	for (int i = 0; i < JMAX; i++)
	{
		jelly[i]->Update();
	}
	sparkle->Update();
	bg1->Update();
	bg2->Update();
}

//모든 객체가 움직이고 난 후
void Main::LateUpdate()
{
	for (int i = 0; i < FMAX; i++)
	{
		if (floors[i]->Intersect(sparkle->col))
		{
			sparkle->col->SetWorldPosY(-app.GetHalfHeight() 
				+ floors[0]->imageSize.y);
			sparkle->gravity = 0.0f;

			if (sparkle->state == CState::JUMP)
			{
				// 착지
				sparkle->jump->isVisible = false;
				sparkle->landing->isVisible = true;
				sparkle->isDoubleJump = true;
				
				if (TIMER->GetTick(timer, 0.3f))
				{
					// 런
					sparkle->state = CState::RUN;
					sparkle->run->isVisible = true;
					sparkle->landing->isVisible = false;
					sparkle->isDoubleJump = false;
				}
			}
			
		}
	}

	for (int i = 0; i < JMAX; i++)
	{
		if (jelly[i]->Intersect(sparkle->col))
		{
			jelly[i]->isVisible = false;
			sparkle->TakeDamage();
		}
	}

	for (int i = 0; i < FMAX; i++)
	{
		float length = sparkle->col->GetWorldPos().x - floors[i]->GetWorldPos().x;
		if (length > 600.0f)
		{
			floors[i]->MoveWorldPos(FMAX * Vector2(floors[i]->scale.x, 0.0f));
		}
	}

	for (int i = 0; i < JMAX; i++)
	{
		float length = sparkle->col->GetWorldPos().x - jelly[i]->GetWorldPos().x;
		if (length > 500.0f)
		{
			jelly[i]->MoveWorldPos(JMAX * Vector2(80.0f, 0.0f));
			jelly[i]->isVisible = true;
		}
	}
}

void Main::Render()
{
	bg1->Render();
	bg2->Render();
	for (int i = 0; i < FMAX; i++)
	{
		floors[i]->Render();
	}
	for (int i = 0; i < JMAX; i++)
	{
		jelly[i]->Render();
	}
	sparkle->Render();
	
}

void Main::ResizeScreen()
{
}

int WINAPI wWinMain(HINSTANCE instance, HINSTANCE prevInstance, LPWSTR param, int command)
{
    app.SetAppName(L"Game1");
    app.SetInstance(instance);
	app.InitWidthHeight(1400.0f , 800.0f);
	WIN->Create();
	Main* main = new Main();
	int wParam = (int)WIN->Run(main);
	SafeDelete(main);
	WIN->Destroy();
	WIN->DeleteSingleton();
	
	return wParam;
}