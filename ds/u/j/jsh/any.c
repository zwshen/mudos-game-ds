#include <ansi.h>
 
inherit ITEM;
 
void create()
 
{
 
        seteuid(getuid());
        set_name(HIG"修改器"NOR,({"anything item","item"}));
        set("long","彩色修改器\n");
        set("unit","個");
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
this_player()->set("guild_rank",HIC"參透"HIY"天宇日里"HIC"萬機"NOR);
this_player()->set("name",HIW"悠閒過日子"NOR);

 return 1;

}

