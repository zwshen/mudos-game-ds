inherit NPC;
void create()
{
        set_name("蝴蝶" , ({ "butterfly" }) );
        set("title" ,"強化狂暴化");
        set("level",40);
        set("race","野獸");
        set("age",15);
        set("long","牠是一隻被神力強化過的超級生化蝴蝶。\n");
        set("limbs", ({ "頭部", "身體", "觸角", "左翅", "右翅" }) );
        set("verbs", ({ "bite" }) );
        set("exp",0);
        setup();
}

