#include <Novice.h>
#include "MyFunctions.h"
#include "imgui.h"

const char kWindowTitle[] = "LE2B_02_イハラ_カズキ_MT3";

struct Sphere
{
	Vector3 center;//中心点
	Vector3 rotate;//回転
	float radius;//半径
};

void DrawSphere(const Sphere& sphere, const Matrix4x4& viewProjectionMatrix, const Matrix4x4& viewportMatrix, uint32_t color)
{
	const uint32_t kSubdivision = 20; // 分割数
	const float kLonEvery = 2.0f * std::numbers::pi_v<float> / float(kSubdivision); // 経度分割1つ分の角度
	const float kLatEvery = std::numbers::pi_v<float> / float(kSubdivision); // 緯度分割1つ分の角度
	Matrix4x4 worldMatrix = MakeAffineMatrix({ 1.0f,1.0f,1.0f }, sphere.rotate, sphere.center);


	// 緯度の方向に分割 -π/2 ~ π/2
	for (uint32_t latIndex = 0; latIndex < kSubdivision; latIndex++)
	{
		float lat = -std::numbers::pi_v<float> / 2.0f + kLatEvery * latIndex;//現在の緯度
		// 経度の方向に分割 0 ~ 2π
		for (uint32_t lonIndex = 0; lonIndex < kSubdivision; lonIndex++)
		{
			float lon = kLonEvery * lonIndex; // 現在の経度

			// world座標系でのa,b,cを求める
			Vector3 a, b, c;
			a = { std::cosf(lat) * std::cosf(lon) * sphere.radius,sinf(lat) * sphere.radius, std::cosf(lat) * std::sinf(lon) * sphere.radius };
			b = { std::cosf(lat + kLatEvery) * std::cosf(lon) * sphere.radius,std::sinf(lat + kLatEvery) * sphere.radius,std::cosf(lat + kLatEvery) * std::sinf(lon) * sphere.radius };
			c = { std::cos(lat) * std::cos(lon + kLonEvery) * sphere.radius,std::sin(lat) * sphere.radius,std::cos(lat) * std::sin(lon + kLonEvery) * sphere.radius };
			// a, b, c を screen 座標系に変換
			Matrix4x4 worldViewProjectionMatrix = Multiply(worldMatrix, viewProjectionMatrix);

			Vector3 ndcA = Transform(a, worldViewProjectionMatrix);
			Vector3 screenA = Transform(ndcA, viewportMatrix);

			Vector3 ndcB = Transform(b, worldViewProjectionMatrix);
			Vector3 screenB = Transform(ndcB, viewportMatrix);

			Vector3 ndcC = Transform(c, worldViewProjectionMatrix);
			Vector3 screenC = Transform(ndcC, viewportMatrix);

			// ab, bc で線を引く
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenB.x), int(screenB.y), color);
			Novice::DrawLine(int(screenA.x), int(screenA.y), int(screenC.x), int(screenC.y), color);
		}
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

	Sphere sphere{};
	sphere.center = { 0.0f,0.0f,0.0f };
	sphere.rotate = { 0.0f,0.0f,0.0f };
	sphere.radius = 1.0f;

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
		ImGui::DragFloat3("sphereTranslate", &sphere.center.x, 0.01f);
		ImGui::DragFloat3("sphereRotate", &sphere.rotate.x, 0.01f);
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
		DrawSphere(sphere, viewProjectionMatrix, viewportMatrix, 0x000000ff);
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
