#include <weapon.h>
#include <ansi.h>
inherit NEEDLE;

void create()
{
        set_name( "月針" ,({"moon needle","needle"}) );
        set("long","一把水藍色的銀針，非常的尖銳。\n");
          set_weight(1200);
          if (clonep() )
          set_default_object(__FILE__);
          else {
                set("unit","根");
                set("value",1000);
                set("material", "silver");
               }
          init_needle(14);
          setup();        
}

