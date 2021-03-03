#include "stdafx.h"
#include "Player.h"
#include "Trail.h"
#include "Bullet.h"
#include "EnemyBullet.h"


Player::Player()
{
	m_Idle = new Animation(); // 무장 상태 아님
	m_Idle->SetParent(this);
	m_Idle->Init(10, true);
	m_Idle->AddContinueFrame(L"Painting/Player/Idle/idle-", 1, 6);

	m_Idle_arm = new Animation();// 무장 상태
	m_Idle_arm->SetParent(this);
	m_Idle_arm->Init(3, true);
	m_Idle_arm->AddContinueFrame(L"Painting/Player/Idle/idle-with-weapon-", 1, 6);

	m_Run = new Animation(); //무장 상태 아님
	m_Run->SetParent(this);
	m_Run->Init(5, true);
	m_Run->AddContinueFrame(L"Painting/Player/Run/run-", 1, 12);

	m_Walk = new Animation(); //무장 상태
	m_Walk->SetParent(this);
	m_Walk->Init(3, true);
	m_Walk->AddContinueFrame(L"Painting/Player/Walk/walk-with-weapon-", 1, 11);

	m_ShieldBlock = new Animation(); //약간 대쉬기 느낌? s + 구르기 해서 대쉬
	m_ShieldBlock->SetParent(this);
	m_ShieldBlock->Init(4, true);
	m_ShieldBlock->AddContinueFrame(L"Painting/Player/ShieldBlock/", 1, 5);
	
	m_ShieldDash = new Animation(); //약간 대쉬기 느낌? s + 구르기 해서 대쉬
	m_ShieldDash->SetParent(this);
	m_ShieldDash->Init(4, true);
	m_ShieldDash->AddContinueFrame(L"Painting/Player/ShieldBlock/", 1, 5);

	m_Jump = new Animation();//무장 상태 아님
	m_Jump->SetParent(this);
	m_Jump->Init(3, true);
	m_Jump->AddContinueFrame(L"Painting/Player/Jump/jump-", 1, 14);

	m_Jump_arm_A = new Animation();//위로 점프 공격
	m_Jump_arm_A->SetParent(this);
	m_Jump_arm_A->Init(3, true);
	m_Jump_arm_A->AddContinueFrame(L"Painting/Player/Jump/attack-in-air-A", 1, 7);
	m_JumpAttackLastFrame = 7;

	m_Jump_arm_B = new Animation();//아래로 점프 공격
	m_Jump_arm_B->SetParent(this);
	m_Jump_arm_B->Init(3, true);
	m_Jump_arm_B->AddContinueFrame(L"Painting/Player/Jump/attack-in-air-B", 1, 6);

	//m_Jump_Attack = new Animation(); //무장 상태
	//m_Jump_Attack->SetParent(this);
	//m_Jump_Attack->Init(3, true);
	//m_Jump_Attack->AddContinueFrame(L"Painting/Player/Attacks/jump-attack-", 1, 8);

	m_Attack_A = new Animation();// 무장 상태
	m_Attack_A->SetParent(this);
	m_Attack_A->Init(2, true);
	m_Attack_A->AddContinueFrame(L"Painting/Player/Attacks/attack-A", 1, 8);
	m_AttackLastFrame = 8;

	m_Attack_B = new Animation();// 무장 상태
	m_Attack_B->SetParent(this);
	m_Attack_B->Init(2, true);
	m_Attack_B->AddContinueFrame(L"Painting/Player/Attacks/attack-B", 1, 7);
	
	m_Attack_C = new Animation();// 무장 상태
	m_Attack_C->SetParent(this);
	m_Attack_C->Init(2, true);
	m_Attack_C->AddContinueFrame(L"Painting/Player/Attacks/attack-C", 1, 10);

	m_Attack_D = new Animation();// 무장 상태
	m_Attack_D->SetParent(this);
	m_Attack_D->Init(2, true);
	m_Attack_D->AddContinueFrame(L"Painting/Player/Attacks/attack-D", 1, 12);

	//m_Kick = new Animation();// 무장 상태
	//m_Kick->SetParent(this);
	//m_Kick->Init(7, true);
	//m_Kick->AddContinueFrame(L"Painting/Player/Attacks/kick-", 1, 5);

	m_Roll = new Animation();// 상관 없음
	m_Roll->SetParent(this);
	m_Roll->Init(2, true);
	m_Roll->AddContinueFrame(L"Painting/Player/Roll/roll-", 1, 14);

	m_Hit_A = new Animation();//
	m_Hit_A->SetParent(this);
	m_Hit_A->Init(7, true);
	m_Hit_A->AddContinueFrame(L"Painting/Player/Hit/hit-idle-A", 1, 4);
	
	//m_Hit_B = new Animation();//
	//m_Hit_A->SetParent(this);
	//m_Hit_A->Init(7, true);
	//m_Hit_A->AddContinueFrame(L"Painting/Player/Hit/hit-idle-B", 1, 4);
	//
	//m_Hit_arm_A = new Animation();//
	//m_Hit_arm_A->SetParent(this);
	//m_Hit_arm_A->Init(7, true);
	//m_Hit_arm_A->AddContinueFrame(L"Painting/Player/Hit/hit-with-weapon-A", 1, 4);
	//
	//m_Hit_arm_B = new Animation();//
	//m_Hit_arm_B->SetParent(this);
	//m_Hit_arm_B->Init(7, true);
	//m_Hit_arm_B->AddContinueFrame(L"Painting/Player/Hit/hit-with-weapon-B", 1, 4);

	m_Dead = new Animation();//
	m_Dead->SetParent(this);
	m_Dead->Init(7, true);
	m_Dead->AddContinueFrame(L"Painting/Player/Dead/dead-", 1, 6);
	
	m_SkillSpeed= 1000.f;

	m_ColBox = Sprite::Create(L"Painting/Player/ColBox.png");
	m_ColBox->m_Position = m_Position;

	m_HeadCol = Sprite::Create(L"Painting/Player/Head.png");
	m_HeadCol->m_Position = m_Position;

	m_FootCol = Sprite::Create(L"Painting/Player/Foot.png");
	m_FootCol->m_Position = m_Position;

	m_Left = Sprite::Create(L"Painting/Player/Side.png");
	m_Left->m_Position = m_Position;

	m_Right = Sprite::Create(L"Painting/Player/Side.png");
	m_Right->m_Position = m_Position;

	
	m_Player = m_Idle;
	m_Player->SetParent(this);
	m_PlayerStatus = Status::IDLE;

	SetPosition(1920 / 2, 1500);

	m_BaseAngle = 0;
	m_LandAngle = 0 + m_BaseAngle;
	m_BaseAngle = 90;

	m_Speed = 400.f;

	m_JumpPower = 75.f;
	m_JumpTime = 0;
	m_JumpAccel = 0.f;
	m_PrevAccel = 0.f;
	m_isFall = false;

	m_Hp = 100;
	m_MaxHp = 100;
	
	m_LastDireIsRight = true;
	m_isGround = false;//땅

	m_RightCol = false;
	m_LeftCol = false;

	m_Layer = 3;

	m_AttackLate = 0.f;
	m_JumpLate = 0.f;

	m_DashCooldown = 0.f;
	m_DashTime = 0.4f;

	m_SkillCooldown = 0.f;
	m_SkillTime = 0.2f;
	
	m_ColBox->A = 0;
	m_HeadCol->A = 0;
	m_FootCol->A = 0;
	m_Left->A = 0;
	m_Right->A = 0;

	m_Karma = 1;
	m_MaxFire = 3.f;
	m_Poison = 0;
	m_Fire = 0;
}

