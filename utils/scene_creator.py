import struct

from enum import Enum
from array import array

from random import randint

class ThingType(Enum):
    PLAYER = 0
    ENTITY = 1
    STATIC = 2
    ITEM = 3
    INTERACTABLE = 4
    PROP = 5
    TILEMAP = 6
    TILESET = 7


thing_model = {
    "x": 0,
    "y": 0,
    "assets": None,
    "thing_type": None,
    "has_physical_body": False,
    "ready": True
}


def main():
    things = []

    block = thing_model.copy()
    block["x"] = randint(-120, 120)
    block["y"] = randint(-120, 120)
    block["thing_type"] = 2
    block["assets"] = {10}
    block["has_physical_body"] = True
    things.append(block)
    
    block1 = thing_model.copy()
    block1["x"] = randint(-120, 120)
    block1["y"] = randint(-120, 120)
    block1["thing_type"] = 2
    block1["assets"] = {10}
    block1["has_physical_body"] = True
    things.append(block1)

    block2 = thing_model.copy()
    block2["x"] = randint(-120, 120)
    block2["y"] = randint(-120, 120)
    block2["thing_type"] = 2
    block2["assets"] = {10}
    block2["has_physical_body"] = False
    things.append(block2)

    player = thing_model.copy()
    player["x"] = 0
    player["y"] = 0
    player["thing_type"] = 0
    player["assets"] = {1}
    player["has_physical_body"] = True
    things.append(player)

    f = open("./build/resources/101.bdgsc", "wb")

    for thing in things:
        content = struct.pack("=?", thing["has_physical_body"])
        f.write(content)

        content = struct.pack("=?", thing["ready"])
        f.write(content)

        content = struct.pack("=f", thing["x"])
        f.write(content)
        
        content = struct.pack("=f", thing["y"])
        f.write(content)

        content = struct.pack("=I", len(thing["assets"]))
        f.write(content)
        
        content = struct.pack("=I", thing["thing_type"])
        f.write(content)

        content = struct.pack("=1I", *thing["assets"])
        f.write(content)

    f.close()


if __name__ == '__main__':
    main()
    exit(0)
