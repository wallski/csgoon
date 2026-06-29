#pragma once
#include <cstdint>
#include <Windows.h>

namespace Memory
{
    uintptr_t GetModuleBase(const char* module);
    uintptr_t PatternScan(const char* module, const char* signature);

    // ── Address sanity check ─────────────────────────────────────────────────
    // Rejects null, kernel-space, and obviously-bad user-space addresses.
    // Not a guarantee the page is committed, but catches 99% of stale pointers.
    inline bool IsValidPtr(uintptr_t addr)
    {
        return addr > 0x10000ULL && addr < 0x7FFFFFFEFFFFULL;
    }

    inline bool IsValidPtr(const void* ptr)
    {
        return IsValidPtr(reinterpret_cast<uintptr_t>(ptr));
    }

    // ── SEH-wrapped read ─────────────────────────────────────────────────────
    // Tries to read sizeof(T) bytes from addr into out.
    // Returns false (and leaves out unchanged) if the address is bad or
    // the read causes an access violation — no crash, just a safe skip.
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


    // ── SEH-wrapped write ────────────────────────────────────────────────────
    // Returns false if the address is bad or the write faults.
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