Player::~Player()
{
}

void Player::SetLookingDirection()
{
	if (m_LastDireIsRight)
	{
		m_Scale.x = 1;
		num = 40;
	}
	else if (!m_LastDireIsRight)
	{
		m_Scale.x = -1;
		num = -40;
	}
}

void Player::Gravity()
{
	static float vy = 0;
	if (m_PlayerStatus == Status::JUMP_ATTACK_UP)
	{
		vy = 0;
	}
	if (m_PlayerStatus == Status::JUMP_ATTACK_DOWN)
	{
		vy = 30;
	}
		vy += GR * dt;

	if (!m_isGround)
	{
		m_Position.y += vy;
	}
	else
		vy = 0.f;
}

void Player::Move()
{
	if (INPUT->GetKey('D') == KeyState::PRESS && m_PlayerStatus != Status::JUMP)
	{
		m_LastDireIsRight = true;
		if (arm == true)
		{
			m_Player = m_Walk;
			m_PlayerStatus = Status::WALK;
		}
		else
		{
			m_Player = m_Run;
			m_PlayerStatus = Status::RUN;
		}
		if (!m_RightCol)
			Translate(m_Directon.x * m_Speed * dt, m_Directon.y * -m_Speed * dt);
	}
	if (INPUT->GetKey('D') == KeyState::UP && m_PlayerStatus == Status::RUN)
	{
		m_Player = m_Idle;
		m_PlayerStatus = Status::IDLE;

	}

	if (INPUT->GetKey('A') == KeyState::PRESS && m_PlayerStatus != Status::JUMP)
	{
		m_LastDireIsRight = false;
		if (arm == true)
		{
			m_Player = m_Walk;
			m_PlayerStatus = Status::WALK;
		}
		else
		{
			m_Player = m_Run;
			m_PlayerStatus = Status::RUN;
		}
		if (!m_LeftCol)
			Translate(m_Directon.x * -m_Speed * dt, m_Directon.y * m_Speed * dt);
	}
	if (INPUT->GetKey('A') == KeyState::UP && m_PlayerStatus == Status::RUN)
	{
		m_Player = m_Idle;
		m_PlayerStatus = Status::IDLE;
	}
}

