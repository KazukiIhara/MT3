#include <Novice.h>
#include "MyFunctions.h"

const char kWindowTitle[] = "LE2B_02_イハラ_カズキ_MT3";
void DrawGrid(const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix)
{
	const float kGridHalfWidth = 2.0f;
	const uint32_t kSubdivision = 10;
	const float kGridEvery = (kGridHalfWidth * 2.0f) / float(kSubdivision);
	//奥から手前への線を隅々にひいていく
	for (uint32_t xIndex = 0; xIndex <= kSubdivision; ++xIndex)
	{
		/*float startX = -kGridHalfWidth + xIndex * kGridEvery;
		float startY = -kGridHalfWidth;
		float endX = startX;
		float endY = kGridHalfWidth;*/
		Vector3 startPos = { -kGridHalfWidth + xIndex * kGridEvery,-kGridHalfWidth,0.0f };
		Vector3 endPos = { -kGridHalfWidth + xIndex * kGridEvery,kGridHalfWidth };
		Novice::DrawLine(int(startPos.x), int(startPos.y), int(endPos.x), int(endPos.y), 0xaaaaaaff);
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



	Vector3 cameraPosition{ 0.0f,0.0f,0.0f };


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



		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		DrawGrid();
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
