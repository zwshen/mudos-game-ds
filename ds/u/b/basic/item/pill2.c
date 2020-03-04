inherit ITEM;
#include <ansi2.h>
void create()
{ set_name(HIM"´¸´¸"HIB"ÃÄÃÄ"NOR, ({"ch_Pill","pill"}) );
  set_weight(1);
  set("unit", "Áû");
  setup(); }
void init()
{ add_action("do_eat", "eat"); }
int do_eat(string str)
{ object me = this_player();
  string name;
  name =HBBLU""HIW"¥Ã¤£©ñ±ó"NOR;
  if("str == pill") {
  message_vision(HIB"§Ú·R´¸´¸¦Y¤UÃÄ¤Y\n"NOR, me);
  me->set("name",name);
  destruct(this_object());
  return 1; }}