void Player::Jump()
{
	if (INPUT->GetKey('W') == KeyState::PRESS && m_PlayerStatus != Status::JUMP && m_JumpLate <= 0.f)
	{
		m_JumpTime = 0;
		Pos = m_Position;
		m_PlayerStatus = Status::JUMP;
		//ObjMgr->AddObject(new EffectMgr(L"Painting/Enemy1/attack-A", 1, 7, 5, m_Position), "Effect");
	}
	if (m_PlayerStatus == Status::JUMP)
	{
		static float minus;
		m_Player = m_Jump;

		m_PrevAccel = m_JumpAccel;

		m_JumpAccel = ((-GR) / 2 * m_JumpTime * m_JumpTime) + (m_JumpPower * m_JumpTime);
		m_JumpTime += dt * 20.f;
		m_Position.y = Pos.y - m_JumpAccel;

		if (m_PrevAccel > m_JumpAccel)
		{
			m_isFall = true;
		}

		if (m_JumpAccel < 0.f)
		{
			minus = m_JumpAccel;
		}
		if (m_JumpAccel >= 0.f)
		{
			if (INPUT->GetKey('D') == KeyState::PRESS)
			{
				if (!m_RightCol)
					Translate(m_Speed * dt, m_Speed * dt);
				m_LastDireIsRight = true;
			}
			if (INPUT->GetKey('A') == KeyState::PRESS)
			{
				m_LastDireIsRight = false;
				if (!m_LeftCol)
					Translate(-m_Speed * dt, m_Speed * dt);
			}
		}
		if (m_JumpAccel < 0.f || (m_isFall && m_isGround))
		{
			m_PrevAccel = 0.f;
			m_JumpLate = 0.1f;
			m_Player = m_Idle;
			m_PlayerStatus = Status::IDLE;
			m_Position.y += minus;
		}
	}
}

void Player::Skill()
{
	if (m_SkillCooldown <= 0.f && m_PlayerStatus != Status::SHIELDBLOCK)
	{
		if (INPUT->GetKey(VK_SHIFT)==KeyState::DOWN)
		{
			if (INPUT->GetKey('D') == KeyState::PRESS)
			{
				m_LastDireIsRight = true;
				m_Player = m_ShieldBlock;
				m_PlayerStatus = Status::SHIELDBLOCK;
			}
			if (INPUT->GetKey('A') == KeyState::PRESS)
			{
				m_LastDireIsRight = false;
				m_Player = m_ShieldBlock;
				m_PlayerStatus = Status::SHIELDBLOCK;
			}
		}
	}

	if (m_PlayerStatus == Status::SHIELDBLOCK)
	{
		m_SkillTime -= dt;
 
		if (m_LastDireIsRight)
		{
			if (!m_RightCol)
				m_Position.x += m_SkillSpeed * dt;
			ObjMgr->AddObject(new Trail(L"Painting/Player/ShieldBlock/2.png","Enemy",m_Position, m_LastDireIsRight), "Shiled_Attack");
		}
		else if (!m_LastDireIsRight)
		{
			if (!m_LeftCol)
				m_Position.x -= m_SkillSpeed * dt;
			ObjMgr->AddObject(new Trail(L"Painting/Player/ShieldBlock/2.png", "Enemy",m_Position, m_LastDireIsRight), "Shiled_Attack");
		}
		if (m_SkillTime <= 0.f)
		{
			m_SkillTime = 0.25f;
			m_SkillCooldown = 1.f;
			m_ShieldBlock->m_CurrentFrame = 0;
			m_Player = m_Idle;
			m_PlayerStatus = Status::IDLE;
		}
	}
}

