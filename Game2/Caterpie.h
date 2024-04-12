#pragma once
class Caterpie : public Tower
{
public:
	ObCircle* PoisonHit;
	ObImage* Poison;
	Vector2 Poisondir;

	float PoisonTimer = 0.0f;


	Caterpie();
	~Caterpie();

	// Tower��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;


	bool ShootPoison();

};

