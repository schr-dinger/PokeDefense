#include "stdafx.h"

Bullet::Bullet()
{
	arrow.scale.x = 50.0f;
	arrow.scale.y = 10.0f;
	//arrow.isVisible = false;
	arrow.isVisible = false;
	arrow.pivot = OFFSET_L;
	arrow.isAxis = true;
}

Bullet::~Bullet()
{
}

void Bullet::Update(ObRect rc)
{
	if (!arrow.isVisible) return;

	Vector2 velocity = fireDir * scalar + DOWN * gravity;
	//Vector2 velocity = fireDir * scalar;
	arrow.MoveWorldPos(velocity * DELTA);
	arrow.rotation = Utility::DirToRadian(velocity);
	arrow.color = Color(RANDOM->Float(), RANDOM->Float(), RANDOM->Float(), 1.0f);
	
	arrow.Update();
	gravity += 300.0f * DELTA;
	//scalar += 300.0f * DELTA;
	//cout << scalar << endl;

	//거리비교
	/*Vector2 dis = arrow.GetWorldPos() - rc.GetWorldPos();
	if (dis.Length() > 1400.0f)
	{
		arrow.isVisible = false;
	}*/
}

void Bullet::LateUpdate()
{
	if (!arrow.isVisible) return;

	//0.5f; 1.0f; 0.0f; 0.3f;
	//판정
	//위 실수 -> 부동소수점 -> 근사값 등호XXXX
	if (arrow.GetWorldPos().y >= app.GetHalfHeight() + CAM->position.y)
	{
		//cout << "dddd" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		arrow.SetWorldPosY(app.GetHalfHeight() + CAM->position.y);
	}
	//아래
	else if (arrow.GetWorldPos().y <= -app.GetHalfHeight() + CAM->position.y)
	{
		//cout << "dddd" << endl;
		fireDir.y *= -1.0f;
		gravity *= -1.0f;

		scalar *= 0.7f;
		gravity *= 0.7f;

		arrow.SetWorldPosY(-app.GetHalfHeight() + CAM->position.y);
	}
	//오른쪽 
	else if (arrow.GetWorldPos().x >= app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "dddd" << endl;
		fireDir.x *= -1.0f;
		scalar *= 0.7f;
		arrow.SetWorldPosX(app.GetHalfWidth() + CAM->position.x);
	}
	//왼쪽
	else if (arrow.GetWorldPos().x <= -app.GetHalfWidth() + CAM->position.x)
	{
		//cout << "dddd" << endl;
		fireDir.x *= -1.0f;
		scalar *= 0.7f;
		arrow.SetWorldPosX(-app.GetHalfWidth() + CAM->position.x);
	}
}

void Bullet::Render()
{
	if (!arrow.isVisible) return;

	arrow.Render();
}

bool Bullet::Shoot(ObRect rc, float scalar, Vector2 firePos)
{
	if (!arrow.isVisible)
	{
		arrow.isVisible = true;
		arrow.SetWorldPos(firePos);
		fireDir = rc.GetRight();                          
		arrow.rotation = Utility::DirToRadian(rc.GetRight());
		//arrow.isVisible = true;

		//rand() % 10 + 1;
		//0 ~ 100 -> 200 ~ 400
		this->scalar = scalar * 2.0f + 200.0f;
		//this->scalar = -scalar * 5.0f;

		gravity = 0.0f;

		return true;
	}

	return false;
}
