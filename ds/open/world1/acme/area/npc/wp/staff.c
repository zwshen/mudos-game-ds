#include <ansi.h>
#include <weapon.h>
inherit STAFF;
void create()
{
  set_name("禪杖",({"monk's staff","staff"}));
  set("long","這把禪杖是得道高僧所使用的法器。\n");
  set_weight(9000);
  if( clonep() )
      set_default_object(__FILE__);
  else {
      set("unit", "把");
     set("value",2500);
set("volume",4);
      set("limit_str",10);
  }
  init_staff(40);
  setup();
} 
