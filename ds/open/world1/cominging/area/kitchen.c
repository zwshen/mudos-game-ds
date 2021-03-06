#include <room.h>
inherit ROOM;
inherit DOOR;

void create()
{
	set("short", "廚房");
	set("long", @LONG
這裡是颬颮客棧內部的一個小廚房，外面不時傳來店小二叫菜及招
呼客人的聲音，這裡面還算乾淨，至少不會過於骯髒，前方的大灶中的
木材不停 口白口劈 的發出聲音，在老廚的後方有一扇門，不過卻早已
封閉，久年失修。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "southwest" : __DIR__"hotel.c",
  "enter" : __DIR__"kitchen2.c",
]));
	set("objects",([
  __DIR__"npc/cook.c":1,
]));
	set("item_desc",([
  "大灶" : "大灶裡充滿了熱氣，似乎要將人吞噬掉一般的大，不過老廚卻不怎麼在意，大灶外黑漆漆的一片。\n",
  "木材" : "一堆被火正燃燒著的木材，還劈劈啪啪的在響。\n",
]));
	set("light", 1);
	set("no_clean_up", 0);
	create_door("enter","木門","out",DOOR_CLOSED);
	setup();
}
