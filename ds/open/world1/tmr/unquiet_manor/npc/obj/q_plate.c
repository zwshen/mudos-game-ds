inherit ITEM;

void create()
{
    set_name("無寧牌子", ({"unquiet sign", "sign"}));
    if( !clonep() ) {
        set("long", "這是一面�覂K，上面刻有「永無安寧」，透露著無法盡訴的怨念。");
        set("value", 100);
        set("unit", "面");
          set("weight", 10);
        } else
		   set_default_object(__FILE__);
    setup();
}
