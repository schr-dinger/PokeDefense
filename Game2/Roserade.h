#pragma once
class Roserade : public Bloon
{
public:

	Roserade();
	~Roserade();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
};

