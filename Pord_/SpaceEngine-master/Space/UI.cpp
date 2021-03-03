#include "stdafx.h"
#include "UI.h"

UI::UI()
{

}

UI::~UI()
{
}

void UI::Init()
{
	m_BGHpBar = Sprite::Create(L"Painting/UI/BGHpBar.png");
	m_BGHpBar->SetPosition(m_BGHpBar->m_Size.x / 2 + 10, 30);

	m_HpBar = Sprite::Create(L"Painting/UI/HpBar.png");
	m_HpBar->SetPosition(m_BGHpBar->m_Size.x / 2 + 10, 30);
	
	m_DashUI = Sprite::Create(L"Painting/UI/DashUI.png");
	m_DashUI->SetPosition(1500, 950);

	m_DashBlind = Sprite::Create(L"Painting/UI/Blind.png");
	m_DashBlind->SetPosition(1500, 957);

	m_Karma = Sprite::Create(L"Painting/UI/Karma.png");
	m_Karma->SetPosition(40, 90);

	m_State = Sprite::Create(L"Painting/UI/State.png");
	m_State->SetPosition(100, 950);

	m_State_Fire = Sprite::Create(L"Painting/UI/State_Fire.png");
	m_State_Fire->SetPosition(100, 950);
	
	m_State_Poison = Sprite::Create(L"Painting/UI/State_Poison.png");
	m_State_Poison->SetPosition(100, 950);
	
	m_State_RGB = Sprite::Create(L"Painting/UI/State_RGB.png");
	m_State_RGB->SetPosition(100, 950);

	m_HealUI = Sprite::Create(L"Painting/UI/HealUI.png");
	m_HealUI->SetPosition(1650, 950);
	
	m_HealBlind = Sprite::Create(L"Painting/UI/Blind.png");
	m_HealBlind->SetPosition(1650, 957);

	m_HpText = new TextMgr();
	m_HpText->Init(30, false, false, "Arial");
	m_HpText->SetColor(255, 255, 255, 255);


	m_DashText = new TextMgr(); 
	m_DashText->Init(72, false, false, "Arial");
	m_DashText->SetColor(255, 255, 255, 255);

	m_HealText = new TextMgr();
	m_HealText->Init(72, false, false, "Arial");
	m_HealText->SetColor(255, 255, 255, 255);

	m_KarmaText = new TextMgr();
	m_KarmaText->Init(60, false, false, "궁서체");
	m_KarmaText->SetColor(255, 255, 255, 255);
	
	m_StateText = new TextMgr();
	m_StateText->Init(40, false, false, "궁서체");
	m_StateText->SetColor(255, 255, 255, 255);

	ObjMgr->AddObject(m_BGHpBar, "UI");
	ObjMgr->AddObject(m_HpBar, "UI");

	ObjMgr->AddObject(m_DashUI, "UI");
	ObjMgr->AddObject(m_DashBlind, "UI");

	ObjMgr->AddObject(m_HealUI, "UI");
	ObjMgr->AddObject(m_HealBlind, "UI");

	ObjMgr->AddObject(m_Karma, "UI");
	ObjMgr->AddObject(m_State, "UI");

	ObjMgr->AddObject(m_State_Fire, "UI");
	ObjMgr->AddObject(m_State_Poison, "UI");
	ObjMgr->AddObject(m_State_RGB, "UI");
	m_State_Fire->A = 0;
	m_State_Poison->A = 0;
	m_State_RGB->m_Rect.bottom = 0;
}

void UI::Release()
{
}

