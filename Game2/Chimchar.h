#pragma once
class Chimchar : public Tower
{
public:
	ObImage* FireUp;
	float UpTimer = 0.0f;
	bool Firing = false;

	Chimchar();
	~Chimchar();

	// Tower��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

