#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "獨眼獸" , ({"single-eye monster","monster"}) );
  set("long",@LONG
一隻只有一隻眼睛的奇異怪物。另一隻眼睛似乎是被挖掉的。表情十
分猙獰，身上不斷散發出邪惡之氣。
LONG);
  set("race", "beast");
  set("unit","隻");
  set("age",70);
  set("attitude", "aggressive");
  set("gender", "雄性" );
  set("level", 30+random(5));
  set("title", "魂獸" );
  set("limbs", ({ "頭部", "身體","尾巴","腹部","背部" }) );
  set("verbs", ({"bite","claw"}) );
        set("chat_chance",10);
        set("chat_msg",({
        (: random_move() :),
        }) );
  setup();
}