void UI::Update()
{
	//플레이어의 기본적으로 3의 카르마가 있어
	//if (m_PlayerState == State::STUN)
	//{
	//	m_State->R = 255;
	//	m_State->G = 196;
	//	m_State->B = 1;
	//	m_CurrentState = "STUN";
	//}
	//if (m_PlayerState == State::SLOW)
	//{
	//	m_CurrentState = "SLOW";
	//}
	//if (m_PlayerState == State::POISON)
	//{
	//	m_State->R = 43;
	//	m_State->G = 165;
	//	m_State->B = 65;
	//	m_CurrentState = "POISON";
	//}
	//if (m_PlayerState == State::FIRE)
	//{
	//	m_State->R = 250;
	//	m_State->G = 61;
	//	m_State->B = 47;
	//	m_CurrentState = "FIRE";
	//}
	//if (!(m_PlayerState == State::FIRE) && m_Fire >= 0.1f)
	//{
	//	m_State->R = 250;
	//	m_State->G = 61;
	//	m_State->B = 47;
	//	m_CurrentState = "FIRE";
	//}
	//if (m_PlayerState == State::WATER)
	//{
	//	m_PlayerState = State::WATER;
	//}
	//if (m_PlayerState == State::SLEEP)
	//{
	//	m_State->R = 238;
	//	m_State->G = 234;
	//	m_State->B = 223;
	//	m_PlayerState = State::SLEEP;
	//}
	//if (m_PlayerState == State::CHARM)//매력==매혹
	//{
	//	m_State->R = 255;
	//	m_State->G = 42;
	//	m_State->B = 222;
	//	m_PlayerState = State::CHARM;
	//}
	//if (m_PlayerState == State::FEAR)//공포
	//{
	//	m_State->R = 59;
	//	m_State->G = 57;
	//	m_State->B = 53;
	//	m_PlayerState = State::FEAR;
	//}
	//if (m_PlayerState == State::ICE)
	//{
	//	m_PlayerState = State::ICE;
	//}
	//if (m_PlayerState == State::INVINCIBILITY)//무적
	//{
	//	m_PlayerState = State::INVINCIBILITY;
	//}
	//if (m_PlayerState == State::UNSTOPPABLE)//저지불가
	//{
	//	m_State->R = 252;
	//	m_State->G = 184;
	//	m_State->B = 0;
	//}
	//if (m_PlayerState == State::ICE)
	//{
	//	m_State->R = 255;
	//	m_State->G = 255;
	//	m_State->B = 255;
	//}
	//if (m_PlayerState == State::NONE)
	//{
	//	m_State->R = 255;
	//	m_State->G = 255;
	//	m_State->B = 255;
	//	m_CurrentState = "NONE";
	//}
}

void UI::Render()
{
	if (m_Hp <= 0)
		m_Hp = 0;

	Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);

	m_HpText->print(std::to_string(m_Hp) + "/" + std::to_string(m_MaxHp) + "(" +
		std::to_string(m_Hp * m_MaxHp / m_MaxHp) + "%)", 170, 15);

	m_DashText->print(std::to_string((int)m_DashCooldown), m_DashBlind->m_Position.x - 30, m_DashBlind->m_Position.y - 50);

	m_HealText->print(std::to_string((int)m_HealCooldown), m_HealBlind->m_Position.x - 30, m_HealBlind->m_Position.y - 50);
	
	m_KarmaText->print(" X " + std::to_string(Karma) , 60, 60);

	m_StateText->print(m_CurrentState , 45, 850);

	Renderer::GetInst()->GetSprite()->End();
	m_HpGage = m_HpBar->m_Size.x / m_MaxHp;

	int Hp = m_MaxHp - m_Hp;

	if (m_Hp >= 0)
	{
		SetRect(&m_HpBar->m_Collision, m_HpBar->m_Position.x - m_HpBar->m_Size.x / 2, m_HpBar->m_Position.y - m_HpBar->m_Size.y / 2,
			m_HpBar->m_Position.x + m_HpBar->m_Size.x / 2, m_HpBar->m_Position.y + m_HpBar->m_Size.y / 2);

		m_HpBar->m_Rect.right = m_HpBar->m_Size.x - (Hp * m_HpGage);
	}
	if (m_Fire >= 0.1f)
	{
		SetRect(&m_State_Fire->m_Collision, m_State_Fire->m_Position.x - m_State_Fire->m_Size.x / 2, m_State_Fire->m_Position.y - m_State_Fire->m_Size.y / 2,
			m_State_Fire->m_Position.x + m_State_Fire->m_Size.x / 2, m_State_Fire->m_Position.y + m_State_Fire->m_Size.y / 2);

		m_State_Fire->A = 255;
		m_State_RGB->m_Rect.bottom = 27 * m_Fire;
		m_State_RGB->A = 150;
		m_State_RGB->R=199;
		m_State_RGB->G=0;
		m_State_RGB->B=33;
		//m_State_RGB->m_Rect.top = m_State_RGB->m_Size.x;
	}
	if (m_Poison >= 0.1f)
	{
		SetRect(&m_State_Poison->m_Collision, m_State_Poison->m_Position.x - m_State_Poison->m_Size.x / 2, m_State_Poison->m_Position.y - m_State_Poison->m_Size.y / 2,
			m_State_Poison->m_Position.x + m_State_Poison->m_Size.x / 2, m_State_Poison->m_Position.y + m_State_Poison->m_Size.y / 2);

		m_State_RGB->m_Rect.bottom = 27 * m_Poison;
		m_State_Poison->A = 255;
		m_State_RGB->A = 150;
		m_State_RGB->R = 21;
		m_State_RGB->G = 153;
		m_State_RGB->B = 1; 
		//m_State_RGB->m_Rect.top = m_State_RGB->m_Size.x;
	}
	if (m_Poison <= 0 && m_Fire <= 0)
	{
		m_State_Fire->A = 0;
		m_State_Poison->A = 0;
		m_State_RGB->m_Rect.bottom = 0;
	}
}
