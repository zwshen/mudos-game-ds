// Npc: /u/l/luky/npc/1.c

inherit NPC;

void create()
{
set_name("小蟲", ({ "little bug","bug" }) );
set("age", 1);
set("level",1);
set("long", @LONG
一隻小蟲子, 因為發現你在看牠而正在裝死。
LONG
);
set("con",1);
set("str",1);
set("dex",1);
set("int",1);
set("race","beast");
set_temp("apply/hit",-20);	//弱化命中率
set_temp("apply/dodge",-20);	//弱化閃躲率
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
setup();
}
