#pragma once
class Charmander : public Tower
{
public:





	ObImage* FireEffect;
	ObRect* BreathHit;

	Charmander();
	~Charmander();

	// Tower��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

