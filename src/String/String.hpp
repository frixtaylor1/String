#pragma once

#include "../Allocator/String/StringAllocator.hpp"
#include <ostream>
#include <cstring>
#include <assert.h>

// String Class-------------------------------------------------->>
namespace frix
{
    class String
    {
    public:

        /**
         * @contructor: filled
         * 
         * @param: <const char*> str  
         */    
        String(const char *str);

        /**
         * @destructor: "deallocating" static mem 
         */
        ~String();

        /**
         * @contructor: void 
         */
        String() = default;

        /**
         * @contructor: copy 
         */
        String(const String &str);

        /**
         * @contructor: move 
         */
        String(String &&str);

        /**
         * @method: concat 
         */
        String concat(const char* str) const;

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

        char *m_str;
    };

    // Operator overloading------------------------------------------>>
    std::ostream &operator<<(std::ostream &stream, const String &str);
}