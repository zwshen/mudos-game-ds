#include <ansi.h>
inherit ROOM;

#define TARGET_ROOM __DIR__"book_hole.c"

void create()
{
	set("short", "黑石陣法");
	set("long", @LONG
這裡非常的奇怪，四周兩面是大沙漠，一面過去是西域大雪山，往西卻
是大草原。周圍亂七八糟的有幾百個灰褐色的巨石(stone)，像是自然形成的
又像是有人搬來的。
LONG);

	set("exits", ([
//	    "west" : __DIR__"plane00",
	]));
	set("item_desc", ([
		"stone" : "這裡有一塊特別大的石頭，它後面還有塊石碑，\n"+
			  "但被這塊大石擋了，看不見上面有些什麼東西。\n",
	]));

	setup();
}

void init()
{
	add_action("do_push", "push");
	add_action("do_look", "look");
}

int do_push(string arg)
{
	object me, room;

	me = this_player();
	room = this_object();
	if( !arg ) return 0;
	if( (int)room->query_temp("stone_pushed") )
		return notify_fail("你怎麼這麼喜歡沒事推石頭？\n");
	if (arg == "stone" ){
	if ( me->query("class1") != "天梟派" ){
		me->add("hp", -500);
		message_vision(HIR "$N運氣猛力向巨石一擊，結果不但沒推開它，反而震傷了自己。\n" NOR, me);
		me->unconcious();
		return 1;
	}
	if (me->query("ap") < 100 || me->query_str() < 20 ){
		message_vision("$N運起易筋經 使勁推了推巨石，無奈力量不夠，只好做罷。\n", me);
		me->add("ap", -100);
		return 1;
	}
	else{
	     me->add("ap", -100);
	       message_vision(HIG "$N體內真氣來回運轉，口中一叫，雙掌推出。\n\n"+
				  "只聽轟的一聲，巨石竟然被$N推開了，露出了後面的石碑。\n" NOR, me);
	       room->set_temp("stone_pushed", 1);
	       call_out("stone_push", 10);
	    }
	}
	return 1;
}

int do_look(string arg)
{
	object me, room;
	me = this_player();
	room = this_object();
	if( !arg ) return 0;
	if( !(int)room->query_temp("stone_pushed") )
		return notify_fail("隔著塊石頭怎麼看得見？\n");
		
	if ( me->query("class1") != "天梟派" )
		return notify_fail("你看了半天，還是不明白那上面寫了些什麼東西。\n");

	tell_object(me, HIB "\n 。。。。。。\n"+
			    "此處乃入藏經山洞之秘道，爾既然可以推開巨石，\n"+
			    "當已有一定用毒功\底，可算吾之傳人之人。可按如\n"+
			    "此走法進入藏經處。。。\n\n"+
			    "                      毒王毒千手\n\n" NOR);	message_vision("$N盯著石碑看了半天，臉上露出欣慰的表情，跟著$N腳步轉了幾轉，走進亂石堆裡不見了。\n", me);
        me->move(TARGET_ROOM);
	tell_object(me, "你兜兜轉轉走了半天，發現自己已經身在山洞中。\n");
	return 1;
}

int stone_push()
{
       object room = this_object();
       if(objectp(room)){
		message("vision", "轟的一聲，巨石又滾回來擋住了石碑。\n", this_object());
		room->delete_temp("stone_pushed");
       }
}
