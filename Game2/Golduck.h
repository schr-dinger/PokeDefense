#pragma once
class Golduck : public Bloon
{
public:
	Golduck();
	~Golduck();
	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

