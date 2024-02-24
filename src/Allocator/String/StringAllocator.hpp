#pragma once

#include "../IAllocator.hpp"

#include <new>

#ifdef DEBUG_MEM
#include <iostream>
#endif

namespace frix {
    class StringAllocator implements IAllocator {
    public:
        StringAllocator() {
            nbFreeblocks = 0;
        }

        void* allocate(size_t size) {
            for (int i = 0; i < nbFreeblocks; ++i) {
                if ((size_t)(freeBlocks[i + 1]) - (size_t)(freeBlocks[i]) >= size) {
                    void* ptr = freeBlocks[i];
                    for (int j = i; j < nbFreeblocks - 1; ++j) {
                        freeBlocks[j] = freeBlocks[j + 1];
                    }
                    nbFreeblocks--;
                    return ptr;
                }
            }
            void* ptr = ::operator new(size);
            return ptr;
        }

        void deallocate(void* ptr) {
            debugMem();
            freeBlocks[nbFreeblocks++] = ptr;
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
