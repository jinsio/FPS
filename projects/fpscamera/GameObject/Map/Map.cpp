#include "Map.h"
#include "../ObjectTag.h"
#include "../../Animation/AssetManager.h"

namespace My3dApp
{
	//----------------------------------------------------------------------
	// @brief BackGround�N���X�R���X�g���N�^�B���f����ǂݍ���
	//----------------------------------------------------------------------
	My3dApp::Map::Map()
		: GameObject(My3dApp::ObjectTag::Map)
	{
		ModelLoad();
	}
	//----------------------------------------------------------------------
	// @brief BackGround�N���X�R���X�g���N�^�B���f����ǂݍ���
	// @param[in] pos �w�i�̃��[���h�z�u�ʒu
	//----------------------------------------------------------------------
	Map::Map(VECTOR pos)
		: GameObject(My3dApp::ObjectTag::Map, pos)
	{
		ModelLoad();
	}

	//----------------------------------------------------------------------
	// @brief BackGround�N���X�f�X�g���N�^
	//----------------------------------------------------------------------
	Map::~Map()
	{
		AssetManager::ReleaseMesh(mModelHandle);
	}

	//----------------------------------------------------------------------
	// @brief �w�i���f���ǂݍ���
	//----------------------------------------------------------------------
	void Map::ModelLoad()
	{
		// �\�����f���ǂݍ��݁��X�P�[�����O���ʒu�Z�b�g
		mModelHandle = AssetManager::GetMesh("data/model/map/___map.mv1");
		MV1SetScale(mModelHandle, VGet(2.0f, 2.0f, 2.0f));
		mPosition.x = -450;
		MV1SetPosition(mModelHandle, mPosition);

		//// �����蔻�胂�f���ǂݍ��݁��X�P�[�����O�������蔻����\�z
		//mCollisionModel = AssetManager::GetMesh("data/model/map/HitMesh2rot.mv1");
		//MV1SetScale(mCollisionModel, VGet(1.0f, 1.0f, 1.0f));
		//MV1SetOpacityRate(mCollisionModel, 0.3f);

		// �\�����f���Ɠ����蔻�胂�f���̈ʒu�������
		MV1SetPosition(mCollisionModel, mPosition + VGet(-45, 200, -35));

		MV1SetupCollInfo(mCollisionModel);

	}
	//----------------------------------------------------------------------
	// @brief �w�i�̃A�b�v�f�[�g�����B�w�i�͓����Ȃ��̂ŉ������Ȃ�.
	// @param[in] deltaTime �P�t���[���̌o�ߎ���.
	//----------------------------------------------------------------------
	void Map::Update(float deltaTime)
	{
	}

	//----------------------------------------------------------------------
	// @brief �w�i�̕`�揈��.
	//----------------------------------------------------------------------
	void Map::Draw()
	{
		MV1DrawModel(mModelHandle);
		//DrawCollider();
	}

}// namespace My3dApp