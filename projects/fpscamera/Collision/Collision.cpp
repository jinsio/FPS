#include "Collision.h"

namespace My3dApp
{
	//-----------------------------------------------------------------------------
	// @brief 球体コンストラクタ
	//-----------------------------------------------------------------------------
	Sphere::Sphere()
		: mLocalCenter()
		, mWorldCenter()
		, mRadius(0.0f)
	{
	}

	//-----------------------------------------------------------------------------
	// @brief 球体コンストラクタ
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
	// @brief 当たり判定 球・球
	// @param[in] sphere1 球
	// @param[in] sphere2 球
	// @return bool 球同士がぶつかっている場合はtrue を返す
	//-----------------------------------------------------------------------------
	bool CollisionPair(const Sphere& sphere1, const Sphere& sphere2)
	{
		return HitCheck_Sphere_Sphere(sphere1.mWorldCenter, sphere1.mRadius, 
			                          sphere2.mWorldCenter, sphere2.mRadius);
	}


}