#pragma once
#include "pch.h"

struct InputCommands;

class Camera
{

	using Vector3 = DirectX::SimpleMath::Vector3;
	using Matrix = DirectX::SimpleMath::Matrix;

public:

	void Update(const InputCommands& inputCommands);

	Matrix GetViewMatrix() const;

	Vector3 GetPosition() const;

	Vector3 GetLookAt() const;

	Vector3 GetVectorUp() const;

	Vector3 GetVectorRight() const;

private:

	Vector3 m_scale;
	Vector3 m_cameraOrientation;
	Vector3 m_cameraPosition{ 0.f, 4.f, -4.f };

	Vector3 m_forward;
	Vector3 m_vectorUp;
	Vector3 m_lookAt;
	Vector3 m_vectorRight;

	float m_movementSpeed = 0.5f;
	float m_rotationRate = 4.f;


};

