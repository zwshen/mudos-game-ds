// Room: /u/a/acme/area2/p9.c

inherit ROOM;

void create()
{
	set("short", "滂水居");
	set("long", @LONG
這裡就是滂水居了，此房子全是由竹子所搭蓋而成，牆上掛滿了圖畫
詩詞，中央竹製小桌上文房四寶樣樣俱全，儼然是個書房，在滂水居外都
是一大片的竹林。在小桌上你可看到一張宣紙，上頭寫了幾行字。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
     "out" : __DIR__"start",
]));
       set("light",1);
set("objects",([
    __DIR__"npc/shi2" : 1,
]));
	set("item_desc", ([ /* sizeof() == 1 */
  "宣紙" : "上頭寫著「無肉讓人瘦，無竹令人俗」，等十字飛草。
",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
