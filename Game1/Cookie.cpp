#include "stdafx.h"

Cookie::Cookie()
{
	col = new ObRect();
	run = new ObImage(L"C_run.png");
	slide = new ObImage(L"C_slide.png");
	jump = new ObImage(L"C_jump2.png");
	landing = new ObImage(L"C_cheat.png");

	col->scale = Vector2(100.0f, 200.0f);
	col->pivot = OFFSET_B;
	col->isFilled = false;

	run->scale.x = run->imageSize.x / 4.0f;
	run->scale.y = run->imageSize.y;
	run->pivot = OFFSET_B;
	run->SetParentRT(*col);
	run->maxFrame.x = 4;
	run->ChangeAnim(ANIMSTATE::LOOP, 0.1f);
	//run->color = Color(0.3f, 0.0f, 0.0f, 0.5f);
	//run->color = Color(0.3f, 0.0f, 0.0f, 0.0f);
	//run->uv = Vector4(0.0f, 0.0f, 1.0f/4.0f, 1.0f);

	slide->scale.x = slide->imageSize.x / 5.0f;
	slide->scale.y = slide->imageSize.y;
	slide->pivot = OFFSET_B;
	slide->SetParentRT(*col);
	slide->maxFrame.x = 5;
	slide->isVisible = false;

	jump->scale.x = jump->imageSize.x / 8.0f;
	jump->scale.y = jump->imageSize.y;
	jump->pivot = OFFSET_B;
	jump->SetParentRT(*col);
	jump->maxFrame.x = 8;
	jump->isVisible = false;

	landing->scale.x = landing->imageSize.x / 2.0f;
	landing->scale.y = landing->imageSize.y;
	landing->pivot = OFFSET_B;
	landing->SetParentRT(*col);
	landing->maxFrame.x = 2;
	landing->isVisible = false;

	gravity = 0.0f;
	isDoubleJump = false;
	isDamage = false;

	state = CState::RUN;
}

Cookie::~Cookie()
{
	SafeDelete(col);
	SafeDelete(run);
	SafeDelete(slide);
	SafeDelete(jump);
	SafeDelete(landing);
}

void Cookie::Update()
{
	switch (state)
	{
	case CState::RUN:
		Run();
		break;
	case CState::JUMP:
		Jump();
		break;
	case CState::SLIDE:
		Slide();
		break;
	}

	Vector2 velocity = RIGHT * 100.0f + DOWN * gravity;
	col->MoveWorldPos(velocity * DELTA);
	gravity += 300.0f * DELTA;

	if (isDamage)
	{
		run->color.w = RANDOM->Float(0.0f, 0.5f);
		jump->color.w = RANDOM->Float(0.0f, 0.5f);
		slide->color.w = RANDOM->Float(0.0f, 0.5f);
		landing->color.w = RANDOM->Float(0.0f, 0.5f);

		if (TIMER->GetTick(timer, 0.5f))
		{
			isDamage = false;
			run->color.w = 0.5f;
			jump->color.w = 0.5f;
			slide->color.w = 0.5f;
			landing->color.w = 0.5f;
		}
	}

	col->Update();
	run->Update();
	slide->Update();
	jump->Update();
	landing->Update();

	//if (state == CState::RUN)
	//{
	//	//jump
	//	if (INPUT->KeyDown(VK_SPACE))
	//	{
	//		state = CState::JUMP;
	//	}

	//	//slide
	//}
	//else if(state == CState::SLIDE)
	//{
	//	//run
	//}
	//else if (state == CState::JUMP)
	//{
	//	//run
	//}
}

void Cookie::Render()
{
	col->Render();
	run->Render();
	slide->Render();
	jump->Render();
	landing->Render();
}

void Cookie::Run()
{
	gravity = 0.0f;

	//jump
	if (INPUT->KeyDown(VK_SPACE))
	{
		state = CState::JUMP;
		jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		landing->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		run->isVisible = false;
		jump->isVisible = true;
		gravity = -300.0f;
	}

	//slide
	if (INPUT->KeyPress(VK_DOWN))
	{
		state = CState::SLIDE;
		slide->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		run->isVisible = false;
		slide->isVisible = true;
	}
}

void Cookie::Slide()
{
	gravity = 0.0f;

	//run
	if (INPUT->KeyUp(VK_DOWN))
	{
		state = CState::RUN;
		run->isVisible = true;
		slide->isVisible = false;
	}
}

void Cookie::Jump()
{
	if (!isDoubleJump && INPUT->KeyDown(VK_SPACE))
	{
		isDoubleJump = true;
		jump->ChangeAnim(ANIMSTATE::ONCE, 0.1f);
		gravity = -300.0f;
	}



	//run
}

void Cookie::TakeDamage()
{
	isDamage = true;
	timer = 0.0f;
}
