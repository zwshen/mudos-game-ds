#include <ansi.h>
inherit F_UNIQUE;
inherit ITEM;

int hit;
int again, index;

void create()
{
  set_name(HIC"究極奧義"NOR,({"final book","book"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","上面寫了什麼，你完全看不懂∼∼∼難道要找人鑑定一番？");
    set("unit","本");
    set("value",10);
  }
  setup();
}

