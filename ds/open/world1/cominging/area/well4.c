inherit ROOM;
void create()
{
        set("short", "井底旁");
        set("long",@LONG
你從井底那慢慢的走了過來，在這裡你猜測大約是東大街的下方，
所以上方安靜得不可理喻，西方是你來的井底。
LONG
        );
        set("exits", ([
  "west" : __DIR__"well.c",
]));
        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}