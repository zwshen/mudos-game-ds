#include <ansi.h>
inherit NPC;

void create()
{
  set_name( "叢林巨魔", ({"jungle troll", "troll"}) );
  set("long",@LONG
巨魔（Troll）起源於北歐神話，是一種穴居性，相貌醜惡的吃人怪物，
身高可達九呎，體重五百磅。巨魔更是什麼肉都吃的恐怖食肉者，通常長的
非常孔武有力，橡膠似的皮膚覆蓋著漲股股的肌肉，好像稍微用點力，就能
把你給撕開了。
LONG
);
  set("age", 200);
  set("gender", "雄性" );
  set("level", 30);
        set("attack_merits","bar");

  setup();
	carry_object(__DIR__"obj/thorn-stick")->wield();
	if(random(10)==0)
		carry_object(__DIR__"obj/troll_blood");

}


