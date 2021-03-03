#include "stdafx.h"
#include "MainScene.h"
#include"Player.h"
#include"Enemy1.h"
#include"Enemy2.h"
#include"Enemy3.h"
#include"Enemy4.h"
#include"Enemy5.h"
#include"Barrel.h"

MainScene::MainScene()
{
}

MainScene::~MainScene()
{
}

void MainScene::Init()
{
	m_BG = Sprite::Create(L"Painting/Map/CastleBG.png");
	m_BG->SetPosition(1920 / 2, m_BG->m_Size.y / 2);

	ObjMgr->AddObject(new Player(), "Player");
	ObjMgr->AddObject(new Barrel(), "Barrel");
	ObjMgr->AddObject(new Enemy1(), "Enemy");
	//ObjMgr->AddObject(new Enemy2(), "Enemy");
	//ObjMgr->AddObject(new Enemy3(), "Enemy");
	//ObjMgr->AddObject(new Enemy4(), "Enemy");
	//ObjMgr->AddObject(new Enemy5(), "Enemy");
	//ObjMgr->AddObject(new Monster1(Vec2(960, 1700)), "Monster");

    UI::GetInst()->Init();

	MapLimit::GetInst()->CreateMap(VERTICAL, 20, Vec2(-1920 / 2 - 700, m_BG->m_Size.y + 300));
	MapLimit::GetInst()->CreateMap(VERTICAL, 20, Vec2(3840 - 240, m_BG->m_Size.y + 310));
	MapLimit::GetInst()->CreateMap(HORIZONTAL, 20, Vec2(-1920 / 2 + 100, m_BG->m_Size.y - 50));
	
	/*m_Text = new TextMgr();
	m_Text->Init(32, true, false, "Arial");
	m_Text->SetColor(255, 255, 255, 255);*/
}

void MainScene::Release()
{
}

void MainScene::Update(float deltaTime, float time)
{
	for (auto& iter : ObjMgr->m_Objects)
	{
		if (iter->m_Tag == "Player")
		{
			PlayerPos = iter->m_Position;
		}
	}
}

void MainScene::Render()
{
	m_BG->Render();

	/*Renderer::GetInst()->GetSprite()->Begin(D3DXSPRITE_ALPHABLEND);
	m_Text->print(std::to_string(INPUT->GetMousePos().x) + " " + std::to_string(INPUT->GetMousePos().y) + " \n" +
		std::to_string(dt)+ " " +std::to_string(gt) + 
		" \n" + std::to_string(PlayerPos.x)+" " + std::to_string(PlayerPos.y)
		, 0, 0);
	Renderer::GetInst()->GetSprite()->End();*/
}
