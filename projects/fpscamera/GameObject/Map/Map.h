//-----------------------------------------------------------
// @brief �w�i�N���X
//-----------------------------------------------------------
#pragma once

#include <DxLib.h>
#include "../GameObject.h"


namespace My3dApp
{
	class Map : public My3dApp::GameObject
	{
	public:
		Map();                          // �w�i�N���X�R���X�g���N�^
		Map(VECTOR pos);                // �ʒu�w��
		~Map();                         // �f�X�g���N�^
		void ModelLoad();                      // ���f���ǂݍ���
		void Update(float deltaTime)override;  // �w�i�X�V����
		void Draw() override;                  // �w�i�`��
	};
}// namespace My3dApp