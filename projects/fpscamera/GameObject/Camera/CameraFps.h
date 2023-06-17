#pragma once
#include"../GameObject.h"

namespace My3dApp {
    const float CameraNear = 1.0f;       //�J�����̕`��͈�(��)
    const float CameraFar = 8000.0f;     //�J�����̕`��͈�(��)

    /*��l�̎��_�̃N���X*/
    class CameraFps :public GameObject
    {
    public:
        /// <summary>
        /// CamreFps�R���X�g���N�^�[
        /// </summary>
        /// <param name="targetPos">�J�����������W</param>
        CameraFps();

        /// <summary>
        /// CamreFps�f�X�g���N�^�[
        /// </summary>
        ~CameraFps() {};

        /// <summary>
        /// CameraFps�X�V����
        /// </summary>
        /// <param name="deltaTime">:�t���[�����[�g</param>
        void Update(float deltaTime)override;

        /// <summary>
        /// CameraFps�ړ�����
        /// </summary>
        /// <param name="deltaTime">:�t���[�����[�g</param>
        void Move(float deltaTime);

        float GetYaw() { return mYaw; }
        float GetPitch() { return mPitch; }

    protected:
        int mouseX;             //�}�E�X���WX
        int mouseY;             //�}�E�X���WY
        VECTOR movePos;         //�ړ����W

        VECTOR camLookPos;      //�����_
    };
}