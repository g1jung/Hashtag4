#include "Application.h"

#include "Events/ApplicationEvent.h"
#include "Log.h"

namespace Hashtag4
{
	Application::Application()
	{

	}

	Application::~Application()
	{

	}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		H4_TRACE(e);

		while (true);
	}

}