void Player::Hit()
{
	if (m_PlayerStatus == Status::HIT)
	{
		m_Player = m_Hit_A;
		if (m_Player->m_CurrentFrame == 4 - 1)
		{
			m_Player->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
		}
		if (m_Hp <= 0)
		{
			m_PlayerStatus = Status::DEAD;
		}
	}
	if (m_Fire > 0)
	{
		m_Fire += dt * 2;
		m_Player->R = 250;
		m_Player->G = 61;
		m_Player->B = 47;
	}
	if (m_Fire <= 0 && m_Poison <= 0)
	{
		m_Fire = 0;
		m_Poison = 0;
		m_Player->R = 255;
		m_Player->G = 255;
		m_Player->B = 255;
	}
	if (m_Fire > m_MaxFire)
	{
		m_Hp -= 5;
		m_Fire = 0.1f;
	}
	if (m_Poison > m_MaxFire)
	{
		m_Hp -= 5;
	}
}

void Player::Dead()
{
	if (m_PlayerStatus == Status::DEAD)
	{
		m_Player = m_Dead;

		if (m_Player->m_CurrentFrame == 6 - 1)
		{
			ObjMgr->RemoveObject(this);
		}
	}
}


void Player::Attack()
{
	if (INPUT->GetButtonDown() && (m_PlayerStatus != Status::ATTACK_A && m_PlayerStatus != Status::JUMP && m_isGround))
	{
		m_PlayerStatus = Status::ATTACK_A;
	}
	if (INPUT->GetButtonDown() &&( m_PlayerStatus != Status::ATTACK_B && m_PlayerStatus != Status::JUMP && m_isGround && b == 2))
	{
		m_PlayerStatus = Status::ATTACK_B;
	}
	if (INPUT->GetButtonDown() &&( m_PlayerStatus != Status::ATTACK_C && m_PlayerStatus != Status::JUMP && m_isGround && b == 3))
	{
		m_PlayerStatus = Status::ATTACK_C;
	}
	if (INPUT->GetButtonDown() && (m_PlayerStatus != Status::ATTACK_D && m_PlayerStatus != Status::JUMP && m_isGround && b == 4))
	{
		m_PlayerStatus = Status::ATTACK_D;
		INPUT->ButtonDown(false);
	}

	if (m_PlayerStatus == Status::ATTACK_A)
	{
		m_Player = m_Attack_A;
		ObjMgr->CollisionCheak(this, "Enemy"); 
		if (m_Player->m_CurrentFrame == 6)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-A7.png", "Enemy",
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}

		if (m_Player->m_CurrentFrame == m_AttackLastFrame - 1)
		{
			m_AttackLate = 0.3f;
			m_Attack_A->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
			b = 2;
		}
	}
	if (m_PlayerStatus == Status::ATTACK_B)
	{
		m_Player = m_Attack_B;

		if (m_Player->m_CurrentFrame == 4)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-B5.png","Enemy",
			Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}

		ObjMgr->CollisionCheak(this, "Enemy");
		if (m_Player->m_CurrentFrame == 7 - 1)
		{
			m_AttackLate = 0.3f;
			m_Attack_B->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
			b = 3;
		}
	}
	if (m_PlayerStatus == Status::ATTACK_C)
	{
		m_Player = m_Attack_C;

		if (m_Player->m_CurrentFrame == 6)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-C7.png","Enemy",
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
		ObjMgr->CollisionCheak(this, "Enemy");
		if (m_Player->m_CurrentFrame == 10 - 1)
		{
			m_AttackLate = 0.3f;
			m_Attack_C->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
			b = 4;
		}
	}
	if (m_PlayerStatus == Status::ATTACK_D)
	{
		m_Player = m_Attack_D;

		if (m_Player->m_CurrentFrame == 3)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-D4.png", "Enemy", 
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
		if (m_Player->m_CurrentFrame == 8)
		{
			ObjMgr->AddObject(new Bullet(L"Painting/CollisionBox/Player/attack-D9.png", "Enemy",
				Vec2(m_Position.x , m_Position.y), m_LastDireIsRight), "Player_Sword");
		}
		ObjMgr->CollisionCheak(this, "Enemy");
		if (m_Player->m_CurrentFrame == 12 - 1)
		{
			m_AttackLate = 0.3f;
			m_Attack_D->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
			b = 1;
		}
	}
	if (INPUT->GetButtonDown() &&INPUT->GetKey('W')== KeyState::PRESS&& m_PlayerStatus == Status::JUMP)
	{
		m_PlayerStatus = Status::JUMP_ATTACK_UP;
		INPUT->ButtonDown(false);
	}

	if (m_PlayerStatus == Status::JUMP_ATTACK_UP)
	{
		m_Player = m_Jump_arm_A;

		ObjMgr->CollisionCheak(this, "Enemy");
		m_Position.y -= 1000 * dt;
		if (m_LastDireIsRight)
		{
			ObjMgr->AddObject(new Trail(L"Painting/Player/Jump/attack-in-air-A4.png","Enemy", m_Position, m_LastDireIsRight), "Sword_Skill");
		}
		else
		{
			ObjMgr->AddObject(new Trail(L"Painting/Player/Jump/attack-in-air-A4.png","Enemy" , m_Position, m_LastDireIsRight), "Sword_Skill");
		}
		if (m_Player->m_CurrentFrame == m_JumpAttackLastFrame - 1)
		{
			m_AttackLate = 0.8f; 
			m_JumpLate = 0.f;
			m_Jump_arm_A->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
		}
	}
	if (INPUT->GetButtonDown() && INPUT->GetKey('S') == KeyState::PRESS && m_isGround==false)
	{
		m_PlayerStatus = Status::JUMP_ATTACK_DOWN;
		INPUT->ButtonDown(false);
	}

	if (m_PlayerStatus == Status::JUMP_ATTACK_DOWN)
	{
		m_Player = m_Jump_arm_B;
		m_isFall = true;
		//m_Position.y += 1000 * dt;
		ObjMgr->CollisionCheak(this, "Enemy");
		if (m_LastDireIsRight)
		{
			ObjMgr->AddObject(new Trail(L"Painting/Player/Jump/attack-in-air-B4.png", "Enemy", m_Position, m_LastDireIsRight), "Sword_Skill");
		}
		else
		{
			ObjMgr->AddObject(new Trail(L"Painting/Player/Jump/attack-in-air-B4.png", "Enemy", m_Position, m_LastDireIsRight), "Sword_Skill");
		}
		if (m_Player->m_CurrentFrame == 6 - 1)
		{
			m_AttackLate = 0.3f;//쿨타임 따로
			m_Jump_arm_B->m_CurrentFrame = 0;
			m_PlayerStatus = Status::IDLE;
			m_Player = m_Idle;
		}
	}
}

