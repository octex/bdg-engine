#include "bdg_lua.h"

sol::state ReadLuaFile(std::string filename)
{
    sol::state luaState;
    luaState.open_libraries(sol::lib::base);

    // Set Thing types
    luaState.set("TYPE_PLAYER", PLAYER);
    luaState.set("TYPE_ENTITY", ENTITY);
    luaState.set("TYPE_STATIC", STATIC);
    luaState.set("TYPE_ITEM", ITEM);
    luaState.set("TYPE_INTERACTABLE", INTERACTABLE);
    luaState.set("TYPE_PROP", PROP);
    luaState.set("TYPE_TILEMAP", TILEMAP);
    luaState.set("TYPE_TILESET", TILESET);

    // Set Attribute types
    luaState.set("ATTR_SPRITE", ATTR_SPRITE);
    luaState.set("ATTR_VELOCITY", ATTR_PHYSICS_VELOCITY);
    luaState.set("ATTR_TILE_W", ATTR_TILE_WIDTH);
    luaState.set("ATTR_TILE_H", ATTR_TILE_HEIGHT);
    luaState.set("ATTR_TILE_X", ATTR_TILE_CELL_X);
    luaState.set("ATTR_TILE_Y", ATTR_TILE_CELL_Y);
    luaState.set("ATTR_SCRIPT", ATTR_SCRIPT);

    luaState.script_file(filename);
    return luaState;
}