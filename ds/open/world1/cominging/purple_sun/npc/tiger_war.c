#include <ansi.h>
inherit  __DIR__"war_base.c";

void create()
{
	set_name("猛虎", ({ "crazy tiger", "tiger", "animal-war-object" }) );
	set("long", @LONG
一隻眼露兇光, 邪氣四溢的野獸, 身上的斑紋似乎看起來就像血一般, 令人不寒而顫。
LONG
	);
	set("title", HIY"狂"NOR); // War 的 Mob
	set("unit","隻");

	set("race", "野獸");
	set("limbs", ({ "頭部", "身體", "後腳","前腳", "尾巴" })); // 受攻部位
	set("verbs", ({ "crash","hoof", "claw" })); // 攻擊型態蹬hoof撞crash咬bite抓claw啄poke
	set("chat_chance", 10);
	set("chat_msg", ({ (: this_object(), "random_move" :), }));

	set("war_score", 1);
	set("age", 32);
	set("level", 31);
	set("str", 62);
	set("con", 61);
	set("attitude", "aggressive"); // 主動攻擊,生性好鬥的的 NPC。

	setup();
	set_living_name("animal-war-object");
	carry_object(__DIR__"obj/meat");
	carry_object(__DIR__"obj/meat");

}