#include "DangerZone.h"

using namespace My3dApp;

namespace My3dApp {

	int DangerZone::mHandle = LoadGraph("../data/model/DangerZone/Red_frame.png");
	DangerZone* DangerZone::mpInstance = nullptr;

	DangerZone::DangerZone()
	{
		mpInstance = nullptr;
		
	}

	DangerZone::~DangerZone()
	{
		delete mpInstance;
	}

	void DangerZone::Intialize()
	{
		mpInstance = new DangerZone;
	}
	void DangerZone::Update(float deltaTime)
	{

	}
	void DangerZone::Draw()
	{
		mHandle = LoadGraph("data/model/DangerZone/Red_frame.png");
		DrawGraph(0,0, mHandle, TRUE);
	}
}