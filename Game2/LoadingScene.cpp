#include "stdafx.h"

int initCount = 0;
mutex m;

void CreateScene()
{
	{ //익명스코프
		Scene01* temp = new Scene01;
		SCENE->AddScene("Scene01", temp);
	}

	//m.lock();
	//initCount++;
	//m.unlock();
	//Sleep(1000);

	//m.lock();
	//initCount++;
	//m.unlock();
	//Sleep(1000);

	//m.lock();
	//initCount++;
	//m.unlock();
	//Sleep(1000);

	//m.lock();
	//initCount++;
	//m.unlock();
	//Sleep(1000);

	//m.lock();
	//initCount++;
	//m.unlock();
	//Sleep(1000);

	//m.lock();
	//initCount++;
	//m.unlock();
	//Sleep(1000);

}

void LoadingScene::Init()
{
	th = new thread(CreateScene);

	pika = new ObImage(L"Pika_dance.png");
	pika->scale.x = pika->imageSize.x / 12.0f ;
	pika->scale.y = pika->imageSize.y ;
	pika->maxFrame.x = 12;
	pika->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	pika->SetWorldPos(Vector2(500.0f, -300.0f));

	bg = new ObImage(L"Loading_starter.jpg");
	bg->scale = bg->imageSize * 1.0f;


	bar = new ObRect();
	bar->pivot = OFFSET_L;
	bar->scale = Vector2(100.0f, 30.0f);
	bar->SetWorldPosX(-app.GetHalfWidth());

	LIGHT->light.lights[0].radius = 2000.0f;
}

void LoadingScene::Release()
{
	th->join();
	SafeDelete(th);
	SafeDelete(bg);
	SafeDelete(pika);
	SafeDelete(bar);
}

void LoadingScene::Update()
{
	if (initCount == 6)
	{
		SCENE->ChangeScene("Scene01");
		return;
	}

	bg->Update();
	bar->Update();
	pika->Update();
}

void LoadingScene::LateUpdate()
{
}

void LoadingScene::Render()
{

	bg->Render();
	//bar->Render();
	pika->Render();
}

void LoadingScene::ResizeScreen()
{
}
