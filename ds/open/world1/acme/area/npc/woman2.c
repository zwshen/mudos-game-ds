#include <ansi.h>
inherit NPC;
void create()
{
        set_name("婦人" , ({ "woman" }) );
        set("level",5);
        set("race","人類");
        set("gender","女性");
        set("age",35);
        set("long","她是一位正在溪邊洗著衣服的婦人。\n");
        setup();
}

