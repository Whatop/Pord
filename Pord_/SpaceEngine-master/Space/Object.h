#pragma once

enum class Status
{
	IDLE,//가만히
	RUN,//뛰기
	JUMP,//점프
	JUMP_ATTACK_UP,//점프
	JUMP_ATTACK_DOWN,//점프
	ATTACK_A,//공격
	ATTACK_B,//공격
	ATTACK_C,//공격
	ATTACK_D,//공격
	ROLL,//구르기
	HIT, //맞았을때
	DEAD,//죽음
	SHIELDBLOCK,//방패밀치기
	WALK,//걷기
	NONE
	//도발 추가 도발 상대가 원거리든 모든 도발 걸려서 플레이어에게 다가옴
};

enum class EnemyStatus
{
	IDLE,//가만히
	JUMP,//점프
	ATTACK_A,//공격
	ATTACK_B,//공격QJH9746	
	HIT, //맞았을때
	DEAD,//죽음
	WALK,//걷기
	NONE
}; 


class Object
{
public:
	Object* m_Parent;
	Matrix m_wMat;
	Vec2 m_Position;
	Vec2 m_Scale;
	Vec2 m_Size;
	Vec2 m_RotationCenter;
	Vec2 m_ScaleCenter;

	float m_Radius;
	float m_Rotation;

	bool m_Destroy;
	RECT m_Collision;

	bool m_Visible;

	int m_Layer;
	std::string m_Tag;

public:
	Object();
	~Object();


protected:
	Matrix GetMatrix();

public:
	virtual void Update(float deltaTime, float time);
	virtual void Render();
	virtual void OnCollision(Object* other);

public:
	void Translate(float x, float y);
	void SetScale(float x, float y);
	void SetPosition(float x, float y);
	void Rotate(float r);
	void SetDestroy(bool destroy) { m_Destroy = destroy; }
	void SetTag(const std::string tag);
	void SetParent(Object* obj);
public:
	bool GetDestroy() { return m_Destroy; }
};