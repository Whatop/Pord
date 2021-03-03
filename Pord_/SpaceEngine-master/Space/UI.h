#pragma once
class UI : public Singleton<UI>, public Object 
{
	Sprite* m_BGHpBar;
	Sprite* m_HpBar;

	Sprite* m_DashUI;
	Sprite* m_DashBlind;

	Sprite* m_HealUI;
	Sprite* m_HealBlind;

	Sprite* m_Karma;
	Sprite* m_State;
	Sprite* m_StateBar;
	Sprite* m_BGStateBar;

	Sprite* m_State_RGB;
	Sprite* m_State_Fire;
	Sprite* m_State_Poison;

	TextMgr* m_HpText;
	TextMgr* m_DashText;
	TextMgr* m_HealText;
	TextMgr* m_KarmaText;
	TextMgr* m_StateText;

public:
	UI();
	~UI();

	int m_MaxHp;
	int m_Hp;
	float m_HpGage;
	float m_StateGage;

	float m_DashCooldown;
	float m_HealCooldown;
	std::string m_CurrentState;
	float m_Fire;
	float m_Poison;
	int Karma;

	void Init();
	void Release();

	void Update();
	void Render();
};

