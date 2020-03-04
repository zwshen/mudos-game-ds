#include <ansi.h>
inherit NPC;
void create()
{
        set_name("代刚脋",({"test monster", "test","monster" }) );
        set("long",@LONG
      TEST ノ┣脋......伐瑻ゴ
LONG
);
        set("title","绊┏");
        set("limbs", ({
                "繷场", "繴场", "", "み", "竬丁", "浮场", "糒","Юぺ",
        }) );
        set("age",500+random(99));
        set("level",70);
        set("hp",999999);
        set("max_hp",999999);
        set("mp",999999);
        set("max_mp",999999);
        set("ap",999999);
        set("max_ap",999999);        set("dex",100);
        set("str",100);
        set("con",100);
        set("int",100);
        set("gender","动┦");
        set("race","monster");
        setup();
}
 

