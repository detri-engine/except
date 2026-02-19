#pragma once

#include <string>
#include <string_view>
#include <stdexcept>

// Defines a new exception category deriving from detri::except::base.
// Example:
//   DETRI_EXCEPTION_BASE(asset_exception, "Asset Exception");
#define DETRI_EXCEPTION_BASE(TypeName, DisplayNameLiteral)                               \
    class TypeName : public ::detri::except::base {                                      \
    public:                                                                              \
        using ::detri::except::base::base;                                               \
        [[nodiscard]] std::string_view name() const noexcept override {                  \
            using namespace std::string_view_literals;                                   \
            return DisplayNameLiteral##sv;                                               \
        }                                                                                \
        ~TypeName() override = default;                                                  \
    };


// Defines a specific exception deriving from a category (or any parent exception).
// Example:
//   DETRI_EXCEPTION(asset_exception, asset_load_error, "Asset Load Error");
#define DETRI_EXCEPTION(ParentType, TypeName, DisplayNameLiteral)                        \
    class TypeName final : public ParentType {                                           \
    public:                                                                              \
        using ParentType::ParentType;                                                    \
        [[nodiscard]] std::string_view name() const noexcept override {                  \
            using namespace std::string_view_literals;                                   \
            return DisplayNameLiteral##sv;                                               \
        }                                                                                \
        ~TypeName() override = default;                                                  \
    };


namespace detri::except
{
    using std::string_view_literals::operator ""sv;

    class base : public std::exception {
    public:
        explicit base(std::string message,
                      const std::exception_ptr& cause = {}) noexcept;

        ~base() override;

        [[nodiscard]] const char* what() const noexcept override;

        [[nodiscard]] virtual std::string_view name() const noexcept;

        [[nodiscard]] std::exception_ptr cause() const noexcept;

        [[nodiscard]] std::string_view message() const noexcept;

    private:
        std::string m_message;
        std::exception_ptr m_cause;
    };
}
