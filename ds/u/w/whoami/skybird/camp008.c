inherit ROOM;

void create()
{
        set("short", "固山寨軍醫處");
        set("long", @LONG
這裡是個簡易搭制的小帳棚，裡面的擺放著各種傷藥以及繃
帶等物，旁邊站了幾位受傷的軍人，正在等候軍醫的叫喚。空氣
中淡淡的藥草味讓你有些感到不舒服。
LONG);
        set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"camp004",
]));
        set("objects", ([
       __DIR__"mob/soldier_doctor" : 1,
                ]));
        set("light",1);
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}

