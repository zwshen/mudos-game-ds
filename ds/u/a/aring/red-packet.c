#include <ansi.h>
inherit ITEM;
void create()
{
        set_name(HIR"低級紅包"NOR,({ "poor red packet","packet" }) );
        set_weight(1);
        if( clonep() )
        set_default_object(__FILE__);
        else {
        set("long",HIW"
很低級就是了。
\n"NOR);
        set("unit", "個");
        setup();
}
}
void init()
{
          if(getuid(this_player())=="aring") add_action("do_giveall","giveall");  
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
                case 0..100:
message("world:world1:vision",HIY"
【飢渴的財神妹妹大報】："HIR+me->query("name")+HIR"中了最高特獎『財神爺的笑顏』！！\n"NOR,users());                                   new(__DIR__"newyear-face")->move(me);   
                           break;  
                case 101..600:
                        amount = random(50000)+1000000;
                        me->add("bank/past", amount);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，裡面居然有 "+amount+" 元獎金！\n"NOR,me,obj);
                        break;
                case 601..800:
                        amount = random(100000)+100000;
                        me->add("exp", random(100000)+1);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，結果獲得 "+amount+" 點經驗值！\n"NOR,me,obj);
                        break;
                case 801..950:
                        amount = random(300)+1000;
                        me->add("popularity", amount);
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"後，結果獲得 "+amount+" 點聲望！\n"NOR,me,obj);
                        break;
                case 951..1000:
                        new(__DIR__"big-manto")->move(me);//玄光護脕
                        message_vision(HIC"$N打開了"HIR"紅包"HIC"時，光芒四射！"HIY"恭喜！"HIC"裡面是 BIG MANTO ！\n"NOR,me,obj);
                        break;
           
            }
  destruct(obj);
  return 1;
} 

int do_giveall(string arg)
{
        int i;
        string *list=({}),*temp=({});
        object *ppl,cake;
        ppl=users();
        if(this_object()->query("gived")) list = this_object()->query("gived");
        for(i=0;i<sizeof(ppl);i++)
        {
                if(getuid(ppl[i])=="jangshow") continue;
                if(!cake=new(base_name(this_object()))) continue;
                if(present("poor red packet",ppl[i])) continue;
                if(sizeof(list))
                {
                        if(member_array(getuid(ppl[i]),list)!=-1) continue;
                }
                
                if(cake->move(ppl[i]))
                {
                                          tell_object(ppl[i],HIW"\n\t財神突然現身於此，灑了大筆的紅包，然而你拾取其一！！\n"NOR);
                       temp+=({getuid(ppl[i])});  //紀錄
                       tell_object(ppl[i],HIY"\n\t       散完財，財神緩緩的走開。\n"NOR);
                } else tell_object(ppl[i],HIG"\n財神妹妹突然竄出來，又搖搖頭就走了。\n"NOR);
        }
        write(NOR+CYN"一共送給了"HIW+sizeof(temp)+NOR+CYN"個玩家紅包。\n"NOR);
        temp+=list;
        this_object()->set("gived",temp); //儲存紀錄
        return 1;
}

