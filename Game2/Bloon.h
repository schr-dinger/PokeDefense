#pragma once
class Bloon : public Entity
{
public:
	enum class NEWS
	{
		E,
		NE,
		N,
		NW,
		W,
		SW,
		S,
		SE
	};

	enum class DEFTYPE
	{
		NormalType,
		FireType,
		GrassType,
		WaterType,
		DragonType
	};


	ObImage* Move[8];
	ObImage* Hurt[8];
	ObTileMap* map;

	//길찾기용 변수
	vector<Tile*> Way;
	//이동시킬 위치
	Vector2 Dest;
	Vector2 Sour;
	//비율
	float   g;

	float Hp;



	NEWS state;
	//GameObject* Cen;

	float ratio = 1.0f;
	Vector2 StartP = Vector2(285.0f, 400.0f);
	Vector2 EndP = Vector2(500.0f, 46.0f);


	bool Calculate = false;
	bool Go = false;
	bool Dead = false;
	float DeadTimer = 0.0f;

	float Speed = 10.0f;
	float FullSpeed = 10.0f;
	float SlowSpeed = 5.0f;
	float StunSpeed = 0.0f;

	//맞기
	ObCircle* BlHit;
	DEFTYPE DefType;
	bool isBurning = false;
	float Health ;
	float FullHealth;
	ObRect* FullHpBar;
	ObRect* RealHpBar;

	ObImage* BurnEffect;
	float BurnTimer;

	ObImage* DefenseDown;
	bool DefenseLowered = false;
	float DefenseTimer = 0.0f;
	float Defense = 1.0f;

	Bloon();
	~Bloon();
	virtual void Release() = 0;
	virtual void Update() = 0;
	virtual void LateUpdate() = 0;
	virtual void Render() override;

	void E();
	void NE();
	void N();
	void NW();
	void W();
	void SW();
	void S();
	void SE();

	void Reset();
};