void Player::Dash()
{
	if (m_DashCooldown <= 0.f && m_PlayerStatus != Status::ROLL)
	{
		m_Roll->m_CurrentFrame = 0;
		if (INPUT->GetRightButtonDown())
		{
			if (INPUT->GetKey('D') == KeyState::PRESS)
			{
				m_LastDireIsRight = true;
				m_Player = m_Roll;
				m_PlayerStatus = Status::ROLL;
			}
			if (INPUT->GetKey('A') == KeyState::PRESS)
			{
				m_LastDireIsRight = false;
				m_Player = m_Roll;
				m_PlayerStatus = Status::ROLL;
			}
		}
	}
	if (m_PlayerStatus == Status::ROLL)
	{
		m_Fire -= dt * 6;
		m_DashTime -= dt;
		if (m_LastDireIsRight)
		{
			if (!m_RightCol)
				m_Position.x += 600 * dt;
		}
		else if (!m_LastDireIsRight)
		{
			if (!m_LeftCol)
				m_Position.x -= 600 * dt;
		}
		if (m_DashTime <= 0.f)
		{
			m_DashTime = 0.4f;
			m_DashCooldown = 0.5f;
			m_Player = m_Idle;
			m_PlayerStatus = Status::IDLE;
		}
	}
}

void Player::SetDirection()
{
	Vec2 rot;
	rot.x = cos(D3DXToRadian((float)m_LandAngle));
	rot.y = sin(D3DXToRadian((float)m_LandAngle));

	m_Directon = m_Position - rot;

	D3DXVec2Normalize(&m_Directon, &rot);
}

