inherit ROOM;

void create()
{
        set("short", "孟村東村口");
        set("long", @LONG
孟村是這附近極有名氣的「八極村」，此村老弱婦孺個個皆懂武術，
男子則都有學過八極拳，聽此地的村民說起，是由一位「八極門」第六
代掌門人，人稱「神槍李」的李書文師父所傳授。往東是座小廣場，往
西是一大片田地，孟村就在田地的彼端。
LONG
        );
        set("exits", ([ /* sizeof() == 2 */
  "west" : __DIR__"ms1",
  "east" : __DIR__"square",
  "north" : __DIR__"post_office",
]));
	set("outdoors","land");
        set("no_clean_up", 0);

set("light",1);
        setup();
        replace_program(ROOM);
}
