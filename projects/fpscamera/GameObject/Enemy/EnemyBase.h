#pragma once
#include "../GameObject.h"
namespace My3dApp
{
    class EnemyBase : public GameObject
    {
	public:
		EnemyBase();
		~EnemyBase();

		virtual void Update(float deltaTime);
		virtual void AnimationUpdate(float deltaTime);
		virtual void Draw();

		void SetAnimTypeId(int a) { mAnimTypeId = a; }
		void OnCollisionEnter(GameObject* other);

	protected:
		float      mSpeed; // �ړ����x
		float      mAnimTime;
		class   AnimationController* mAnimControl;// �A�j���[�V�����Ǘ��p
		bool    mCollisionFlag;
    };

}