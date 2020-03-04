inherit ROOM;
void create()
{
      set("short","超•光子練習場『初級區』");
      set("long",@LONG
這裡的是讓新手互相切磋技巧的地方，在這裡有許多記載著關於涉及
技巧的電腦(computer)，旁邊放著許多電子報，有兩名新手正在合力與教
練周旋，希望能早日升到終極神槍手。
LONG);
set("exits",([
     "east":__DIR__"3.c",
]) );
        set("world", "future"); 
set("objects", ([
__DIR__"obj/computer.c"  :1,
__DIR__"npc/lv4_guard":   4,
]) );
setup();
}
void init()
{
        add_action("do_push","push");
}

int do_push(string arg)
{
        object me;
        me=this_player();
        if(!arg || arg!="1" ) return 0;
        message_vision("$N伸手在電腦上碰螢幕一下, 瞬間分解消失在這個房間了。 \n",me);
        me->move(__DIR__"weapon.c");
          tell_room(environment(me),me->query("name")+"的分子突然在這裡排列顯示出來。\n",me );
        return 1;
}

