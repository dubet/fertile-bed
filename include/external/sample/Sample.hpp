#ifndef API_SAMPLE_H
#define API_SAMPLE_H

#include <cstddef>
#include <cstdint>

#define CTOR(ClassName, ...) ClassName(__VA_ARGS__)
#define DTOR(ClassName) ~ClassName()

// Generic types

namespace sample
{
	using i8 = int8_t;
	using i16 = int16_t;
	using i32 = int32_t;
	using i64 = int64_t;
	using u8 = uint8_t;
	using u16 = uint16_t;
	using u32 = uint32_t;
	using u64 = uint64_t;
	using f32 = float;
	using f64 = double;
	using nil = void;
	using bln = bool;
	using uSz = size_t;
	using chr = char;
	using str = char const *;

	class NonCopyable
	{
	protected:
		CTOR(NonCopyable) noexcept = default;

	private:
		CTOR(NonCopyable, NonCopyable const &) = delete;

		NonCopyable &operator=(NonCopyable const &) = delete;
	};
}

#endif // API_SAMPLE_H
