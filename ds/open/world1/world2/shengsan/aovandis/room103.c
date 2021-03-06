// 奧凡迪斯

// LV 1~50
#include <ansi.h>
#include <path.h>
#include <command.h>
inherit ROOM;

void create()
{
	set("short", HIC"小神殿"NOR);
	set("long", @LONG
你發現一座小神殿在這裡，但是卻找不出任何可以進去的方法，也許
這裡是神尊進出世界的出入口吧。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
        "out": __DIR__"room083",
            ]));

	set("no_clean_up", 0);
	set("light", 1);
	set("valid_startroom",1);
	set("item_desc",([	
	"壁畫" : "一幅掛在牆壁上的壁畫，壁畫裡有一位祥和的白衣老人正向你微笑著。\n"+
	"你發現壁畫下方有個鐵環(ring)。\n",
	])	);
	set("hide_item_desc",([	
	"ring" : "一個鑲在牆壁上的鐵環，可能常常有人去拉動(pull)它所以才沒生鏽。\n",
	])	);
	setup();
}

void init()
{
 add_action("do_pull","pull");
 add_action("do_out","out");
  tell_object(this_player(),"你發現你來到了一個神秘的地方。\n");
}

int do_pull(string arg)
{
 object me,*inv;
 int i;
 string buffer1,file;
 me=this_player();
 if(!arg) return 0;
 if(me->is_busy()) return notify_fail("你上一個動作還沒完成。\n");
 if(me->query_temp("ride")) return notify_fail("你騎著東西不方便靠過去拉鐵環。\n");
   if(me->query_temp("killer"))
  {
    write("你殺了人暫時不可以跨越時空!\n");
    return 1;
  }
   if(me->query_temp("invader"))
  {
    write("你攻擊了玩家暫時不可以跨越時空!\n");
    return 1;
  }

 
  if(arg=="ring" || arg=="鐵環")
  {
   inv = all_inventory(me);
   for(i=0; i<sizeof(inv); i++)
   {
    if(inv[i]->query("secured")) inv[i]->delete("secured");
    if(!inv[i]->query("base_value"))
    {
     file=base_name(inv[i]);
     if(sscanf(file,"/open/world1/%s",buffer1)!=1
     && sscanf(file,"/open/always/%s",buffer1)!=1 )
     {
      if(inv[i]->query("equipped")) inv[i]->unequip();
      DROP_CMD->do_drop(me, inv[i]);
     }
    }
   }
   tell_room(environment(me),me->name()+"拉了拉鐵環，突然發生一陣時空的扭曲。\n",({ me }));
   message("system", "你用力的拉了鐵環一把，突然間天旋地轉。\n\n",me);

   me->move(NOW"anfernee/start/nowroom");
   me->set("startroom",NOW"anfernee/start/nowroom");
   me->save();
   me->start_busy(1);
   message("system", "突然一陣空間的扭曲，你又回到了熟悉的地方。\n\n",me);
   tell_room(environment(me),"突然一陣強光，"+me->name()+"漸漸在你身邊凝聚成型。\n",({ me }));
   return 1;
  } 
 return 0;
}

int do_out()
{
if(this_player()->query_temp("now_old_city"))
  this_player()->move("/open/world2/shengsan/aovandis/room083");
else this_player()->move("/open/world2/lichi_town_2/map_5_26");

  return 1;
}
