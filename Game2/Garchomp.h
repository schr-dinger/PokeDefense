#pragma once
class Garchomp : public Bloon
{
public:

	ObImage* Burrow[8];

	float BurrowTimer = 0.0f;
	bool Burrowed = false;

	Garchomp();
	~Garchomp();
	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

