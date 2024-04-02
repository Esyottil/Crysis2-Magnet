#include <Windows.h>
#include <iostream>
#include "Minhook/MinHook.h"
#include "xorstr.h"
#include "cSDK.h"

#pragma endregion

static struct _Keys
{
    bool bPressed;
    DWORD dwStartTime;
}

kPressingKey[256];

BOOL KeyState(int Key, DWORD dwTimeOut)
{
    if (HIWORD(GetKeyState(Key)))
    {
        if (!kPressingKey[Key].bPressed || (kPressingKey[Key].dwStartTime && (kPressingKey[Key].dwStartTime + dwTimeOut) <= GetTickCount()))
        {
            kPressingKey[Key].bPressed = TRUE;

            if (dwTimeOut > NULL)
                kPressingKey[Key].dwStartTime = GetTickCount();

            return TRUE;
        }
    }
    else
        kPressingKey[Key].bPressed = FALSE;

    return FALSE;
}

template< typename cData >
cData vFun_Call(PVOID BaseClass, DWORD vOFFSET)
{
    PDWORD* vPointer = (PDWORD*)BaseClass;
    PDWORD vFunction = *vPointer;
    DWORD dwAddress = vFunction[vOFFSET];
    return (cData)(dwAddress);
}

class SSystemGlobalEnvironment;
class IConsole;
class ISystem;
class IGame;
class IGameFramework;
class IEntitySystem;
class IEntity;
class IEntityIt;
class IActor;
class IActorSystem;
class IEntityProxy;

class SSystemGlobalEnvironment
{
public:
    char pad_0x0000[0x44]; //0x0000
    IGame* pGame; //0x0044 
    char pad_0x0048[0x4]; //0x0048
    IEntitySystem* pEntitySystem; //0x004C 
    IConsole* pConsole; //0x0050 
    char pad_0x0054[0x4]; //0x0054
    ISystem* pSystem; //0x0058 
    char pad_0x005C[0x24]; //0x005C

    static SSystemGlobalEnvironment* Singleton()
    {
        return *(SSystemGlobalEnvironment**)0x1916CC0;
    }
};

class IEntitySystem
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //GetEntity
    virtual void Function11(); //FindEntityByName
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual IEntityIt* GetEntityIterator(); //

}; //Size=0x0004

class IGame
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual IGameFramework* GetIGameFramework(); //
};

class IEntityIt
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual IEntity* Next(); //
};

class IEntity
{
public:
    virtual void Function0(); //
    virtual EntityId GetId(); //EntityId GetId() || 1 vfunc
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual const char* GetName();//12
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void SetWorldTM(const Matrix34& tm, int nWhyFlags = 0); // 21
    virtual void Function22(); //
    virtual Matrix34& GetWorldTM(); //23
    virtual void Function24(); //
    virtual void Function25(); //
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual void Function32(); //
    virtual void Function33(); //
    virtual void Function34(); //
    virtual void Function35(); //
    virtual void Function36(); //
    virtual void Function37(); //
    virtual void Function38(); //
    virtual void Function39(); //
    virtual void Function40(); //
    virtual void Function41(); //
    virtual void Function42(); //
    virtual void Function43(); //
    virtual void Function44(); //
    virtual void Function45(); //
    virtual void Function46(); //
    virtual void Function47(); //
    virtual void Function48(); //
    virtual void Function49(); //
    virtual void Function50(); //
    virtual void Function51(); //
    virtual void Function52(); //
    virtual void Function53(); //
    virtual void Function54(); //
    virtual void Function55(); //
    virtual void Function56(); //
    virtual void Function57(); //
    virtual IEntityProxy* GetProxy(EEntityProxy proxy);
    //GetProxy
};

class IEntityProxy
{
public:
    void SetHUDSilhouettesParams(float a, float r, float g, float b)
    {
        vFun_Call<void(__thiscall*)(PVOID, float, float, float, float)>(this, 44)(this, a, r, g, b);
        *(int*)((DWORD)this + 0x8) = 0;
    }

    //232 Возможно Флаг
};

class IGameFramework
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void Function21(); //
    virtual void Function22(); //
    virtual void Function23(); //
    virtual void Function24(); //
    virtual IActorSystem* GetIActorSystem();//Возможно IActorSystem || 12 / 4 = GetActor || 25 vfunc
    virtual void Function26(); //
    virtual void Function27(); //
    virtual void Function28(); //
    virtual void Function29(); //
    virtual void Function30(); //
    virtual void Function31(); //
    virtual void Function32(); //
    virtual void Function33(); //
    virtual void Function34(); //
    virtual void Function35(); //
    virtual void Function36(); //
    virtual void Function37(); //
    virtual void Function38(); //
    virtual void Function39(); //
    virtual void Function40(); //
    virtual void Function41(); //
    virtual void Function42(); //
    virtual void Function43(); //
    virtual void Function44(); //
    virtual void Function45(); //
    virtual void Function46(); //
    virtual void Function47(); //
    virtual void Function48(); //
    virtual void Function49(); //
    virtual void Function50(); //
    virtual void Function51(); //
    virtual void Function52(); //
    virtual void Function53(); //
    virtual void Function54(); //
    virtual void Function55(); //
    virtual void Function56(); //
    virtual void Function57(); //
    virtual void Function58(); //
    virtual void Function59(); //
    virtual void Function60(); //
    virtual void Function61(); //
    virtual void Function62(); //
    virtual void Function63(); //
    virtual void Function64(); //
    virtual void Function65(); //
    virtual void Function66(); //
    virtual void Function67(); //
    virtual void Function68(); //
    virtual void Function69(); //
    virtual void Function70(); //
    virtual IActor* GetClientActor();
};

