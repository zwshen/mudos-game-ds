#include <ansi.h>
#include <weapon.h>
inherit FORK;
void create()
{
        set_name("黑鐵槍" , ({ "black iron lance","lance" }) );
        set_weight(8000);
        if( clonep() )
                set_default_object(__FILE__);
        else {
               set("limit_str",10);
               set("unit", "把");
		set("volume",5);
               set("long", "這是一把由黑鐵所冶鍊而成的長槍，相當沉重。\n");
           set("value",2000);
            set("material","iron");
        }
    init_fork(30);
   setup();
}
