#pragma once
#include "../GameObject.h"

namespace My3dApp
{
    class Dragon : public GameObject
    {
    public:
        Dragon();
        ~Dragon();

		void Update(float deltaTime);
		void Draw();

		void SetAnimTypeId(int a) { mAnimTypeId = a; }
		void OnCollisionEnter(GameObject* other);

	protected:
		float      mSpeed; // �ړ����x
		float      mAnimTime;
		class   AnimationController* mAnimControl;// �A�j���[�V�����Ǘ��p
		bool    mCollisionFlag;

		const VECTOR BOSS_SPOT = VGet(5000, 0, 0);
    };
}

