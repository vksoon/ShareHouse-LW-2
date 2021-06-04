#pragma once
#include "SHCoreMinimal.h"

namespace SHCore
{
	enum class SH_CORE_API EWindowMode : uint8
	{
		FullScreen = 0,
		Borderless = 1,
		Window = 2,
	};

	struct SH_CORE_API FRenderWindowOption
	{
	public:
		FRenderWindowOption(EWindowMode inWindowMode = EWindowMode::Window,
			int32 inWidth = 1280, int32 inHeight = 720,
			int32 inPosX = 0, int32 inPosY = 0,
			const std::string& inWindowTitle = "")
			: _WindowMode(inWindowMode)
			, _Width(inWidth)
			, _Height(inHeight)
			, _PosX(inPosX)
			, _PosY(inPosY)
			, _WindowTitle(inWindowTitle)
		{}

		void SetSize(int32 inWidth, int32 inHeight) { _Width = inWidth; _Height = inHeight; }
		int32 GetWidth()	const { return _Width; }
		int32 GetHeight()	const { return _Height; }

		void SetPos(int32 inPosX, int32 inPosY) { _PosX = inPosX; _PosY = inPosY; }
		int32 GetPosX()		const { return _PosX; }
		int32 GetPosY()		const { return _PosY; }

		void SetWindowMode(EWindowMode inWindowMode) { _WindowMode = inWindowMode; }
		EWindowMode GetWindowMode() const { return _WindowMode; }

		bool IsFullScreen() const { return _WindowMode == EWindowMode::FullScreen; }
		bool IsBorderless() const { return _WindowMode == EWindowMode::Borderless; }
		bool IsWindow()		const { return _WindowMode == EWindowMode::Window; }

		void SetWindowTitle(const std::string& inWindowTitle) { _WindowTitle = inWindowTitle; }
		const std::string& GetWindowTitle() const { return _WindowTitle; }
	private:
		int32 _Width;
		int32 _Height;
		int32 _PosX;
		int32 _PosY;
		EWindowMode _WindowMode;
		std::string _WindowTitle;
	};

	class SH_CORE_API SHRenderWindow
	{
	public:
		static FRenderWindowOption CreateRenderWindowOption(
			EWindowMode inWindowMode = EWindowMode::Window,
			int32 inWidth = 1280, int32 inHeight = 720,
			int32 inPosX = 0, int32 inPosY = 0,
			const std::string& inWindowTitle = "");

		SHRenderWindow() {}
		virtual ~SHRenderWindow() = default;

		virtual bool Create(const FRenderWindowOption& inRenderWindowOption) = 0;
		virtual bool Show() = 0;
		virtual void Destroy() = 0;

	protected:
		FRenderWindowOption m_RenderWindowOption;
	};
}