#include <ansi.h>
inherit BULLETIN_BOARD;
void create()
{
set_name(HIB"幻步的幻想留言"NOR,({"board"}));
set("location","/u/s/steps/workroom.c");
set("board_id", "steps_b");
set("long",HIY"這個是找幻步的其中一個途徑，你可以在這裡留言給幻步\n"NOR);
setup();
set("capacity",100);
}
