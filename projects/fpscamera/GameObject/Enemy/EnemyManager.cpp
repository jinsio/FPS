#include "EnemyManager.h"
#include <string>

namespace My3dApp
{
	// �A�Z�b�g�}�l�[�W�����̂ւ̃|�C���^��`
	EnemyManager* EnemyManager::mpInstance = nullptr;

	//-----------------------------------------------------------------------------
	// @brief  �R���X�g���N�^.
	//-----------------------------------------------------------------------------
	EnemyManager::EnemyManager()
		:EnemyCoolTime(2.0f)
	{
		mpInstance = nullptr;
	}

	//-----------------------------------------------------------------------------
	// @brief  �f�X�g���N�^.
	//-----------------------------------------------------------------------------
	EnemyManager::~EnemyManager()
	{
		mpInstance = nullptr;
	}
	//-----------------------------------------------------------------------------
	// @brief  �A�Z�b�g�}�l�[�W���̐���
	// @detail dxlibInit�̌�ɃA�Z�b�g�}�l�[�W�����g�p���邽�߂̏������������s��
	// Create�����ɑ��̃A�Z�b�g�}�l�[�W���̊֐������g�p���邱�Ƃ͂ł��Ȃ��B
	//-----------------------------------------------------------------------------
	void EnemyManager::Initialize()
	{
		if (!mpInstance)
		{
			mpInstance = new EnemyManager;
		}
	}

	//------------------------------------------------------------------------------------------
	// @brief  AssetManager�̌�n������.
	// @detail �A�v���P�[�V�����I���O�ɌĂяo���K�v������B�}�l�[�W�����m�ۂ����̈��
	// �}�l�[�W�����g�̉���������s���BEnd���s�킸�ɏI�������ꍇ�̓��������[�N���N�����B
	// �܂����̊֐��ȍ~��AssetManger�̊֐����g�p���邱�Ƃ͂ł��Ȃ��B
	//------------------------------------------------------------------------------------------
	void EnemyManager::Finalize()
	{
		if (mpInstance)
		{
			delete mpInstance;
		}
	}

} // namespace My3dApp