class IActorSystem
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual IActor* GetActor(EntityId entityId);
};

class IActor
{
public:
    virtual void Function0(); //
    virtual void Function1(); //
    virtual void Function2(); //
    virtual void Function3(); //
    virtual void Function4(); //
    virtual void Function5(); //
    virtual void Function6(); //
    virtual void Function7(); //
    virtual void Function8(); //
    virtual void Function9(); //
    virtual void Function10(); //
    virtual void Function11(); //
    virtual void Function12(); //
    virtual void Function13(); //
    virtual void Function14(); //
    virtual void Function15(); //
    virtual void Function16(); //
    virtual void Function17(); //
    virtual void Function18(); //
    virtual void Function19(); //
    virtual void Function20(); //
    virtual void Function21(); //
    virtual void Function22(); //
    virtual void SetHealth(float health); //
    virtual virtual float GetHealth();

    IEntity* GetEntity()
    {
        return *(IEntity**)((uintptr_t)this + 0x000C);
    }

    bool IsDead() {
        return this->GetHealth() <= 0;
    }
};

Vec3 GetEntityPos(IEntity* pEntit)
{
    Vec3 vOffset = Vec3();
    Matrix34 pWorld = pEntit->GetWorldTM();
    vOffset = pWorld.GetTranslation();
    return vOffset;
}

bool GetDeadPlayer(IActor* Player)
{
    if (Player->IsDead()) return true;
    else return false;
}

void Console()
{
    AllocConsole();
    freopen_s(reinterpret_cast<FILE**>(stdout), "CONOUT$", "w", stdout);
}

bool Magnit = false;

void Func()
{
    SSystemGlobalEnvironment* gEnv = SSystemGlobalEnvironment::Singleton();
    if (gEnv)
    {
        IEntitySystem* pEntitySystem = gEnv->pEntitySystem;
        if (pEntitySystem)
        {
            IGame* pGame = gEnv->pGame;
            if (pGame)
            {
                IGameFramework* pGameFramework = pGame->GetIGameFramework();
                if (pGameFramework)
                {
                    IActor* m_pActor = pGameFramework->GetClientActor();
                    if (m_pActor)
                    {
                        if (KeyState(0x58, 1000)) //x
                        {
                            printf("[Actor] Name: [%s] Health: [%.1f]\n", m_pActor->GetEntity()->GetName(), m_pActor->GetHealth());
                            m_pActor->SetHealth(m_pActor->GetHealth() + 11000.f);
                        }
                        if (KeyState(0x5A, 1000)) // z
                        {
                            Magnit = !Magnit;
                        }
                        IEntityIt* pEntityIt = pEntitySystem->GetEntityIterator();
                        if (pEntityIt)
                        {
                            while (IEntity* pEntity = pEntityIt->Next())
                            {
                                IActor* pActor = pGameFramework->GetIActorSystem()->GetActor(pEntity->GetId());
                                if (pActor)
                                {
                                    if (!GetDeadPlayer(pActor))
                                    {
                                        Vec3 MyPos = GetEntityPos(m_pActor->GetEntity());
                                        Vec3 Rotation = { 0,0,0 };
                                        if (pEntity == m_pActor->GetEntity())
                                        {
                                            continue;
                                        }
                                        Vec3 Huipos = { MyPos.x + 1,MyPos.y + 1,MyPos.z + 1 };
                                        Matrix34 EntPos = m_pActor->GetEntity()->GetWorldTM();
                                        EntPos.SetTranslationAndRotation(Huipos, Rotation);
                                        if (Magnit)
                                        {
                                            pEntity->SetWorldTM(EntPos);
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}


typedef bool(__thiscall* nSystemUpdateHook)(ISystem*, int, int);
nSystemUpdateHook mSystemUpdateHook;

bool __fastcall SystemUpdateHook(ISystem* mSystem, void* unk, int updateFlags, int nPauseMode)
{
    __asm pushad;
    Func();
    __asm popad;

    return mSystemUpdateHook(mSystem, updateFlags, nPauseMode);
}

bool IsCMASet = false;
typedef HANDLE(__stdcall* nCreateMutexA)(LPSECURITY_ATTRIBUTES, BOOL, LPCSTR);
nCreateMutexA mCreateMutexA;
HANDLE __stdcall CreateMutexAHook(LPSECURITY_ATTRIBUTES lpMutexAttributes, BOOL bInitialOwner, LPCSTR lpName)
{
    __asm pushad;
    if(lpName != NULL)
    {
        if (strstr(lpName, xorstr("GameSpyApplication")))
        {
            MH_DisableHook((void*)GetProcAddress(GetModuleHandle(xorstr("KERNEL32")), xorstr("CreateMutexA")));
        }
    }
    __asm popad;

    return mCreateMutexA(lpMutexAttributes, bInitialOwner, lpName);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        Console();
        if (MH_CreateHook((void*)0x468170, SystemUpdateHook, (LPVOID*)&mSystemUpdateHook) != MH_OK) { return 1; }
        if (MH_EnableHook((void*)0x468170) != MH_OK) { return 1; }
        //while (!IsCMASet)
        //{
        //   if (DWORD NCreateMutexAAdr = (DWORD)GetProcAddress(GetModuleHandle(xorstr("KERNEL32")), xorstr("CreateMutexA")))
        //    {
        //        if (MH_CreateHook((void*)NCreateMutexAAdr, CreateMutexAHook, (LPVOID*)&mCreateMutexA) == MH_OK)
        //        {
        //            MH_EnableHook((void*)NCreateMutexAAdr);
        //            IsCMASet = true;
        //        }
        //    }
        //    Sleep(200);
        //}
    }
    return TRUE;
}
// BreakListenerThread