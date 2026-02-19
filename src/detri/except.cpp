#include "detri/except.hpp"

namespace detri::except
{
    base::base(std::string message, const std::exception_ptr& cause) noexcept: m_message{std::move(message)}
                                                                               , m_cause{cause} {}

    base::~base() = default;

    const char* base::what() const noexcept
    {
        return m_message.c_str();
    }

    std::string_view base::name() const noexcept {
        return "Exception"sv;
    }
    std::exception_ptr base::cause() const noexcept {
        return m_cause;
    }
    std::string_view base::message() const noexcept {
        return m_message;
    }
}
