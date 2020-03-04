// Room: /u/a/acme/area2/t11.c

inherit ROOM;

void create()
{
	set("short", "«Õ­ß¦aµ¢[¦a¤U¤G¼h]");
	set("long", @LONG
@§A¥¿¦æ¨«¦b³o²`¤£¨£§Cªº¶Â·t¦a¹D¡A¦a¹D³±·t¼éÀã¡A¥O§A´ý¨­Ä±
±o¤£µÎªA¡C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "northwest" : __DIR__"t12",
  "westup" : __DIR__"t10",
]));
          set("objects",([
             __DIR__"npc/jui" : 1,
          ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
       if( dir=="westup" && !userp(me) )
                return notify_fail("¨º¸Ì¥u¦³ª±®a¤~¯à¶i¥h¡C\n");
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("³o¸Ì¤Ó¹L¾ÖÀ½¤F¡A§A¨«¤£¹L¥h¡C\n");
        return ::valid_leave(me, dir);
}
