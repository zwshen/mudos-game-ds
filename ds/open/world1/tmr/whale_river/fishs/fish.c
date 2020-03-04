inherit ITEM;
inherit F_FOOD;


string* fish_name=({
        "白邊天竺鯛 ","庫氏天竺鯛 ","帆鰭魚"
        "三齒魨","艾齒魚","短吻六鰓魟","彎線雙邊魚","北梭魚","平額魚",
 });

void create()
{
        string n=fish_name[random(sizeof(fish_name))];
        set_name( n, ({ "fish" }) );
        if( !clonep() ) {
                  set("unit", "條");
                set("base_unit", "條");
                set("food_stuff", 50);
                set("long", 
                "這是一條剛釣上岸的"+ n +"，在你手上還活蹦亂跳的。\n"
                );
        }
        set("value", (1+random(5))*10);
          set_weight(500);
        setup();
}

