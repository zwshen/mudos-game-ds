#include <command.h>
#include <path.h>
// Room: /open/world3/tmr/basic/digging_street2.c

inherit ROOM;

void create()
{
	set("short", "馬路");
	set("long", @LONG
一條連繫礦場與住宅區的馬路。由於礦場的空氣非常污濁，在馬路兩
旁有大型的空氣清新機，亦用可穿越型護罩將兩區隔離，令到居民得到舒
適的生活環境。你不經意發現，在你腳邊的護罩底破了個小洞，冒出一縷
縷的[0;1;37m�[1m�[1m�[1m�[1m�[1m�[1m�[1m�[0m....
LONG
	);
	set("item_desc", ([ /* sizeof() == 1 */
  "穿越型護罩" : "由一種膠質物體製成的，只能讓液體和固體通過，使得能夠達到阻隔
污濁空氣的效果。
",
"白色霧氣":"散發著香味的白色霧氣，不知讓身體浸滲(immerse)裡頭會如何。\n",
]));
	set("world", "future");
	set("outdoors", "desert");
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"digging_street1",
  "south" : __DIR__"digging_street3",
]));
	set("no_clean_up", 0);

	setup();
}

void init()
{
        add_action("do_immerse","immerse");
}

int do_immerse(string arg)
{
        object me,*inv;
        int i;
        string buffer1,file;
        me=this_player();
        if(!arg || arg!="白色霧氣") return 0;

        if(me->is_busy()) return notify_fail("你上一個動作還沒完成。\n");

        if(me->query_temp("ride")) 
                return notify_fail("你的座騎顯然不願意陪你一起靠進霧氣....\n");
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


        tell_room(environment(me),me->query("name")+"慢慢地的整個身體滲進白色霧氣裡頭了....\n",({me}) );
        inv = all_inventory(me);

        for(i=0; i<sizeof(inv); i++)
        {
        if(inv[i]->query("secured")) 
                inv[i]->delete("secured");
        if(!inv[i]->query("base_value"))
        {
        file=base_name(inv[i]);
        if((sscanf(file,"/open/world2/%s",buffer1)!=1 && sscanf(file,"/open/always/%s",buffer1)!=1 )
                || inv[i]->query_max_encumbrance() > 0)
                {
                if(inv[i]->query("equipped")) inv[i]->unequip();
                DROP_CMD->do_drop(me, inv[i]);
                }
        }
        }
        message("system", "你丟下一些多餘的物品, 慢慢的走進白色的霧氣。\n\n",me);
        me->move(NOW"anfernee/start/hall3");
        me->set("startroom",NOW"anfernee/start/hall3");
        me->save();
        message("system", "突然一陣空間的扭曲.. 你又回到了熟悉的地方。\n\n",me);
        tell_room(environment(me),me->name()+"突然出現在你的面前。\n",({ me }));
        me->start_busy(1);
        return 1;
}

