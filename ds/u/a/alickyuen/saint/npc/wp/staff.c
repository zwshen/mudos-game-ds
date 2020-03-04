#include <weapon.h>
#include <ansi.h>
inherit STAFF;
void create()
{
        set_name(HIY "筿阑次" NOR,({"electric staff","staff"}) );
        set("long",
        "硂琌р猜╁次\n"
        "硂р次程疭ぇ矪碞琌穦筿璝さウ筿碞衡ぃ端\n"
);
        set_weight(20000);
        if (clonep() )
                set_default_object(__FILE__);
        else {
                set("unit","р");
          set("value",500);
set("weapon_prop/hit", -2);
        }
 set("material","silver");
   set("weapon_prop/dodge",-2);
        init_staff(20);
        setup();
}
