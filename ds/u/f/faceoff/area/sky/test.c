#include <ansi.h>
#include <room.h>
#include <path.h>
inherit ROOM;
void create()
{
 set("short",HIC"祭天壇"NOR);
 set("long",@LONG
你現在終於站在這座平台之上，平台的地板是由青石所
鋪成的，看起來似乎是一座普通的祭天壇，唯一較為不同的
地方是，祭天壇的四周有四座不同顏色的雕像，分別為青，
赤，白，灰，而中央有一個金色的高台，大約到你的腰際，
上面有一個凹陷，裡面似乎可以放進什麼東西....
LONG
    );
 set("exits",([   "west":__DIR__"ten8",
               "east":__DIR__"ten7",
    ]));
set("item_desc",([
        "凹陷" : CYN"仔細一看，高台上有三個凹陷，分別是臉型凹陷，長型凹陷，及手型凹陷....\n"NOR,
       "手型凹陷" : CYN"就是手型的凹陷咩! 看來可以放進什麼東西..(putin)\n"NOR,
       "長型凹陷" : CYN"就是長型的凹陷咩! 看來可以放進什麼東西..(putin)\n"NOR,
        "臉型凹陷" : CYN"就是臉型的凹陷咩! 看來可以放進什麼東西..(putin)\n"NOR,
]));
set("no_clean_up",0);
set("outdoors","land");
 setup();
}

void init()
{
        add_action("do_putin","putin");
}
int do_putin(string arg)
{
       object me,ob,ghost,mask;
        me=this_player();
        ob=this_object();
      if ( arg == "mask")
      {
        if(!objectp(mask=present("faceoff mask",me) ) )
                return notify_fail("你身上沒有面具之類的東西。\n");
        destruct(mask);
        message_vision("$N將一個面具放進臉型凹陷。\n",me);
        message_vision(CYN"\n一股腥臭之氣從祭天壇的缺口中冒出!\n"NOR,me);
      ob->set("mask",1);
     if (ob->query("mask") == 1 && ob->query("leg") == 1 && ob->query("glove") == 1)
    {
       ob->set("open_war",1);
        call_out("open_war1",3,me,ob);
      }
        return 1;
     }
    if ( arg == "leggings")
      {
        if(!objectp(mask=present("baal leggings",me) ) )
                return notify_fail("你身上沒有護腿之類的東西。\n");
        destruct(mask);
        message_vision("$N將一雙護腿放進長型凹陷。\n",me);
        message_vision(CYN"\n一股血腥之氣從祭天壇的缺口中冒出!\n"NOR,me);
      ob->set("leg",1);
     if (ob->query("mask") == 1 && ob->query("leg") == 1 && ob->query("glove") == 1)
    {
       ob->set("open_war",1);
        call_out("open_war1",3,me,ob);
      }
        return 1;
     }
     if ( arg == "gloves")
      {
        if(!objectp(mask=present("uchimaha gloves",me) ) )
                return notify_fail("你身上沒有手套之類的東西。\n");
        destruct(mask);
        message_vision("$N將一雙手套放進手型凹陷。\n",me);
        message_vision(CYN"\n一股肅殺之氣從祭天壇的缺口中冒出!\n"NOR,me);
      ob->set("glove",1);
     if (ob->query("mask") == 1 && ob->query("leg") == 1 && ob->query("glove") == 1)
    {
       ob->set("open_war",1);
        call_out("open_war1",3,me,ob);
      }
        return 1;
     }

}

void open_war1(object me,object ob)
{
        int i;
       message("world:world1:vision",
           MAG"\n【十萬大山】"+HIR"祭天壇忽然籠罩在一片血腥之中，三道封印岌岌可危！！\n\n"+NOR,users());
        call_out("open_war2",3);
        return;
}
void open_war2(object me,object ob)
{
        int i;
        object g;
       message("world:world1:vision",
           MAG"\n【十萬大山】"+HIR"十萬生死印終於被解開，奇倪獸本尊重新回到奇倪峰！！\n\n"+NOR,users());
        g=new(__DIR__"npc/chini.c");
        g->move("/u/f/faceoff/area/sky/ten9.c");
        return;
}

