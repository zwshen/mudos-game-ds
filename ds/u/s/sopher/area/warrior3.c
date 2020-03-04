#include <path.h>
#include <ansi.h>
inherit ROOM;
void create()
{
        set ("short", HIY"超龍軍團第一分部軍務處"NOR);
        set ("long", @LONG
這裡是軍務處，堆的如山高的文件，散落一地。你兩旁
盡是書架和書櫃，裡面也裝滿了文件，你眼前這位軍務官，
你不禁開始同情他了....:P
LONG);  
        set("no_fight",1);
        set("no_spells",1);
        set("no_magic",1);
        set("exits", ([
        "east": __DIR__"warrior2",
        "north":__DIR__"lightning",
        "south":__DIR__"ice",
        "west": __DIR__"fire",
         ]) );
        set("objects", ([
        __DIR__"npc/guard3" : 1,
        __DIR__"npc/knight" :2,
        ]) );
        set("outdoors","workroom.c"); 
        set("item_desc", ([
         "sign": "
          西:火龍騎團本部
          北:雷龍騎團本部
          南:冰龍騎團本部
          ", ]) );
        setup();
        replace_program(ROOM);
}
