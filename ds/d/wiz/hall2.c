// Room: /d/wiz/hall2.c
#include <path.h>
inherit ROOM;

void create()
{
 set("short", "裝備討論廳");
 set("long", @LONG

  這裡是巫師討論裝備寫法和發表新裝備的地方﹐往上是怪物討論廳﹐
往下是巫師會客室。 要觀看裝備注意事項請輸入 < about equip > 
地上有幾件簡單的裝備, 你可以用 < more 裝備名 > 來看程式. 

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "down"   : __DIR__"hall1",
    "up"     : __DIR__"hall3",
    "east"   : __DIR__"hall2e",
 ]));
 set("objects",([
 "/u/l/luky/obj/fighterneck":1,
 "/u/l/luky/npc/eq/blackjacket":1,
 "/u/l/luky/npc/wp/kaisan_b":1,
 "/u/l/luky/npc/eq/detectring":1,
 "/u/l/luky/npc/wp/gun":1,
 "/u/l/luky/npc/wp/bullet":1,
 "/u/l/luky/npc/wp/bow":1,
 "/u/l/luky/npc/wp/arrow":5,
 "/u/l/luky/npc/item/dump":1,
 "/u/l/luky/npc/item/beer":1,
 "/u/l/luky/npc/item/pill1":1,
 "/u/l/luky/obj/torch":1,
 SHENGSAN2"aovandis/npc/food/cola":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/equip_b", "???");
}

void init()
{
 add_action("do_help","about");
}

int do_help(string arg)
{
 if(arg=="equip")
 {
   if( file_size("/doc/wiz/equip.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/equip.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}