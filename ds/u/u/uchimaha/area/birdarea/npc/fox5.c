#include <ansi.h>
inherit NPC;
void create()
{
        set_name("瘋狐狸",({"crazy fox", "fox"}));
        set("level",24);
        set("race", "野獸");
        set("age", 16);
        set("long", "這是一隻眼睛充滿殺氣的瘋狐狸。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳", "尾巴" }) );
        set("verbs", ({ "bite", "claw" }) );
        set("attitude", "aggressive");
        setup();
}
