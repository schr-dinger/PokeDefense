#pragma once
class Delibird : public Tower
{
public:
	float CandyTimer = 0.0f;

	ObRect* FullCandyBar;
	ObRect* RealCandyBar;



	Delibird();
	~Delibird();

	// Tower��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

