#include "Player3D.h"

using namespace My3dApp;

namespace My3dApp
{
	Player3D::Player3D()
		:	GameObject(ObjectTag::Player),          // GameObject���p������ۂ́AGameObject�̃R���X�g���N�^���ĂԕK�v������B
		                                          // GameObject�̃R���X�g���N�^�̓^�O��K�{�Ƃ���̂ł��̂悤�ɌĂ�
			mShootTime(0.0f),
			mCameraPosition(VGet(0.0f,0.0f,0.0f)),
			mCameraTarget(VGet(0.0f,0.0f,0.0f)),
			mNowCameraTime(0),
			mMouseX(0),
			mMouseY(0),
			tmpMouseX(0),
			tmpMouseY(0),
			mCameraCoolTime(0),
			mMovePos()
	{
		mDir = VGet(1.0f, 0.0f, 0.0f);

		mCameraYaw = (3.14/2.0f);
		mCameraPitch = (3.14/2.0f);
		

		//�}�E�X����ʒ����ɃZ�b�g
		SetMousePoint(1920 / 2, 1080 / 2);
	}
	
	Player3D::~Player3D()
	{
	}

	void Player3D::Update(float deltaTime)
	{
		GameObject* cameraptr = GameObjectManager::GetFirstGameObject(ObjectTag::Camera);
		//�J�����̐��ʕ����̈ʒu�x�N�g�����v�Z
		VECTOR front = cameraptr->GetDir();
		front.y = 0.0f;//��������������

		//�x�N�g���𐳋K��
		front = VNorm(front);

		//Y���x�N�g��
		VECTOR YAxis = { 0,1,0 };
		

		// �㉺���E����
		VECTOR UP = front;
		VECTOR DOWN = VScale(front,-1.0f);
		VECTOR RIGHT = VCross(YAxis,front);
		VECTOR LEFT = VScale(RIGHT,-1.0f);

		VECTOR inputVec = VGet(0, 0, 0);

		mDir = front;	//�L�����̌����ɑO��������


		// mPosition , mDir ���L�����N�^�[�̈ʒu�E��]���Z�b�g
		MV1SetPosition(mModelHandle, mPosition);

		// z�����t�������Ă���̂�mDir��180�x��]������
		MATRIX rotYMat = MGetRotY(180.0f * (float)(DX_PI / 180.0f));
		VECTOR negativeVec = VTransform(mDir, rotYMat);

		// ���f���ɉ�]���Z�b�g mDir������
		MV1SetRotationZYAxis(mModelHandle, negativeVec, VGet(0.0f, 1.0f, 0.0f), 0.0f);

		//�����蔻��̍X�V
		CollisionUpdate();
}

	void Player3D::Draw()
	{
		
	}
}