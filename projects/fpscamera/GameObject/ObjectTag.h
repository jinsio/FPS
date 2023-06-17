#pragma once
#include <vector>

namespace My3dApp
{
	// �Q�[�����A�N�^�[�E�����蔻��̎�ޕʃ^�O
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
	// @brief ���[�v����p�B��L�^�O�̑S�v�f���L�q���Ă�������.
	// @detail �g�p�@�Ƃ���,for( ObjectTag &tag : ObjectTagAll ) �Ƃ��邱�ƂŁA
	// �STag�v�f�̃��[�v�ɂł���
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

