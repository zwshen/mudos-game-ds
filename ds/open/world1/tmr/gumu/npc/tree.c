// Room: /d/gumu/npc/dumang.c
// Last Modifyed by Winder on Jan. 14 2002

inherit NPC;

void create()
{
        set_name("毒蟒", ({ "du mang", "mang" }));
        set("race", "野獸");
        set("age", 50);
         set("level", 8 );
        set("long", "一條龐大無比, 色彩斑斕的巨蟒。 渾身發出陣陣強烈的腥臭味。\n");
        set("attitude", "aggressive");
        setup();
}

