/**
 * Shadow's area [荒廢漁村 - a3]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"空地"NOR);
	set("long",@LONG
穿過了一大片惱人的芒草後，眼前竟是一大片的空地。青磚所舖
成的步道依稀可見，一些簡單的捕魚工具卻散置在地上，路旁的大樹
下亦可看出有人在此飲酒作樂的痕跡，散落的酒瓶與歪歪斜斜的桌椅
讓人可以想見當年熱鬧的情景，偏偏這四周的寂靜卻讓你彷彿置身在
空城之中，讓你不禁心生納悶著這兒究竟發生了什麼事。
LONG
	);
	set("light",1);
	set("outdoors","land");
	set("exits",([
		"east": __DIR__"a4",
		"north": __DIR__"a7",
		"leave": __DIR__"a2",
	]));

	setup();
}
