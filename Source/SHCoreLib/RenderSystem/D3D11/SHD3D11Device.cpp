#include "SHD3D11Device.h"

using namespace SHCore;

void SHD3D11Device::Create(IDXGIAdapter* inAdapter, D3D_DRIVER_TYPE inDriverType, HMODULE inSoftware, UINT inFlags,
	const D3D_FEATURE_LEVEL* inFeatureLevel, UINT inFeatureLevels, UINT inSDKVersion)
{
	if (m_D3D11Device != nullptr)
	{
		SAFE_RELEASE(m_D3D11Device);
	}

	D3D_FEATURE_LEVEL* featureLevel = nullptr;
	ID3D11DeviceContext* immediateDC = nullptr;

	D3D11CreateDevice(inAdapter, inDriverType, inSoftware, inFlags, inFeatureLevel, inFeatureLevels, inSDKVersion, &m_D3D11Device, featureLevel, &immediateDC);
}