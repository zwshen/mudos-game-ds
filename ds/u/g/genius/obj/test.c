#include <ansi.h>
inherit ITEM;

void create()
{
       set_name(HIW"變態丹藥"NOR,({"pill"}) );
        set("long","LONG");
        set_weight(80);
        if( clonep() )
                set_default_object(__FILE__);
        else {  set("unit", "個");
                set("value",50000); }
setup();
}

void init()
{
     add_action("do_eat","eat");
}

int do_eat(string arg)
{
       object me = this_player();
       object ob = this_object();

       if( !this_object() ) return 0;        
       if( !this_object()->id(arg) ) return 0;
       me->set("env/msg_mout",CYN"\n$N念著古老的咒文，突然在$N的面前出現了一道暗影門，$N走了進去，消失的無影無蹤。\n"NOR);
       me->set("env/msg_min",BLU"\n一陣神秘的咒語從耳邊傳出，突然一陣灰影飄過，身邊似乎多了一個人。\n"NOR);
       me->set("env/msg_clone",HIY"$N"HIY"微笑地念著："HIG"「疾疾∼$n"HIG"現身∼」"HIY"，你的面前赫然出現了一個$n。\n"NOR);
       me->set("env/msg_dest",HIY"$N"HIY"大叫："HIR"「去去∼$n"HIR"走∼」"HIY"，你面前的$n"HIY"忽然消失在空氣中。\n"NOR);
       write(".....&^#@(&)*#@$@#&.....\n"NOR);
       destruct(ob);
       return 1;
}

