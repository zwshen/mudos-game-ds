inherit ROOM;
void create()
{
	set("short", "側街出口");
	set("long",@LONG
你終於走出了側街，又再度的感覺到了人聲的嘈雜，往東邊是步靈
城中央廣場的南邊，而往西邊是往側街的裡面，你不很清楚的看到側街
的轉角處有一些人圍著一棟三合院看戲的樣子。
LONG
	);
	set("exits", ([
  "west" : __DIR__"sidestreet3.c",
//  "east" : __DIR__"boo-lin3.c",
]));

	set("no_clean_up", 0);
	set("outdoors","land");
	setup();
	replace_program(ROOM);
}
