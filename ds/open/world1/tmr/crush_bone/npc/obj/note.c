inherit ITEM;

void create()
{
    set_name("碎骨三斧祕籍", "crush-bone axe note", "note");
    set_weight(1000);
    if( !clonep() ) {
        set("unit", "本");
        set("value", 0);
         set("no_give",1);
        set("long",@long
　　這是一本有關碎骨三斧招式的祕籍，您可以藉由閱讀上面的文字
及符號來學得「碎骨三斧」。
long
);
        set("required/skill", ([
            "literate" : 50,
        ]));
        set("content", ([
            "crush-bone axe" : 20
        ]));
    }
          set("no_give",1);
    setup();
}

