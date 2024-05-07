#include <Novice.h>
#include "MyFunctions.h"

const char kWindowTitle[] = "LE2B_02_イハラ_カズキ_MT3";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kScreenWidth, kScreenHeight);
	WindowMode windowMode = kWindowed;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 v1{ 1.2f, -3.9f, 2.5f };
	Vector3 v2{ 2.8f, 0.4f, -1.3f };
	Vector3 cross = Cross(v1, v2);
	VectorScreenPrintf(0, 0, cross, "Cross");

	Vector3 rotate{ 0.0f,0.0f,0.0f };
	Vector3 translate{ 0.0f,0.0f,1.0f };
	Vector3 kLocalVertex[3];
	kLocalVertex[0] = { -1.0f,1.0f,0.0f };
	kLocalVertex[1] = { 0.0f,-1.0f,0.0f };
	kLocalVertex[2] = { 1.0f,1.0f,0.0f };

	Vector3 cameraPosition{ 0.0f,0.0f,10.0f };


	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		Novice::SetWindowMode(windowMode);

		///
		/// ↓更新処理ここから
		///
		rotate.y -= 0.03f;
		if (keys[DIK_W])
		{
			translate.z -= 0.1f;
		}
		if (keys[DIK_S])
		{
			translate.z += 0.1f;
		}
		if (keys[DIK_A])
		{
			translate.x += 0.1f;
		}
		if (keys[DIK_D])
		{
			translate.x -= 0.1f;
		}

		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, rotate, translate);
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, cameraPosition);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kScreenWidth) / float(kScreenHeight), 0.1f, 100.0f);
		Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, Multiply(viewMatrix, projectionMatrix));
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kScreenWidth), float(kScreenHeight), 0.0f, 1.0f);
		Vector3 screenVertices[3];
		for (uint32_t i = 0; i < 3; i++)
		{
			Vector3 ndcVertex = Transform(kLocalVertex[i], worldViewProjectionMatrix);
			screenVertices[i] = Transform(ndcVertex, viewportMatrix);
		}


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		VectorScreenPrintf(0, 0, cross, "Cross");

		Novice::DrawTriangle(
			int(screenVertices[0].x), int(screenVertices[0].y),
			int(screenVertices[1].x), int(screenVertices[1].y),
			int(screenVertices[2].x), int(screenVertices[2].y),
			RED, kFillModeSolid
		);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) { break; }
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
