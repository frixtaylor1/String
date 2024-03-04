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
         * 
         * @param c_string str 
         * 
         * @returns `frix::String`
         */
        String concat(const char* str) const;

        /**
         * @method: endsWith
         * 
         * @param c_string str
         * 
         * @returns `bool` 
         */
        bool endsWith(const char* str);

        /**
         * @method: beginsWith
         * 
         * @param c_string str
         * 
         * @returns `bool` 
         */
        bool beginsWith(const char* str);

        /**
         * @method: includes
         * 
         * @param c_string str
         * 
         * @returns `bool` 
         */
        bool includes(const char* str);

        /**
         * @method: replace
         * 
         * @param c_string str
         * 
         * @returns `void` 
         */
        void replace(const char* str);

        /**
         * @method: replace
         * 
         * @param c_string str
         * 
         * @returns `String` 
         */
        String replace(const char* str) const;

        /**
         * @method: trim
         * 
         * @returns `String` 
         */
        String trim() const;

        /**
         * @method: trim
         * 
         * @returns `void` 
         */
        void trim();

        /**
         * @method: trimStart
         * 
         * @returns `String` 
         */
        String trimStart() const;

        /**
         * @method: trimStart
         * 
         * @returns `void` 
         */
        void trimStart();

        /**
         * @method: trimEnd
         * 
         * @returns `String` 
         */
        String trimEnd() const;

        /**
         * @method: trimEnd
         * 
         * @returns `void` 
         */
        void trimEnd();

        /**
         * @method: toLowerCase
         * 
         * @returns `String` 
         */
        String toLowerCase() const;

        /**
         * @method: toLowerCase
         * 
         * @returns `void` 
         */
        void toLowerCase();

        /**
         * @method: toUpperCase
         * 
         * @returns `String` 
         */
        String toUpperCase() const;

        /**
         * @method: toUpperCase
         * 
         * @returns `void` 
         */
        void toUpperCase();

        /**
         * @todo: Implement the defined member functions...
         *
        **/

    protected:
        void replaceImpl(const char* str);

        char *m_str;
    };

    // Operator overloading------------------------------------------>>
    std::ostream &operator<<(std::ostream &stream, const String &str);
}