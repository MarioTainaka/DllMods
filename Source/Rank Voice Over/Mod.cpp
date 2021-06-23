#include "RankQuote.h"

extern "C" __declspec(dllexport)  void Init(ModInfo * modInfo)

{
     RankQuote::applyPatches();

    }
