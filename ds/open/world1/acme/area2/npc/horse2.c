inherit NPC;
void create()
{
        set_name("白馬",({"white horse","horse"}) );
        set("race", "野獸");
        set("level",15);
        set("age",10);
        set("long", "一隻全身長滿白毛的大馬。\n");
        set("limbs", ({ "頭部", "身體", "前腳", "後腳","復部"}));
        set("verbs", ({"bite","hoof","crash"}));
        set("ridable",1);               // 設定為可騎乘的
        setup();
}

int ride_before_action(object me)       // 騎乘之前會執行函式
{
        int s = me->query("str");
        if( s<15 || !s )
        {
                message_vision("由於$N的力量不夠，無法控制"+this_object()->name()+"，因而被"+this_object()->name()+"從白馬背上摔了下來！\n",me);
                return 0;               // 回傳 0 就是代表不能騎乘
        }
        else 
        {
                message_vision("$N使出全身的蠻力準備征服這隻"+this_object()->name()+"。\n",me);
                return 1;               // 回傳 1 就是代表可以騎乘
        }
}

int ride_after_action(object me)        // 騎乘之後會執行函式
{
        message_vision("$N已經騎上了"+this_object()->name()+"。\n",me);
        return 1;                       // 必須要回傳 1
}


int ride_off_action(object me)          // 離開座騎之後會執行函式
{
        message_vision("$N已經離開"+this_object()->name()+"了。\n",me);
        return 1;                       // 必須要回傳 1
}
