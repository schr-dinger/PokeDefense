#pragma once
class Magby : public Bloon
{
public:
	Magby();
	~Magby();



	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

