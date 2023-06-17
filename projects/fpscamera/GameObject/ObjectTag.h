#pragma once
#include <vector>

namespace My3dApp
{
	// ゲーム内アクター・当たり判定の種類別タグ
	enum class ObjectTag : unsigned char
	{
		Player,
		PlayerGun,
		Camera,
		Reticle,
		PlayerBullet,
		EnemyBullet,
		Enemy,
		Map,
		DangerZone,
	};

	//------------------------------------------------------------------------------------
	// @brief ループ制御用。上記タグの全要素を記述しておくこと.
	// @detail 使用法として,for( ObjectTag &tag : ObjectTagAll ) とすることで、
	// 全Tag要素のループにできる
	//------------------------------------------------------------------------------------
	constexpr static ObjectTag ObjectTagAll[] =
	{
		ObjectTag::Player,
		ObjectTag::PlayerGun,
		ObjectTag::Camera,
		ObjectTag::Reticle,
		ObjectTag::PlayerBullet,
		ObjectTag::EnemyBullet,
		ObjectTag::Enemy,
		ObjectTag::Map,
		ObjectTag::DangerZone,
	};
}// namespace My3dApp

