inherit ROOM;
void create()
{
        set("short","祭靈森林西側");
        set("long",@LONG
你走到了森林中的一條岔路，從西北邊隱約感覺似乎有著人煙居住
，看來森林應該並非是渺無人跡，東北則是一條小路，不知道通往何方
不過也許可以走去看看，到了這裡已經是森林深處了。
LONG
        );
        set("exits", ([
  "northeast" : __DIR__"t10",
  "northwest" : __DIR__"t8",
  "south" : __DIR__"t6",
]));
        set("no_clean_up", 0);
        set("outdoors","forest");
        setup();
        replace_program(ROOM);
}











