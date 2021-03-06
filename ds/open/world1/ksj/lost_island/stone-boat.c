#include <room.h>
#include <ansi.h>
inherit ROOM;

void create()
{
  set("short", "石舟上");
  set("long", @LONG
這是一艘石製的小船，船上無帆無蓬也沒有槳跟舵，石舟兩旁鑲
嵌許多藍色的小石子，形成網狀的紋路，奇特的是海水似乎被小石子
所排斥，使得整個石舟是浮在海面上。
LONG
);
  set("item_desc", ([ /* sizeof() == 1 */
      "石臺" : "立在石舟上的小石臺，上面有個小凹洞，不知是何用處(use)。\n",
     ]));
  set("exits", ([ /* sizeof() == 2 */
      "out" : __DIR__"room_add",
     ]));
  set("no_clean_up", 0);
  set("light",1);
  set("no_recall",1);
  setup();
}

void init()
{
  int i,count;
  object *inv,room;
  count=0;
  inv = all_inventory(this_object());
  room = load_object(__DIR__"room_add");
  add_action("do_use","use");

  for(i=0;i<sizeof(inv);i++)
  {
    if( living(inv[i]) && userp(inv[i]) ) count++;
  }
  
  if( count > 3)
  {
    message_vision("\n$N因為石舟空間狹窄，而硬是被擠了出去！\n\n",this_player());
    this_player()->move(__DIR__"room_add");
    tell_room(room,"石舟晃了一晃，有個人被擠了出來...\n");
  }
}

int do_use(string arg)
{
  object me,room,*inv,z;
  me=this_player();
  if(arg != "stone") return 0;
  if(!objectp(z=present("sea stone",me) ) )
    return notify_fail("你身上並沒有合適的物品可供使用。\n");
  if(!this_object()->query_temp("moving")) 
  {
    inv = all_inventory(this_object());
    message_vision(HIC"\n$N將碧海石嵌在石舟的小平臺上，石舟像是得到動力似的朝海上急駛！\n\n"NOR,me);
    destruct(z);
    call_out("domessage",5,6);
    this_object()->set_temp("moving",1);
    this_object()->delete("exits");
    room = load_object(__DIR__"room_add");
    room->delete("exits/enter");
    tell_room(room,"你看到石舟以高速航向遠方...\n");
    return 1;
  }
  else
  {
    tell_object(me,"石舟高速遠離岸邊。\n");
    return 1;
  }

}

int domessage(int b)
{
  object *inv,room;
  int i;
  if(b==6) tell_room(this_object(),HIW "石舟飄浮在海面急駛，你只聽得到耳邊呼呼的風聲...\n\n" NOR);
  else if(b==5) tell_room(this_object(), HIW "石舟繼續在海面急駛....\n\n" NOR );
  else if(b==4) tell_room(this_object(), HIW "石舟連續衝過幾個大浪，劇烈搖晃了幾下....\n\n" NOR );
  else if(b==3) tell_room(this_object(), HIY "石舟的速度越來越快了！！\n\n" NOR );
  else if(b==2) tell_room(this_object(), HIR "你注意到"HIC"碧海石"HIR"冒出一絲青煙....\n\n" NOR );
  else if(b==1) tell_room(this_object(), HIW "遠遠地你看到一個黑點，漸漸地越來越大，原來是座小島。\n\n" NOR );
  else
  {
    inv = all_inventory(this_object());
    tell_room(this_object(),HIR "一陣劇烈的衝擊使得你從石舟上飛了出去，狠狠地摔在岩灘上..\n\n" NOR );
    this_object()->delete_temp("moving");
    room = load_object(__DIR__"room1");
    tell_room(room,HIW"你看到一條小船高速衝了過來..\n"NOR);
    for(i=0;i<sizeof(inv);i++)
    {
      if(living(inv[i])) inv[i]->move(__DIR__"room1");
    }
    tell_room(room,HIR"石舟衝撞岩灘後，遠遠的彈了開去，..\n"NOR);
    this_object()->set("exits", ([
                       "out" : __DIR__"room_add",
                      ]));
    call_out("delay",900);
    if( userp(this_player()) )
    {
      message("world:world1:vision",
        HIW"\n\t幾經波折"HIY""+this_player()->name(1)+HIW"終於到達了傳說中的"HIG"【遺世島】"HIW"！\n\n"NOR
        ,users());
    }
    return 1;
  }
  b--;
  call_out("domessage",5,b);
}

void delay()
{
  object room;
  room = load_object(__DIR__"room_add");
  room->set("exits", ([ /* sizeof() == 2 */
            "north" : "/open/world1/wu_sha_town/seacoun42",
            "enter" : __DIR__"stone-boat",
           ]));
}
