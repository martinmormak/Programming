#include <stdio.h>
#include <stdlib.h>

#include "backpack.h"
#include "command.h"
#include "container.h"
#include "game.h"
#include "item.h"
#include "parser.h"
#include "room.h"
#include "world.h"

int main()
{
    struct game* game=create_game();
    play_game(game);
    struct backpack* backpack=create_backpack(10);
    struct item* item=create_item("ITEM", "ITEM FOR TEST", 0);
    add_item_to_backpack(backpack,item);
    get_item_from_backpack(backpack, "ITEM");
    delete_item_from_backpack(backpack, item);
    destroy_backpack(backpack);
    struct command* command=create_command("COMMAND", "COMMAND FOR TEST", "(COMMAND)", 1);
    execute_command(game,command);
    destroy_game(game);
    destroy_command(command);
    struct container* container=create_container(NULL,ITEM,item);
    struct item* item2=create_item("ITEM2", "ITEM FOR TEST", 0);
    create_container(NULL,ITEM,item2);
    get_from_container_by_name(container, "ITEM");
    remove_container(container, item2);
    destroy_containers(container);
    destroy_item(item2);
    struct parser* parser=create_parser();
    parse_input(parser, "KONIEC");
    destroy_parser(parser);
    struct room* room=create_room("ROOM", "ROOM FOR TEST");
    set_exits_from_room(room, NULL, NULL, NULL, NULL);
    add_item_to_room(room,item);
    show_room(room);
    get_item_from_room(room,"ITEM");
    delete_item_from_room(room,item);
    struct container* world=create_world();
    add_room_to_world(world,room);
    get_room(world,"ROOM");
    destroy_room(room);
    destroy_world(world);
    return 0;
}