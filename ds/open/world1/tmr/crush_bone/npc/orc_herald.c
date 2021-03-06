#include <ansi.h>
#include <skill.h>


inherit __DIR__"inherit/do_fight_ai.c";
inherit NPC;

void create()
{
    set_name("半獸人使者", ({ "orc herald", "orc", "herald", "_CRUSH_BONE_ORC_" }) );

    set("long", @LONG
半獸人，身體呈暗綠色，有著一張猙獰的臉，他是屬於碎骨寨的使者。
LONG);

    set("title", HIW"碎骨寨"NOR);
    set("gender", "male");
    set("age", 23);
        set("attack_merits", "bar");
        set("level",40);

    /* 技能設定 */
    set_skill("dodge", 100);
    set_skill("axe", 100);
    set_skill("parry", 100);
    set_skill("unarmed", 100);


    /* 人物動作 */
    set("chat_chance", 10);
    set("chat_msg", ({
        (: random_move :),
    }) );

    /* 戰鬥動作 */
    set("chat_chance_combat", 50);
    set("chat_msg_combat", ({
      (: do_fight_heal :),
    }) );

    set("vendetta_mark", "_CRUSH_BONE_ORC_");
    set("attitude", "aggressive");

    setup();
	set_temp("apply/armor",100);
	set_temp("apply/damage",100);
	set_temp("apply/shield",200);

    set_living_name("_CRUSH_BONE_ORC_");
        carry_object(__DIR__"obj/orc_belt")->wear();
        carry_object(__DIR__"obj/cb_boots")->wear();
        carry_object(__DIR__"obj/wristlet")->wear();
        carry_object(__DIR__"obj/cb_necklace")->wear();
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_skull");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_rib");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_foot");
    if( random(100) < 33 ) carry_object(__DIR__"obj/orc_shin_bone");
    if( random(100) < 70 ) carry_object(__DIR__"obj/orc_blood");
}

