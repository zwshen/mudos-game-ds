// Room: /u/a/acme/area2/t26.c

inherit ROOM;

void create()
{
	set("short", "�խߦa��[�a�U�T�h]");
	set("long", @LONG
�A�A�e��ƤV�A�a�D��M�����A�����}���Ӧ�A�V�V�e��A�s�y
�V�C�C
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "east" : __DIR__"t27",
  "south" : __DIR__"t25",
]));
        set("objects",([
           __DIR__"npc/lancer" : 1,
        ]));
	set("no_clean_up", 0);

	setup();
}
int valid_leave(object me, string dir)
{
    if( userp(me) && objectp( present("__GUARD__", this_object()) ))
            return notify_fail("�o�̤ӹL�����F�A�A�����L�h�C\n");
    return ::valid_leave(me, dir);
}
