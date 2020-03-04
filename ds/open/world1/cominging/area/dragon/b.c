// This is a room made by roommaker.

inherit ROOM;

void create()
{
	set("short", "空房間");
	set("long", "這是一間什麼也沒有的空房間。\n");
        set("objects", ([ __DIR__"item/weapon_shelf" : 1,
                          __DIR__"item/equip_shelf" : 1,
                          __DIR__"item/item_shelf" : 1, ]));
        set("light",1);
        set("stroom",1); //這樣就不會清掉這裡的東西.也不會再生 (特殊情況才用)

	setup();
}
