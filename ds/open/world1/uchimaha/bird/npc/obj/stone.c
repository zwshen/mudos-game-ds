inherit ITEM;
void create()
{
        set_name("五彩石",({ "five-color-stone","stone" }));
        set_weight(500);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("long","這是一顆擁有五種顏色的石頭。\n");
                set("unit","顆");
                set("value",0);
        }
        setup();
}
