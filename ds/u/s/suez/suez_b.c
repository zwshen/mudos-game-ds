inherit BULLETIN_BOARD;

void create()
{
        set_name("筆記本", ({ "notebook","board" }) );
        set("location", "/u/s/suez/workroom.c");
        set("board_id", "suez_b");
        set("long",
                "一本簡單的筆記本，除了一些塗鴉外是全空白的，\n"
                "要留言給蘇子奇可以寫在上面喔！\n" );
        setup();
        set("capacity", 77);

    set("master", ({ "suez" }));

}
