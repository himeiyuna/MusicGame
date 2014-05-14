#include <Windows.h>
#include <memory>
#include <string>

///@brief Windowsウィンドウ管理インターフェース
class Window
{
	class HolderBase
	{
	public:
		virtual ~HolderBase() {}
		virtual void createWindow(std::string & windowTitle) = 0;
		virtual void destroyWindow() = 0;
	};

	template <class T>
	class Holder : public HolderBase
	{
		std::shared_ptr<T> ptr_;
	public:
		Holder(std::shared_ptr<T> & ptr)
		{
			ptr_ = ptr;
		}
		virtual ~Holder() {}
		
		///@brief ウィンドウ生成
		virtual void createWindow(std::string & windowTitle)
		{
			ptr_->createWindow(windowTitle);
		}

		///@brief ウィンドウ破棄
		virtual void destroyWindow()
		{
			ptr_->destroyWindow();
		}
	};

	std::shared_ptr<HolderBase> window_;
public:
};