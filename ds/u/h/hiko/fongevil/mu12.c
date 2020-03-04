inherit ROOM;
void create()
{
        set("short", "山腰");
        set("long",@LONG
這裡是約接近山腰的地方，道路到此竟然有些修茸過，也許附近有
人居住於此，道路雜草較為低矮，，看來該是有人清理過的痕跡，使你
更加確信這裡有人跡，而東面的岩壁似乎有個小縫，北邊有一條路往半
山腰，西南則是往山下。
LONG
        );
  
set("exits", ([
  "northup" : __DIR__"mu13",
  "southwest" : __DIR__"mu11",
]));
set("item_desc",([
        "岩隙":"一條小小的隙縫，看來可以容人勉強鑽(squeeze)過。\n",
        ]) );
        set("no_clean_up", 0);
        set("outdoors","land");
        setup();
}

void init()
{
  add_action("do_squeeze","squeeze");
}

int do_squeeze(string arg)
{
  object me;
  me=this_player();
  if(!arg || arg != "岩隙") return notify_fail("你要鑽進哪裡 ?\n");
  message_vision("$N縮著身子硬是鑽進了岩隙中\n",me);
  me->start_busy(1);
  me->move(__DIR__"mu14");
  return 1;
}





