inherit ITEM;
#include <ansi2.h>
void create()
{ set_name(HIM"晴晴"HIB"藥藥"NOR, ({"ch_Pill","pill"}) );
  set_weight(1);
  set("unit", "顆");
  setup(); }
void init()
{ add_action("do_eat", "eat"); }
int do_eat(string str)
{ object me = this_player();
  string guild_rank;
  guild_rank =HBCYN""HIW"每天無所事事巫師"NOR;
  if("str == pill") {
  message_vision(HIB"我愛晴晴吃下藥丸\n"NOR, me);
  me->set("guild_rank",guild_rank);
  destruct(this_object());
  return 1; }}
