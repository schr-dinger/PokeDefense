#pragma once
class Ninetails : public Bloon
{
public:
	Ninetails();
	~Ninetails();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
};

