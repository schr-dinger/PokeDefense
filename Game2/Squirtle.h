#pragma once
class Squirtle : public Tower
{
public:
	ObCircle* BubbleHit[3];
	ObImage* Bubble[3];
	Vector2 Bubbledir[3];

	float BubbleTimer = 0.0f;

	Squirtle();
	~Squirtle();


	// Tower을(를) 통해 상속됨
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

	bool ShootBubble1();
	bool ShootBubble2();
	bool ShootBubble3();


};

