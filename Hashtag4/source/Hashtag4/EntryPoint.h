#pragma once

#ifdef H4_PLATFORM_WINDOWS

extern Hashtag4::Application* Hashtag4::CreateApplication();

int main(int argc, char** argv)
{
	Hashtag4::Log::Init();
	H4_CORE_WARN("Initialized Log!");
	int a = 5;
	H4_INFO("Hello! Var={0}", a);

	auto app = Hashtag4::CreateApplication();
	app->Run();
	delete app;
}

#endif
