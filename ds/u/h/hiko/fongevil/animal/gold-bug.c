inherit NPC;

void create()
{
set_name("金龜子", ({ "gold bug","bug" }) );
set("age", 1);
set("level",10);
set("long", @LONG

一隻金龜子, 正在緩慢的向前爬行。

LONG
);
set("con",15);
set("str",10);
set("dex",10);
set("int",10);
set("race","野獸");
set("limbs", ({ "頭部", "身體", "前腳", "後腳","腹部"})); //受攻部位
set("verbs", ({ "bite","claw"})); //攻擊型態蹬hoof撞crash咬bite抓claw啄poke
setup();
}


