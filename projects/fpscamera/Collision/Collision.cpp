#include "Collision.h"

namespace My3dApp
{
	//-----------------------------------------------------------------------------
	// @brief ���̃R���X�g���N�^
	//-----------------------------------------------------------------------------
	Sphere::Sphere()
		: mLocalCenter()
		, mWorldCenter()
		, mRadius(0.0f)
	{
	}

	//-----------------------------------------------------------------------------
	// @brief ���̃R���X�g���N�^
	//-----------------------------------------------------------------------------
	Sphere::Sphere(const VECTOR& center, float radius)
		: mLocalCenter(center)
		, mWorldCenter(center)
		, mRadius(radius)
	{
	}

	void Sphere::Move(const VECTOR& pos)
	{
		mWorldCenter = mLocalCenter + pos;
	}


	//-----------------------------------------------------------------------------
	// @brief �����蔻�� ���E��
	// @param[in] sphere1 ��
	// @param[in] sphere2 ��
	// @return bool �����m���Ԃ����Ă���ꍇ��true ��Ԃ�
	//-----------------------------------------------------------------------------
	bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2)
	{
		return HitCheck_Sphere_Sphere(sphere1.mWorldCenter, sphere1.mRadius, 
			                          sphere2.mWorldCenter, sphere2.mRadius);
	}


}