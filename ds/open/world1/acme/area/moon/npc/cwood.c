inherit ITEM;
void create()
{
        set_name("毀壞的木人",({"bad wood's man","man"}));
        set_weight(10);
        if( clonep() )
                set_default_object(__FILE__);
        else {
set("long",@long
這是一個不成人形的木人，木人上滿滿是被人破壞的痕跡。
long
);
        set("unit","俱");
        }
        setup();
}
