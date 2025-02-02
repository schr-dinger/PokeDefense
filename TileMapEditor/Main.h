#pragma once
class Main : public Scene
{
private:
	ObTileMap* map;

	Int2		tileIdx;
	Int2		guiPickingIdx;
	int			imgIdx; 
	Int2		tileSize;
	Color		tileColor;
	int			tileState;
	ObImage* FealMap;

public:
	virtual void Init() override;
	virtual void Release() override; //����
	virtual void Update() override;
	virtual void LateUpdate() override;//����
	virtual void Render() override;
	virtual void ResizeScreen() override;

	void MoveCam();
};
