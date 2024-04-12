#pragma once
class Turtwig : public Tower
{
public:
	ObImage* Earthquake;
	float QuakeTimer = 0.0f;
	bool isQuaking = false;
	bool isJumping = false;
	float gravity = 0.0f;


	Turtwig();
	~Turtwig();

	// Tower��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

