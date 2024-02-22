#pragma once

#include "../IAllocator.hpp"

#include <new>

#ifdef DEBUG_MEM
#include <iostream>
#endif

// StringAllocator Definitions----------------------------------->>
#define DEFAULT_MAX_SIZE 1024
#define BLOCK_SIZE 16

// StringAllocator Class----------------------------------------->>
namespace frix {
    class StringAllocator implements IAllocator {
    public:
        StringAllocator() {
            nbFreeblocks = MAX_SIZE / BLOCK_SIZE;
            for (int i = 0; i < nbFreeblocks; ++i) {
                freeBlocks[i] = arena + i * BLOCK_SIZE;
            }
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
            throw std::bad_alloc();
        }

        void deallocate(void* ptr) {
            debugMem();
            int i;
            for (i = 0; i < nbFreeblocks; ++i) {
                if (freeBlocks[i] > ptr) {
                    break;
                }
            }
            for (int j = nbFreeblocks; j > i; --j) {
                freeBlocks[j] = freeBlocks[j - 1];
            }
            freeBlocks[i] = ptr;
            nbFreeblocks++;
        }

    private:
        void debugMem() {
#ifdef DEBUG_MEM
            std::cout << ".................................................................................\n";
            for (int idx = 0; idx < MAX_SIZE; idx += BLOCK_SIZE)
            {
                std::cout << "[idx memAddr]: " << &arena[idx] << " [value]: ";
                // Imprimir el valor en cada posición de memoria
                for (int j = 0; j < BLOCK_SIZE; ++j)
                {
                    std::cout << static_cast<int>(arena[idx + j]) << " ";
                }
                std::cout << std::endl;
            }
            std::cout << ".................................................................................\n";
#endif
        }

        enum { MAX_SIZE = DEFAULT_MAX_SIZE };
        char arena[MAX_SIZE];
        void* freeBlocks[MAX_SIZE / BLOCK_SIZE];
        int nbFreeblocks;
    };
}
