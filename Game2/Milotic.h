#pragma once
class Milotic : public Bloon
{
public:

	Milotic();
	~Milotic();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
};

