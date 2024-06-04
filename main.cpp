#include <Novice.h>
#include "MyFunctions.h"
#include "imgui.h"

const char kWindowTitle[] = "LE2B_02_イハラ_カズキ_MT3_02_02";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kScreenWidth, kScreenHeight);
	WindowMode windowMode = kWindowed;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 cameraTranslate{ 5.00f,3.00f,-2.8f };
	Vector3 cameraRotate{ 0.45f,-1.00f,0.0f };

	AABB aabb1
	{
		.min{-0.5f,-0.5f,-0.5f},
		.max{0.0f,0.0f,0.0f},
	};
	uint32_t aabb1Color = 0xffffffff;
	AABB aabb2
	{
		.min{0.2f,0.2f,0.2f},
		.max{1.0f,1.0f,1.0f},
	};

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
		ImGui::DragFloat3("AABB1 min", &aabb1.min.x, 0.01f);
		ImGui::DragFloat3("AABB1 max", &aabb1.max.x, 0.01f);
		ImGui::DragFloat3("AABB2 min", &aabb2.min.x, 0.01f);
		ImGui::DragFloat3("AABB2 max", &aabb2.max.x, 0.01f);

		ImGui::End();

		///
		/// ↓更新処理ここから
		///
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kScreenWidth) / float(kScreenHeight), 0.1f, 100.0f);
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kScreenWidth), float(kScreenHeight), 0.0f, 1.0f);
		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);

		if (IsCollision(aabb1, aabb2))
		{
			aabb1Color = RED;
		}
		else
		{
			aabb1Color = WHITE;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		DrawGrid(viewProjectionMatrix, viewportMatrix);

		DrawAABB(aabb1, viewProjectionMatrix, viewportMatrix, aabb1Color);
		DrawAABB(aabb2, viewProjectionMatrix, viewportMatrix, 0xffffffff);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0)
		{
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
