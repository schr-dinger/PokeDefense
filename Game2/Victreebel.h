#pragma once
class Victreebel : public Bloon
{
public:
	Victreebel();
	~Victreebel();

	// Bloon��(��) ���� ��ӵ�
	virtual void Release() override;
	virtual void Update() override;
	virtual void LateUpdate() override;
	virtual void Render() override;
};

