#pragma once
class Magmator : public Bloon
{
public:

	Magmator();
	~Magmator();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

