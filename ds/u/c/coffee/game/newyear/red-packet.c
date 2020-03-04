#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"紅包"NOR, ({ "red packet","packet" }));
        if( clonep() )
                set_default_object(__FILE__);
        else

                set("long","看起來很大包的紅包，快打開(open)看看吧！\n");
        
        set("no_auc",1);
        set("no_put",1);
        set("no_sell",1);
        set("no_give",1);
        set("no_drop",1);
        set("unit", "個");
        setup();
}

void init()
{
  add_action("do_open","open");
}

int do_open(string str)
{
        int amount;
        object obj,me;        
        obj = this_object();
        me = this_player();
                
        if(!str || str != "packet")
           return notify_fail("你要開什麼？\n");
        if(me->query("red-packet2"))
           return notify_fail("你剛剛已經開過了哦...\n");

        switch(random(1000))
        {
                case 0..400:
                        new(__DIR__"cookie")->move(me);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，裡面竟然是一塊大餅！\n"NOR,me,obj); 
                        break;
                case 401..700:
                        amount = random(50000)+1;
                        me->add("bank/past", amount);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，裡面居然有 "+amount+" 元獎金！\n"NOR,me,obj);
                        break;
                case 701..850:
                        amount = random(100000)+1;
                        me->add("exp", random(100000)+1);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，結果獲得 "+amount+" 點經驗值！\n"NOR,me,obj);
                        break;
                case 851..990:
                        amount = random(20)+1;
                        me->add("popularity", amount);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，結果獲得 "+amount+" 點聲望！\n"NOR,me,obj);
                        break;
                case 991..999:
                        new(__DIR__"light-hands")->move(me);//玄光護脕
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"時，光芒四射！"HIY"恭喜！"HIC"裡面是 SAVE EQ ！\n"NOR,me,obj);
                        break;
           
            }
  destruct(obj);
  return 1;
}


