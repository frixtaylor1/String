#include "./String.hpp"

namespace frix {
    static StringAllocator allocator;

    String::String(const char* str) {
        m_str = (char *)(allocator.allocate(strlen(str) + 1));
        strcpy(m_str, str);
    }

    String::~String() {
        allocator.deallocate(m_str);
    }

    String::String(const String& str) {
        m_str = str.m_str;
    }

    String::String(String&& str) : m_str{str.m_str} {
        str.m_str = nullptr;
    }

    String String::concat(const char* str) const {
        size_t lenLsh = std::strlen(m_str);
        size_t lenRsh = std::strlen(str);

        char newBuff[lenLsh + lenRsh];
        std::memcpy(newBuff, m_str, lenLsh);
        std::memcpy(newBuff + lenLsh, str, lenRsh);
        newBuff[lenLsh + lenRsh] = '\0';
        return String(newBuff);
    }

    bool String::endsWith(const char* str) {
        return true;
    }

    bool String::beginsWith(const char* str) {
        return true;
    }

    std::ostream &operator<<(std::ostream &stream, const String& str) {
        stream << str.m_str;
        return stream;
    }

    std::istream &operator>>(std::istream &stream, const String &str) {

    }
}
    