#include <ansi.h>
#include <weapon.h>

inherit FIST;

void create()
{
        set_name(HIM"晴晴"HIB"爪爪"NOR,({"ching ching fist","fist"}) );
        set("long",
"以我最愛的人名字做的爪。\n"
);
        set_weight(2000);
        if (clonep() )
                     set_default_object(__FILE__);
        else {
        set("unit","個");
          set("value",3000);
        set("material","gold");
                set("volume",2);
        set("limit_str",1);
          set("limit_level",14);
        }
        init_fist(100);
setup();
}
int query_autoload() { return 1; }
