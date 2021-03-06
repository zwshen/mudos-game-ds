// Room: /open/world1/cominging/area/survey.c

inherit ROOM;

void create()
{
	set("short", "步靈城俯瞰台");
	set("long", @LONG
這裡是步靈城中最古老的遙望台，在這裡的周圍是由竹木所築成的
，似乎有點容易倒塌的樣子，在這的四周有許許多多的窗戶(windows)
，可以望向步靈城的四周，在晚上時的夜景也可稱的是蔚為一觀，可也
是步靈城中特別繁榮的景象，在牆壁上有許多地圖，也有許多人的作詩
，頗有些愛國的感覺，在你的腳下是通往廣場的樓梯，旁邊的牆上有著
一片小紙條(scrip)。
LONG
	);
	set("god_club_enter", 1);
	set("exits", ([ /* sizeof() == 2 */
  "out" : __DIR__"survey_out",
  "down" : __DIR__"boo-lin.c",
]));
	set("current_light", 1);
	set("light", 1);
	set("objects", ([ /* sizeof() == 1 */
  __DIR__"npc/minstrel.c" : 1,
]));
	set("item_desc", ([ /* sizeof() == 2 */
  "windows" : "這是一個由竹做成的窗戶，似乎可以從這跳下(jump)到南大街。
",
  "scrip" : "[1;36m小紙條上面寫著：
[1;32m可以用 singing 來讓我唱些歌曲或 ( talk with geisha ) 我將告訴你我會唱的歌。
[0m",
]));
	set("outdoors", "land");
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
