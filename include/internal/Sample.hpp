#ifndef SAMPLE_H
#define SAMPLE_H

#include "../external/sample/Sample.hpp"

#ifdef NDEBUG
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_INFO
#else
#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG
#endif

#include <fmt/format.h>
#include <list>
#include <span>
#include <spdlog/spdlog.h>
#include <string>

namespace sample
{
	template <typename T> using Vector = std::vector<T>;
	template <typename T> using List = std::list<T>;
	template <typename T, uSz N> using Span = std::span<T, N>;

	using String = std::string;
}

#define TRACK(Format, ...) do { SPDLOG_INFO(Format __VA_OPT__(, ) __VA_ARGS__); } while (0)
#define ALERT(Format, ...) do { SPDLOG_WARN(Format __VA_OPT__(, ) __VA_ARGS__); } while (0)
#define ERROR(Format, ...) do { SPDLOG_ERROR(Format __VA_OPT__(, ) __VA_ARGS__); } while (0)
#define FATAL(Format, ...) do { SPDLOG_CRITICAL(Format __VA_OPT__(, ) __VA_ARGS__); } while (0)
#define THROW(Format, ...) do { std::string message{fmt::format(Format __VA_OPT__(, ) __VA_ARGS__)}; FATAL("Exception thrown: {}", message); throw sample::Exception{std::move(message)}; } while (0)

// Change the behavior of DEBUG / CHECK macros depending on the current build type

#ifdef NDEBUG

#define DEBUG(Format, ...) ;;
#define CHECK(Assertion) ;;

#else

#define DEBUG(Format, ...) do { SPDLOG_DEBUG(Format __VA_OPT__(, ) __VA_ARGS__); } while (0)
#define CHECK(Assertion) do { if (!(Assertion)) { FATAL("Assertion failed: {}", #Assertion); exit(-1); } } while (0)

#endif

namespace sample
{
	class Exception : public std::exception
	{
	public:
		DTOR(Exception) noexcept = default;

		CTOR(Exception)
			: m_Message{"No message provided"}
		{
		}

		template <typename... Ts> inline CTOR(Exception, std::string &&message)
			: m_Message{message}
		{
		}

		template <typename... Ts> inline CTOR(Exception, fmt::format_string<Ts...> format, Ts &&...args)
			: m_Message{fmt::format(format, args...)}
		{
		}

		[[nodiscard]] str what() const noexcept override { return m_Message.c_str(); }

	protected:
		String m_Message;
	};
}

#endif // SAMPLE_H
