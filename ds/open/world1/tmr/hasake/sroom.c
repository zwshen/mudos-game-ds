// sroom.c 睡房
inherit ROOM;

void create()
{
        set("short", "哈薩克帳篷");
        set("long", @LONG
這是哈薩克族人居住的帳篷，帳篷內用羊皮鋪地，四周也掛了好些羊
皮牛皮，左邊是一張用幹草墊底的羊毛床，入口有一小火盆。看起來主人
似乎不在家，你如果累了就歇息一下吧。
LONG);
        set("exits", ([            
            "southeast" : __DIR__"shop",            
        ]));                
        setup();
        replace_program(ROOM);
}
