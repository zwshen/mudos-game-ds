inherit ROOM;

void create()
{
        set("short", "神界之門");
        set("long", @long
眼前有一座聳入雲霄的高塔 ─ 諸神塔，傳說遠古以前裡面住著
許多落入人間的神靈與惡魔。而現在已為一群與神最為接近的人所居
住，他們自稱為神族，塔內雖然已經找不到神魔的蹤跡了，但仍不減
當年全盛時期之氣勢。接近門口，便可以看到守護諸神塔的兩尊雕像
 ─ 米迦勒與路西法，讓人看了不禁心生敬畏。現今的神族雖是江湖
上新興的一股勢力，不過在名氣與實力方面，已經超越許多舊幫會。

long);
        set("exits", ([
  "south" : __DIR__"ladder-1",
]));
	set("objects", ([ "/open/world1/npc/goldman.c" : 10 ]));
        set("god_club_out", 1);
        set("light", 1);
        setup();
        replace_program(ROOM);
}

