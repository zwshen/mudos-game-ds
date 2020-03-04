
inherit ROOM;

void create()
{
	set("short", "·Ò¤¦©Ð");
	set("long", @LONG
³o¸Ì¬O§Å¬r±Ð·Ò¤¦ªº¦a¤è¡A¦³¤@¦ì·Ò¤¦®v³Å±Mªù¦b³o·Ò¦UºØ¯S®íªºÃÄ
¤¦¡C§A¥i¥H¬Ý¨ì¦³¤@­Ó·Ò¤¦¥Îªº·Ò¤¦Äl(furnace)¦b³o©Ð¶¡ªº¥¿¤¤¥¡¡AÁÙ¦³
¤@¨Ç¤u¨ã¤Î·Ò¤¦ªºÃÄ«~§÷®Æ³£¦b®à¤W¡C
LONG
	);

	set("item_desc", (["furnace":@NOTE
[1;36m
³o­Ó·Ò¤¦Äl¬O±Mªù·Ò¥X¦UºØ¯«©_ÃÄ¤¦ªºµ´¨Î¤u¨ã¡A¤]³\§A·|·Q¥hºNºN¥¦
(touch furnace)¡C
[m
NOTE
        ]) );

	set("exits", ([ /* sizeof() == 1 */
            "east" : __DIR__"room35",
            ]));

	set("objects", ([ /* sizeof() == 1 */
            __DIR__"mob/alchemist" : 1,
            ]));

	set("no_clean_up", 0);

	set("light", "1");

	setup();
}

void init()
{
  add_action("do_touch","touch");
}

int do_touch(string arg)
{
object me;
me=this_player();
  if (!arg || arg!="furnace") return notify_fail("§A­nºN¤°»ò?\n");
    message_vision("$N[1;36mºN¤F·Ò¤¦Äl¤@¤U......[1;31m«z!!!¦n¿Sªü[1;36m...[m\n",this_player());
    me->add("hp",-(10+random(10)));
//	message_vision("$N³Q¿S¶Ë¤F¡C\n",this_player());
	message_vision("$N³Q¿S¶Ë¤F¡C\n",me);
	return 1;
}
