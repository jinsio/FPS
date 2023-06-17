#include "AssetManager.h"
#include <string>

namespace My3dApp
{
	// �A�Z�b�g�}�l�[�W�����̂ւ̃|�C���^��`
	AssetManager* AssetManager::mpInstance = nullptr;

	//-----------------------------------------------------------------------------
	// @brief  �R���X�g���N�^.
	//-----------------------------------------------------------------------------
	AssetManager::AssetManager()
	{
		mpInstance = nullptr;
	}

	//-----------------------------------------------------------------------------
	// @brief  �f�X�g���N�^.
	//-----------------------------------------------------------------------------
	AssetManager::~AssetManager()
	{
		mpInstance->ReleaseAllAsset();
		mpInstance = nullptr;
	}
	//-----------------------------------------------------------------------------
	// @brief  �A�Z�b�g�}�l�[�W���̐���
	// @detail dxlibInit�̌�ɃA�Z�b�g�}�l�[�W�����g�p���邽�߂̏������������s��
	// Create�����ɑ��̃A�Z�b�g�}�l�[�W���̊֐������g�p���邱�Ƃ͂ł��Ȃ��B
	//-----------------------------------------------------------------------------
	void AssetManager::Initialize()
	{
		if (!mpInstance)
		{
			mpInstance = new AssetManager;
		}
	}

	//-----------------------------------------------------------------------------
	// @brief  ���b�V���̎擾.
	// @param[in] meshFileName �擾���������b�V���t�@�C����.
	// @return int ���b�V���̃n���h��.
	// 
	// @details ���b�V���i���f��)�n���h�����擾����B
	// �����t�@�C������2�x�ȏ�w�肵���Ƃ��́A�t�@�C���ǂݍ��݂͍s��ꂸ�Aduplicate���ꂽ�n���h����Ԃ��B
	// �t�@�C����������Ȃ��Ƃ���-1��Ԃ�.
	//-----------------------------------------------------------------------------
	int AssetManager::GetMesh(std::string meshFileName)
	{
		int meshId = 0;
		// �A�z�z�񂩂�ȑO�ɓo�^����ĂȂ����𒲂ׂ�
		auto iter = mpInstance->mMeshMap.find(meshFileName);

		// ������Ȃ������ꍇ�͐V�K�Ńt�@�C����ǂݍ��݁A�A�z�z��ɋL�^����
		if (iter == mpInstance->mMeshMap.end())
		{
			meshId = MV1LoadModel(meshFileName.c_str());
			if (meshId == -1)
			{
				return meshId;
			}
			mpInstance->mMeshMap.emplace(meshFileName, meshId); //mMeshMap[meshFileName] = meshId�̂���
		}

		// �V�K�ǂݍ��݂�2��ړǂݍ��݂��Aduplicate�������̂�ԋp����
		// ���b�V�����g���L�����N�^�[�����������ꍇ�ɁA���{���������ƑS�������č��邽��
		// ���b�V���̃R�s�[�폜�p��mDuplicateMesh�ɕۑ�
		meshId = MV1DuplicateModel(mpInstance->mMeshMap[meshFileName]);
		mpInstance->mDuplicatesMesh.push_back(meshId);
		return meshId;
	}

