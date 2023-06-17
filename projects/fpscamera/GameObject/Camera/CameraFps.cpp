#include "CameraFps.h"
#include <DxLib.h>
#include "../Player/Player3D.h"
#include"../GameObjectManager.h"
using namespace My3dApp;
// @brief CameraFps�R���X�g���N�^�[ //
namespace My3dApp{
CameraFps::CameraFps()
    :GameObject(ObjectTag::Camera)
    ,camLookPos{0,0,0}
    ,mouseX(0)
    ,mouseY(0)
    ,movePos{0,0,0}
{
    SetCameraNearFar(CameraNear, CameraFar);                                            //�J�����̕`��͈͐ݒ�
    SetMouseDispFlag(FALSE);
}

// @brief CameraFps�X�V���� //

void CameraFps::Update(float deltaTime)
{
    GameObject* player = GameObjectManager::GetFirstGameObject(ObjectTag::Player);                    //�v���C���[�I�u�W�F�N�g�擾
    if (player)                                                                         //�I�u�W�F�N�g�̒��g����łȂ����
    {
        //---�J�������W�ݒ�---//
        mPosition = player->GetPosition();                                                      //�J�����̈ʒu�̓v���C���[�̍��W
        mPosition.y = 200;                                                                  //�����͖ڐ��̈ʒu

        Move(deltaTime);
        SetCameraPositionAndTarget_UpVecY(mPosition, mPosition + camLookPos);      //�v���C���[�̈ʒu���璍���_�Ɍ����ăJ�������Z�b�g
        mDir = camLookPos;                                                   //�J�����̐��ʕ����x�N�g��
    }
    SetMousePoint(1920 / 2, 1080 / 2);                        //�}�E�X���W����ʂ̒��S�ɃZ�b�g
}

// @brief CameraFps�ړ����� //

void CameraFps::Move(float deltaTime)
{
        GetMousePoint(&mouseX, &mouseY);                                        //�}�E�X���W�擾

        //---�}�E�X���W����X�N���[�����W�̒��S������---//
        movePos.x = (float)mouseX - static_cast<float>(1920) / 2;
        movePos.y = (float)mouseY - static_cast<float>(1080) / 2;

        //---���_�ړ�--//
        if (abs(movePos.x) > 0)                                                      //�}�E�X�J�[�\��X�����X���C�h��
        {
            mYaw -= movePos.x * deltaTime * (float)DX_PI / 30;                         //�J�[�\���̈ړ��ʕ����������ɉ�]
        }
        if (abs(movePos.y) > 0)                                                     //�}�E�X�J�[�\��Y�����X���C�h��
        {
            mPitch -= movePos.y * deltaTime * (float)DX_PI / 30;                     //�J�[�\���̈ړ��̕����������ɉ�]
        }

        //---�����_����---//
        camLookPos.x = cosf(mYaw);
        camLookPos.y = mPitch;
        camLookPos.z = sinf(mYaw);
}
}