inherit BULLETIN_BOARD;

void create()
{
        set_name("一張白紙", ({ "board" }) );
        set("location", "/u/k/king/workroom");
        set("board_id", "king_b");
        set("long",
                "這是一個供人留言記事的留言板。\n" );
        setup();
        set("capacity", 99);
}

