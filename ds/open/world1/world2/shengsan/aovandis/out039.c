// 奧凡迪斯郊區
// LV 1~50
inherit ROOM;

void create()
{
	set("short", "樹林");
	set("long", @LONG
樹林間的小生物常在這玩耍，頑皮的小松鼠有時會把牠們在外面偷來
的東西藏在這裡面。你看到這裡有涓涓的流水從石壁縫裡流出來，也許你
可以嚐嚐(taste)其中的箇中滋味。
LONG
	);

	set("exits", ([ /* sizeof() == 4 */
	    "south": __DIR__"out045",
            ]));

	set("outdoors","land");	// 平原
	set("no_clean_up", 0);
	set("valid_startroom",1);

	setup();
}

void init()
{
	add_action("do_taste","taste");
}

int do_taste(string arg)
{
	object me;
	me=this_player();
 
  if(!arg) return notify_fail("你想嚐什麼?\n");
  if(arg=="流水"||arg=="水"||arg=="water")
  {
 	if(me->is_ghost()) return notify_fail("�[1m天上傳來悠悠的聲音: �[33m我只能幫助有生命的人。�[0m\n");
	message_vision("$N彎下腰喝了幾口天然泉水。\n", me);
	if((me->query("hp")<me->query("max_hp") || me->query("wound")) && me->query("level")<6 )
	{
 	 me->reincarnate();
	 tell_object(me,"你的身體狀況完全回復了。\n");
	 return 1;
	} else
	{
		return notify_fail("你覺得十分清涼。\n");
	}
 }
 notify_fail("你想嚐什麼?\n");
 return 0;
}
