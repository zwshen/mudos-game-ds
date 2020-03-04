#include <ansi.h>
inherit NPC;
void create()
{
        set_name("幽遮蘭城城門守衛", ({ "gate guard of ugelan","guard" }) );
        set("long","身著筆挺制服，神氣的站在道路兩旁守衛著的幽遮蘭守衛，不過，
跟一旁全副武裝的索蘭尼亞禁衛軍比起來，他感覺上是展示用的...\n");
        set("level",18+random(5));
        set("age",20+random(3));

        set("combat_exp", 30000);
        set("chat_chance", 7);
        set("chat_msg", ({
  "守衛歪著頭, 上下打量了你一眼。\n",
}));
        set("chat_chance_combat", 14);
        set("chat_msg_combat", ({
  HIW"守衛大喊：DIE!!Scum!!\n"NOR,
  HIW"守衛大喊：You are not welcome in ugelan.\n"NOR
}));
        set_skill("sword", 50);
        set_skill("parry", 20);
        set_skill("unarmed", 50);
        set_skill("dodge", 55);
        setup();
        carry_object(__DIR__"wp/silverlsword")->wield();
        carry_object(__DIR__"eq/gcap")->wear();
        carry_object(__DIR__"eq/gpant")->wear();
        carry_object(__DIR__"eq/guniform")->wear();
        carry_object(__DIR__"eq/ridingboots")->wear();
        carry_object(__DIR__"eq/waist")->wear();
}


