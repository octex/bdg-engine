#ifndef BDG_LUA
#define BDG_LUA

/*
    Utils to read and use Lua structures with sol.hpp
*/

#include <string>
#include "things.h"
#include "sol/sol.hpp"

sol::state ReadLuaFile(std::string filename);

#endif