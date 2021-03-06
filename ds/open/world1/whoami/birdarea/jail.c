#include <ansi.h>
#include <path.h>
#include <room.h>

inherit ROOM;
inherit DOOR;

void create()
{
    set("short", "監牢");
        set("long", @LONG
這裡是一個監牢，四周的牆上掛滿了各式各樣的刑具，這裡
還充斥著一股惡心的屍臭味，看來似乎有不少人被刑求而死，眼
前還有兩個拿著鞭子的獄卒，看來變成那堆屍骨的時間也不遠了
LONG);
        set("exits", ([  "up" : __DIR__"rich6", ]));
        set("item_desc",([
            "屍骨":"一個早已乾枯\的屍骨，他身上應該沒什麼值錢貨•\n",     ]));
        set("no_recall",1); 
        set("no_pick",1);
        setup();
        create_door("up","鐵門","down",DOOR_LOCKED,"nokey"); 
}

int room_effect(object me)
{
   if(!me) return 1;
   message_vision(HIR"獄卒拿起鞭子往$N身上抽去，打得$N皮開肉綻！\n"NOR,me);
   me->receive_damage("hp",random(50), this_object());  
   return 1;
}

void init()
{
        ::init();
  add_action("do_run","run"); 
  add_action("do_fly","fly"); 
  add_action("do_search","search");
  add_action("do_send","send");
}

void clear_item() {
         set("item_desc",([
                "屍骨":"一個早已乾枯\的屍骨，他身上應該沒什麼值錢貨•\n",     ]));
        delete_temp("search_item");
}

int do_search(string arg)
{
        object me,item;
        if(arg != "屍骨") return 0;
        me = this_player();
        if( me->is_busy() ) return notify_fail("你的動作還沒有完成﹐不能做動作。\n");
        message_vision("$N不信邪的找了找屍骨，看看有沒有什麼寶貝•••\n",me);

        if( !query_temp("search_item") && me->query_temp("can_search_seal") ){
                item=new(__DIR__"npc/obj/seal");
                message_vision("找了又找，$N終於在屍骨裡找到"+item->query("name")+"•\n" ,me);
                item->move(this_player());
                set_temp("search_item", 1);
                  me->delete_temp("can_search_seal");
                 set("item_desc",([
                        "屍骨":"一個早已乾枯\的屍骨，看起來好像才剛被搜過。\n",     ]));
                call_out("clear_item", 600+random(300));
        } else
        {
                message_vision("$N找了又找，還是什麼也翻不出來..\n",me);
        }                               
        return 1;
}

int do_run()
{
  write("這裡是監牢！\n");
  return 1;
}

int do_fly()
{
  write("這裡是監牢！\n");
  return 1;
}

int do_send()
{
  write("這裡是監牢！\n");
  return 1;
}

int valid_leave(object me, string dir)
{
  mapping doors;
  doors = environment(me)->query_doors();
  if( dir=="up" && doors[dir]["status"] == DOOR_OPENED )
  { 
    message_vision("\n『碰』的一聲，$N身後的厚重鐵門突然被關上了•\n"NOR,me);
    lock_door(dir);
    return 1;
  }
  else if( dir=="up" && !doors[dir]["status"] == DOOR_OPENED ) 
    return notify_fail("門還沒開喔!\n");
  else return 0;
}


