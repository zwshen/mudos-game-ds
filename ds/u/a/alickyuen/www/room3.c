/*-----------取至/d/wiz/hall_area.c修改-----------*/
#include <ansi.h>

string query_ips(object *all_ppl, object current_ppl);
inherit ROOM;
 
void create()
{
    set("short", HIW+BLK"測試區"NOR);
    set("long",
WHT"\n█████"NOR+RED"█████"YEL"█████"BLU"█████\n"
HIW"█████"HIR"█████"HIY"█████"HIB"█████\n"
BLK"█████"HIM"█████"HIG"█████"HIC"█████\n"NOR);
    set("light",1);               
    set("no_clean_up", 0);
    set("exits", ([
        "up"     : __DIR__"workroom"]));
    set("objects", ([
                "/u/f/fedex/fantasyland/obj/obj1" : 1,
]));
    set("valid_startroom", 1);
    setup();
}

void init()
{
    object me;
    me = this_player();

    if(!userp(me)) return;
    if(!this_object()->query("open") && me->query("id") != "fedex")
    {
       message_vision("\n\n"HIY+me->query("name")+HIM",目前這個地方無法進入。\n\n"NOR,me);
       me->move(__DIR__"workroom");
    }
    else
    {
       add_action("do_lock","on");
       add_action("do_unlock","off");
       call_out("welcome",1,me);
    }
    return;
}

int welcome(object me)
{
    int player,wiz;

    foreach(object user in users())
    {
       if(wizardp(user))
       { wiz++; } 
       else if(userp(user) && environment(user))
       { player++; }
    }
    message_vision(HIY+me->query("name")+HIM",歡迎回來。\n"NOR,me);
    write(HIM"目前線上有: 玩家"+player+"人 巫師"+wiz+"人\n"NOR);

    if(this_object()->query("open"))
    { write(HIW+BLK"[磁場已關閉]\n"NOR,me); }
    else
    { write(HIW+BLK"[磁場已啟動]\n"NOR,me); }
    return 1;
}

int do_unlock(string arg)
{
    if(this_object()->query("open"))
       return notify_fail("巫師過濾力場已經關閉了。\n");
    message_vision(HIW"$N關閉了巫師過濾裝置磁力場!!\n\n"NOR, this_player());
    this_object()->set("open",1);
    return 1;
}

int do_lock(string arg)
{
    object *inv;

    if(!this_object()->query("open"))
       return notify_fail("巫師過濾力場已經啟動了。\n");
    message_vision(HIW"$N啟動了巫師過濾裝置磁力場!!\n\n"NOR, this_player());
    this_object()->delete("open");

    inv = all_inventory(this_object());
    foreach(object user in inv)
    {
       if(!userp(user)) continue;
       if((user)->query("id") != "fedex")
       {
          message_vision(HIW"\n\n"HIY+user->query("name")+HIM",目前這個地方無法進入。\n\n"NOR, user);
          user->move(__DIR__"workroom");
       }
    }
    return 1;
}
