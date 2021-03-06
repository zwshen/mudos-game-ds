#include <npc.h>

inherit F_VILLAGER;
inherit F_VENDOR;

void create()
{
        set_name("哈笑臉", ({ "ha xiao lian","lian"}) );
        set_race("human");
        set_attr("int", 30 );
        set_attr("str", 19);
        set_attr("cor", 17);
        set_attr("cps", 15);
        set_attr("dex", 18);
          set("gender", "male");
          set("title", "副村長");
        set("age", 20);
        set("long",@long
哈笑臉是哈哈村的副村長，一張臉永遠帶著微笑，似乎完全沒
有憂愁一般，若你能把他搞得變苦臉，或許能在哈哈村成名。
long
);

        set("merchandise", ([
            "/d/obj/food/manto": 100,
            "/d/obj/food/manto2": 100,
            "/d/obj/food/dumpling": 100,
            __DIR__"obj/boat_ticket": 50,
            __DIR__"obj/bottle": 50,
            "/d/obj/drug/gin_pill" : 150,
            "/d/obj/drug/hp_pill" : 150,
            "/d/obj/bag" : 30,

        ]));


        set("chat_chance", 5);
        set("chat_msg", ({
                 "哈笑臉仰天打了個哈哈，您完全搞不清楚他在笑什麼...\n",
                 "哈笑臉堆滿滿臉的笑容熱情地招呼您...\n",
                 "哈笑臉正忙進忙出，臉上的笑意卻是絲毫未減...\n",
        }));
        setup();
}

void init()
{
        ::init();
        add_action("do_vendor_list", "list");
}
