#include <Common.hpp>
#include <ctype.h>

// Allocator Interface------------------------------------------->>
namespace frix {
    interface IAllocator {
        virtual void* allocate(size_t size) = 0;
        virtual void deallocate(void* ptr) = 0;
    };
}