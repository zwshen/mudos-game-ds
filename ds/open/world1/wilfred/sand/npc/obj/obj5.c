#include <ansi.h>
#include <login.h>
inherit ITEM;

string *club_area = ({ 
	"/open/world1/cominging/area/dragon/",
	"/open/world1/god_club/",
	"/open/world1/baal/ming_club/",
	"/open/world1/acme/area/sky/",
	"/open/world1/acme/area/moon/",
	});

void create()
{
  set_name(WHT"神行符"NOR,({"walk tally","tally"}));
  set_weight(100);
  if( clonep() )
    set_default_object(__FILE__);
  else
  {
    set("long","這是一道謎般的符紙，符紙上寫了一堆奇怪文字，詭譎無比。\n使用方法: send <某玩家的英文名>");
    set("value",2000);
    set("unit","張");
  }
  setup();
}
void init()
{
  add_action("do_send","send");
}

int do_send(string str)
{
  object obj, me = this_player(), ob = this_object();
	int i;
  if(!str) return notify_fail("請輸入對方的英文名。\n");

  if(ob->query("in_use")) return notify_fail("此符咒只能用一次。\n");
  if( !obj=find_player(str) )
    return notify_fail("沒有這個玩家。\n");

	if( me->query_temp("ride") ) 
		return notify_fail("騎馬中又怎能神『行』~?~?\n");
  if(obj->money_type() != me->money_type() )
    return notify_fail(obj->name(1)+ "跟你所處的時空不同，無法進行傳送。\n");
  if(!environment(obj) || wizardp(obj) || environment(obj)->query("no_goto") || environment(me)->query("no_goto"))
    return notify_fail("似乎有股力量讓你無法唸咒。\n");
	for(i = 0;i<sizeof(club_area);i++)
	{
	if( strsrch(file_name(environment(obj)), club_area[i]) != -1 ) 
		return notify_fail("對方在幫會區域。\n");
	}

  set("in_use",1);
  set("no_sac",1);
  set("no_sell",1);
  set("no_drop",1);
  set("no_give",1);
  set("value",0);
  message_vision(HIR"$N舉起手中的$n，開始喃喃念咒，只見$N周圍的空氣開始騷動起來 ....\n"NOR,me,ob);
  ob->set("in_use",1);
  me->start_busy(1);
  call_out("walk",2,obj,me,ob);
  return 1;
}

void walk(object obj, object me, object ob)
{
  if(obj)
  {
    message_vision(HIC"\n一陣狂風之後，$N己消失在眾人的面前。\n\n"NOR,me);
    me->move(environment(obj));
    write(NOR""WHT"風神對著你說道：到達目的地了，主人。\n"NOR);
    message_vision(HIC"\n隨著一陣狂風，$N突然出現在此地！\n"NOR,me);
    write(HIR"神行符突然燒了起來！\n"NOR,me);
    destruct(ob);
    return;
  }
  message_vision(HIR"..... 結果什麼事都沒發生\n"NOR,me);
  ob->delete("in_use");
  return;
}

