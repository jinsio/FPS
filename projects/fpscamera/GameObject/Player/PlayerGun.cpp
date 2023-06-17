#include "PlayerGun.h"

using namespace My3dApp;

namespace My3dApp 
{
    PlayerGun::PlayerGun()
        :GameObject(ObjectTag::PlayerGun),
        mGunOffSet(),
        mGanRadius(),
        mShotTime(0.0f),
        mShotIntervalTime(0.5f)
    {
        // ���f���ǂݍ��݂ƃe�N�X�`���\��t��
        mModelHandle = AssetManager::GetMesh("data/model/FPS/PlayerGun.mv1");
        mDir = VGet(0, 1, 0);

    }

    PlayerGun::~PlayerGun()
    {
 
    }

    void PlayerGun::Shot()
    {
        mShotTime = mShotIntervalTime;
        GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Camera);
        PlayerBullet* pb = new My3dApp::PlayerBullet(this);
        GameObjectManager::Entry(pb);
    }

    void PlayerGun::Update(float deltaTime)
    {
        
        GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Camera);
        //mDir = cameraptr->GetDir();
        mGanRadius = mGunSet;
        mPosition.x = mGanRadius.y * cosf( -cameraptr->GetYaw())+cameraptr->GetPosition().x;
        mPosition.y = 175;
        mPosition.z = mGanRadius.y * sinf(-cameraptr->GetYaw())+cameraptr->GetPosition().z;
        //Move(deltaTime);
        //SetCameraPositionAndTarget_UpVecY(mPosition, mPosition );      //�v���C���[�̈ʒu���璍���_�Ɍ����ăJ�������Z�b�g
       

        MV1SetPosition(mModelHandle, mPosition);
        // �����蔻�苅��ݒ�
        mCollisionSphere.mLocalCenter = VGet(0, 175, 0);
        mCollisionSphere.mRadius = 25.0f;
        mCollisionSphere.mWorldCenter = VGet(0,175,0);

        //�����ɍ��킹�ă��f������]
        MATRIX rotYMat = MGetRotY(90.0f * (float)(DX_PI / 180.f));
        VECTOR negativeVec = VTransform(cameraptr->GetDir(), rotYMat);
        negativeVec.y = 0;
        MV1SetRotationZYAxis(mModelHandle,negativeVec,VGet(0.0f,1.0f,0.0f),0.0f);

        mShotTime -= deltaTime;
        // �X�y�[�X�L�[(�}�E�X���{�^��)�������ꂽ��e�𔭎�
        int MouseInput;
        MouseInput = GetMouseInput();
        if (mShotTime < 0.0f && (CheckHitKey(KEY_INPUT_SPACE) || MouseInput & MOUSE_INPUT_LEFT)) {
            Shot();
        }
    }

    void PlayerGun::Draw()
    {
        MV1DrawModel(mModelHandle);
        DrawSphere3D(mCollisionSphere.mWorldCenter, mCollisionSphere.mRadius, 8, GetColor(0, 255, 255), 0, FALSE);
    }

    void PlayerGun::OnCollisionEnter(GameObject* other)
    {
        ObjectTag tag = other->GetTag();

        //�G�Ƃ̏Փ�
        if (tag == ObjectTag::Enemy)
        {
            //�v���C���[�̒e�ƓG�̓����蔻��
            if (CollisionPair(mCollisionSphere, other->GetCollisionSphere()))
            {
                //Life::LifeSub();//�_���[�W����
                //other->SetAlive(FALSE);//Enemy����(��)
            }
        }
    }

}