// Room: /u/a/acme/area/cloth.c

inherit ROOM;

void create()
{
	set("short", "布莊");
     set("light",1);
	set("long", @LONG
這裡是一間頗具規模的布莊，四周掛滿了布匹，這裡的裁縫師是聘請
當地最有名的師傅，他可為你度身縫裁適合自已體形的各式衣服。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"street3",
]));
set("room_type","sell");        //商店(只能買東西)
	set("no_clean_up", 0);
        set("objects",([
                __DIR__"npc/lin" : 1,
        ]) );

	setup();
	replace_program(ROOM);
}
