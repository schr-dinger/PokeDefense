#pragma once
class Skuntank : public  Bloon
{
public:
	ObImage* Fart;

	ObCircle* FartHit;



	Skuntank();
	~Skuntank();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

