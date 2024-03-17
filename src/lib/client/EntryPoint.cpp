#include <internal/Sample.hpp>

void SetupLogging()
{
#ifndef NDEBUG
	spdlog::set_level(spdlog::level::debug);
#else
	spdlog::set_level(spdlog::level::info);
#endif
}

#ifndef TESTING

#include <sample/client/Client.hpp>

using namespace sample::client;

int main(int argc, char **argv)
{
	SetupLogging();

	DEBUG("LibClient version 0.1.0");

	if (std::unique_ptr<Scene> root{sample::client::Root()})
	{
		root->Do();
	}
	else
	{
		THROW("Root scene is undefined");
	}
}

#endif // !TESTING
