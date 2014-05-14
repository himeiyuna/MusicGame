#include <Windows.h>
#include <memory>
#include <string>

///@brief Windows�E�B���h�E�Ǘ��C���^�[�t�F�[�X
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
		
		///@brief �E�B���h�E����
		virtual void createWindow(std::string & windowTitle)
		{
			ptr_->createWindow(windowTitle);
		}

		///@brief �E�B���h�E�j��
		virtual void destroyWindow()
		{
			ptr_->destroyWindow();
		}
	};

	std::shared_ptr<HolderBase> window_;
public:
};