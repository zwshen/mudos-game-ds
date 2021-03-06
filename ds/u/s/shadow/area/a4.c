/**
 * Shadow's area [荒廢漁村 - a4]
 */
 
#include <login.h>
#include <room.h>
#include <ansi.h>

inherit ROOM;

void create()
{
	set("short",HIW"竹屋"NOR);
	set("long",@LONG
眼前是一幢破舊的竹屋，在蕭瑟的風中顯得格外的淒涼，但屋旁
所栽種的一畦菜園卻不似無人居住之地；屋旁有一大湖，柔水如鏡，
波光粼粼，水上還有浮橋一座，仔細一瞧隱約有一人影佇立其上。
LONG
	);
	set("light",1);
	set("outdoors","land");
	set("exits",([
		"west": __DIR__"a3",
		"east": __DIR__"a6",
		"enter": __DIR__"a5",
	]));

	setup();
}
