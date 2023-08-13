#include <lua.h>
#include <lauxlib.h>

// Because This is Lua I do not think you need a DLLMain function
// https://learn.microsoft.com/en-us/cpp/build/reference/md-mt-ld-use-run-time-library?view=msvc-170&source=recommendations
__declspec(dllexport) int hello(lua_State *L)
{
    printf("hello!\n");
    return 0;
}

__declspec(dllexport) int goodbye(lua_State *L)
{
    printf("goodbye!\n");
    return 0;
}

__declspec(dllexport) luaL_Reg test[] = {
    {"goodbye", goodbye},
    {"hello", hello},
    {NULL, NULL}
};

__declspec(dllexport) int luaopen_test_lib(lua_State *L)
{
    luaL_newlib(L, test);
    return 1;
}
