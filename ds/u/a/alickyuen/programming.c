#include <ansi.h>

inherit ROOM;

void create()
{
        set("short", HIR"程式討論室 "HIY"[Java 2 Version]"NOR);
	set("long", @long
這裡最剛落成的新房間，除了有現行最新的設備外，還有一塊全
世界最得一塊的超新科技電子顯示版，是用來記錄關於程式寫作的討
論文章。當然歡迎你來討論及提了出你寶貴的意見。
long);
	set("light", 1);
	set("no_fight", 1);
	set("no_cast", 1);
	set("valid_startroom", 1);
	set("exits", ([
		"out" : __DIR__"workroom.c",
	]));

	setup();
        load_object("/obj/board/programming_b.c");
}

void init()
{
}

void test()
{
	write(""+save_variable(dbase));
}
