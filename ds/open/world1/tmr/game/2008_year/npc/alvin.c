#include <ansi.h>
inherit NPC;
inherit LOTTERYMAN;
void create()
{
        set_name( "︺ゅ", ({ "alvin mouse", "alvin", "mouse"}));
        set("long", @LONG
︺ゅ琌公ㄓ腳いρ琌稲公
ぃ度穦弧杠临穦佰簈
LONG
        );
        set("level", 1);
        set("title", HIG"公ㄓ腳"NOR);
        set("gender", "╧┦");
        set("race", "摸");
        set("age", 15);
        set("exp",1000);
	set("attitude", "peaceful");   //放㎝ NPC
	set("no_kill",1);
	set("no_fight",1);

    setup();
}
