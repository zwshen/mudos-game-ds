inherit NPC;
void create()
{
        set_name("小白蟻", ({ "baby ant","baby","ant" }) );
        set("race", "beast");
        set("age", 1);
        set("level",5);
        set("long", @LONG
一隻剛出生的白蟻。
LONG);
        set("max_hp",50);
        set("unit","隻");
        set("limbs", ({ "頭部", "身體" }) );
        set("verbs", ({ "crash" }) );
        setup();
}
