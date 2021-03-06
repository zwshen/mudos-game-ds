#include <ansi.h>
#include <room.h>
#include <localtime.h>

inherit ROOM;
void create()
{
   set("short",HIG"活跳跳"NOR);
   set("no_clean_up",0);        
   set("light",1);               
   set("exits", ([
       "east" : __DIR__"room"]));
//   set("objects", ([
//                __DIR__"npc/man" : 1]));
   set("valid_startroom", 1);
   setup();
   load_object(__DIR__"board/www_b");
}

void init()
{
   mixed *local;
   int WDAY;
   object me = this_player();
   string time,day;
   local = localtime(time());
   WDAY = local[LT_WDAY];

   // ===============設定時間===============
   if(WDAY == 1) day="一";
      else if(WDAY == 2) day="二";
      else if(WDAY == 3) day="三";
      else if(WDAY == 4) day="四";
      else if(WDAY == 5) day="五";
      else if(WDAY == 6) day="六";
      else if(WDAY == 0) day="日";
   time = sprintf("\n\n\t【"HIW"%d年%d月%d日 星期%s"BLK" %d:"HIW+BLK"%d"NOR"】\n\n",
          local[LT_YEAR]-1911,local[LT_MON]+1,local[LT_MDAY],
          day,local[LT_HOUR],local[LT_MIN]);
   set("long",time);
}