	//-----------------------------------------------------------------------------
	// @brief  �A�j���[�V�����̓ǂݍ���.
	// @param[in] animationFileName �ǂݍ��݂����A�j���[�V�����t�@�C����.
	// @return int �A�j���[�V�����n���h��.
	// 
	// @details �A�j���[�V�������t�@�C���ǂݍ��݂��A�A�j���[�V�����n���h����Ԃ�
	// �����t�@�C������2�x�ȏ�ǂݍ��܂ꂽ�ꍇ�́A�ǂݍ��݂��s�킸�n���h���̂ݕԂ�
	// �A�j���[�V������Duplicate����Ȃ��B�t�@�C����������Ȃ��Ƃ���-1��Ԃ�.         
	//-----------------------------------------------------------------------------
	int AssetManager::GetAnimation(std::string animFileName)
	{
		int animId = 0;
		auto iter = mpInstance->mAnimationMap.find(animFileName);

		// ������Ȃ������ꍇ�͐V�K�ǂݍ��݂��A�A�z�z��ɋL�^����
		if (iter == mpInstance->mAnimationMap.end())
		{
			animId = MV1LoadModel(animFileName.c_str());
			if (animId == -1)
			{
				return animId;
			}
			mpInstance->mAnimationMap.emplace(animFileName, animId);  // mAnimationMap[animationFileName] = animId;�̂���
		}

		// �A�j���[�V������ID��Ԃ�
		return mpInstance->mAnimationMap[animFileName];
	}

	//-----------------------------------------------------------------------------
	// @brief  ���b�V���̉��
	// @param[in] meshID ������������f���n���h��.
	// 
	// @details duplicate���ꂽ���f���n���h�����J������
	// duplicate���ꂽ���f���n���h���Ȃ̂ŁA�S�������Ă����{�̃��f���n���h���͓����I�Ɏc��         
	//-----------------------------------------------------------------------------
	void AssetManager::ReleaseMesh(int meshID)
	{
		// Duplicate�̒��Ń��b�V�����������A�폜
		auto iter = std::find(mpInstance->mDuplicatesMesh.begin(), mpInstance->mDuplicatesMesh.end(), meshID);
		if (iter == mpInstance->mDuplicatesMesh.end())
		{
			// ������Ȃ�����
			return;
		}

		MV1DeleteModel(meshID);

		// �����̃f�[�^�Ɠ���ւ��Ė������폜
		std::iter_swap(iter, mpInstance->mDuplicatesMesh.end() - 1);
		mpInstance->mDuplicatesMesh.pop_back();
	}

	//-----------------------------------------------------------------------------
	// @brief  �@���ׂẴ��b�V���̉��
	// 
	// @details duplicate, ���{�̃��f���n���h���A�A�j���[�V�������ׂĂ��J������
	// �A�v���P�[�V�����̏I������dxLib_End()���O�ɌĂяo���K�v������B.
	//-----------------------------------------------------------------------------
	void AssetManager::ReleaseAllAsset()
	{
		// �S�ẴA�j���[�V�������J������
		for (auto iter = mpInstance->mAnimationMap.begin(); iter != mpInstance->mAnimationMap.end(); ++iter)
		{
			MV1DeleteModel(iter->second);

		}
		// �S�Ẵ��f�����J������
		for (auto iter = mpInstance->mMeshMap.begin(); iter != mpInstance->mMeshMap.end(); ++iter)
		{
			MV1DeleteModel(iter->second);

		}
		// �S�Ă�Duplicate���폜����
		for (auto iter = mpInstance->mDuplicatesMesh.begin(); iter != mpInstance->mDuplicatesMesh.end(); ++iter)
		{
			MV1DeleteModel(*iter);
		}

		mpInstance->mAnimationMap.clear();
		mpInstance->mMeshMap.clear();
		mpInstance->mDuplicatesMesh.clear();
	}
	//------------------------------------------------------------------------------------------
	// @brief  AssetManager�̌�n������.
	// @detail �A�v���P�[�V�����I���O�ɌĂяo���K�v������B�}�l�[�W�����m�ۂ����̈��
	// �}�l�[�W�����g�̉���������s���BEnd���s�킸�ɏI�������ꍇ�̓��������[�N���N�����B
	// �܂����̊֐��ȍ~��AssetManger�̊֐����g�p���邱�Ƃ͂ł��Ȃ��B
	//------------------------------------------------------------------------------------------
	void AssetManager::Finalize()
	{
		ReleaseAllAsset();
		if (mpInstance)
		{
			delete mpInstance;
		}
	}

} // namespace My3dApp