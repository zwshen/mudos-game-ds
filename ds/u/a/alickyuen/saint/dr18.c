// Room: /u/a/alickyuen/area/dr18.c

inherit ROOM;

void create()
{
	set("short", "ST。Hospital＠Corridor");
	set("long", @LONG
這裡就是通往病房的走廊，所以你可以見到護士走來走去，忙得不可
開交。而有些病人在由護士送入病房，當然有些不同級數的病房供病人選
擇，亦會得到不同級數的服務。
LONG
	);
	set("exits", ([ /* sizeof() == 3 */
  "west" : __DIR__"dr17",
  "east" : __DIR__"dr19",
"north" : __DIR__"dr21",
]));
        set("item_desc", ([ /* sizeof() == 1 */
  "門" : "這是一道會自動開的門。\n",
]));
set("light",1);
	set("world", "future");
	set("no_clean_up", 0);

	setup();
}

int valid_leave(object me, string dir)
{
        if( dir=="north" ) tell_object(me,"當你正想走去開那扇門時，門突然自動打開了，原來是一扇《自動門》。\n");
        return ::valid_leave(me, dir);
}