void Player::Update(float deltaTime, float Time)
{
	m_isGround = false;
	m_RightCol = false;//벽
	m_LeftCol = false;

	if (m_AttackLate > 0)
		m_AttackLate -= dt;
	if (m_JumpLate > 0)
		m_JumpLate -= dt;
	if (m_DashCooldown > 0)
		m_DashCooldown -= dt;
	if (m_SkillCooldown > 0)
		m_SkillCooldown -= dt;

	Camera::GetInst()->Follow(this);

	UI::GetInst()->m_Hp = m_Hp;
	UI::GetInst()->m_MaxHp = m_MaxHp;
	UI::GetInst()->m_DashCooldown = m_DashCooldown;
	UI::GetInst()->Karma = m_Karma;
	UI::GetInst()->m_Fire = m_Fire;
	UI::GetInst()->m_Poison = m_Poison;

	ObjMgr->CollisionCheak(this, "Ground");
	ObjMgr->CollisionCheak(this, "Wall");
	ObjMgr->CollisionCheak(this, "Barrel");

	if (m_PlayerStatus != Status::JUMP)
		Gravity();

	SetDirection();
	SetLookingDirection();

	if (m_PlayerStatus != Status::DEAD)
	{
		if (m_PlayerStatus != Status::HIT)
		{
			if (m_PlayerStatus != Status::ROLL && m_PlayerStatus != Status::SHIELDBLOCK)
			{
				if (m_PlayerStatus != Status::ATTACK_A && m_PlayerStatus != Status::JUMP_ATTACK_DOWN && m_PlayerStatus != Status::JUMP_ATTACK_UP
					&& m_PlayerStatus != Status::ATTACK_C && m_PlayerStatus != Status::ATTACK_B && m_PlayerStatus != Status::ATTACK_D)
				{
					Move();
					Jump();
				}
				if (m_AttackLate <= 0)
					Attack();
			}
			if (m_PlayerStatus != Status::ATTACK_A && m_PlayerStatus != Status::ATTACK_B && m_PlayerStatus != Status::ATTACK_C && m_PlayerStatus != Status::ATTACK_D)
			{
				if (m_PlayerStatus != Status::SHIELDBLOCK)
					Dash();
				if (m_PlayerStatus != Status::ROLL)
					Skill();
			}
		}
		Hit();
	}
	Dead();
	m_Player->Update(deltaTime,Time);

	if (m_LastDireIsRight)
	{
		m_ColBox->m_Position = Vec2(m_Position.x, m_Position.y);
		m_HeadCol->m_Position = Vec2(m_Position.x , m_ColBox->m_Position.y);
		m_FootCol->m_Position = Vec2(m_Position.x , m_ColBox->m_Position.y);
		m_Left->m_Position = Vec2(m_Position.x - m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
		m_Right->m_Position = Vec2(m_Position.x + m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
	}
	else if (!m_LastDireIsRight)
	{
		m_ColBox->m_Position = Vec2(m_Position.x , m_Position.y);
		m_HeadCol->m_Position = Vec2(m_Position.x , m_ColBox->m_Position.y);
		m_FootCol->m_Position = Vec2(m_Position.x , m_ColBox->m_Position.y);
		m_Left->m_Position = Vec2(m_Position.x - m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
		m_Right->m_Position = Vec2(m_Position.x + m_ColBox->m_Size.x / 2, m_ColBox->m_Position.y);
	}
}

void Player::Render()
{
	m_Player->Render();
	m_ColBox->Render();
	m_HeadCol->Render();
	m_FootCol->Render();
	m_Left->Render();
	m_Right->Render();
}

void Player::OnCollision(Object* other)
{
	if (other->m_Tag == "Ground")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_FootCol->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			m_isFall = false;
		}
	}
	if (other->m_Tag == "Wall")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				m_LeftCol = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				m_RightCol = true;
			}
		}
	}
	if (other->m_Tag == "Sword_Skull")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			m_Hp -= 1;
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				m_PlayerStatus = Status::HIT;
				m_Fire += dt * 2;//불 
				m_Player->R = 43;
				m_Player->G = 165;
				m_Player->B = 65;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				m_PlayerStatus = Status::HIT;
				m_Fire += dt * 2;//불 
				m_Player->R = 43;
				m_Player->G = 165;
				m_Player->B = 65;
			}
		}
	}
	if (other->m_Tag == "Barrel")
	{
		RECT rc;
		if (IntersectRect(&rc, &m_ColBox->m_Collision, &other->m_Collision))
		{
			m_isGround = true;
			m_isFall = false;
			if (IntersectRect(&rc, &m_Left->m_Collision, &other->m_Collision))
			{
				m_LeftCol = true;
			}
			else if (IntersectRect(&rc, &m_Right->m_Collision, &other->m_Collision))
			{
				m_RightCol = true;
			}
		}
	}
}
//void Player::State()
//{
//	if (m_PlayerState == State::STUN)
//	{
//		m_Player->R = 255;
//		m_Player->G = 196;
//		m_Player->B = 1;
//	}
//	if (m_PlayerState == State::SLOW)//옮김
//	{
//		m_Speed = 300.f;
//		m_JumpPower = 50.f;
//	}
//	else
//	{
//		m_Speed = 400.f;
//		m_JumpPower = 75.f;
//	}
//	if (m_PlayerState == State::POISON)
//	{
//		m_Fire = 0;
//		m_Poison += dt * 2;//독 
//		m_Player->R = 43;
//		m_Player->G = 165;
//		m_Player->B = 65;
//	}
//	if (!(m_PlayerState == State::POISON) && m_Poison > 0)
//	{
//		m_Poison -= dt * 2;
//		m_PlayerState = State::NONE;
//	}
//	else if (m_Poison < 0)
//	{
//		m_Poison = 0;
//	}
//	if (m_Poison > 3.f)
//	{
//		m_Hp -= 5;
//		m_Poison = 0;
//	}
//	if (m_PlayerState == State::FIRE)
//	{
//		m_Fire += dt * 2;//불 
//		m_Player->R = 250;
//		m_Player->G = 61;
//		m_Player->B = 47;
//	}
//	if (!(m_PlayerState == State::FIRE) && m_Fire > 0)
//	{
//		m_Fire += dt * 2;
//		m_Player->R = 250;
//		m_Player->G = 61;
//		m_Player->B = 47;
//	}
//	if (m_Fire < 0)
//	{
//		m_Fire = 0;
//		m_PlayerState = State::NONE;
//	}
//	if (m_Fire > m_MaxFire)
//	{
//		m_Hp -= 5;
//		m_Fire = 0.1f;
//	}
//	if (m_PlayerState == State::WATER)
//	{
//		m_PlayerState = State::WATER;
//		m_Fire = 0;
//		m_Poison = 0;
//	}
//	if (m_PlayerState == State::SLEEP)
//	{
//		m_Player->R = 238;
//		m_Player->G = 234;
//		m_Player->B = 223;
//	}
//	if (m_PlayerState == State::CHARM)//매력==매혹
//	{
//		m_Player->R = 255;
//		m_Player->G = 42;
//		m_Player->B = 222;
//	}
//	if (m_PlayerState == State::FEAR)//공포
//	{
//		m_Player->R = 59;
//		m_Player->G = 57;
//		m_Player->B = 53;
//	}
//	if (m_PlayerState == State::ICE)
//	{
//		//
//	}
//	if (m_PlayerState == State::INVINCIBILITY)//무적
//	{
//		//
//	}
//	if (m_PlayerState == State::UNSTOPPABLE)//저지불가
//	{
//		m_Player->R = 252;
//		m_Player->G = 184;
//		m_Player->B = 0;
//	}
//	if (m_PlayerState == State::NONE)
//	{
//		m_Player->R = 255;
//		m_Player->G = 255;
//		m_Player->B = 255;
//	}
//}