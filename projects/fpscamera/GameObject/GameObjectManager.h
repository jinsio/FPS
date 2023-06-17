//------------------------------------------------------------------------------
// @brief �Q�[���I�u�W�F�N�g�}�l�[�W��
//------------------------------------------------------------------------------
#pragma once

#include <vector>
#include <unordered_map>
#include <DxLib.h>

#include "GameObject.h"
#include "ObjectTag.h"
#include "../math/math3D.h"

namespace My3dApp
{
	class GameObjectManager final
	{
	public:
		static void Initialize();                              // �Q�[���I�u�W�F�N�g�}�l�[�W���̏���������
		static void Entry(GameObject* newObj);                 // �Q�[���I�u�W�F�N�g�o�^
		static void Release(GameObject* releaseObj);           // �Q�[���I�u�W�F�N�g�폜
		static void ReleaseAllObj();                           // �S�I�u�W�F�N�g�폜

		static void Update(float deltaTime);                   // �S�I�u�W�F�N�g�̍X�V����
		static void Draw();                                    // �`�� 

		static void Collision();                               // �����蔻��
		static void Coordinate();							   // ���W�\��

		static GameObject* GetFirstGameObject(ObjectTag tag);  // �I�u�W�F�N�g�^�O��̍ŏ���GameObject��Ԃ�

		static void Finalize();

	private:
		GameObjectManager();                                   // �V���O���g��
		~GameObjectManager();                                  // �Q�[���I�u�W�F�N�g�}�l�[�W���f�X�g���N�^
		static GameObjectManager* mpInstance;                  // �}�l�[�W���̎��́i�A�v�����ɗB�ꑶ��)
		std::vector<GameObject*>  mPendingObjects;             // �ꎞ�ҋ@�I�u�W�F�N�g
		std::unordered_map<ObjectTag, std::vector<GameObject*>> mObjects;        // mObjects[�^�O���][�I�u�W�F�N�g��]; 
	};

}// namespace My3dApp
