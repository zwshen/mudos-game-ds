#include <armor.h>
inherit PANTS;

void create()
{
        set_name("丁字褲",({ "japen jeans","jeans" }) );
        set("long",@LONG
這是日本壯丁勞動時為了方便所穿的內褲，十分火辣。
LONG
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("material", "cloth");
                set("unit", "件");
        set("value",200);
        set("volume", 1);
        set("max_lv",50);
        set("limit_lv",1);
   set("armor_prop/armor",2);
  }
      setup();
}
