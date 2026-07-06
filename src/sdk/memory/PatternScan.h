#pragma once
#include <cstdint>
#include <Windows.h>

namespace Memory
{
    uintptr_t GetModuleBase(const char* module);
    uintptr_t PatternScan(const char* module, const char* signature);


    inline bool IsValidPtr(uintptr_t addr)
    {
        return addr > 0x10000ULL && addr < 0x7FFFFFFEFFFFULL;
    }

    inline bool IsValidPtr(const void* ptr)
    {
        return IsValidPtr(reinterpret_cast<uintptr_t>(ptr));
    }


    template<typename T>
    inline bool SafeRead(uintptr_t addr, T& out)
    {
        if (!IsValidPtr(addr))
            return false;
        __try
        {
            out = *reinterpret_cast<const T*>(addr);
            return true;
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            return false;
        }
    }



    template<typename T>
    inline bool SafeWrite(uintptr_t addr, const T& val)
    {
        if (!IsValidPtr(addr))
            return false;
        __try
        {
            *reinterpret_cast<T*>(addr) = val;
            return true;
        }
        __except (EXCEPTION_EXECUTE_HANDLER)
        {
            return false;
        }
    }
}
