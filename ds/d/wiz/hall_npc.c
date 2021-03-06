// Room: /d/wiz/hall3.c

inherit ROOM;

void create()
{
 set("short", "怪物討論廳");
 set("long", @LONG
這裡是巫師討論怪物寫法和發表新怪物的地方，往北是區域研究
室。要觀看技能注意事項請輸入 < about mob >，這裡也提供了測試
亂數的功能 <random 數字>，可以讓你更了解亂數的範圍及寫法。

LONG
	);
 set("light",1);
 set("exits", ([ /* sizeof() == 2 */
    "north"   : __DIR__"hall_area",
 ]));
 set("objects",([
  "/u/l/luky/npc/passenger":1,
  __DIR__"npc/playboy":3,
 "/u/s/shengsan/npc/groundmob":1,
 ]));
 set("no_clean_up", 0);
 set("valid_startroom", 1);
 setup();
 call_other("/obj/board/mob_b", "???");
}

void init()
{
 add_action("do_help","about");
 add_action("do_random","random");
}

int do_help(string arg)
{
 if(arg=="mob")
 {
   if( file_size("/doc/wiz/mob.txt")>0 )
   {
    this_player()->start_more( read_file("/doc/wiz/mob.txt") );
    write("\n");
   } else write(" SORRY. 說明檔尚未建立. \n");
  return 1;
 }
 return 0;
}

int do_random(string arg)
{
 string result;
 int p,i;
 if(!arg) return notify_fail(" 用法: random <數字範圍>\n");
 if(sscanf(arg, "%d", p)!=1)
	return notify_fail(" 用法: random <數字範圍>\n");
 result=sprintf("以下為重複100次 random(%d) 的結果:\n",p);
 for(i=0;i<20;i++)
 {
  result+=sprintf("%-8d  %-8d  %-8d  %-8d  %-8d\n",random(p),random(p),random(p),random(p),random(p));
 }
 write(result);
 return 1;
}