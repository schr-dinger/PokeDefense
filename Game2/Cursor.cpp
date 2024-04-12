#include "stdafx.h"

Cursor::Cursor()
{
	Mouse = new GameObject;


	Default = new ObImage(L"Cursor/Cursor_default.png");
	Default->SetParentRT(*Mouse);
	Default->scale = Default->imageSize * 0.3f;
	Default->SetLocalPos(Vector2(20.0f, -20.0f));

	Grab = new ObImage(L"Cursor/Cursor_grab.png");
	Grab->SetParentRT(*Mouse);
	Grab->scale = Grab->imageSize * 0.3f;
	Grab->SetLocalPos(Vector2(20.0f, -20.0f));

	Letgo = new ObImage(L"Cursor/Cursor_letgo.png");
	Letgo->SetParentRT(*Mouse);
	Letgo->scale = Letgo->imageSize * 0.3f;
	Letgo->SetLocalPos(Vector2(20.0f, -20.0f));

	mstate = Mstate::D;
}

Cursor::~Cursor()
{
}

void Cursor::Release()
{
}

void Cursor::Update()
{
	Mouse->SetWorldPos(INPUT->GetMouseWorldPos());

	GrabTimer += DELTA;

	switch (mstate)
	{
	case Mstate::D:
		D();
		break;

	case Mstate::G:
		G();
		break;

	case Mstate::L:
		L();
		break;
	}





	Mouse->Update();
	Default->Update();
	Grab->Update();
	Letgo->Update();
}

void Cursor::LateUpdate()
{
}

void Cursor::Render()
{
	Default->Render();
	Grab->Render();
	Letgo->Render();
}

void Cursor::D()
{
	Default->isVisible = true;
	Grab->isVisible = false;
	Letgo->isVisible = false;

	if (INPUT->KeyPress(VK_LBUTTON))
	{
		mstate = Mstate::G;
	}


}

void Cursor::G()
{
	Default->isVisible = false;
	Grab->isVisible = true;
	Letgo->isVisible = false;

	if (INPUT->KeyUp(VK_LBUTTON))
	{
		GrabTimer = 0.0f;
		mstate = Mstate::L;
	}
}

void Cursor::L()
{
	Default->isVisible = false;
	Grab->isVisible = false;
	Letgo->isVisible = true;

	if (GrabTimer > 0.2f)
	{
		mstate = Mstate::D;
	}

}
