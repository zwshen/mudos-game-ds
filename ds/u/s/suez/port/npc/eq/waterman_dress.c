#include <armor.h>
#include <ansi.h>
inherit CLOTH;

void create()
{
        set_name(HIC"水手服"NOR,({"waterman dress","dress"}) );

        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else {
         set("long","水軍領加上迷你裙...這...這難道是傳說中的水手服！！\n"
                 HIW"真想穿上大喊:「我要代替月亮來懲罰你！喔呵呵∼∼」\n"NOR
          );
         set("material", "cloth");
         set("unit", "件");
         set("value",500);

         set("armor_prop/armor", 1);

        }
        setup();
	set("wear_msg",HIY"$N"HIY"穿起一件$n"HIY"，擺\了個POSE大喊﹕「我要代替月亮來懲罰你！喔呵呵∼∼」\n"NOR);
}


