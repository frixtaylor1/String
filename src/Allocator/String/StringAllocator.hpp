#pragma once

#include "../IAllocator.hpp"

#include <new>
#include <iostream>

#ifdef EMBEDDED_SYSTEM
    #define EMBEDDED_SYSTEM_ENABLED 1
#else
    #define EMBEDDED_SYSTEM_ENABLED 0
#endif

namespace frix {
    class StringAllocator implements IAllocator {
    public:
        StringAllocator() {
            nbFreeblocks = 0;
        }

        void* allocate(size_t size) {
            if (EMBEDDED_SYSTEM_ENABLED) {
                if (nbFreeblocks < DEFAULT_MAX_SIZE) {
                    void* ptr = &freeBlocks[nbFreeblocks++];
                    return ptr;
                } else {
                    return nullptr;
                }
            } else {
                void* ptr = ::operator new(size);
                return ptr;
            }
        }

        void deallocate(void* ptr) {
            debugMem();
            if (nbFreeblocks < DEFAULT_MAX_SIZE) {
                freeBlocks[nbFreeblocks++] = ptr;
            }
        }

    private:
        void debugMem() {
#ifdef DEBUG_MEM
            std::cout << "-------------------------------------------------------------\n";
            std::cout << "Memory Allocation Debug Information:\n";
            std::cout << "-------------------------------------------------------------\n";

            std::cout << "Free Memory Blocks:\n";
            for (int i = 0; i < nbFreeblocks; ++i) {
                std::cout << "[" << i << "] " << freeBlocks[i] << std::endl;
            }
 
            std::cout << "-------------------------------------------------------------\n";
#endif
        }

        enum { DEFAULT_MAX_SIZE = 1024 };
        void* freeBlocks[DEFAULT_MAX_SIZE];
        int nbFreeblocks;
    };
}
