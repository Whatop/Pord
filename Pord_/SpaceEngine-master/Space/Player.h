#pragma once

class Player : public Object
{
	Animation* m_Player;

	Animation* m_Attack_A;
	Animation* m_Attack_B;
	Animation* m_Attack_C;
	Animation* m_Attack_D;

//	Animation* m_Climb;// 해야될까?

	Animation* m_Dead;

	Animation* m_Hit_arm_A;
	Animation* m_Hit_arm_B;
	Animation* m_Hit_A;
	Animation* m_Hit_B;

	Animation* m_Idle;//
	Animation* m_Idle_arm;//

	Animation* m_Jump;//
	Animation* m_Jump_arm_A;//
	Animation* m_Jump_arm_B;//
	Animation* m_Jump_Attack;//

	Animation* m_Kick;
	
	Animation* m_Roll;

	Animation* m_Run;
	
	Animation* m_Walk;
	Animation* m_ShieldBlock;
	Animation* m_ShieldDash;


	Sprite* m_ColBox;
	Sprite* m_HeadCol;
	Sprite* m_FootCol;
	Sprite* m_Left;
	Sprite* m_Right;
public:
	bool arm; //무장
	bool walk; //걷기
	int b;
	int i;
	int m_Karma;
	Vec2 m_Directon;
	int m_LandAngle;
	int m_BaseAngle;

	Status m_PlayerStatus;

	float m_Speed;

	float m_SkillSpeed;
	int m_Hp;
	int m_MaxHp;

	float m_DashCooldown;
	float m_DashTime;
	
	float m_SkillCooldown;
	float m_SkillTime;

	Vec2 Pos;
	
	int num;
	bool m_LastDireIsRight;
	float m_AttackLate;
	int m_AttackLastFrame;
	int m_JumpAttackLastFrame;

	bool m_RightCol;
	bool m_LeftCol;
	
	Vec2 m_JumpPos;
	float m_JumpTime;
	float m_JumpPower;
	float m_JumpAccel;
	float m_PrevAccel;
	float m_JumpLate;

	bool m_isFall;
	bool m_isGround;
	//state
	float m_Poison;
	float m_Fire;
	float m_MaxFire;


	Player();
	~Player();

	void Dash();
	void Move();
	void Attack();
	void Jump();
	void Skill();
	void Hit();
	void Dead();
	void Shield();

	void SetLookingDirection();
	void Gravity();
	void SetDirection();

	void Update(float deltaTime,float Time);
	void Render();
	void OnCollision(Object* other);
};

