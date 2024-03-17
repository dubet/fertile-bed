#ifndef API_SAMPLE_CLIENT_SCENE_H
#define API_SAMPLE_CLIENT_SCENE_H

#include "../Sample.hpp"

namespace sample::client
{
	class Scene : private NonCopyable
	{
	public:
		virtual DTOR(Scene) noexcept = default;

		CTOR(Scene) = default;

		virtual void Do() = 0;
	};
}

#endif // API_SAMPLE_CLIENT_SCENE_H
