#pragma once
class Purugly : public Bloon
{
public:




	Purugly();
	~Purugly();
	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;

};

