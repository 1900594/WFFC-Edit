#include "Camera.h"
#include"InputCommands.h"

using namespace DirectX;

void Camera::Update(const InputCommands& inputCommands)
{

	if (inputCommands.rotRight)
	{
		m_cameraOrientation.y -= m_rotationRate;
	}

	if (inputCommands.rotLeft)
	{
		m_cameraOrientation.y += m_rotationRate;
	}
	if (inputCommands.rotUp)
	{
		m_cameraOrientation.x += m_rotationRate;
	}
	if (inputCommands.rotDown)
	{
		m_cameraOrientation.x -= m_rotationRate;
	}

	m_cameraOrientation.y += inputCommands.mouseDX;
	m_cameraOrientation.x += inputCommands.mouseDY;

	m_cameraOrientation.x = std::min(m_cameraOrientation.x, +89.f);
	m_cameraOrientation.x = std::max(m_cameraOrientation.x, -89.f);


	float cosY = cosf(XMConvertToRadians(m_cameraOrientation.y));
	float cosP = cosf(XMConvertToRadians(m_cameraOrientation.x));

	float sinY = sinf(XMConvertToRadians(m_cameraOrientation.y));
	float sinP = sinf(XMConvertToRadians(m_cameraOrientation.x));

	m_forward.x = sinY * cosP;

	m_forward.y = sinP;

	m_forward.z = cosP * cosY;
	m_forward.Normalize();


	if (inputCommands.forward)
	{
		m_cameraPosition += m_forward * m_movementSpeed;
	}
	if (inputCommands.back)
	{
		m_cameraPosition -= m_forward * m_movementSpeed;
	}
	if (inputCommands.right)
	{
		m_cameraPosition += m_vectorRight * m_movementSpeed;
	}
	if (inputCommands.left)
	{
		m_cameraPosition -= m_vectorRight * m_movementSpeed;
	}
	if (inputCommands.up)
	{
		m_cameraPosition.y += m_movementSpeed;
	}
	if (inputCommands.down)
	{
		m_cameraPosition.y -= m_movementSpeed;
	}

	m_lookAt = m_cameraPosition + m_forward;

}

DirectX::SimpleMath::Matrix Camera::GetViewMatrix() const
{
	return Matrix::CreateLookAt(m_cameraPosition, m_lookAt, Vector3::UnitY);
}

DirectX::SimpleMath::Vector3 Camera::GetPosition() const
{
	return m_cameraPosition;
}

DirectX::SimpleMath::Vector3 Camera::GetLookAt() const
{
	return m_lookAt;
}

DirectX::SimpleMath::Vector3 Camera::GetVectorUp() const
{
	return m_vectorUp;
}

DirectX::SimpleMath::Vector3 Camera::GetVectorRight() const
{
	return m_vectorRight;
}
