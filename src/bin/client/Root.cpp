#include <internal/Sample.hpp>
#include <sample/client/Client.hpp>

using namespace sample::client;

class MyScene : public Scene
{
public:
	DTOR(MyScene) = default;

	CTOR(MyScene) = default;

	void Do() override
	{
		DEBUG("Hello MyScene");
	}
};

Scene *sample::client::Root()
{
	return new MyScene();
}
