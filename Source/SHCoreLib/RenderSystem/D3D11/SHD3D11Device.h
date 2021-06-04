#pragma once

#include "SHCoreMinimal.h"
#include "SHD3D11Define.h"

namespace SHCore
{
	class SH_CORE_API SHD3D11Device
	{
	public:
		void Create(IDXGIAdapter* inAdapter, D3D_DRIVER_TYPE inDriverType, HMODULE inSoftware, UINT inFlags, 
			const D3D_FEATURE_LEVEL* inFeatureLevel, UINT inFeatureLevels, UINT inSDKVersion);
	private:
		ID3D11Device* m_D3D11Device = nullptr;
		IDXGIFactory* m_DXGIFactory = nullptr;
	};
}