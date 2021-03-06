inherit ROOM;

void create()
{
	set("short", "電子帳棚中");
	set("long", @LONG
這是電子帳棚的內部，空氣十分清新，與外頭風沙漫天的情形不
同，帳棚裡頭有個小螢幕，正播放著輕鬆的音樂節目，音樂聲讓你眼
皮越來越沈重，你可以先躺下來，再好好享受這裡所提供的服務，保
證舒適(sleep)。
LONG
	);
	set("no_clean_up", 0);
	set("current_light", 1);
	set("exits", ([ /* sizeof() == 1 */
  "out" : __DIR__"minetown1",
]));

	setup();
}
void init()
{
        object me,out;
        me = this_player();
        out = find_object(__DIR__"minetown1");
        if(out) out->set("full",1);
        me->add_busy(1);
        call_out("sleep",0,me);
        call_out("wakeup",6,me);
        call_out("leaveroom",7,me);
        call_out("empty",7,out);
        return;
}

void sleep(object me)
{
        if(!me) return;
        me->remove_all_enemy();
        message("system","\n幽雅的古典樂在耳邊播放著...ZzzZzz \n\n",me);
        me->disable_player_cmds("你睡的正舒服，一根手指也動不了...。\n");
        //this_object()->disable_player(" <不醒人事>");
        me->set_temp("block_msg/all", 2);
        return;
}

void wakeup(object me)
{
        if(!me) return;
        me->set("hp",me->query("max_hp"));
        me->set("mp",me->query("max_mp"));
        me->set("ap",me->query("max_ap"));
        me->wakeup(2);
        me->start_busy(2);
        me->delete_temp("mine/tent");
        return;
}

void leaveroom(object me)
{
        if(!me) return;
        tell_room(this_object(),"你拍拍衣服爬起來，然後走出帳棚。\n");
        me->move(__DIR__"minetown1");
        tell_room(environment(me),me->name()+"從帳棚裡走了出來。\n",({me}));
        return;
}

void empty(object room)
{
        room->delete("full");
        return;
}
