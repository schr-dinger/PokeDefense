#pragma once
class Rattata : public Bloon
{
public:
	Rattata();
	~Rattata();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

