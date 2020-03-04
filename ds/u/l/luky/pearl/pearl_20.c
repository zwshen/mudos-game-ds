// Room: /u/l/luky/room/pearl_20.c
#include <ansi.h>
inherit ROOM;
void create()
{
set("short", HIG"珍珠北街"NOR);
set("long", @LONG

＿＿＿＿＿   這裡是碧雷爾鎮的東北角。你看到牆  ＿＿＿＿╱��
"  .   -   角有個三角形的小洞，洞口還有一些魚        ▕: ��
:      -   骨頭。從這裡往南是珍珠東街，往西則       -▕: ��
= ."   -   是熱鬧的珍珠北街，那裡有幾棟十分現       =▕: ��
==-  " -   代化的建築物。                 -      -=[32m▲[m▕: ��
￣￣￣￣￣                   ￣￣￣￣￣￣￣￣￣￣￣￣￣╲��


LONG
);
set("exits", ([ /* sizeof() == 2 */
"west" : __DIR__"pearl_19",
"south" : __DIR__"pearl_21",
]));
set("item_desc",([
"hole":"一個三角形的小洞。\n",
"bone":"一堆吃剩的魚骨頭。\n",
]));
set("no_clean_up", 0);
set("light",1);
setup();
}

void init()
{
 add_action("do_search","search");
}

int do_search(string arg)
{
 object me,obj;
 me=this_player();
 if(!arg) return notify_fail("你要搜查什麼?\n");
 if(arg=="hole" || arg=="小洞" || arg=="洞")
 {
  if(query_temp("nocork")) return notify_fail("小洞裡面沒有任何東西.\n");
  message_vision("$N從小洞中找到了一個小木塞。\n",me);
  obj=new(__DIR__"obj/cork");
  if ( (obj->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
  {
   write("你拿不動小木塞, 手一軟..小木塞掉到地上了!!\n");
   obj->move(environment(me));
  } else
  obj->move(me);
  set_temp("nocork",1);
  call_out("do_reborn",600);
  return 1;
 }
 if(arg=="bone" || arg=="魚骨頭" || arg=="骨頭")
 {
  if(query_temp("bone")>10) return notify_fail("剩下一堆殘渣..沒有什麼好拿的了.\n");
  message_vision("$N從魚骨頭中找到了一隻魚骨箭。\n",me);
  obj=new(__DIR__"npc/item/fisharrow");
  if ( (obj->query_weight()+this_player()->query_encumbrance())>this_player()->query_max_encumbrance() )
   return notify_fail("可是你的力量不夠,拿不起來\n");
  obj->move(me);
  add_temp("bone",1);
  call_out("do_reborn",600);
  return 1;
 }
 return 0;
}

void do_reborn()
{
 this_object()->delete_temp("nocork");
 this_object()->delete_temp("bone");
}