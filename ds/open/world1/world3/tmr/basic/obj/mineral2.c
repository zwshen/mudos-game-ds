inherit ITEM;

void create()
{
        set_name("金礦",({ "gold mineral","mineral" }) );
        set("long",@long
一小塊剛挖出來的金礦，還參雜著其他無用的礦物，看來未經提鍊，
也是沒什麼用處。金礦是現有礦產中，售價頗高的礦物，只是存量已經不
多了。
long
);
        set_weight(100);
        if( clonep() )
                set_default_object(__FILE__);
        else
        {
                set("unit","堆");
                  set("value",200);
		set("material","gold");
		set("volume",1);
        }
        setup();
}

