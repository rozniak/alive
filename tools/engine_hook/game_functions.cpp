#include "game_functions.hpp"

std::map<DWORD, BaseFunction*>& BaseFunction::FunctionTable()
{
    return mFunctionTable;
}

void BaseFunction::HookAll()
{
    LONG err = DetourTransactionBegin();

    if (err != NO_ERROR)
    {
        ALIVE_HOOK_FATAL("DetourTransactionBegin failed");
    }

    err = DetourUpdateThread(GetCurrentThread());

    if (err != NO_ERROR)
    {
        ALIVE_HOOK_FATAL("DetourUpdateThread failed");
    }

    for (auto& fn : mFunctionTable)
    {
        fn.second->Apply();
    }

    err = DetourTransactionCommit();
    if (err != NO_ERROR)
    {
        ALIVE_HOOK_FATAL("DetourTransactionCommit failed");
    }
}

std::map<DWORD, BaseFunction*> BaseFunction::mFunctionTable;

// Called by SND_PlayEx - appears to not exist in AO
ALIVE_FUNC_NOT_IMPL(0x0, 0x004EF970, IDirectSoundBuffer*__cdecl(int soundIndex, int a2), sub_4EF970);

GameFunctions& Funcs()
{
    static GameFunctions f;
    return f;
}

GameVars& Vars()
{
    static GameVars v;
    return v;
}
