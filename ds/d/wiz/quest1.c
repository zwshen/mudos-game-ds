// Room: /u/l/luky/workroom.c
#include <ansi.h>  //若要用有顏色的須加此行
#include <room.h> //要加門要這一行
#include <path.h>
inherit ROOM;
inherit DOOR;

void create()
{
 set("short","廢棄礦坑");  //短敘述
 set("long","\n"
	+"  這裡是一個廢棄的礦坑, 四週都是一些損壞的工具和垃圾...不過你發現\n"
	+"旁邊有雙小孩子穿的運動鞋(boots), 似乎還蠻新的。這裡很適合當孩子們\n"
	+"的秘密基地..或許\它已經是某些孩子們的基地了。\n"
 ); //長敘述

 set("exits", ([  //此房間連結之出口方向及檔案
 "north": __DIR__"quest2",
 "out": __DIR__"hall4",
 ]));
 set("item_desc", ([
     "boots" : "一雙白色的運動鞋, 或許\你可以試著更仔細的搜查(search)看看。\n",
 ]));
 set("no_clean_up", 0);
 set("light",1);
 create_door("north","黑色鐵門","south",DOOR_LOCKED,"redkey");
 setup();
}

void init()
{
 add_action("do_open","open");
}

int do_open(string arg)
{
 object me,jail,boy;
 
 me = this_player();
 
 if(arg=="door" || arg=="north")
 {
  jail = load_object("/d/wiz/quest2");
  if(!jail) return 0;
  boy=present("boy",jail);
  if(!boy) return (int)call_other("/cmds/std/open", "main", me, arg);
  if(!call_other("/cmds/std/open", "main", me, arg)) return call_other("/cmds/std/open", "main", me, arg);
  message_vision("突然一個小孩子從鐵門後面走了出來。\n",me);
  boy->move(this_object());
  message_vision(YEL"$N(boy)說:我忘了帶鑰匙了...謝謝你救了我一命!!\n",boy);
  message_vision(HIY"$n由衷的感激$N的幫助。\n"NOR,me,boy);
  tell_object(me,HIC"\n恭喜你完成了一個最簡單的任務!!, 現在對任務有點心得了吧!\n\n"NOR);
  return 1;
 }
 return 0;
}

int do_search(object me,string arg)
{
 object key;
 if(!arg) return 0;
 if(arg == "boots")
 {
  if(this_object()->query_temp("key"))
  {
   message_vision("$N拿起兒童運動鞋檢查了一番..但是沒有什麼新發現, 只好放回原處。\n",me);
   return 1;
  }
  message_vision("$N拿起兒童運動鞋檢查了一番..突然掉出一把鑰匙。\n",me);
  key = new("/u/l/luky/redkey");
  key->move(this_object());
  this_object()->set_temp("key",1);
  return 1;
 }
 return 0;
}

void reset()
{
	this_object()->delete_temp("key");
	::reset();
}