#include <Novice.h>
#include "MyFunctions.h"
#include "imgui.h"


const char kWindowTitle[] = "LE2B_02_イハラ_カズキ_MT3";
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix)
{
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubdivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);
	Vector3 kLocalGrid{ 0.0f,0.0f,0.0f };

	//奥から手前への線を隅々にひいていく
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex)
	{
		Vector3 startPos = { -kGridHalfWidth + xIndex * kGridEvery,0.0f,-kGridHalfWidth };
		Vector3 endPos = { -kGridHalfWidth + xIndex * kGridEvery,0.0f,kGridHalfWidth };

		Matrix4x4 sWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, startPos);
		Matrix4x4 sWorldViewProjectionMatrix = Multiply(sWorldMatrix, viewProjectionMatrix);
		Vector3 ndcStart = Transform(kLocalGrid, sWorldViewProjectionMatrix);
		Vector3 screenStart = Transform(ndcStart, viewportMatrix);

		Matrix4x4 eWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, endPos);
		Matrix4x4 eWorldViewProjectionMatrix = Multiply(eWorldMatrix, viewProjectionMatrix);
		Vector3 ndcEnd = Transform(kLocalGrid, eWorldViewProjectionMatrix);
		Vector3 screenEnd = Transform(ndcEnd, viewportMatrix);

		Novice::DrawLine(int(screenStart.x), int(screenStart.y), int(screenEnd.x), int(screenEnd.y), 0xaaaaaaff);
	}
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex)
	{
		Vector3 startPos = { -kGridHalfWidth,0.0f,-kGridHalfWidth + xIndex * kGridEvery };
		Vector3 endPos = { kGridHalfWidth,0.0f,-kGridHalfWidth + xIndex * kGridEvery };

		Matrix4x4 sWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, startPos);
		Matrix4x4 sWorldViewProjectionMatrix = Multiply(sWorldMatrix, viewProjectionMatrix);
		Vector3 ndcStart = Transform(kLocalGrid, sWorldViewProjectionMatrix);
		Vector3 screenStart = Transform(ndcStart, viewportMatrix);

		Matrix4x4 eWorldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f, 0.0f, 0.0f }, endPos);
		Matrix4x4 eWorldViewProjectionMatrix = Multiply(eWorldMatrix, viewProjectionMatrix);
		Vector3 ndcEnd = Transform(kLocalGrid, eWorldViewProjectionMatrix);
		Vector3 screenEnd = Transform(ndcEnd, viewportMatrix);

		Novice::DrawLine(int(screenStart.x), int(screenStart.y), int(screenEnd.x), int(screenEnd.y), 0xaaaaaaff);
	}

}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kScreenWidth, kScreenHeight);
	WindowMode windowMode = kWindowed;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 cameraTranslate{ 0.0f,1.9f,-6.49f };
	Vector3 cameraRotate{ 0.26f,0.0f,0.0f };

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0)
	{
		// フレームの開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		Novice::SetWindowMode(windowMode);

		//Imgui
		ImGui::Begin("Window");
		ImGui::DragFloat3("cameraTranslate", &cameraTranslate.x, 0.01f);
		ImGui::DragFloat3("cameraRotate", &cameraRotate.x, 0.01f);

		ImGui::End();


		///
		/// ↓更新処理ここから
		///
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kScreenWidth) / float(kScreenHeight), 0.1f, 100.0f);
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kScreenWidth), float(kScreenHeight), 0.0f, 1.0f);
		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);


		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		DrawGrid(viewProjectionMatrix, viewportMatrix);
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
