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

	Vector3 cameraTranslate{ 4.07f,3.13f,-0.9f };
	Vector3 cameraRotate{ 0.66f,-1.43f,0.0f };

	Segment line{};
	line.origin = { -0.19f,-0.21f,0.09f };
	line.diff = { 0.598f,1.15f,-0.54f };

	int lineColor = WHITE;

	Triangle tri{};
	tri.vertices[0] = { -1.0f,0.0f,0.0f };
	tri.vertices[1] = { 0.0f,1.0f,0.0f };
	tri.vertices[2] = { 1.0f,0.0f,0.0f };

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
		ImGui::DragFloat3("segment.origin", &line.origin.x, 0.01f);
		ImGui::DragFloat3("segment.diff", &line.diff.x, 0.01f);
		ImGui::DragFloat3("triangle.verteice1", &tri.vertices[0].x, 0.01f);
		ImGui::DragFloat3("triangle.verteice2", &tri.vertices[1].x, 0.01f);
		ImGui::DragFloat3("triangle.verteice3", &tri.vertices[2].x, 0.01f);

		ImGui::End();

		///
		/// ↓更新処理ここから
		///
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kScreenWidth) / float(kScreenHeight), 0.1f, 100.0f);
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kScreenWidth), float(kScreenHeight), 0.0f, 1.0f);
		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);

		if (IsCollision(tri, line))
		{
			lineColor = RED;
		}
		else
		{
			lineColor = WHITE;
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///
		DrawGrid(viewProjectionMatrix, viewportMatrix);
		DrawTriangle(tri, viewProjectionMatrix, viewportMatrix, WHITE);
		DrawLine(line, viewProjectionMatrix, viewportMatrix, lineColor);
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
