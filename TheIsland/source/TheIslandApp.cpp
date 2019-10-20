#include <Hashtag4.h>

class TheIsland : public Hashtag4::Application
{
public:
	TheIsland()
	{

	}

	~TheIsland()
	{

	}
};

Hashtag4::Application* Hashtag4::CreateApplication()
{
	return new TheIsland();
}