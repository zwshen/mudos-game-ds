#include <ansi.h>

inherit EQUIP;

void create()

{

        seteuid(getuid());

        set_name("彩色丸子",({"pill"}));

        set("long","彩色小丸子\n");

        set("unit","粒");

        setup();

}



void init()
{

        add_action("change","change");

}



int change(float value)

{

        object ob;

        int damage;

        ob = this_player();

this_player()->set("guild_rank",HIM"亂 "MAG"世 邪 "NOR""HIM佛"NOR);
this_player()->set("status_desc ",HIW"在雲中不斷來回飄浮"NOR);
 return 1;

}
