// This is a npc made by npcmaker.

inherit NPC;

void create()
{
        set_name( "守城護衛", ({ "guard" }));
        set("long", "他看起來十分勇猛, 全身筋骨爆出, 看起來相當不好應付的樣子。\n");
        set("age", 30);
        set("level",15);
	set("race", "人類");
	setup();
carry_object(__DIR__"wq/guardsword")->wield();}
