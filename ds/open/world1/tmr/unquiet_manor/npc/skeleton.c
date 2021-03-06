#include <ansi.h>
#include <skill.h>

inherit NPC;
inherit __DIR__"inherit/do_fight_ai.c";

void create()
{
    set_name("腐爛的骸骨", ({ "unquiet skeleton", "skeleton", "_UNQUIET_MANOR_NPC_" }) );
    set("long", @LONG
這是一具腐爛的骸骨，不知為何竟然還能走動。它的空洞眼眶
似乎正望著你，一副要殺掉你的樣子。		
LONG);

	set("title",HIG"無寧莊園"NOR);
    set("age", 23);
	set("level", 35);
    set("race","celestial");
    /* 人物動作 */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_issue :),        
    }) );
    set("attitude", "aggressive");
    setup();
    set_living_name("_UNQUIET_MANOR_NPC_");
    if( random(100) < 10 ) carry_object(__DIR__"obj/q_plate");
    if( random(100) < 10 )	carry_object(__DIR__"obj/blood_meat");
}
