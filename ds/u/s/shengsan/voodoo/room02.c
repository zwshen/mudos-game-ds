inherit ROOM;

void create()
{
	set("short", "翠林石階");
	set("long", @LONG
沙沙的竹葉聲從你耳邊彿去，美麗的鳥兒在竹林中啾啾的叫，但是
不管身旁有什麼景色，你畢竟還是在別人的地盤上，還是小心點好。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
            "up"   : __DIR__"room03",
	    "down" : __DIR__"room01",
            ]));

	set("no_clean_up", 0);
	set("outdoors",1);
	setup();
	replace_program(ROOM);
}
