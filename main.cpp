#include <Novice.h>
#include "MyFunctions.h"
#include "imgui.h"

const char kWindowTitle[] = "LE2B_02_イハラ_カズキ_MT3_02_02";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {
	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, kScreenWidth, kScreenHeight);
	WindowMode windowMode = kWindowed;
	// キー入力結果を受け取る箱
	char keys[256] = { 0 };
	char preKeys[256] = { 0 };

	Vector3 cameraTranslate{ 0.00f,1.90f,-5.0f };
	Vector3 cameraRotate{ 0.39f,0.0f,0.0f };

	Vector3 position{};

	Pendulum pendulum;
	pendulum.anchor = { 0.0f,1.0f,0.0f };
	pendulum.length = 0.8f;
	pendulum.angle = 0.7f;
	pendulum.angulerVelocity = 0.0f;
	pendulum.angulerAcceleration = 0.0f;

	Segment segment{};

	float deltaTime = 1.0f / 60.0f;

	bool isUpdate = false;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();
		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		Novice::SetWindowMode(windowMode);

		//Imgui
		ImGui::Begin("Window");
		if (ImGui::Button("Start")) {
			isUpdate = true;
		}
		ImGui::End();

		///
		/// ↓更新処理ここから
		///
		Matrix4x4 cameraMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, cameraRotate, cameraTranslate);
		Matrix4x4 viewMatrix = Inverse(cameraMatrix);
		Matrix4x4 projectionMatrix = MakePerspectiveFovMatrix(0.45f, float(kScreenWidth) / float(kScreenHeight), 0.1f, 100.0f);
		Matrix4x4 viewportMatrix = MakeViewportMatrix(0, 0, float(kScreenWidth), float(kScreenHeight), 0.0f, 1.0f);
		Matrix4x4 viewProjectionMatrix = Multiply(viewMatrix, projectionMatrix);

		if (isUpdate) {
			pendulum.angulerAcceleration = -(9.8f / pendulum.length) * std::sin(pendulum.angle);
			pendulum.angulerVelocity += pendulum.angulerAcceleration * deltaTime;
			pendulum.angle += pendulum.angulerVelocity * deltaTime;
		}

		position.x = pendulum.anchor.x + std::sin(pendulum.angle) * pendulum.length;
		position.y = pendulum.anchor.y - std::cos(pendulum.angle) * pendulum.length;
		position.z = pendulum.anchor.z;

		Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, { 0.0f,0.0f,0.0f }, position);

		segment.origin = pendulum.anchor;
		segment.diff = position - pendulum.anchor;

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		DrawGrid(viewProjectionMatrix, viewportMatrix);
		DrawLine(segment, viewProjectionMatrix, viewportMatrix, WHITE);
		DrawSphereWorldMatrix(worldMatrix, viewProjectionMatrix, viewportMatrix, BLUE);

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
