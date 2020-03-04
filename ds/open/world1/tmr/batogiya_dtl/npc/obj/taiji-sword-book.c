inherit ITEM;
inherit F_STUDY;

void create()
{
    set_name("太極劍譜", "taiji-sword book", "book");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 0);
        set("no_give",1);
        set("long",@long
　　這是一本太極劍法的劍譜，封面有個太極的圖示。
long
);
        set("required/skill", ([
            "literate" : 110,
        ]));
        set("content", ([
            "taiji-sword" : 10,
        ]));
    }
    setup();
}

