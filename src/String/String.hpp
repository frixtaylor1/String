#pragma once

#include "../Allocator/String/StringAllocator.hpp"
#include <ostream>
#include <cstring>

// String Class-------------------------------------------------->>
namespace frix
{
    StringAllocator allocator;

    class String
    {
    public:

        /**
         * @contructor: filled
         * 
         * @param <const char*> str  
         */    
        String(const char *str) {
            m_str = (char *)(allocator.allocate(strlen(str) + 1));
            strcpy(m_str, str);
        }

        /**
         * @destructor: "deallocating" static mem 
         */
        ~String() {
            allocator.deallocate(m_str);
        }

        /**
         * @contructor: void 
         */
        String() = default;

        /**
         * @contructor: copy 
         */
        String(const String &str) {
            m_str = str.m_str;
        }

        /**
         * @contructor: move 
         */
        String(String &&str)
            : m_str{str.m_str} {
            str.m_str = nullptr;
        }

        /**
         * @todo: Operations with strings...
         *
         * @method: Contact
         * @method: Includes
         * @method: endsWith
         * @method: beginsWith
         * @method: replace
         * @method: trim
         * @method: trimStart
         * @method: trimEnd
         * @method: toLowerCase
         * @method: toUpperCase
        **/

        friend std::ostream &operator<<(std::ostream &stream, const String &str);
        char *m_str;
    };

    // Operator overloading------------------------------------------>>
    std::ostream &operator<<(std::ostream &stream, const String &str)
    {
        stream << str.m_str;
        return stream;
    }
}